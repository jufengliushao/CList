//
//  SQHanoiFunction.c
//  Clist
//
//  Created by cnlive-lsf on 2017/6/2.
//  Copyright © 2017年 lsf. All rights reserved.
//

#include "SQHanoiFunction.h"

/**
 初始化源数据组 切从小到大排序

 @param stack SQstack
 */
void hanoi_private_initSourceSQ(SQstack *stack);

/**
 移动函数

 @param from 源栈
 @param to 目标栈
 */
void hanoi_private_move(SQstack *from, SQstack *to);

/**
 交换主函数 迭代入口

 @param n 需要移动的数目
 @param from 源栈
 @param to 目标栈
 @param tmp 中间栈
 */
void hanoi_private_main(int n, SQstack *from, SQstack *to, SQstack *tmp);

int i = 1; // 当前步数

void hanoi_main(){
    SQstack *sourceSQ = sq_initStack();
    SQstack *dependSQ = sq_initStack();
    SQstack *aimSQ = sq_initStack();
    
    hanoi_private_initSourceSQ(sourceSQ);
    hanoi_private_main(sourceSQ->top, sourceSQ, aimSQ, dependSQ);
}

void hanoi_private_initSourceSQ(SQstack *stack){
    for (int i = 2; i > 0; i --) {
        sq_push(stack, i);
    }
}

void hanoi_private_main(int n, SQstack *from, SQstack *to, SQstack *tmp){
    if(n == 1){
        hanoi_private_move(from, to);
    }else{
        hanoi_private_main(n-1, from, tmp, to);
        hanoi_private_move(from, to);
        hanoi_private_main(n-1, tmp, to, from);
    }
}

void hanoi_private_move(SQstack *from, SQstack *to){
    DATA element = sq_returnTopElementWithoutPrint(from);
    from->top --;
    sq_push(to, element);
    printf("step:%d----data:%d----from:%p----to:%p\n", i++, element, from, to);
}
