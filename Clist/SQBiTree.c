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

void sq_bitree_init(){
    for (int i = 0; i < 11; i++) {
        element[i] = i+1;
    }
    element[5] = 0;
    element[6] = 0;
    element[7] = 0;
    element[8] = 0;
}

int sq_bitree_returnLeftChild(int index){
    sq_bitree_private_indexLegal(index);
    
    return 0;
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
    return 0;
}
