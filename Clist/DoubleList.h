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
    Data data; // 数据域
    struct DuList *former; // 前指针
    struct DuList *next; // 后指针
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
 public 获取指定顺序的结点

 @param index index 从0开始
 @param L DoubleList
 @return DuNode
 */
DuNode* dl_public_getElement(int index, DoubleList *L);

/**
 创建结点

 @param data 数据域数值
 @return DuNode
 */
DuNode *dl_createNode(Data data);

/**
 插入结点

 @param data 数据域数值
 @param index 在第index结点之前插入
 @param L 头指针
 */
void dl_insertNode(Data data, int index, DoubleList *L);

/**
 删除结点

 @param index 删除index结点
 @param L 头指针
 */
void dl_deleteNode(int index, DoubleList *L);

/**
 打印L的双向链表

 @param L 头指针
 */
void dl_printfDoubleList(DoubleList *L);

void dl_printNode(DuNode *element);
#endif /* DoubleList_h */
