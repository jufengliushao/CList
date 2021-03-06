//
//  SignalList.c
//  Clist
//
//  Created by cnlive-lsf on 2017/5/18.
//  Copyright © 2017年 lsf. All rights reserved.
//

#include "SignalList.h"

Node* sl_returnHeaderNode(){
    Node *header = (ListNode)malloc(sizeof(Node));
    if (!header) {
        printf("Create header-node fail! (in SignalList)");
    }
    header->data = 0;
    header->next = NULL;
    return header;
}

Node* sl_createNode(DATA data, Node *formerNode){
    Node *node = (ListNode)malloc(sizeof(Node));
    if (!node) {
        printf("Create node-node fail! (in SignalList)");
        exit(0);
    }
    
    node->data = data;
    node->next = NULL;
    if (formerNode) {
       formerNode->next = node;
    }
    return node;
}

void sl_initSignalList(int length, Node *header){
    if (!length || length > MAX_VALUE) {
        printf("init fail! check lenght");
        exit(1);
    }
    
    currentNum = length; // 存储现有的长度
    sl_returnHeaderNode(); // 初始化头结点
    
}

Node *sl_returnIndexNode(int index, Node *header){
    // 从0开始
    if(index>=currentNum){
        printf("get fail! check index");
        exit(0);
    }
    
    int i = 0;
    Node *node = header;
    // 索引查询
    while (i <= index) {
        node = node->next;
        i ++;
    }
    return node;
}

void sl_insertNode(int index, DATA data, Node *header){
    if (index < 0 || index > currentNum + 1) {
        printf("insert fail! check index");
        exit(0);
    }
    
    Node *element = sl_createNode(data, NULL);
    Node *former = sl_returnIndexNode(index - 1, header);
    element->next = former->next;
    former->next = element;
    currentNum ++;
}

void sl_deleteNode(int index, Node *header){
    if(index < 0 || index > currentNum){
        printf("delete fail! check index");
        exit(0);
    }
    
    Node *former = sl_returnIndexNode(index-1, header);
    Node *element = former->next;
    former->next = element->next;
    element->next = NULL;
    element->data = 0;
    free(element); // 释放内存
}

void sl_bubbleSortList(Node *header){
    Node *m = header;
    Node *p = m->next;
    Node *q = p->next;
    int exchange = 1;
    while (m&&exchange) {
        exchange = 0;
        while (q) {
            if (p->data > q->data) {
                // 交换
                exchange = 1;
                p->next = q->next;
                m->next = q;
                q->next = p;
                m = q;
                q = p->next;
            }else{
                m = p;
                p = q;
                q = q->next;
            }
        }
        m = header;
        p = m->next;
        q = p->next;
    }
}

void sl_selectSort(Node *header){
    Node *min = header->next;
    Node *element = min;
    Node *temp;
    while (min->next) {
        while (element) {
            if (min->data > element->data) {
                min = element;
                temp = element;
            }
            element = element->next;
        }
        
    }
}

void sl_setCycleSignalList(Node *header){
    Node *node = header;
    if (node->next) {
        node = node->next;
    }
    node->next = header;
}

void sl_printNode(Node *header){
    Node *node = header;
    while (node->next) {
        node = node->next;
        printf("###data:%d----self:%p---next:%p\n", node->data, node, node->next);
    }
}
