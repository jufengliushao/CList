//
//  SQBiTree.c
//  Clist
//
//  Created by cnlive-lsf on 2017/6/6.
//  Copyright © 2017年 lsf. All rights reserved.
//

#include "SQBiTree.h"
#define FALSE 0
#define TRUE 1

SQBiTree element[MAX_BiTree_LENGTH];

/**
 检查index是否越界

 @param index int
 */
void sq_bitree_private_indexLegal(int index);

/**
 检查左子树是否越界

 @param index int
 @return FALSE-0 TRUE-1
 */
int sq_bitree_private_indexLeftLegal(int index);

/**
 检查右子树是否越界
 
 @param index int
 @return FALSE-0 TRUE-1
 */
int sq_bitree_private_indexRightLegal(int index);

void sq_bitree_init(){
    int index = 1;
    for (int i = 0; i < 11; i++) {
        if (i == 5 || i == 6 || i == 7 || i == 8) {
            element[i] = 0;
        }else{
            element[i] = index ++;
        }
    }
}

int sq_bitree_returnLeftChild(int index){
    index = element[index];
    sq_bitree_private_indexLegal(index);
    if(sq_bitree_private_indexLeftLegal(index)){
        return element[index * 2 - 1];
    }
    printf("the index don't has left-child!\n");
    return -1;
}

int sq_bitree_returnRightChild(int index){
    index = element[index];
    sq_bitree_private_indexLegal(index);
    if (sq_bitree_private_indexRightLegal(index)) {
        return element[index * 2];
    }
    printf("the index don't has right-child!\n");
    return -1;
}

void sq_bitree_private_indexLegal(int index){
    if (index > MAX_BiTree_LENGTH) {
        printf("check your indx!\n");
        exit(0);
    }
}

int sq_bitree_private_indexLeftLegal(int index){
    if (index * 2 > MAX_BiTree_LENGTH) {
        return FALSE;
    }
    return TRUE;
}

int sq_bitree_private_indexRightLegal(int index){
    if (index * 2 + 1 > MAX_BiTree_LENGTH) {
        return FALSE;
    }
    return TRUE;
}
