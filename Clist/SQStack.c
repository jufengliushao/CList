//
//  SQStack.c
//  Clist
//
//  Created by cnlive-lsf on 2017/5/27.
//  Copyright © 2017年 lsf. All rights reserved.
//

#include "SQStack.h"

/**
 私有--打印

 @param data 打印数据
 */
void sq_private_printTheData(DATA data);

SQstack *sq_initStack(){
    SQstack *stack = (sqStack)malloc(sizeof(SQstack));
    stack->top = 0;
    return stack;
}

void sq_push(SQstack *stack, DATA data){
    if (stack->top > MAX_LENGTH) {
        printf("the stack is full!");
        exit(0);
    }
    
    stack->data[stack->top] = data;
    stack->top ++;
}

void sq_pop(SQstack *stack){
    if(!stack->top){
        printf("the stack is empty!");
        exit(0);
    }
    sq_private_printTheData(stack->data[stack->top]);
    stack->top --;
}

void sq_isEmpty(SQstack *stack){
    if (!stack->top) {
        printf("The stack is empty");
    }
}

void sq_lengthOfStack(SQstack *stack){
    printf("the stack length is:%d", stack->top);
}

void sq_private_printTheData(DATA data){
    printf("pop the data:%d\n", data);
}
