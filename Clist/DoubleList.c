//
//  DoubleList.c
//  Clist
//
//  Created by cnlive-lsf on 2017/5/23.
//  Copyright © 2017年 lsf. All rights reserved.
//

#include "DoubleList.h"

DoubleList* dl_returnHeaderNode(){
    DoubleList *b = (doubleList)malloc(sizeof(DoubleList));
    if (!b) {
        printf("create header fail!");
        exit(0);
    }
    b->len = 0;
    b->head = NULL;
    b->tail = NULL;
    return b;
}

void dl_freeNode(DuNode *p){
    free(p);
}

DuNode *dl_createNode(Data data){
    DuNode *node = (duNode)malloc(sizeof(DuNode));
    if (!node) {
        printf("double-list node create fail!\n");
        exit(0);
    }
    node->data = data;
    node->former = NULL;
    node->next = NULL;
    return node;
}

DuNode *dl_getElement(int index, DoubleList *L){
    if (index >= L->len || index < 0) {
        printf("check index!\n");
        exit(0);
    }
    
    DuNode *node = L->head;
    int i = 0;
    while (node && i < index) {
        node = node->next;
        ++i;
    }
    return node;
}

void dl_insertNode(Data data, int index, DoubleList *L){
    if (index > L->len || index < 0) {
        printf("check index!\n");
        exit(0);
    }
    
    DuNode *node = dl_createNode(data);
    DuNode *element = dl_getElement(index, L);
    
    element->former->next = node;
    node->former = element->former;
    node->next = element;
    element->former = node;
    L->len += 1;
}

void dl_deleteNode(int index, DoubleList *L){
    
}
