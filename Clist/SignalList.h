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

Node *header; // 头结点
Node nodesArr[100]; // 存储节点的数组
Node* returnHeaderNode(); // 获取头结点
Node* createNode(DATA data, Node *formerNode); // 创建节点 data 数据域
Node *returnIndexNode(int index); // 返回指定链表中的节点 从1开始计数
void initSignalList(int length); // 初始化一个固定长度的带有头结点的单链表

void insertNode(int index, DATA data);  // 插入节点 从1开始计数
void deleteNode(int index); // 删除指定节点 从1开始计数

void bubbleSortList(); // 冒泡排序

void printNode();// 打印函数


#endif /* SignalList_h */
