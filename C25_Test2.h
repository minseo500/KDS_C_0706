// 외부에서 Test2 구조체를 제작, 
// int형 배열 10개짜리, size가지고 있음
// InitTest2 1~10데이터 넣고, size 조정
// PrintTest2 모든 요소 출력
// C25_Test2.h
#include <stdio.h>
#ifndef C25_TEST2_H
#define C25_TEST2_H
typedef struct{
    int ary[10];
    int size;
}Test2;

void InitTest2(Test2* t){
    for(int i=0; i<10; i++){
        t->ary[i] = i+1;
    }
    t->size = 10;
}
void PrintTest2(Test2 t){
    for(int i=0; i<t.size; i++){
        printf("%d ", t.ary[i] );
    }
    printf("\n");
}

#endif