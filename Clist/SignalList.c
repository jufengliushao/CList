//
//  SignalList.c
//  Clist
//
//  Created by cnlive-lsf on 2017/5/18.
//  Copyright © 2017年 lsf. All rights reserved.
//

#include "SignalList.h"

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
    if (formerNode) {
       formerNode->next = node;
    }
    return node;
}

void initSignalList(int length){
    if (!length || length > MAX_VALUE) {
        printf("init fail! check lenght");
        exit(1);
    }
    
    currentNum = length; // 存储现有的长度
    returnHeaderNode(); // 初始化头结点
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

Node *returnIndexNode(int index){
    if(index<0 || index>=currentNum-1){
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

void insertNode(int index, DATA data){
    if (index < 1 || index > currentNum + 1) {
        printf("insert fail! check index");
        exit(0);
    }
    
    int crIn = index -1;
    Node *element = createNode(data, NULL);
    if(!crIn){
        // 第一个节点
        element->next = header->next;
        header->next = element;
    }else{
        // 其余节点
        Node *former = returnIndexNode(index);
        element->next = former->next;
        former->next = element;
    }
    currentNum ++;
}

void deleteNode(int index){
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
