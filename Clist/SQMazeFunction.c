//
//  SQMazeFunction.c
//  Clist
//
//  Created by cnlive-lsf on 2017/5/31.
//  Copyright © 2017年 lsf. All rights reserved.
//

#include "SQMazeFunction.h"
#include <malloc/malloc.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MAZE_LEGNTH_I 10
#define MAX_MAZE_LEGNTH_J 20
#define TRUE 1
#define FALSE 0

Point *maps[MAX_MAZE_LEGNTH_I][MAX_MAZE_LEGNTH_J];

void maze_private_printMap();
void maze_private_resetMaps();
int maze_private_pointIsEmpty(Point *point);
Point* maze_private_judegmentBack(Point *point);
void maze_private_printPoint(Point *point);
void maze_private_getRoad(SQstack *stack);

void maze_private_setRoadPoint(Point *point, SQstack *stack); // 设成路径上的点
void maze_private_setUnroadPoint(Point *point, SQstack *stack); // 设成未使用的点

Point* maze_private_backPoint(Point *point, SQstack *stack); // 路径回退

void maze_initMap(){
    for(int i = 0; i < MAX_MAZE_LEGNTH_I; i ++){
        for(int j = 0; j < MAX_MAZE_LEGNTH_J; j ++){
            Point *point1 = malloc(sizeof(Point));
            point1->seat = *(pointSeat)malloc(sizeof(PointSeat));
            if(i == 0 || i == MAX_MAZE_LEGNTH_I-1 || j == 0 || j == MAX_MAZE_LEGNTH_J-1){
                point1->data = '#';
            }else{
                point1->data = ' ';
            }
            point1->seat.i = i;
            point1->seat.j = j;
            point1->isUse = 0;
            point1->order = 0;
            maps[i][j] = point1;
        }
    }
    maze_private_resetMaps();
    maze_private_printMap();
}

void maze_getRoad(){
    SQstack *stack = sq_initStack();
    maze_private_getRoad(stack);
}

// ----------------------------------------------------------------
void maze_private_resetMaps(){
    // set enter
    maps[0][0]->data = ' ';
    maps[0][1]->data = ' ';
    // set exit
    maps[MAX_MAZE_LEGNTH_I - 1][MAX_MAZE_LEGNTH_J-1]->data = ' ';
    maps[MAX_MAZE_LEGNTH_I - 1][MAX_MAZE_LEGNTH_J-2]->data = ' ';
    
    // rand set #
    int i = 1;
    while (i < MAX_MAZE_LEGNTH_I-1) {
        int total = rand()%(MAX_MAZE_LEGNTH_J - 2);
        while (total < 3 || total > 8) {
            total = rand()%(MAX_MAZE_LEGNTH_J - 2);
        }
        for (int j = 0; j < total; j ++) {
            int col = rand()%(MAX_MAZE_LEGNTH_J-2) + 1;
            maps[i][col]->data = '#';
        }
        i ++;
    }
}

void maze_private_printMap(){
    for(int i = 0; i < MAX_MAZE_LEGNTH_I; i ++){
        for(int j = 0; j < MAX_MAZE_LEGNTH_J; j ++){
            printf("%c", maps[i][j]->data);
        }
        printf("\n");
    }
}

Point* maze_private_judegmentBack(Point *point){
    // 顺时针
    if (point->seat.j + 1 < MAX_MAZE_LEGNTH_J && maze_private_pointIsEmpty(maps[point->seat.i][point->seat.j+1])) {
        return maps[point->seat.i][point->seat.j+1];
    }else if (point->seat.i - 1>0 && maze_private_pointIsEmpty(maps[point->seat.i-1][point->seat.j])){
        return maps[point->seat.i-1][point->seat.j];
    }else if (point->seat.j - 1 > 0 && maze_private_pointIsEmpty(maps[point->seat.i][point->seat.j-1])){
        return maps[point->seat.i][point->seat.j-1];
    }else if (point->seat.i + 1<MAX_MAZE_LEGNTH_I && maze_private_pointIsEmpty(maps[point->seat.i+1][point->seat.j])){
        return maps[point->seat.i+1][point->seat.j];
    }
    Point *point1 = malloc(sizeof(Point));
    point1->data = -1;
    return point1;
}

int maze_private_pointIsEmpty(Point *point){
    if (point->data == '#' || point->isUse) {
        return FALSE;
    }
    return TRUE;
}

void maze_private_getRoad(SQstack *stack){
    Point *point = maps[0][0];
    sq_push(stack, point);
    while (point->data != -1 || (point->seat.i != MAX_MAZE_LEGNTH_I-1 && point->seat.j != MAX_MAZE_LEGNTH_J-1)) {
        point = maze_private_judegmentBack(point);
    }
    maze_private_printPoint(point);
}

void maze_private_setRoadPoint(Point *point, SQstack *stack){
    point->isUse = 1;
    point->data = '*';
    point->order = stack->top-1;
}

void maze_private_setUnroadPoint(Point *point, SQstack *stack){
    point->isUse = 0;
    point->data = ' ';
    point->order = 0;
}

Point* maze_private_backPoint(Point *point, SQstack *stack){
    maze_private_setUnroadPoint(point, stack);
    sq_pop(stack);
    return stack->data[stack->top-1];
}

void maze_private_printPoint(Point *point){
    printf("order:%d------i:%d---j:%d\n", point->order, point->seat.i, point->seat.j);
}
