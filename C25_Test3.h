// 배열받아서 1~20 세팅
#include <stdio.h>
#ifndef C25_TEST3_H
#define C25_TEST3_H
void O(int ary[],int size){
    for(int i=0; i<size; i++){
        ary[i] = i+1;
    }
}
#endif