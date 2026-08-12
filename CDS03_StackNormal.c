#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#define MAXSIZE 10
// =========================================================
// < 구조체 자리 >
// =========================================================
typedef struct{
    int data[MAXSIZE];
    int top;
}Stack;
// =========================================================
// < 함수 자리 >
// =========================================================
// < 스택을 초기화하는 함수. 리셋의 역할도 같이 진행. >
void InitStack(Stack* mainStack){
    mainStack->top = -1;
    for(int i=0; i<MAXSIZE; i++){
        mainStack->data[i]=0;
    }
    printf("[SYSTEM] Initialize Complete\n");
}

// < 출력 - 간단하게 >
void PrintStack(Stack mainStack){
    printf("------------------------\n");
    for (int i=0; i<=mainStack.top; i++){
        printf("%d \n", mainStack.data[i]);
    }
    printf("------------------------\n");
}
// < 삽입 >
void Push(Stack* mainStack, int data){
    // 꽉 차지만 않았다면
    if (mainStack->top >= MAXSIZE-1){
        printf("[ERROR] Overflow!\n");
        return;
    }
    // top을 증가 후 data를 그 자리에 넣기
    mainStack-> top++;
    mainStack-> data[mainStack->top] = data;
    }

// < 추출 >
int Pop(Stack* mainStack){
    // 비어있지만 않다면
    if(mainStack->top <= -1){
        printf("[ERROR] Underflow\n");
    }
    int result = mainStack->data[mainStack->top];
    mainStack->top--;
    return result;
}
// < 검색 >
// 해당 값이 어디에 있는지 검색(배열리스트 기준)
// -->  -1 2 3 4 5 6 7 8 9  -->

void SearchStack(Stack stack, int target){
    // 0~k까지, 만약 있다? -> 인덱스 출력하고 끝.
    int k = stack.top;
    for(int i=0; i<=k; i++){
        if(stack.data[i]==target){
            printf("Target %d : %d\n", target, stack.data[i]);
            return;
        }
    }
    // k를 벗어날 경우. -> 없다 출력하고 끝.
    printf("Target Missing...\n");
}

// 스택 거꾸로 담기
// 10 20 30 40 50
// 50 40 30 20 10
// 임시 배열 하나 만들어서, POP 한 거 순서대로 넣기
// 이후 순서대로 배열에 다시 PUSH할 것. (k)

void ReverseStack(Stack* stack){
    int temp[MAXSIZE] = {0};
    int k = stack->top;
    for(int i=0; i<=k; i++){
        temp[i] = Pop(stack);
    }
    for(int i=0; i<=k; i++){
        Push(stack, temp[i]);
    }
    PrintStack(*stack);
}

void PrintUI(){
    printf("===============\n");
    printf(" 1. Print\n");
    printf(" 2. Push\n");
    printf(" 3. Pop\n");
    printf(" 4. Search\n");
    printf(" 5. Reverse\n");
    printf(" 6. Reset\n");
    printf("-1. Print\n");
    printf("===============\n");
    printf("Input Menu : ");
}

void Start(){
    Stack s;
    for(;1;){
        system("cls");
        PrintUI();
        int choice;
        scanf("%d", &choice);
        if(choice==1){
            PrintStack(s);
        }
        else if(choice==2){
            printf("Input Number : ");
            int number;
            scanf("%d", &number);
            Push(&s, number);
            printf("Success Push\n");
        }
        else if(choice==3){
            int t = Pop(t);
            if(t!=-99999){
                printf("Pop : %d\n", t);
            }
        }
        else if(choice==4){
            printf("Input Target : ");

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

// =========================================================
int main(){
   Stack stack;
   InitStack(&stack);
   Push(&stack, 10);
   Push(&stack, 20);
   Push(&stack, 30);
   Push(&stack, 40);
   Push(&stack, 50);
   PrintStack(stack);

    ReverseStack(&stack);

   SearchStack(stack, 40);
   Pop(&stack);
   Pop(&stack);
   PrintStack(stack);
    // ----------------------------------------------------

}// ========================================================
/*----------------------------------------------------------
/*

< 종합 실습 >
스택을 이용해서 시스템을 구현하세요. 구현해야 하는
기능들의 프로세스는 아래와 같습니다.
1. 프로그램 실행 후 UI 출력
     > 스택 출력, 스택 삽입, 스택 추출, 스택 검색, 스택 뒤집기, 스택 초기화
2. 사용자가 선택한 기능에 대해, 필요하다면 입력을 받아 처리
3. 처리 후 약간의 대기 시간 필요(너무 빠르면 안됩니다)
4. 이러한 것들을 무한반복으로 처리하세요
5. 이러한 작업을 CDS02_StackEasySystem.c에 저장.
3시 10분까지. 쉬는시간 포함
*/
----------------------------------------------------------*/