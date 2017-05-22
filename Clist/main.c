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
    Node *header = returnHeaderNode();
    insertNode(0, 201, header);
    insertNode(1, 202, header);
    insertNode(0, 203, header);
    insertNode(1, 204, header);
    insertNode(2, 200, header);
    insertNode(2, 201, header);
    printNode(header);
    printf("\n\n");
    bubbleSortList(header);
    printNode(header);
    return 0;
}
