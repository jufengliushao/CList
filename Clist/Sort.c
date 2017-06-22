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
