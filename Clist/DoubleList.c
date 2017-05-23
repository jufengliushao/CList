//
//  DoubleList.c
//  Clist
//
//  Created by cnlive-lsf on 2017/5/23.
//  Copyright © 2017年 lsf. All rights reserved.
//

#include "DoubleList.h"

DuNode* dl_returnHeaderNode(){
    DuNode *header = (duNode)malloc(sizeof(DuNode));
    if (!header) {
        printf("double-list header create fail!");
    }
    header->data = 0;
    header->former = NULL;
    header->next = NULL;
    return header;
}
