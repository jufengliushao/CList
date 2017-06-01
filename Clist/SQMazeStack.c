//
//  SQMazeStack.c
//  Clist
//
//  Created by cnlive-lsf on 2017/6/1.
//  Copyright © 2017年 lsf. All rights reserved.
//

#include "SQMazeStack.h"
SQMazeStack* sq_maze_initMaze(){
    SQMazeStack *stack = malloc(sizeof(sqMazeStack));
    if (!stack) {
        printf("create stack fail!\n");
        exit(0);
    }
    stack->top = 0;
    return stack;
}

void sq_maze_push(SQMazeStack *stack, Point *point){
    if (stack->top == MAX_LENGTH) {
        printf("stack is full!\n");
        exit(0);
    }
    stack->point[stack->top] = *point;
    stack->top ++;
}

void sq_maze_pop(SQMazeStack *stack){
    if(!stack->top){
        printf("stack is empty!\n");
        exit(0);
    }
    stack->top --;
}

void sq_maze_private_free(Point *point){
    free(point);
}
