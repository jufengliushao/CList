//
//  SQStackFunction.c
//  Clist
//
//  Created by cnlive-lsf on 2017/5/27.
//  Copyright © 2017年 lsf. All rights reserved.
//

#include "SQStackFunction.h"
#include "SQStack.h"

/**
 input message
 */
void stack_private_remindMessage();
void stack_private_getChar(SQstack *stack);
void stack_private_judegemntChar(char ch, SQstack *stack);

void stack_inputFunction(){
    SQstack *stack = sq_initStack();
    stack_private_remindMessage();
    stack_private_getChar(stack);
}

void stack_private_remindMessage(){
    printf("----------------------------------------\n");
    printf("------you can input any words-----------\n");
    printf("---@ clear all your input befroe\n");
    printf("---# clean the last character you input\n");
    printf("----------------------------------------\n");
    printf("you can input now:\n");
}

void stack_private_getChar(SQstack *stack){
    char ch = '\0';
    while (ch != '\n') {
        ch = getchar();
        stack_private_judegemntChar(ch, stack);
    }
}

void stack_private_judegemntChar(char ch, SQstack *stack){
    switch (ch) {
        case '@':{
            sq_emptyStack(stack);
        }
            break;
            
        case '#':{
            sq_clearTopElement(stack);
        }
            break;
            
        case '\n':{
            sq_popAllElement(stack);
        }
            break;
            
        default:{
            sq_push(stack, ch);
        }
            break;
    }
}
