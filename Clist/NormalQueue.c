//
//  NormalQueue.c
//  Clist
//
//  Created by cnlive-lsf on 2017/6/2.
//  Copyright © 2017年 lsf. All rights reserved.
//

#include "NormalQueue.h"
#include <malloc/malloc.h>


NormalQueue* nq_initQueue(){
    NormalQueue *queue = (normalQueue)malloc(sizeof(NormalQueue));
    return queue;
}
