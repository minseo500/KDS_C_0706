// C20_StructProject.c
// - - - o - 0 
// - - - - - 1
// - - ○ - - 2
// - - - - - 3 
// - - - - - 4
// 0 1 2 3 4 x
// 2 2 입력 -> 2.2자리에 O
// 또다시 입력 -> 입력받은 자리에 o 위치
// Rock : x, y좌표 가지고 있음 + 출력을 뭐로 할지 저장 ( o )
// Board : 25개 2차원 배열. Rock 여러개 최대 25개.

// 모든 Rock은 순서대로 00, 01, 02, .... 좌표를 가지며 -를 가짐
// 사용자가 입력한 좌표에 해당하는 Rock의 - -> o / 안전장치
// 보드를 다시 출력 + 화면 초기화(검색)
// 이후 다시 입력받기
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
// =========================================================
// < 구조체 자리 >
// =========================================================
struct Rock{
    int x;
    int y;
    char marker; // 기본값 -, 입력받을시 o
};
struct Board{
    struct Rock board[5][5];
    int sizeRock; // 25개가 되면 강제 종료
};
// =========================================================
// < 함수 자리 >
// =========================================================
void InitBoard(struct Board* board){
    // 25개의 Board안의 board에 x, y 세팅, - 세팅
    board->sizeRock = 0;
    // (*board).sizeRock=0 이게 어려워서 쉽게 만들어 줌.
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            (*board).board[i][j].x = i;
            (*board).board[i][j].y = j;
            (*board).board[i][j].marker = '-';
        }
    }
}
void PrintUI(struct Board board){
    // 5x5 Rock의 모든 marker 출력 + 1칸 공백
    // - - - o - 0 
    // - - - - - 1
    // - - ○ - - 2
    // - - - - - 3 
    // - - - - - 4
    // 0 1 2 3 4 x
    // ----------------------------
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            printf("%c ", board.board[i][j].marker );
        }
        printf("%d\n",i);
    }
    // 0 1 2 3 4 x
    printf("0 1 2 3 4 x\n");
}
void Start(struct Board* board){
    // Init 함수
    InitBoard(board);
    // UI 출력 함수
    // PrintUI(*board);
    // 무한반복 -> 출력 - 입력 - 변경 ->, sizeRock 5(25)되면 끝.
    for( ; (*board).sizeRock<25 ; ){// 5->10->25
        // 화면 초기화하기(cmd clear) 나중에!!
        system("cls");
        // UI 출력
        PrintUI(*board);
        // 사용자에게 입력 받기(무한반복)
        int x=0,y=0;
        for(;1;){
            printf("Input X Y : ");
            scanf("%d %d", &x, &y);
            if((x>=0 && x<=4) && (y>=0 && y<=4) ) break;
            system("cls");
            PrintUI(*board);
            printf("Wrong Index!!!\n");
        }
        // -------------------------------
        // 올바른 좌표가 들어옴
        // -------------------------------
        // 해당 좌표의 Rock marker 수정하기
        if( (*board).board[x][y].marker == 'o' ){
            (*board).board[x][y].marker = '-';
        }else if( (*board).board[x][y].marker == '-' ){
            (*board).board[x][y].marker = 'o';
        }else{
            // 알수 없는 오류에 의해 o - 아닌 값이 들어옴
            for(int i=0; i<99; i++){
                printf("[ERROR] 관리자에게 문의하세요\n");
            }
        }

        // RockSize 하나 증가
        (*board).sizeRock++;
    }
    system("cls");
    PrintUI(*board);
    printf("<GAME END>\n");
}
// =========================================================
int main(){
    srand(time(NULL));
    // ----------------------------------------------------
    struct Board board;
    Start(&board);
}// ========================================================
/*
    - - - - - -> board , Rock
    숫자 0~4사이에 입력 받아서, 해당 자리에 -라면 o변경
    o있었다면, - 변경.
    모든 - 이 ㅇ 되면 종료.
    조건. 최소 2개이상의 구조체 사용
          Main은, 구조체 생성 및 Start 하나만 있어야 함.

★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
< 프로젝트 진행 시 주의사항 >
  기본적인 기능을 모두 구현하기 전까지는 추가 기능 구현금지
    -> 반드시 기획서를 만들어 둔 후, 이거 먼저 끝내야 함.
    다만, 기능 추가 필요하다면? 추가 기획서에 해당 아이디어 작성
    ★★★★ 팀원도 이걸 지켜줘야 함. ★★★★

        팀원들과 분열, 싸움 -> 나이스 ~ 해야 함. = 자소서거리
    팀플레이, 협업, 커뮤니케이션, 의사소통 => 무조건 채용공고 있음.
      => 미리 증명 => 갈등 생겨야 함 + 어떻게 해결?????
*/