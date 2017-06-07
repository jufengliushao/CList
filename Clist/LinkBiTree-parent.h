//
//  LinkBiTree-parent.h
//  Clist
//
//  Created by cnlive-lsf on 2017/6/6.
//  Copyright © 2017年 lsf. All rights reserved.
//

#ifndef LinkBiTree_parent_h
#define LinkBiTree_parent_h

#include <stdio.h>
#include <malloc/malloc.h>
#include <stdlib.h>

typedef  int TElemType;

typedef struct LINKBT{
    TElemType data;
    struct LINKBT *lchild, *rchild, *parent;
}BiNode, *Bitree;

typedef struct LINK_NODE{
    Bitree element;
    struct LINK_NODE *next;
}QNode;

typedef struct LINK_QUEUE{
    QNode *front;
    QNode *rear;
}linkQueue;

/**
 创建根节点

 @param data data int
 @return Bitree
 */
Bitree bt_link_init(TElemType data);

/**
 创建左孩子结点

 @param parent parent Bitree
 @param data int
 */
void bt_link_setLeftChild(Bitree parent, TElemType data);

/**
 创建右孩子结点
 
 @param parent parent Bitree
 @param data int
 */
void bt_link_setRightChild(Bitree parent, TElemType data);

/**
 先序遍历

 @param node node
 */
void bt_link_formerSort(Bitree node);

/**
 中序遍历

 @param node node
 */
void bt_link_middleSort(Bitree node);

/**
 后序遍历

 @param node node
 */
void bt_link_backSort(Bitree node);

/**
 统计叶子节点数目

 @param node Bitree
 */
int bt_link_countLeafs(Bitree node);

void bt_link_lineSort(Bitree root);
#endif /* LinkBiTree_parent_h */
