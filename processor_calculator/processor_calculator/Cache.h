//
//  Cache.h
//  processor_calculator
//
//  Created by LeeChungHee on 2015. 6. 4..
//  Copyright (c) 2015년 CH. All rights reserved.
//
#pragma once
#define CacheLine   64
#define Lines        4
#define Sets         4
#define CacheSize CacheLine * Lines

#define lineMask_64     0x00000000
#define lineMask_128    0x00000040
#define lineMask_256    0x000000c0

#define offsetMask      0x0000003f


class CacheInfo{
public:
    CacheInfo();
public:
    unsigned int    _tag;
    bool            _dirty;
    bool            _SCA;
};

class Line{
public:
    Line();
    unsigned int _cacheData[CacheLine/4];
    CacheInfo    _cacheInfo;
};

class Set{
public:
    Line            _line[Lines];
    
public:
    Set();
};

class Cache{
public:
    Set             _set[Sets];
    int             _LRUCounter[Lines];
    
public:
    unsigned int _lineMask;
    unsigned int _tagMask;
    
public:
    Cache();
    
public:
    void SetMasking();
    
    void InsertData(unsigned int set, unsigned int line, unsigned int offset, unsigned int inst);
    //InsertData 에서 해당 라인, 옵셋에 데이터 입력
    void InsertTag(unsigned int set, unsigned int tag, unsigned int line);
    //라인의 Tag입력
    unsigned int GetData(unsigned int set, unsigned int line, unsigned int offset);
    //Cache에서 데이터를 가지고 온다
    void WriteData(unsigned int set, unsigned int line, unsigned int offset, unsigned int data);
    //Write 명령의 경우, Cache에 데이터를 쓰고 dirty bit 체크
    bool HitMissCheck(unsigned int set, unsigned int tag, unsigned int line);
    //cacheInfo의 tag와 pc의 tag를 비교
    unsigned int LRU(unsigned int line);
    //Second-Chanch Algo. 교체될 Set의 index를 돌려준다
    
};









