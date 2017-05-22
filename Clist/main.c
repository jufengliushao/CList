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
    printNode(header);
    insertNode(0, 203, header);
    printNode(header);
    deleteNode(1, header);
    printNode(header);
    return 0;
}
