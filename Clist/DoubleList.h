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

typedef struct {
    duNode head, tail; // head->头结点 tail->尾节点
    int len; // 个数
}DoubleList, *doubleList;

/**
 返回头结点 双向链表

 @return DoubleList
 */
DoubleList* dl_returnHeaderNode();

/**
 释放内存地址

 @param p 对应的结点
 */
void dl_freeNode(DuNode *p);

/**
 返回对应的节点

 @param index 结点 从0开始
 @param L 头结点
 @return DuNode
 */
DuNode *dl_getElement(int index, DoubleList *L);

/**
 创建结点

 @param data <#data description#>
 @return <#return value description#>
 */
DuNode *dl_createNode(Data data);

/**
 <#Description#>

 @param data <#data description#>
 @param index <#index description#>
 @param L <#L description#>
 */
void dl_insertNode(Data data, int index, DoubleList *L);

void dl_deleteNode(int index, DoubleList *L);
#endif /* DoubleList_h */
