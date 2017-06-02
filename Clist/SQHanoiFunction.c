//
//  SQHanoiFunction.c
//  Clist
//
//  Created by cnlive-lsf on 2017/6/2.
//  Copyright © 2017年 lsf. All rights reserved.
//

#include "SQHanoiFunction.h"

void hanoi_private_initSourceSQ(SQstack *stack); // 初始化源数据组 切从小到大排序
void hanoi_private_move(SQstack *from, SQstack *to); // 将第一个数据移动到目标栈中
void hanoi_private_main(int n, SQstack *from, SQstack *to, SQstack *tmp); // 迭代入口

int i = 1; // 当前步数

void hanoi_main(){
    SQstack *sourceSQ = sq_initStack();
    SQstack *dependSQ = sq_initStack();
    SQstack *aimSQ = sq_initStack();
    
    hanoi_private_initSourceSQ(sourceSQ);
    hanoi_private_main(sourceSQ->top, sourceSQ, aimSQ, dependSQ);
}

void hanoi_private_initSourceSQ(SQstack *stack){
    for (int i = 10; i > 0; i --) {
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
