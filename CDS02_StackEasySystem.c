// CDS02_StackEasy.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#define MAXSIZE 10
int stack[MAXSIZE]; // 알아서 0으로 초기화됨
int top = -1; // 여기까지 데이터 있지롱~
// =======================================================
// < 전 역 함 수 >
// =======================================================

// 🔥 스택에 데이터를 밀어넣는 함수. 꽉 차면 Overflow 🔥
void Push(int data){
     // 1. 꽉 차 있으면 Overflow 출력하고 끝
     if(top == MAXSIZE){
          printf("[ERROR] Overflow !\n");
          return;
     }
     else{
          // 2. 꽉 차 있지 않다면, top을 하나 증가시킴
          // 3. top인덱스 번째 stack에 data 때려넣기
          stack[++top] = data;
     }
}

// 🏳‍🌈 모든 스택의 요소를 "이쁘게" 출력하는 함수 제작 🏳‍🌈
// (추가예제) top보다 위에 있으면, 숫자 출력 X
void PrintStack(){
     system("cls");
     printf("|   |\n");
     for(int i=0 ; i<MAXSIZE; i++){
          if(MAXSIZE-i-1 > top){
               printf("|   |\n");     
          }else{
               printf("| %d |\n", stack[MAXSIZE-i-1]);
          }
     }
     printf("-----\n");
}
// ✨ 스택에서 하나 빼서 돌려주는 Pop ✨
int Pop(){
     // 1. 비어있으면 Underflow 출력
     if(top == -1){
          printf("[ERROR] Underflow !!\n");
          return -99999;
     }
     else{
          // 2. top에 있는거 백업
          int temp = stack[top];
          // 2-1 그 안에 숫자를 0 넣기
          stack[top] = 0;
          // 3. top을 하나 내리기
          top--;
          // 4. 돌려주기
          return temp;
          // <실습> 이거를 한줄로 바꿔보세요.
          // return stack[top--];
     }
}
void PrintUI(){
    printf("===============\n");
    printf(" 1. Print\n");
    printf(" 2. Push\n");
    printf(" 3. Pop\n");
    printf(" 4. Reset\n");
    printf("-1. Print\n");
    printf("===============\n");
    printf("Input Menu : ");
}

void Start(){
    for(;1;){
        system("cls");
        PrintUI();
        int choice;
        scanf("%d", &choice);
        if(choice==1){
            PrintStack();
        }
        else if(choice==2){
            printf("Input Number : ");
            int number;
            scanf("%d", &number);
            Push(number);
            printf("Success Push\n");
        }
        else if(choice==3){
            int t = Pop();
            if(t!=-99999){
                printf("Pop : %d\n", t);
            }
        }
        else if(choice==4){
            // 스택 초기화
            // top이 어디까지 데이터 있어요~~관리
            top = -1;
            // 엥?? 데이터 남아있는거 아니에요???
            // > 맞음. 근데 출력될 일 없음.
        }
        else if(choice==-1){
            printf("Bye\n");
            return;
        }else{
            printf("Wrong Input. Restart\n");
        }
        Sleep(1000);
        
    }
}

// =======================================================
int main(){
    Start();
}// ======================================================
/*

< 종합 실습 >
스택을 이용해서 시스템을 구현하세요. 구현해야 하는
기능들의 프로세스는 아래와 같습니다.
1. 프로그램 실행 후 UI 출력
     > 스택 출력, 스택 삽입, 스택 추출, 스택 초기화
2. 사용자가 선택한 기능에 대해, 필요하다면 입력을 받아 처리
3. 처리 후 약간의 대기 시간 필요(너무 빠르면 안됩니다)
4. 이러한 것들을 무한반복으로 처리하세요
5. 이러한 작업을 CDS02_StackEasySystem.c에 저장.
3시 10분까지. 쉬는시간 포함
*/