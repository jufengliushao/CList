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
int main(int argc, const char * argv[]) {
    // insert code here...
    SQstack *stack = sq_initStack();
    sq_push(stack, 10);
    sq_push(stack, 11);
    sq_push(stack, 12);
    sq_pop(stack);
    sq_push(stack, 13);
    sq_push(stack, 14);
    sq_pop(stack);
    sq_pop(stack);
    return 0;
}
