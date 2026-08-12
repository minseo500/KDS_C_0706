// CDS01_List.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
// =======================================================
// < 구 조 체 >
// =======================================================
typedef struct Node{ // 나 자신의 자료형 사용하기에...
    int data;
    struct Node* next; // 또다른 내 자료형의 주소 저장
}Node;
// =======================================================
// < 전 역 함 수 >
// =======================================================

// 🎲 새로운 노드를 만드는 + 리턴 함수 🎲
Node* CreateNode(int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    // 안전장치 생략
    temp->data = data;
    temp->next = NULL;
}

// 🥱 모든 요소를 출력하기 + 원본 변경 안함 🥱
void PrintNode(Node* start){
    Node* temp = start;
    printf("Start->");
    for(; temp!=NULL ;){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("End\n");
    // Start->100->200->300->End
}

// 🥰 새로운 노드를 맨 앞에 삽입하는 함수 😘
void InsertNodeFront(Node** mainHead, 
                      int   data){
    Node* temp = CreateNode(data);
    temp->next = *mainHead;
    *mainHead = temp;
}

// 😪 새로운 노드를 맨 "뒤"에 삽입하는 함수😪
void InsertNodeBack(Node** mainHead,int data){
    Node* temp = CreateNode(data);
    if(*mainHead == NULL){
        // 진짜 아무것도 없는 상황. 넣으면 끄읏
        // 1. InsertNodeFront 호출
        // InsertNodeBack(mainHead, data);
        // 2. 맨 앞에 새 노드 삽입(노드필요)
        *mainHead = temp;
        return; // 종료.
    }
    // 만약, main의 head가 비어있지 않은 경우
    // 진짜 맨 뒤를 찾아야 함.(Next가 NULL인놈)
    Node* move = *mainHead;
    for( ; move->next != NULL ; ){
        move = move->next;
    }
    // 마지막위치에 move가 대기하고 있음
    move->next = temp;
}

// =======================================================
int main(){
    // Node* head = NULL;
    // Node A = {100, NULL};
    // Node B = {200, NULL};
    // head = &A;
    // A.next = &B;
    // // -----------------
    // // K로 100과 200을 출력하기
    // printf("%d %d",head->data,
    //                head->next->data );

    // Node* head = NULL;
    // head = CreateNode(100);
    // printf("Head->%d\n",head->data);
    // head->next = CreateNode(200);
    // head->next->next = CreateNode(300);
    // head->next->next->next = CreateNode(400);
    // head->next->next->next->next = CreateNode(500);
    // head->next->next->next->next->next = CreateNode(600);
    // head->next->next->next->next->next->next = CreateNode(700);
    // head->next->next->next->next->next->next->next = CreateNode(800);
    // head->next->next->next->next->next->next->next->next = CreateNode(900);
    // 그 이후로도 400 500 600... 900까지
    // 새로운 놈들을 계속 연결하세요.
    //💀💀💀💀💀💀 이건좀 아니잖아!!@!! 💀💀💀💀💀💀
    
    // 😎 함수를 이용해서 head에 새로운 요소 붙이기
    Node* head = NULL;
    for(int i=0; i<3; i++){
        InsertNodeFront(&head, (i+1)*100 );
        InsertNodeBack( &head, (i+1)*100 );
        PrintNode(head);
    }

    
    // 100부터 900까지 모든 요소를 출력하세요
    // < 반복문 이용하기 > -> Next자리가 NULL이면 출력하고 끝.
    // Node* move = head;
    // for(;1;){
    //     if(move->next == NULL){
    //         printf("%d\n",move->data);
    //         break;
    //     }else{
    //         printf("%d->", move->data);
    //         move = move->next ;
    //     }
    
    // 😋 함수를 이용해서, 모든 요소 출력하기
    PrintNode(head);
    
    


}// ======================================================
// 시스템 만들기.
// 연결하기, 연결 끊기, 확인하기