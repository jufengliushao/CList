//
//  DoubleList.c
//  Clist
//
//  Created by cnlive-lsf on 2017/5/23.
//  Copyright © 2017年 lsf. All rights reserved.
//

#include "DoubleList.h"
#include <string.h>

/**
 返回对应的节点
 
 @param index 结点 从0开始
 @param L 头结点
 @return DuNode
 */
DuNode *dl_prative_getElement(int index, DoubleList *L);

DuNode* dl_private_returnIndex(int index, DoubleList *L); // 私有获取指定下标的结点
void dl_private_deepCopy(DuNode *dest, DuNode *source); // 深拷贝

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

DuNode *dl_prative_getElement(int index, DoubleList *L){
    if (index > L->len || index < 0) {
        printf("check index!\n");
        exit(0);
    }
    
    return dl_private_returnIndex(index, L);
}

DuNode* dl_public_getElement(int index, DoubleList *L){
    if (index >= L->len || index < 0) {
        printf("check index!\n");
        exit(0);
    }
    
    return dl_private_returnIndex(index, L);
}

DuNode* dl_private_returnIndex(int index, DoubleList *L){
    DuNode *node = L->head;
    int i = 0;
    if(L->len / 2 > index){
        // 从前往后搜索
        while (node && i <= index) {
            if (i == 0) {
                ++i;
                continue;
            }
            node = node->next;
            ++i;
        }
    }else{
        i = L->len;
        node = L->tail;
        while (node && index < i) {
            if (i == L->len) {
                --i;
                continue;
            }
            node = node->former;
            --i;
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
        if (L->head) {
            L->head->former = node; // 若不为空表
        }
        L->head = node;
        L->len += 1;
        if (L->len == 1) {
            L->tail = node; // 链表中只有一个元素，使尾指针指向元素
        }
        return;
    }else if(index == L->len){
        // 在队尾插入
        node->former = L->tail;
        L->tail = node;
        node->former->next = node;
        L->len += 1;
        return;
    }
    DuNode *element = dl_prative_getElement(index, L);
    
    node->next = element->next;
    node->next->former = element;
    element->next = node;
    node->former = element;
    L->len += 1;
}

void dl_deleteNode(int index, DoubleList *L){
    if(index < 0 || index >= L->len){
        printf("check index!\n");
        exit(0);
    }
    
    DuNode *element = dl_public_getElement(index, L);
    if (index == 0) {
       // 删除头结点
        L->head = element->next;
        if (L->len == 1) {
            L->tail = L->head = NULL;
        }else{
            element->next->former = NULL;
        }
        L->len -= 1;
        dl_freeNode(element);
        return;
    }else if(index == L->len-1){
        // 在队尾删除
        L->tail = element->former;
        element->former->next = NULL;
        L->len -= 1;
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
        printf("i:%d---", i);
        if(i){
          element = element->next;
        }
        dl_printNode(element);
        i ++;
    }
}

void dl_printNode(DuNode *element){
    printf("currentP:%p-------formerP:%p------data:%d-------next:%p\n", element, element->former, element->data, element->next);
}

DoubleList * dl_departmentDoubleListOdd(DoubleList *L){
    DoubleList *L1 = (doubleList)malloc(sizeof(DoubleList));
    if (!L1) {
        printf("malloc fail!");
        exit(0);
    }
    L1->len = 0;
    if (!L->len) {
        printf("List is empty!");
        exit(0);
    }
    
    int i = 0, total = L->len - 1;
    DuNode *node = L->head;
    DuNode *tailL1 = NULL;
    while (i < total+1) {
        if (i) {
            node = node->next;
        }
        if (i%2==0) {
            L1->len ++;
            L->len --;
            // 奇数
            if (!i) {
                // 第一个结点
                L1->tail = L1->head = node;
                L->head = node->next;
                tailL1 = node;
                ++i;
                continue;
            }
            if (i == total) {
                // 最后一个
                L->tail = node->former;
                node->former->next = NULL;
                node->next = NULL;
            }else{
                // 正常添加
                node->former->next = node->next;
                node->next->former = node->former;
            }
            tailL1->next = node;
            node->former = tailL1;
            L1->tail = node;
            tailL1 = node;
        }
        ++i;
    }
    return L1;
}

void dl_bublleSort(DoubleList *L){
    if (L->len) {
        printf("The double-list is empty!");
        exit(0);
    }
    
    DuNode *node = L->head;
    int exchange = 1;
    int i = 0;
    if(L->len == 1) return; // 只有一个结点不需要排序
    while (exchange && node) {
        exchange = 0;
        i = 0;
        while (node->next) {
            if (node->data > node->next->data) {
                // 交换
                if (!i) {
                    //为第一个结点 a->data > b->data b->next = c
                    L->head = node->next; // L->head = b
                }else{
                    node->former->next = node->next;
                }
                if (i == L->len - 2) {
                    // 最后倒数第二个
                    L->tail = node;
                }
                
                // 通用交换
                node->former->next = node->next;
                node->next->former = node->former;
                node->former = node->next;
                node->next = node->former->next;
            }
        }
    }
}

void dl_mergeDoubleList_ASC(DoubleList *L1, DoubleList *L2){
    if (L1->len < 1 && L2->len < 1) {
        printf("The list is empty!");
        exit(0);
    }
    
    DuNode *element_L1 = L1->head;
    DuNode *element_L2 = L2->head;
    DuNode *tmp1 = dl_createNode(0);
    dl_private_deepCopy(tmp1, element_L1);
    DuNode *tmp2 = dl_createNode(0);
    dl_private_deepCopy(tmp2, element_L2);
    while (element_L1 && element_L2) {
        if(element_L1->data > element_L2->data){
            if(!element_L1->former){
                // 在L1的头插入
                L1->head = element_L2;
            }else{
                element_L1->former->next = element_L2;
            }
            element_L2->former = element_L1->former;
            element_L2->next = element_L1;
            element_L1->former = element_L2;
            element_L2 = tmp2->next;
            dl_private_deepCopy(tmp2, element_L2);
            L1->len ++;
        }else{
            if (element_L1->next == NULL) {
                // 在L1的尾结点插入
                L1->tail = element_L2;
                element_L2->next = NULL;
                element_L2->former = element_L1;
                element_L1->next = element_L2;
                element_L1 = element_L1->next;
                dl_private_deepCopy(tmp1, element_L1);
                element_L2 = tmp2->next;
                dl_private_deepCopy(tmp2, element_L2);
                L1->len ++;
            }else{
                element_L1 = tmp1->next;
                dl_private_deepCopy(tmp1, element_L1);
            }
        }
    }
}

void dl_private_deepCopy(DuNode *dest, DuNode *source){
    if (!source) {
        return;
    }
    dest->data = source->data;
    dest->former = source->former;
    dest->next = source->next;
}
