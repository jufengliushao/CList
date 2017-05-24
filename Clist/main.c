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
    dl_insertNode(201, 0, doubleL);
    dl_insertNode(200, 1, doubleL);
    dl_printfDoubleList(doubleL);
    return 0;
}
