//
//  NormalQueue.h
//  Clist
//
//  Created by cnlive-lsf on 2017/6/2.
//  Copyright © 2017年 lsf. All rights reserved.
//

#ifndef NormalQueue_h
#define NormalQueue_h

#include <stdio.h>

typedef int NQ_Data;

typedef struct NQUEUE{
    NQ_Data data;
    struct NQUEUE *next;
}NormalQueue, *normalQueue;

struct Node{
    normalQueue fornt;
    normalQueue rear;
};

#endif /* NormalQueue_h */
