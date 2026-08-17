#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
// =========================================================
// < 구조체 자리 >
// =========================================================
typedef struct Node{
    int data;
    struct Node* next;

}Node;

typedef struct Task{
    char tak[100];
    struct Task* next;
}Task;

typedef struct TaskQueue{
    Task* front;
    Task* rear;
}TaskQueue;

typedef struct Queue{
    Node* front; // 맨 앞, 출력할 놈 -> Dequeue
    Node* rear; // 맨 뒤, 데이터 여기까지 -> Enqueue
    // 큐가 비어있다? -> rear가 NULL -> front도 NULL
}Queue;
// =========================================================
// < 함수 자리 >
// =========================================================
// 큐를 초기화
void InitQueue(Queue* mainQ){
    // 추후, 이 함수를 리셋처럼 쓰기 위해
    // 큐 모든 내용 삭제도 안에 나중에 탑재
    mainQ->front = NULL;
    mainQ->rear = NULL;
}

void Enqueue(Queue* mainQ, int data){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    // 비어있는 경우: front, rear가 모두 NULL
    if(mainQ->front==NULL && mainQ->rear==NULL){
        // 아예 비어있으면 f,r 모두 세팅
        mainQ-> front = temp;
        mainQ-> rear = temp;
    }
    else{
        mainQ->rear->next=temp;
        mainQ->rear=temp;
    }
}

// 비어있으면 1 아니면 0
int IsEmpty(Queue* mainQ){
    if(mainQ->front==NULL && mainQ->rear==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void PrintEmpty(){
    printf("[System] Empty\n");
}

void Dequeue(Queue* mainQ){

    // 비어있으면 Empty를 출력.
    if(IsEmpty(mainQ)==1){
        PrintEmpty();
        return;
    }
    else{
        Node* temp = mainQ->front;
        // 1. 백업하기
        int result = mainQ->front->data; // temp->data
        // 2. front를 next로 옮기기
        mainQ->front = mainQ->front->next; // temp->next
        // 3. temp를 이용해서 free하기
        free(temp);
        // 4. front가 NULL이 되었다? -> 아무것도 x
        // rear도 NULL로 만들기
        if(mainQ->front==NULL) mainQ->rear=NULL;
        // 5. 백업한 데이터를 출력하기
        printf("result: %d\n", result);
    }
}

// 큐를 초기화
// 구현 후, InitQueue에 탑재
void ResetQueue(Queue* mainQ){
    // front, rear 모두 NULL이면 끝
    for(;1;){
    if(IsEmpty(mainQ)==1){
            return;
        }
    // 아니면 계속 Dequeue할 것.
    else{
        Dequeue(mainQ);
    }
}
}

// Front&Rear 값 확인
void PrintFrontRear(Queue* mainQ){
    if(IsEmpty(mainQ)==1){
        PrintEmpty();
    }
    // front와 rear의 값을 mainQ를 이용해서
    int front = mainQ->front->data;
    int rear = mainQ->rear->data;
    printf("Front: %d, Rear: %d\n", front, rear);
    // 각각 출력
}

// 전체 큐 리스트 출력
void PrintQueue(Queue* mainQ){
    if(IsEmpty(mainQ)==1)
    PrintEmpty();
    // front부터 시작해서 NULL될 때까지
    // 계속 이동하면서 모든 값들을 출력하기
    Node* move = mainQ->front;
    printf("Start -> ");
    for(;1;){
        if (move==NULL){
            printf("End\n");
            return;
        }
        else{
            printf("%d -> ", move->data);
            move = move->next;
        }
    }
}
// =========================================================
int main(){
    Queue q;
    InitQueue(&q);
    Enqueue(&q, 10);
    Enqueue(&q, 10);
    Enqueue(&q, 10);
    PrintQueue(&q);
    PrintFrontRear(&q);
// ----------------------------------------------------

}// ========================================================
/*----------------------------------------------------------
문자열 큐
작업 큐 제작
할일 넣고 할일 빼고
f_gets

<숙제>
1. 큐 하드 시스템 만들기. 메인에는 Queue 하나랑, Start만 허용
2. 문자열 작업 큐 제작 - 시스템
- 넣어야 하는 작업의 개수는 정해지지 않음. - 배열 사용 x
- 넣어야 하는 데이터는 int가 아닌, 최대 100글자의 문자열
    Node의 int data가 아닌 다른 걸 넣어야 한다.
- 필수 구현 기능은 아래와 같음
    1. 작업 추가하기 - 무슨 작업 넣을지 키보드로 입력
                        최근에 추가한 작업은 가장 마지막에 완료
    2. 작업 완료하기 - 가장 과거에 넣었던 작업을 출력 후 삭제
    3. 작업 목록 확인하기 - 해야 하는 순서대로 넘버링해서(1,2,3)
                            한 줄당 한 개의 작업목록이 나오게
    4. 엎어버리기 - 모든 작업목록을 삭제 후 "아 몰라 안해" 출력
- 메모리 누수 조심하기!
- 그 외 더 넣고 싶은 기능 있으면 넣기. 가능하면 궁금하면 연락주세용
----------------------------------------------------------*/