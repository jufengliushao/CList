//
//  Sort.c
//  Clist
//
//  Created by cnlive-lsf on 2017/6/21.
//  Copyright © 2017年 lsf. All rights reserved.
//

#include "Sort.h"
void sortTheArray(int a[], int lenght){
    for (int i = 2; i < lenght; i ++) {
        // 真实数据是从1开始的
        if(a[i] < a[i-1]){
            // 当前数小于前一个数
            // 进行交换
            a[0] = a[i];
            a[i] = a[i-1];
            int j;
            for (j = i - 2; a[0] < a[j] && j >= 0; j--) {
                a[j+1] = a[j];
            }
            a[j+1]= a[0];
        }
    }
    for (int i = 0; i < lenght; i++) {
        printf("%d-", a[i]);
    }
}


void bubbleSort(int a[], int length){
    int flag = 0; // 是否 交换的标志
    for (int i = 0; i < length - 1; i ++) {
        flag = 0;
        for (int j = i + 1; j < length; j ++) {
            if(a[i] > a[j]){
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                flag = 1;
            }
        }
    }
    for (int i = 0; i < length; i ++) {
        printf("%d-", a[i]);
    }
}

void bubbleRearSort(int a[], int length){
    for (int i = length-1; i > 0; i --) {
        for (int j = i - 1; j >= 0; j --) {
            if (a[i] < a[j]) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    for (int i = 0; i < length; i ++) {
        printf("%d-", a[i]);
    }
}

void quickSort(int a[], int start, int end){
    if (start >= end) {
        return;
    }
    
    int i = start, j = end, mid = a[i];
    
    while (i < j) {
        while (i < j && mid < a[j]) {
            j --;
        }
        //判断是否需要交换
        if (i < j) {
            a[i] = a[j];
            a[j] = mid;
            i ++;
        }
        while (i < j && mid > a[i]) {
            i ++;
        }
        // 判断是否交换
        if(i < j){
            a[j] = a[i];
            a[i] = mid;
            j --;
        }
    }
    
    for (int i = 0; i < 8; i ++) {
        printf("%d-", a[i]);
    }
    printf("\n");
    
    quickSort(a, start, i - 1);
    quickSort(a, i + 1, end);
}
