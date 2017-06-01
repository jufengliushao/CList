//
//  SQMazeFunction.h
//  Clist
//
//  Created by cnlive-lsf on 2017/5/31.
//  Copyright © 2017年 lsf. All rights reserved.
//

#ifndef SQMazeFunction_h
#define SQMazeFunction_h

#include <stdio.h>
#include "SQStack.h"

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


void maze_initMap();
void maze_getRoad();

#endif /* SQMazeFunction_h */
