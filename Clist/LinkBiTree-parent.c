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

/* ------------------------------------------------------------------ */

/**
 创建队列

 @param q linkQueue
 */
void bt_link_queue_private_initQueue(linkQueue *q);

/**
 创建并返回队列结点

 @param node Bitree
 @return QNode
 */
QNode* bt_link_queue_private_CreateNode(Bitree node);

/**
 入队操作

 @param q linkQueue
 @param node Bitree
 */
void bt_link_queue_private_enQueue(linkQueue *q, Bitree node);

/**
 出队操作

 @param q linkQueue
 @param node Bitree
 */
void bt_link_queue_private_deQueue(linkQueue *q, Bitree *node);
/* ------------------------------------------------------------------ */

void bt_link_queue_private_initQueue(linkQueue *q){
    if(!q){
        printf("create link queue fail!\n");
        exit(0);
    }
    
    q->front = q->rear = (QNode *)malloc(sizeof(QNode));
    q->front->next = NULL;
}

QNode* bt_link_queue_private_CreateNode(Bitree node){
    QNode *elem = (QNode *)malloc(sizeof(QNode));
    if (!elem) {
        printf("create QNode fail!\n");
        exit(0);
    }
    
    elem->element = malloc(sizeof(Bitree));
    elem->element = node;
    elem->next = NULL;
    return elem;
}

void bt_link_queue_private_enQueue(linkQueue *q, Bitree node){
    QNode *qNode = bt_link_queue_private_CreateNode(node);
    q->rear->next = qNode; // 等同于 q->front->next = qNode 在队列为空的时候
    q->rear = qNode;
}

void bt_link_queue_private_deQueue(linkQueue *q, Bitree *node){
    QNode *elem = (QNode *)malloc(sizeof(QNode));
    elem = q->front->next;
    *node = elem->element;
    q->front->next = elem->next;
    
    if (q->rear == elem) {
        q->rear = q->front;
    }
}

void bt_link_lineSort(Bitree root){
    linkQueue *q = malloc(sizeof(linkQueue));
    bt_link_queue_private_initQueue(q);
    
    bt_link_queue_private_enQueue(q, root);
    
    Bitree node = malloc(sizeof(Bitree));
    while (1) {
        if (q->rear->element->data != -1) {
            // 队尾不是标识符，添加
            bt_link_queue_private_enQueue(q, bt_link_private_initNode(-1));
            printf("\n");
        }
        
        if (q->front->next->element->data == -1) {
            // 如果队首元素是标志
            bt_link_queue_private_deQueue(q, &node);
        }else{
            while (q->front->next->element->data != -1) {
                bt_link_queue_private_deQueue(q, &node);
                if (node->lchild) {
                    bt_link_queue_private_enQueue(q, node->lchild);
                }
                if(node->rchild){
                    bt_link_queue_private_enQueue(q, node->rchild);
                }
                printf("%c\t", node->data);
            }
        }
        if (q->front == q->rear) {
            break;
        }
    }
    
}
