//
//  SignalList.h
//  Clist
//
//  Created by cnlive-lsf on 2017/5/18.
//  Copyright © 2017年 lsf. All rights reserved.
//

#ifndef SignalList_h
#define SignalList_h

#include <stdio.h>
#include <malloc/malloc.h>
#include <stdlib.h>

#define MAX_VALUE 100 // 最大值

typedef int DATA;

typedef struct SignalNode{
    DATA data;
    struct SignalNode *next;
}Node, *ListNode;

static int currentNum = 0;

Node* sl_returnHeaderNode(); // 获取头结点
Node* sl_createNode(DATA data, Node *formerNode); // 创建节点 data 数据域
Node *sl_returnIndexNode(int index, Node *header); // 返回指定链表中的节点 从0开始计数
void sl_initSignalList(int length, Node *header); // 初始化一个固定长度的带有头结点的单链表

void sl_insertNode(int index, DATA data, Node *header);  // 插入节点 从0开始计数
void sl_deleteNode(int index, Node *header); // 删除指定节点 从0开始计数

void sl_setCycleSignalList(Node *header); // 设置成单链表的循环链表

void sl_bubbleSortList(Node *header); // 冒泡排序
void sl_selectSort(Node *header); // 选择排序

void sl_printNode(Node *header);// 打印函数


#endif /* SignalList_h */
