// C22_StructDynamic.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
// =========================================================
// < 구조체 자리 >
// =========================================================
typedef struct{
    int    x; // 4
    double y; // 8
    char   z; // 1
}Test;
typedef struct{
    char name[100];
    int hp;
    int mp;
}Player;
// =========================================================
// < 함수 자리 >
// =========================================================
Test* GetTest(){
    // 임시로 하나 만들고
    Test* temp = (Test*)malloc( sizeof(Test) ); // 1개짜리
    // 세팅하고
    // ★ 포변이 알고있는 데이터 공간사용?? -> 쓰면 끝.
    (*temp).x = rand()*10;
      temp->y = 3.14;
      temp->z = rand()%26+65;

    // 돌려주기
    return temp;
}
void PrintTest(Test t){
    printf("%d, %lf, %c\n", t.x,t.y,t.z);
}
//  55분
// 지금 넘겨받은 놈의 정체가 무엇인지 확인
void SetTest( Test** tPtr ){
    // 임시로 하나 malloc temp에 받기
    Test* temp = (Test*)malloc(sizeof(Test));
    // 값 설정하기
    temp->x = 10 ;
    temp->y = 1.1;
    temp->z = 'A';

    // 원본 데이터 공간에 직접 주소를 넣기
    *tPtr = temp;   // *가 ->  원본 데이터 공간 사용
}

// -----------------------------------------------------
// Main함수에 구조체 Player를 통해 만들어진 포변수가 있음
// 이 변수에, 직접 값을 넣어주는 SetPlayer, 직접 만들어서
// 넘겨주는 GetPlayer함수를 구현하세요.
// Player구조체에는, name(최대100글자), hp, mp등이 있습니다.
// 이름은 키보드로 입력 받게끔 해주셔야 합니다.
Player* InitPlayer(){
    Player* temp = (Player*)malloc(sizeof(Player));
    printf("Input Your Name : ");
    scanf("%s", temp->name);
    temp->hp = 100;
    temp->mp = 50;

    return temp;
}

void SetPlayer(Player** p){
    *p = InitPlayer();
}
Player* GetPlayer(){
    return InitPlayer();
}

// =========================================================
int main(){
    srand(time(NULL));
    // ----------------------------------------------------
    // 구조체의 크기 측정하기
    Test t = {10,1.1,'C'};
    printf("%d\n", sizeof(t  ) ); // 이론상 12 -> 16 ????
    printf("%d\n", sizeof(t.x) ); // int    4
    printf("%d\n", sizeof(t.y) ); // double 8
    printf("%d\n", sizeof(t.z) ); // char   1
    // 이론상 12, 13인데, 구조체 전체 크기는 다름!! > 패킹
    // --------------------------------------------------
    Test* tPtr = NULL;
    // 외부에서 얘한테 직접 세팅
    SetTest( &tPtr ); // 외부에서 내꺼 데이터공간 변경필요
                      // 그럼 내꺼 주소 넘겨야 함.

    // 외부에서 뭐 만들어서 돌려주기
    tPtr = GetTest();
    PrintTest(*tPtr); // 굳이 주소를....?
    // -------------------------------------------
    Player* player=NULL;
    SetPlayer(&player);
    player = GetPlayer();

}// ========================================================
/*----------------------------------------------------------
구조체의 동적 할당
구조체는 여러 변수가 들어있어서, 크기를 구하기 쉽지 않음
 -> 구조체 사이즈는 직접 계산 절대 XXX  무조건 sizeof

기존의 동적 할당과 동일함.
// --------------------------------------
컴퓨터는 사실, 2진법 기반으로 돌아감 - C언어도 마찬가지
구조체 안에 있는 자료형들의 크기가 통일이 안되면???
  -> 컴퓨터(운영체제)가 비효율적으로 코드를 실행하게 됨.
|~~~~~~~~~~~~~~~~~~~
|  int    :oooo----|
|  double :oooooooo|
|  char   :o-------|
|~~~~~~~~~~~~~~~~~~~ 강제로, 큰 자료형 기준으로 패킹
구조체의 크기를 직접 구하는 것은 바보바보 멍청멍청 해삼 말미잘

----------------------------------------------------------*/