//
//  SignalList.c
//  Clist
//
//  Created by cnlive-lsf on 2017/5/18.
//  Copyright © 2017年 lsf. All rights reserved.
//

#include "SignalList.h"
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
Node nodesArr[MAX_VALUE];

Node* returnHeaderNode(); // 获取头结点
Node* createNode(DATA data, Node *formerNode); // 创建节点 data 数据域

void initSignalList(int length); // 初始化一个固定长度的带有头结点的单链表

void printNode();// 打印函数

Node* returnHeaderNode(){
    if (!header) {
        header = (ListNode)malloc(sizeof(Node));
        if (!header) {
            printf("Create header-node fail! (in SignalList)");
        }
        header->data = 0;
        header->next = NULL;
    }
    return header;
}

Node* createNode(DATA data, Node *formerNode){
    Node *node = (ListNode)malloc(sizeof(Node));
    if (!node) {
        printf("Create node-node fail! (in SignalList)");
        exit(0);
    }
    
    node->data = data;
    node->next = NULL;
    formerNode->next = node;
    return node;
}

void initSignalList(int length){
    if (!length || length > MAX_VALUE) {
        printf("init fail! check lenght");
        exit(1);
    }
    
    returnHeaderNode();
    for (int i = 0; i < length; i ++) {
        if (!i) {
            // 第一个元素
            nodesArr[i] = *createNode(i + 10, header);
        }else{
            Node *former = &nodesArr[i-1];
            nodesArr[i] = *createNode(i + 10, former);
            nodesArr[i-1] = *former; // resave
        }
    }
}

void printNode(){
    for (int i = 0; i < currentNum - 1; i ++) {
        printf("###data:%d-------next:%p-------next-data:%d\n", nodesArr[i].data, nodesArr[i].next, (nodesArr[i].next)->data);
    }
    printf("###data:%d-------next:%p-------next-data:0\n", nodesArr[currentNum-1].data, nodesArr[currentNum-1].next);
}
