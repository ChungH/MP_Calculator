//
//  Cache.cpp
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 6. 4..
//  Copyright (c) 2015년 CH. All rights reserved.
//

#include <iostream>
#include "Cache.h"

CacheInfo::CacheInfo():_tag(-1),_dirty(false),_SCA(false){
    
}

Line::Line(){
    int i;
    for(i = 0; i < CacheLine/4; i++)
        _cacheData[i] = 0;
    
    _cacheInfo = CacheInfo();
    
}

Set::Set(){
    int i ;
    for(i = 0; i < Lines; i++){
        _line[i] = Line();
    }
}

Cache::Cache(){
    int i;
    for(i = 0; i<Sets; i++){
        _set[i] = Set();
    }
    memset(_LRUCounter,0,sizeof(int)*Lines);
    SetMasking();
}


void Cache::SetMasking(){
    if(CacheSize == 64){
        _lineMask = lineMask_64;
        _tagMask = ~(offsetMask);
    }
    else if(CacheSize == 128){
        _lineMask = lineMask_128;
        _tagMask  = ~(lineMask_128 | offsetMask);
    }
    else if(CacheSize == 256){
        _lineMask = lineMask_256;
        _tagMask  = ~(lineMask_256 | offsetMask);
    }
}

void Cache::InsertData(unsigned int set, unsigned int line, unsigned int offset, unsigned int inst){
    _set[set]._line[line]._cacheData[offset] = inst;
}

void Cache::InsertTag(unsigned int set, unsigned int tag, unsigned int line){
    _set[set]._line[line]._cacheInfo._tag = tag;
}

unsigned int Cache::GetData(unsigned int set, unsigned int line, unsigned int offset){
    _set[set]._line[line]._cacheInfo._SCA = true;
    return _set[set]._line[line]._cacheData[offset];
}

void Cache::WriteData(unsigned int set, unsigned int line, unsigned int offset, unsigned int data){
    _set[set]._line[line]._cacheInfo._dirty = true;
    _set[set]._line[line]._cacheData[offset] = data;
}

bool Cache::HitMissCheck(unsigned int set, unsigned int tag, unsigned int line){
    //cacheInfo의 라인&태그 와 현재 pc의 라인&태그가 같다면 true <-Hit
    //아니면 false <- Miss
    //Instructor에서는 모든 Cache Set을 체크하여
    //모두 false라면 Miss 하나라도 true라면 Hit로 본다
    if(_set[set]._line[line]._cacheInfo._tag == tag){
        return true;
    }
    
    return false;
}

unsigned int Cache::LRU(unsigned int line){
    int set;
    while (1) {
        if(_set[_LRUCounter[line]]._line[line]._cacheInfo._SCA == 0){
            set =_LRUCounter[line]++;
            if(_LRUCounter[line] == Sets)
                _LRUCounter[line] = 0;
            return set;
        }
        else{
            _set[_LRUCounter[line]]._line[line]._cacheInfo._SCA = 0;
            _LRUCounter[line]++;
            if(_LRUCounter[line] == Sets)
                _LRUCounter[line] = 0;
        }
    }
}

