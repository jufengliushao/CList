//
//  SQMazeStack.h
//  Clist
//
//  Created by cnlive-lsf on 2017/6/1.
//  Copyright © 2017年 lsf. All rights reserved.
//

#ifndef SQMazeStack_h
#define SQMazeStack_h

#include <stdio.h>
#include <malloc/malloc.h>
#include <stdlib.h>

#define MAX_LENGTH 100

typedef struct PS{
    int i;
    int j;
}PointSeat, *pointSeat;

typedef struct Po{
    PointSeat seat;
    int order;
    int isUse;
    int data;
}Point, *point;

typedef struct {
    int top;
    Point point[MAX_LENGTH];
}SQMazeStack, *sqMazeStack;


/**
 初始化栈

 @return SQMazeStack
 */
SQMazeStack* sq_maze_initMaze();

/**
 将数据压入栈

 @param stack SQMazeStack
 */
void sq_maze_pop(SQMazeStack *stack);

/**
 弹出数据

 @param stack SQMazeStack
 @param point Point
 */
void sq_maze_push(SQMazeStack *stack, Point *point);
#endif /* SQMazeStack_h */
