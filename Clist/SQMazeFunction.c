//
//  SQMazeFunction.c
//  Clist
//
//  Created by cnlive-lsf on 2017/5/31.
//  Copyright © 2017年 lsf. All rights reserved.
//

#include "SQMazeFunction.h"
#include <malloc/malloc.h>

#define MAX_MAZE_LEGNTH 10

Point *maps[MAX_MAZE_LEGNTH][MAX_MAZE_LEGNTH];

void maze_initMap(){
    Point *point1 = malloc(sizeof(Point));
    point1->seat = *(pointSeat)malloc(sizeof(PointSeat));
    maps[1][1] = point1;
}
