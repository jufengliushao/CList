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
Node *createNode(DATA data); // 创建节点 data 数据域

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

Node *createNode(DATA data){
    Node *node = (ListNode)malloc(sizeof(Node));
    if (!node) {
        printf("Create node-node fail! (in SignalList)");
        exit(0);
    }
    
    node->data = data;
    node->next = NULL;
    return node;
}

