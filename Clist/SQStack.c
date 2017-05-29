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
void sq_private_isEmpty(SQstack *stack);

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
    sq_private_isEmpty(stack);
    sq_private_printTheData(stack->data[stack->top-1]);
    stack->top --;
}

void sq_popAllElement(SQstack *stack){
    sq_private_isEmpty(stack);
    while (stack->top) {
        printf("%c", stack->data[stack->top-1]);
        stack->data[stack->top-1] = 0;
        stack->top --;
    }
}

void sq_isEmpty(SQstack *stack){
    if (!stack->top) {
        printf("The stack is empty");
    }
}

void sq_emptyStack(SQstack *stack){
    while (stack->top) {
        stack->data[stack->top-1] = 0;
        stack->top --;
    }
}

void sq_clearTopElement(SQstack *stack){
    sq_private_isEmpty(stack);
    stack->data[stack->top-1] = 0;
    stack->top --;
}

void sq_private_isEmpty(SQstack *stack){
    if(!stack->top){
        printf("the stack is empty!");
        exit(0);
    }
}

void sq_lengthOfStack(SQstack *stack){
    printf("the stack length is:%d", stack->top);
}

void sq_private_printTheData(DATA data){
    printf("pop the data:%c\n", data);
}

void sq_popElementFromBottom(SQstack *stack){
    sq_isEmpty(stack);
    
    char string[MAX_LENGTH];
    int i = 0;
    while (stack->top) {
        string[i] = stack->data[stack->top-1];
        stack->top --;
        i ++;
    }
    
    while (i >= 0) {
        printf("%c", string[i--]);
    }
    printf("\n");
}

int sq_returnTopElementWithoutPrint(SQstack *stack){
    return stack->data[stack->top - 1];
}
