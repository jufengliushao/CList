//
//  LinkBiTree-parent.c
//  Clist
//
//  Created by cnlive-lsf on 2017/6/6.
//  Copyright © 2017年 lsf. All rights reserved.
//

#include "LinkBiTree-parent.h"
Bitree header;
/**
 创建结点

 @param data data int
 @return Bitree
 */
Bitree bt_link_private_initNode(TElemType data);

Bitree bt_link_init(TElemType data){
    if (!header) {
        header = bt_link_private_initNode(data);
    }
    return header;
}

void bt_link_setLeftChild(Bitree parent, TElemType data){
    Bitree lchild = bt_link_private_initNode(data);
    parent->lchild = lchild;
    lchild->parent = parent;
}

void bt_link_setRightChild(Bitree parent, TElemType data){
    Bitree rchild = bt_link_private_initNode(data);
    parent->rchild = rchild;
    rchild->parent = parent;
}

void bt_link_formerSort(Bitree node){
    printf("%d\t", node->data);
    if (node->lchild) {
        bt_link_formerSort(node->lchild);
    }
    if (node->rchild){
        bt_link_formerSort(node->rchild);
    }
    return;
}

Bitree bt_link_private_initNode(TElemType data){
    Bitree node = (Bitree)malloc(sizeof(BiNode));
    if (!node) {
        printf("the node create fail!\n");
        exit(0);
    }
    node->data = data;
    node->lchild = node->parent = node->rchild = NULL;
    return node;
}
