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

int main(int argc, const char * argv[]) {
    // insert code here...
    DoubleList *doubleL = dl_returnHeaderNode();
    dl_insertNode(205, 0, doubleL);
    dl_insertNode(204, 0, doubleL);
    dl_insertNode(203, 0, doubleL);
    dl_insertNode(202, 0, doubleL);
    dl_insertNode(201, 0, doubleL);
    dl_insertNode(200, 0, doubleL);
    dl_printfDoubleList(doubleL);
    printf("\n\n\n");
    
    DoubleList *doubleR = dl_returnHeaderNode();
    dl_insertNode(206, 0, doubleR);
    dl_insertNode(205, 0, doubleR);
    dl_insertNode(204, 0, doubleR);
    dl_insertNode(203, 0, doubleR);
    dl_insertNode(202, 0, doubleR);
    dl_insertNode(201, 0, doubleR);
    dl_printfDoubleList(doubleR);
    printf("\n\n\n");
    
    dl_mergeDoubleList_ASC(doubleL, doubleR);
    dl_printfDoubleList(doubleL);
    return 0;
}
