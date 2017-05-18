//
//  main.c
//  Clist
//
//  Created by cnlive-lsf on 2017/5/18.
//  Copyright © 2017年 lsf. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>

#define MAX_VALUE 100

typedef double dataType;

typedef struct node{
    dataType key;
    struct node *next;
} linkList, *Node;

static int currentNum = 0;

linkList listArr[MAX_VALUE];
linkList *header;

void initForList(int totalNum);
void printListArr();
linkList* initForHeaderNode();
//linkList* createNode(Node former);
void insertNode(double key, int index);
linkList *createNode(double key);

void test();


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    test();
    listArr[0] = *initForHeaderNode();
    initForList(5);
    printListArr();
    
    int a =0;
    scanf("%d", &a);
    if (a) {
        insertNode(17, currentNum);
    }
    printListArr();
    return 0;
}

void initForList(int totalNum){
    // 非空判断
    if(totalNum < 1 || totalNum > MAX_VALUE) return;
    
    currentNum = totalNum + 1;
    for (int i = 1; i < totalNum + 1; i ++) {
        listArr[i] = *createNode(0);
    }
}

linkList* initForHeaderNode(){
    linkList *head = (Node)malloc(sizeof(linkList));
    head->key = 0;
    head->next = NULL;
    return head;
}

void insertNode(double key, int index){
    if (index < 0 || index > currentNum){
        printf("insert fail! check index");
        exit(0);
    }
    
    if(index == currentNum){
        // 在最后插入数据
        linkList former = listArr[currentNum - 1];
        linkList *node = createNode(0);
        listArr[currentNum - 1] = former;
        node->key = key;
        listArr[currentNum] = *node;
        currentNum += 1;
    }else if (index == 0){
        linkList *node = (Node)malloc(sizeof(linkList));
    }
}

linkList *createNode(double key){
    linkList *node;;
    if (!(node = (Node)malloc(sizeof(linkList)))) {
        // 分配内存失败
        exit(0); // 退出程序
    }
    
    node->key = rand() % 100;
    node->next = NULL;
    
    return node;
}

void deleteNode(int index){
    if (index < 0 || index > currentNum) {
        printf("delete fail! chech index");
        exit(0);
    }
    
    
    
}

void printListArr(){
    for (int i = 0; i < currentNum; i ++) {
        printf("key:%.2f-----next:%p\n", listArr[i].key, listArr[i].next);
    }
}
