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

 @param parent root 
 */
void bt_link_formerSort(Bitree parent);
#endif /* LinkBiTree_parent_h */