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
typedef struct Queue{
    Node* front; // 맨 앞, 출력할 놈 -> Dequeue
    Node* rear; // 맨 뒤, 데이터 여기까지 -> Enqueue
    // 큐가 비어있다? -> rear가 NULL -> front도 NULL
}Queue;
// =========================================================
// < 함수 자리 >
// =========================================================
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

void Dequeue(Queue* mainQ){

    // 비어있으면 Empty를 출력.
    if(mainQ->front==NULL && mainQ->rear==NULL){
        printf("[System] Empty\n");
        return;
    }
    else{
        Node* temp = mainQ->front;
        // 1. 백업하기
        mainQ->front=temp;
        mainQ->rear=temp;
        // 2. front를 next로 옮기기
        mainQ->front->next=temp;
        // 3. temp를 이용해서 free하기
        // 4. front가 NULL이 되었다? -> 아무것도 x
        // rear도 NULL로 만들기
        // 5. 백업한 데이터를 출력하기
    }

}
// =========================================================
int main(){
    Queue q;
    InitQueue(&q);
// ----------------------------------------------------

}// ========================================================
/*----------------------------------------------------------
문자열 큐
작업 큐 제작
할일 넣고 할일 빼고
f_gets
----------------------------------------------------------*/