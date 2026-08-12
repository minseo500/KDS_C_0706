// C24_Preprocessing.c
#include <stdio.h>
#define TEST 987984362
#define TT
#define VERSION1_0
#define VERSION1_1
#define VERSION1_2
#define VERSION1_3
#define VERSION 2
#define XXX 999999
// define이나, 전역변수 같은건, 어디서나 쓸 수 있으니까
// 전부 대문자로 표시하도록 합시다.
// define언제써? -> 모두가 공용으로 같은 값을 사용할 때
//     예시 : API Key, DBMS ID/PS, IP Address ....
// -------------------------------------------------



int main(){
    printf("Test : %d\n", TEST);
    // TEST = 123123;
    // x =30;
    // -------------------------------
    // TT가 선언되어 있으면 "티티~" 아니면, "ㅠㅠ"출력
    #ifdef tt
        // 만약에 TT가 정의되어 있다면... 여기를 실행
        printf("TT~\n");
    #else
        // 정의되어 있지 않으면 여기 실행
        printf("uu...\n");
    #endif

    // ----------------------------------
    // 운영체제 따라 결과 다르게 나오게 하기
    // Window : _WIN32 또는 _WIN64
    // MAC(매킨토시) : __APPLE__
    // Linux : __linux__
    // ----------------------------------
    #ifdef _WIN64
        printf("Hello Window\n");
    #elifdef __APPLE__
        printf("Hello Apple\n");
    #elifdef __linux__
        printf("Hello Linux\n");
    #else
        printf("Unknown OS\n");
    #endif

    #ifdef _WIN64
        printf("워쩌고저쩌고");
    #endif
    #ifdef __APPLE__
        printf("애플 시러");
    #endif
    #ifdef __linux__
        printf("리눅스 역겨워");
    #endif

    // ----------------------------------
    // VERSION이라는 이름을 define으로 정의하세요
    // 만약, VERSION이 정의되어 있다면 A함수를
    // 그렇지 않다면 B 함수를 싫애하세요
    // A : Hello 출력,  B : World 출력
    // #else는 사용 금지. 강의자료 40페이지 참고
    #ifdef VERSION
        // A(); // 만들어야하는데 그냥 여기다 작성
        printf("Hello\n");
    #endif
    #ifndef VERSION
        // B(); // 절 대 귀찮은거 아님다 ^^7
        printf("World\n");
    #endif
    // ----------------------------------------
    #if VERSION >= 3
        printf("Version 3!!\n");
    #else
        printf("Version 2\n");
    #endif

    // int x=1111;
    #if XXX >= 999
        printf("Hello");
    #endif
}