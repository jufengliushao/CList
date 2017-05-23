//
//  main.c
//  Clist
//
//  Created by cnlive-lsf on 2017/5/18.
//  Copyright © 2017年 lsf. All rights reserved.
//

#include <stdio.h>
#include "SignalList.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Node *header = sl_returnHeaderNode();
    sl_insertNode(0, 201, header);
    sl_insertNode(1, 202, header);
    sl_insertNode(0, 203, header);
    sl_insertNode(1, 204, header);
    sl_insertNode(2, 200, header);
    sl_insertNode(2, 201, header);
    sl_printNode(header);
    printf("\n\n");
    sl_bubbleSortList(header);
    sl_printNode(header);
    return 0;
}
