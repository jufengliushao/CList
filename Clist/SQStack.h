//
//  SQStack.h
//  Clist
//
//  Created by cnlive-lsf on 2017/5/27.
//  Copyright © 2017年 lsf. All rights reserved.
//

#ifndef SQStack_h
#define SQStack_h

#include <stdio.h>
#include <malloc/malloc.h>
#include <stdlib.h>

#define MAX_LENGTH 100

typedef int DATA;

typedef struct {
    DATA data[MAX_LENGTH];
    int top;
}SQstack, *sqStack;

/**
 初始化

 @return SQstack
 */
SQstack *sq_initStack();

/**
 添加元素

 @param stack 栈
 @param data 数据
 */
void sq_push(SQstack *stack, DATA data);

/**
 栈顶元素出栈

 @param stack 栈
 */
void sq_pop(SQstack *stack);

/**
 判断是否为空

 @param stack 栈
 */
void sq_isEmpty(SQstack *stack);

/**
 返回栈的长度

 @param stack 栈
 */
void sq_lengthOfStack(SQstack *stack);

/**
 打印所有数据

 @param stack SQstack
 */
void sq_popAllElement(SQstack *stack);

/**
 清空栈

 @param stack SQstack
 */
void sq_emptyStack(SQstack *stack);

/**
 回退栈顶元素，不打印

 @param stack SQstack
 */
void sq_clearTopElement(SQstack *stack);

/**
 从栈底开始输出元素

 @param stack SQstack
 */
void sq_popElementFromBottom(SQstack *stack);

#endif /* SQStack_h */
