// 연결리스트 스택 -> 좀어려움...
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#define FAIL 20040413
// =========================================================
// < 구조체 자리 >
// =========================================================
typedef struct Node{
    // 노드가 뭔가요? -> 하나의 데이터 단위
    // 본인의 데이터와, 다음꺼는 뭡니다를 가지고 있는 것.
    int data;
    struct Node* next;
}Node;

typedef struct Stack{
    Node* top;
    int size; // 나와 연결되어 있는 노드의 개수를 관리
    // Node** prtAry;
} Stack;
// =========================================================
// < 함수 자리 >
// =========================================================

// <스택 초기화>
void InitStack(Stack* s){
    s->top = NULL;
    s->size = 0;
}

// <스택에 새로운 "Node"를 만들고 연결시키기>
void Push(Stack* s, int data){
    // 1. 새로운 놈 만들기
    Node* temp = (Node*)malloc(sizeof(Node));
    // 2. 안전장치(생략)
    if(temp==NULL){
        // 메모리 할당 할라했는데, 모자라서 못한 경우
        // WINDOW와 같은 우리 컴터는 절대 발생 안함
        printf("[FAIL] Memory Fail\n");
        return;
    }
    // 3. 새로운 놈 값 변경
    temp->data = data;
    temp->next = s->top;
    // 4. s -> top 변경하기
    s->top = temp;
    // 5. s->size를 하나 증가시키기
    s->size++;
}

// <스택에 있는 가장 먼저 넣은 놈(top)을 빼서 리턴>
int Pop(Stack* s){
    // 1. 비어있는지 확인
    if(s->size==0){
        printf("[FAIL] Underflow!!\n");
        return FAIL;
    }
    // 2. 뺄 놈의 주소 확보
    Node* temp = s->top; // 첫 노드의 집주소 저장 = 삭제용
    // 3. 뺄 놈의 데이터 확보
    int result = temp->data;
    // 4. top 교체하기
    s->top = s->top->next; // temp->next
    // 5. size 하나 줄이기
    s->size--;
    // 6. temp free하기
    free(temp); // 누수방지
    // 7. 리턴하기
    return result;
}

// <스택 출력하기>
void PrintStack(Stack s){
    printf("==========================================\n");
    Node* move = s.top;
    for(int i=0; i<s.size; i++){
        printf("%d ", move->data);
        move = move->next;
    }

    printf("\n==========================================\n");

}

// <검색하기>
void SearchStack(Stack s, int target){
    // 1. 비어있으면 끝
    // 2. 안 비어있으면 s.size만큼 반복해서
    // 3. 찾는 게 없으면 다음 이동
    // 4. 찾았으면 i번째 있다 출력하고 끝
    // 5. 아예 없으면 없다고 출력하고 끝.
    if (s.size==0){
        printf("[Message] Empty!\n");
        return;
    }
    Node*move = s.top; // 움직일 놈 필요
    for(int i=0; i<s.size; i++){
        if (move->data==target){
            printf("[Message] Target : %d\n", i);
            return;
        }
        else{
            move = move->next;
        }
        /*if (stack[i]==target){
            printf("On %d", stack[i]);
        }*/
    }
    printf("[Message] not found Target\n");
}

// <리셋하기>
// 모든 요소 free 시키기
void Reset(Stack* s){
    int size = s-> size;
    for(int i=0; i<s->size; i++){
        Pop(s);
    }
    printf("[Message] Reset Complete\n");
}

// <전체삭제>
// =========================================================
int main(){
    Stack stack;
    InitStack(&stack);
    // ----------------------------------------------------
    // 데이터 좀 몇 개 넣어보고 출력
    // 몇 개 또 빼보고 출력, 넣고 빼고 ㄱㄱ

    for(int i=0; i<5;i++){
        Push(&stack, (i+1)*10);
    }
    PrintStack(stack);
    Pop(&stack);
    Pop(&stack);
    PrintStack(stack);
}// ========================================================
/*----------------------------------------------------------
<숙제>
StackHard로 만든 코드들을 유기적으로 작동하는 시스템으로 구현하세요
단, 모든 함수들을 시스템 내에 포함시켜야 합니다.
기존에 했던 시스템과 비슷하게 구현해 오세요.
----------------------------------------------------------*/