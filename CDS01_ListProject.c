#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
//==================================================
//<구조체>
//===============================================
typedef struct Node{ // 나 자신의 자료형 사용하기에...
    int data;
    struct Node* next; // 또다른 내 자료형의 주소 저장
} Node;
//==================================================
//<전역함수>
Node* CreateNode(int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    // 안전장치 생략
    temp->data = data;
    temp->next = NULL;
    return temp;
// <새로운 노드를 만드는 + 리턴 함수>
}

// 모든 요소를 출력하기 + 원본 변경 안 함
void PrintNode(Node* start){
    Node* temp = start;
    printf("Start->");
    for(;temp!=NULL;){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("->End\n");
    // Start->100->200->300->End
}

// < 새로운 노드를 맨 앞에 삽입하는 함수 >
void InsertNodeFront(Node** mainHead, int data){
    Node* temp = CreateNode(data);
    temp->next = *mainHead;
    *mainHead = temp;
}

// < 새로운 노드를 맨 "뒤"에 삽입하는 함수 >
void InsertNodeBack(Node** mainHead, int data){
    Node* temp = CreateNode(data);
    if(*mainHead == NULL){
        // 진짜 아무것도 없는 상황. 넣으면 끄읏.
        // 1. InsertNodeFront 호출
        InsertNodeBack(mainHead, data);
        // 2. 맨 앞에 새 노드 삽입(노드필요)
        *mainHead = temp;
        return; // 종료
    }
    // 만약 main의 head가 비어있지 않은 경우
    // 진짜 맨 뒤를 찾아야 함. (Next가 NULL인 놈)
    Node* move = *mainHead;
    for(;move->next != NULL;){
        move = move -> next;
    }
    // 마지막 위치에 move가 대기하고 있음
    move->next = temp;
}

// < 노드의 중간에 때려넣는 함수 >
void InsertNodeMid(Node** mainHead, int data, int position){
    // 1. position이 0이면 => 맨 앞
    if (position==0 || *mainHead == NULL){
        InsertNodeFront(mainHead, data);
        return;
        // 책임회피
    }
    Node* move = *mainHead;
    for(int i=0; i<position-1; i++){
        if (move->next == NULL){
            break;
        }
        move = move->next;
        // move 안에 NULL 있는데, 이동하면?
        // 프로그램이 멈추는 에러 발생
    }
    // 5. 중간에 멈췄다면, 그대로 삽입
    Node* temp = CreateNode(data);
    temp->next = move->next;
    move->next = temp;
    
}

void DeleteNodeKey(Node** mainHead, int target){
    // head가 비어잇으면? 입뺀
    if(*mainHead == NULL){
        printf("강해져서 돌아와라.\n");
        return;
    }
    // 삭제해야 하는 데이터가 첫 노드일 때
    if((*mainHead)->data==target){
        Node* temp = *mainHead; // 삭제할 놈
        *mainHead = (*mainHead)->next;
        free(temp);
        return;
    }
    // 검색해야 함.
    Node* move = *mainHead;
    Node* pred = NULL;
    for(;move!=NULL;){
        if(move->data == target){

            // 데이터를 찾은 경우
            pred->next = move->next;
            free(move);
            printf("Removed\n");
            return;

        }
        // 데이터를 찾지 못한 경우
        pred = move;
        move = move-> next;

    }
    // 그냥 밖으로 나온 경우 -> 찾는 거 없음
    // 삭제할 거 없다고 출력하면 끝.
        printf("No value to delete\n");
        return;
}

// < HW >
void DeleteNodeIndex(){
    
}

// 검색하기 실습
int FindNode(Node* mainHead, int target){
    Node* move = mainHead;
    int cnt=0;
    for(;move!=NULL;){
        if(move->data == target){
            printf("%d의 위치: %d\n", target, cnt);
            return cnt;
        }
        else{
            cnt++;
            move = move -> next;
        }
    }
}

void PrintUI(){
    system("cls");
    printf("====================================================\n");
    printf("1. See List\n");
    printf("2. Put in Front\n");
    printf("3. Put in back\n");
    printf("4. Put in middle\n");
    printf("5. Delete certain value\n");
    printf("6. Search certain value\n");
    printf("-1. End Program\n");
    printf("====================================================\n");
    printf(" > Select wanted Menu: ");

}


int main(){
    Node* head = NULL;
    for(;1;){
        // 1. UI 출력 - 뭐 할래?
        PrintUI();
        // 2. 사용자의 입력에 따른 처리
        int choice;
        scanf("%d", &choice);
        // 4. 반드시 종료하는 기능이 있어야 함.
        if(choice==-1){
            printf("End program\n");
            printf("3 "); Sleep(1000);
            printf("2 "); Sleep(1000);
            printf("1 "); Sleep(1000);
            printf("Bye\n");
            return 0;
        }
        // 3. 이상한 입력은 받지 않게 처리해야 함
        if (choice<1 || choice>6){
            printf("wrong state\n");
            printf("Restart in 3 seconds\n");
            Sleep(3000);
        }

        // 정상 처리 진행

        // 1~6 기능 실행
        if (choice==1){
            PrintNode(head);
            Sleep(3000);
        }
        else if(choice==2){
            printf("< InsertNodeFront >\n");
            printf("Put number data: ");
            int input;
            scanf("%d", &input);
            InsertNodeFront(&head, input);

            printf("New Data Complete\n");
            Sleep(1000);
        }
        else if(choice==3){
            printf("< InsertNodeBack >\n");
            printf("Put number data: ");
            int input;
            scanf("%d", &input);
            InsertNodeBack(&head, input);

            printf("New Data Complete\n");
            Sleep(1000);
            
        }
        else if(choice==4){
            printf("< InsertNodeMid >\n");
            PrintNode(head); // 이거 보고 입력해
            printf("Put number data: ");
            int input;
            scanf("%d", &input);

            printf("Put location data: ");
            int position;
            scanf("%d", &position);
            InsertNodeMid(&head, input, position);

            printf("New Data Complete\n");
            Sleep(1000);
        }
        else if(choice==5){
            printf("< DeleteNode >\n");
            PrintNode(head); // 이거 보고 삭제해

            printf("Put deleting number data(only first data): ");
            int input;
            scanf("%d", &input);

            DeleteNodeKey(&head, input);

            PrintNode(head);
            printf("%d data deleted.\n", input);
            Sleep(1000);
        }
        else if(choice==6){
            printf("< FindNode >\n");
            PrintNode(head); 

            printf("Find data: ");
            int input;
            scanf("%d", &input);

            FindNode(head, input);
            Sleep(1000);
        }
    }


}

/*
시스템(System)
시작부터 종료까지 유기적으로 연결되는 구조를 제작
하나의 전체 프로그램을 만드는 개념
사용자의 입력에 따른 UI/UX도 고려해서 화면을 출력해야 함
다양한 안전장치들도 구현해야 함

<아쉬운 점>
1. 다양한 안전장치를 만들지 못한 것.
2. 파일 입출력으로 프로그램 종료 시 현 상태를 저장하는 기능을 구현하지 못한 것.
3. 리스트를 뒤집는 기능이 없는 것
4. 맨 앞의 값을 추출해서 돌려주고, 맨 뒤의 값을 추출해서 돌려주는 함수가 없다는 것.
5. CMD의 한글 문제를 해결하지 못함...ㅠ

*/