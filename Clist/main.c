//
//  main.c
//  Clist
//
//  Created by cnlive-lsf on 2017/5/18.
//  Copyright © 2017年 lsf. All rights reserved.
//

#include <stdio.h>
#include "SignalList.h"
#include "DoubleList.h"
#include "SQStack.h"
#include "SQStackFunction.h"
#include "SQMazeFunction.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    maze_initMap();
    maze_getRoad();
    return 0;
}
