//
//  SQBiTree.h
//  Clist
//
//  Created by cnlive-lsf on 2017/6/6.
//  Copyright © 2017年 lsf. All rights reserved.
//

#ifndef SQBiTree_h
#define SQBiTree_h

#include <stdio.h>
#include <malloc/malloc.h>
#include <stdlib.h>

#define MAX_BiTree_LENGTH 100

typedef int SQBiTree;


/**
 初始化
 */
void sq_bitree_init();

/**
 返回左孩子

 @param index int 从0开始
 @return int
 */
int sq_bitree_returnLeftChild(int index);

/**
 返回右孩子
 
 @param index int 从0开始
 @return int
 */
int sq_bitree_returnRightChild(int index);




#endif /* SQBiTree_h */
