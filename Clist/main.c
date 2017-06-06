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
#include "SQStackFunction.h"
#include "SQMazeFunction.h"
#include "SQHanoiFunction.h"
#include "SQBiTree.h"
#include "LinkBiTree-parent.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    Bitree root = bt_link_init(1);
    bt_link_setLeftChild(root, 2);
    bt_link_setRightChild(root, 3);
    bt_link_setLeftChild(root->lchild, 4);
    bt_link_setRightChild(root->lchild, 5);
    bt_link_setRightChild(root->rchild, 6);
    bt_link_formerSort(root);
    return 0;
}
