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
    return node;
}

void dl_insertNode(Data data, int index, DoubleList *L){
    if (index > L->len || index < 0) {
        printf("check index!\n");
        exit(0);
    }
    
    DuNode *node = dl_createNode(data);
    if (index == 0) {
        node->next = L->head;
        L->head = node;
        L->len += 1;
        return;
    }else if(index == L->len){
        // 在队尾插入
        L->tail = node; // 修改尾指针
    }
    DuNode *element = dl_getElement(index-1, L);
    
    node->next = element->next;
    element->next = node;
    node->former = element;
    L->len += 1;
}

void dl_deleteNode(int index, DoubleList *L){
    if(index < 0 || index >= L->len){
        printf("check index!\n");
        exit(0);
    }
    
    DuNode *element = dl_getElement(index, L);
    if (index == 0) {
       // 删除头结点
        L->head = element->next;
        element->former = element->next = NULL;
        dl_freeNode(element);
        return;
    }else if(index == L->len-1){
        // 在队尾删除
        L->tail = element->former;
        element->former = element->next = NULL;
        dl_freeNode(element);
        return;
    }

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
        element = element->next;
        i ++;
    }
}

void dl_updateHeader(DoubleList *L){
    
}
