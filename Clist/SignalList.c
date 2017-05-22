//
//  SignalList.c
//  Clist
//
//  Created by cnlive-lsf on 2017/5/18.
//  Copyright © 2017年 lsf. All rights reserved.
//

#include "SignalList.h"

Node* returnHeaderNode(){
    Node *header = (ListNode)malloc(sizeof(Node));
    if (!header) {
        printf("Create header-node fail! (in SignalList)");
    }
    header->data = 0;
    header->next = NULL;
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
    if (formerNode) {
       formerNode->next = node;
    }
    return node;
}

void initSignalList(int length, Node *header){
    if (!length || length > MAX_VALUE) {
        printf("init fail! check lenght");
        exit(1);
    }
    
    currentNum = length; // 存储现有的长度
    returnHeaderNode(); // 初始化头结点
    
}

Node *returnIndexNode(int index, Node *header){
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

void insertNode(int index, DATA data, Node *header){
    if (index < 1 || index > currentNum + 1) {
        printf("insert fail! check index");
        exit(0);
    }
    
    Node *element = createNode(data, NULL);
    Node *former = returnIndexNode(index - 1, header);
    element->next = former->next;
    former->next = element;
}

void deleteNode(int index, Node *header){
    if(index < 1 || index > currentNum){
        printf("delete fail! check index");
        exit(0);
    }
    
    Node *node = returnIndexNode(index - 1);
    if (index == 1) {
        // 删除头结点
        header->next = node->next;
    }else{
        Node *former = returnIndexNode(index - 2);
        former->next = node->next;
    }
    node->next = NULL;
    node->data = 0;
    currentNum --;
}

void bubbleSortList(){
    
}

void printNode(){
    Node *node = header;
    while (!node->next) {
        node = node->next;
        printf("###data:%d-------next:%p\n", node->data, node->next);
    }
}
