// C25_Header.c
#include <stdio.h>
#include "C25_Test.h"
#include "C25_Test2.h"

// < 경로 작성법 >
// ./         현재 폴더 : 생략 가능 
// ../        상위폴더
// ./폴더명/  이 폴더명 안쪽으로 이동
// ../폴더명/ 상위폴더에서 폴더명 안쪽으로 이동

// 구조체 Test를 만들고, 외부에서
// 구조체의 값을 조작 및 출력하는 h파일
// C25_Test.h


// 외부에서 Test2 구조체를 제작, 
// int형 배열 10개짜리, size가지고 있음
// InitTest2 1~10데이터 넣고, size 조정
// PrintTest2 모든 요소 출력
// C25_Test2.h

int main(){
    Test t;
    InitTest(&t);
    PrintTest(t);
    printf("Hello World\n");
    // -------------------------
    Test2 t2;
    InitTest2(&t2);
    PrintTest2(t2);
}