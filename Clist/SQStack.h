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

SQstack *sq_initStack();

void sq_push(SQstack *stack, DATA data);
void sq_pop(SQstack *stack, DATA data);

void sq_isEmpty(SQstack *stack);
void sq_lengthOfStack(SQstack *stack);

#endif /* SQStack_h */
