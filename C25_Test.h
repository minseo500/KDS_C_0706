// 여기에 구조체 Test를 만들고,
// 구조체의 값을 조작 및 출력하는 h파일
// C25_Test.h
// typedef struct{
//     int x;
//     int y;
// }Test;
#include <stdio.h>
#ifndef C25_TEST_H
#define C25_TEST_H
typedef struct{
    int x;
    int y;
}Test;
void InitTest(Test* t){
    t->x=10;
    t->y=20;
}
void PrintTest(Test t){
    printf("%d %d\n", t.x, t.y);
}
#endif
//★ 절대 여기는 메인 함수 들어갈 수 없음!!!