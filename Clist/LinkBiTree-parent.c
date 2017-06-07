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
    printf("%c\t", node->data);
    if (node->lchild) {
        bt_link_formerSort(node->lchild);
    }
    if (node->rchild){
        bt_link_formerSort(node->rchild);
    }
    return;
}

void bt_link_middleSort(Bitree node){
    if (node->lchild) {
        bt_link_middleSort(node->lchild);
    }
    printf("%c\t", node->data);
    if (node->rchild) {
        bt_link_middleSort(node->rchild);
    }
}

void bt_link_backSort(Bitree node){
    if (node->lchild) {
        bt_link_backSort(node->lchild);
    }
    
    if (node->rchild) {
        bt_link_backSort(node->rchild);
    }
    printf("%c\t", node->data);
}

int bt_link_countLeafs(Bitree node){
    static int count = 0;
    if (node->lchild) {
        bt_link_countLeafs(node->lchild);
    }
    if (node->rchild){
        bt_link_countLeafs(node->rchild);
    }
    if (!node->lchild && !node->rchild) {
        count ++;
        printf("%d\n", count);
    }
    return count;
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
