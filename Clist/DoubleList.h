//
//  DoubleList.h
//  Clist
//
//  Created by cnlive-lsf on 2017/5/23.
//  Copyright © 2017年 lsf. All rights reserved.
//

#ifndef DoubleList_h
#define DoubleList_h

#include <stdio.h>
#include <malloc/malloc.h>
#include <stdlib.h>


typedef int Data;

typedef struct DuList{
    Data data;
    struct DuList *former;
    struct DuList *next;
}DuNode, *duNode;

/**
 返回头结点 双向链表

 @return DuNode
 */
DuNode* dl_returnHeaderNode();

#endif /* DoubleList_h */
