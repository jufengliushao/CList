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
    p->former = p->next = NULL;
    p->data = 0;
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
    if((L->len-1) / 2 > index){
        // 从前往后搜索
        while (node && i < index) {
            node = node->next;
            ++i;
        }
    }else{
        i = L->len - 1;
        while (node && index < i) {
            node = node->former;
        }
    }
    
    if (index == L->len-1) {
        // 查找最后一个
        return L->tail;
    }
    
    
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
    if(index < 0 || index > L->len){
        printf("check index!\n");
        exit(0);
    }
    
    DuNode *element = dl_getElement(index, L);
    element->former->next = element->next;
    element->next->former = element->former;
    -- L->len;
    dl_freeNode(element);
}

void dl_printfDoubleList(DoubleList *L){
    DuNode *element = L->head;
    int i = 0;
    while (i < L->len) {
        printf("i:%d----currentP:%p-------formerP:%p------data:%d-------next:%p\n", i, element, element->former, element->data, element->next);
        i ++;
    }
}
