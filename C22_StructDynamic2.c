// C22_StructDynamic2.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
// =========================================================
// < 구조체 자리 >
// =========================================================
typedef struct{
    int* ary;
    int size;
}Test;
// =========================================================
// < 함수 자리 >
// =========================================================
void InitTest(Test* t, int size){
    // 넘겨받은 구조체 안에 있는 포인터변수에
    // 추가로 넘겨받은 사이즈 만큼, 배열을 만들고, size세팅
    // 이후, 모든 요소에 랜덤값 (1~9)를 넣어주는 함수
    int* ary = (int*)malloc( size * sizeof(int));
    for(int i=0; i<size; i++){
        ary[i] = rand()%9+1;
    }
    t->size = size;
    t->ary = ary;
}
void PrintTest(Test t){
    // 모든 요소출력. 구조체 하나만 넘겨받아 작업
    for(int i=0; i<t.size ;i++){
        printf( "%d ",t.ary[i] ); 
    }   printf("\n");
}
void ResizeTest(Test* t, int size){
    // 기존의 구조체와, 사이즈를 넘겨받아
    // 구조체의 사이즈를, 새로운 사이즈로 변경(realloc)
    // 이후, 새로 만들어진 공간에는 0으로 가득 채우기
    if(  t->size < size ){
        // 사이즈를 늘려야 함
         printf("[SYSTEM] Size UP\n");
        int originSize = t->size;
        t->ary = realloc(t->ary, size*sizeof(int) );
        t->size=size;
        // 배열이 늘어났으니, originSize ~ size -> 0초기화
        for(int i=originSize; i<size; i++){
            t->ary[i] = 0;
        }

    }else if(t->size > size){
        // 사이즈를 줄여야 함
        printf("[SYSTEM] Size Down\n");
        // realloc을 이용하려면, 힙에 만든 주소 필요
        t->ary = realloc(t->ary, size*sizeof(int) );
        t->size=size;
    }else{
        // 사이즈가 똑같다.
        printf("[SYSTEM] Size Equal\n");
    }
}
// ResetNumberTest() > 넘겨받은 배열의 모든 요소에
// 1부터 순서대로 넣어주는 함수
void ResetNumberTest(Test* qwer){
    for(int i=0; i< (*qwer).size ; i++){
        qwer->ary[i] = i+1;
    }
    PrintTest(*qwer);
}

// ResetRandomTest() > 넘겨받은 배열의 모든 요소에
// 1~9랜덤값을 넣어주는 함수
void ResetRandomTest(Test* qwer){
    for(int i=0; i< (*qwer).size ; i++){
        qwer->ary[i] = rand()%9+1;
    }
    PrintTest(*qwer);
}
// =========================================================
int main(){
    srand(time(NULL));
    // ----------------------------------------------------
    Test t; // 일반 구조체 변수
    InitTest(&t , 30);
    PrintTest( t);
    ResizeTest(&t, 50);
    PrintTest( t);
    printf("-------------\n");
    ResetNumberTest(&t);
    printf("-------------\n");
    ResetRandomTest(&t);
}// ========================================================
/*----------------------------------------------------------
# 재밌는 진도 나갈 예정.
----------------------------------------------------------*/