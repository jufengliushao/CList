//
//  SQStackFunction.c
//  Clist
//
//  Created by cnlive-lsf on 2017/5/27.
//  Copyright © 2017年 lsf. All rights reserved.
//

#include "SQStackFunction.h"
#include "SQStack.h"
/**********************************************************************/
/**
 input message
 */
void stack_private_remindMessage();
void stack_private_getChar(SQstack *stack);
void stack_private_judegemntChar(char ch, SQstack *stack);
/**********************************************************************/

/**********************************************************************/

/* -------------------------------------------------------------- */
/* ---------------------- input function ------------------------ */
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
            sq_popElementFromBottom(stack);
        }
            break;
            
        default:{
            sq_push(stack, ch);
        }
            break;
    }
}
/* ---------------------- input function end -------------------- */
/* -------------------------------------------------------------- */

/* -------------------------------------------------------------- */
/* ------------------------ data transform ---------------------- */

void stack_private_transformMessage(int source, int aim);
void stack_private_transformDataJudgemnt(int data);
void stack_private_transformLenght(int length, int data);
void stack_private_transformPrintResult(int data, int length, SQstack *stack);
void stack_private_computer(int data, int length, SQstack *stack);
void stack_private_transform_sixteen_result(SQstack *stack);
char stack_private_transform_sixteen_replace(int source);

void stack_transform(){
    int source = 0, aim = 0;
    stack_private_transformMessage(source, aim);
    
    SQstack *stack = sq_initStack();
    stack_private_computer(source, aim, stack);
}

void stack_private_transformMessage(int source, int aim){
    printf("------------------------------\n");
    printf("----------- 进制转化 ----------\n");
    printf("------------------------------\n");
    printf("please input data(10): ");
    int data = 0;
    scanf("%d", &data);
    stack_private_transformDataJudgemnt(data);
    source = data;
    printf("please input the termail: 2-二进制, 8-八进制, 10-十进制, 16-十六进制\n");
    int length = 0;
    scanf("%d", &length);
    stack_private_transformLenght(length, data);
    aim = length;
}

void stack_private_transformDataJudgemnt(int data){
    if (data <= 0) {
        printf("please check your input!\n");
        exit(0);
    }
}

void stack_private_transformLenght(int length, int data){
    switch (length) {
        case 2:{
            
        }
            break;
        
        case 8:{
            
        }
            break;
            
        case 10:{
            
        }
            break;
            
        case 16:{
            
        }
            break;
            
        default:{
            printf("please check your input!\n");
            exit(0);
        }
            break;
    }
}

void stack_private_computer(int data, int length, SQstack *stack){
    int source = data;
    while (source) {
        sq_push(stack, source % length);
        source /= length;
    }
    stack_private_transformPrintResult(data, length, stack);
}

void stack_private_transformPrintResult(int data, int length, SQstack *stack){
    printf("the data %d - %d is:", data, length);
    if (length == 10) {
        printf("%d\n", data);
    }else if (length == 16){
        
    }else{
        sq_popAllElement(stack);
        printf("\n");
    }
    
    exit(0);
}

void stack_private_transform_sixteen_result(SQstack *stack){
    while (stack->top) {
        int a = sq_returnTopElementWithoutPrint(stack);
        if (a > 9) {
            printf("%d", a);
        }else{
            printf("%c", stack_private_transform_sixteen_replace(a));
        }
    }
}

char stack_private_transform_sixteen_replace(int source){
    char ch = '\0';
    switch (source) {
        case 10:{
            ch = 'A';
        }
            break;
        
        case 11:{
            ch = 'B';
        }
            break;
            
        case 12:{
            ch = 'C';
        }
            break;
            
        case 13:{
            ch = 'D';
        }
            break;
            
        case 14:{
            ch = 'E';
        }
            break;
            
        case 15:{
            ch = 'F';
        }
            break;
        default:{
            
        }
            break;
    }
    return ch;
}
