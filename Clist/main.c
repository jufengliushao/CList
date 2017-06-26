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
#include "Sort.h"
int main(int argc, const char * argv[]) {
    // insert code here...
//    Bitree root = bt_link_init('A');
//    bt_link_setLeftChild(root, 'B');
//    bt_link_setRightChild(root, 'C');
//    bt_link_setLeftChild(root->lchild, 'D');
//    bt_link_setRightChild(root->lchild, 'E');
//    bt_link_setLeftChild(root->lchild->rchild, 'G');
//    bt_link_setRightChild(root->rchild, 'F');
//    bt_link_countLeafs(root);
    
//    bt_link_lineSort(root);
//    
//    int a[] = {0, 5, 3, 1, 6, 4};
//    bubbleRearSort(a, 3);

    int a[] = {46, 55, 13, 42, 94, 05, 17, 70};
    selectSort(a, 0, 8);
    return 0;
}
