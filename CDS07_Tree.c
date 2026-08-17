#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
//<전역변수>
int cnt=0; // 트리 구조에서 검색 시에만 사용할 것.
int find=0; // 1이면 뭔가 찾음. 0이면 못 찾음 검색시에만 사용
int flag=0;
// =========================================================
// < 구조체 자리 >
// =========================================================
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    int index;
}Node;
// =========================================================
// < 함수 자리 >
// =========================================================
// 새로운 노드 만들어서 넘겨주기
Node* CreateNode(int data){
    static int index=0;
    // 하나의 노드를 만들어서 주소를 리턴
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    temp->index=++index;
    return temp;
}

// 전위 순회로 모든 노드 출력하기->나중에 검색
void PrintPre(Node* current){
    //1. 내가 비어있으면 끝나야 함
    if(current==NULL) return;
    // 원하는 값인지 아닌지를 검색해야 함
    // + 빈 게 아니라면, 전역변수 cnt를 +1!

    //2. 안 비어 있으면 전위순회니까 출력 먼저
    printf("%d[%d] - ", current->data, current->index);
    //3. 이후 왼쪽으로 이동하는데, 다시 함수호출
    PrintPre(current->left);
    //4. 이후 오른쪽 이동, 다시 함수 호출
    PrintPre(current->right);
}

// 중위검색
void PrintIn(Node* current){
    //1. 내가 비어있으면 끝나야 함
    if(current==NULL) return;
    //3. 이후 왼쪽으로 이동하는데, 다시 함수호출
    PrintIn(current->left);
    //2. 안 비어 있으면 전위순회니까 출력 먼저
    printf("%d[%d] - ", current->data, current->index);
    //4. 이후 오른쪽 이동, 다시 함수 호출
    PrintIn(current->right);
}

// 후위검색
void PrintPost(Node* current){
    //1. 내가 비어있으면 끝나야 함
    if(current==NULL) return;
    //3. 이후 왼쪽으로 이동하는데, 다시 함수호출
    PrintPost(current->left);
    //4. 이후 오른쪽 이동, 다시 함수 호출
    PrintPost(current->right);
    //2. 안 비어 있으면 전위순회니까 출력 먼저
    printf("%d[%d] - ", current->data, current->index);
}

// Search 전용, 전위, 중위, 후위 함수 만들기->카운팅 포함
void SearchPre(Node* current, int target){
    // 만약에 원하는 값을 찾았다? -> index 알려주는것.
    // + 일괄정지->모두가 볼 수 있는 스위치(flag)

    if(current==NULL) return;

    // 안쪽으로 들어왔다? - 1단계를 지났다는 뜻.
    cnt++;
    if(current->data==target){
        printf("Current Target %d Index\n", current->index);
        find=1; // 외부의 Search 함수가 알 수 있게
        return;
    }
    SearchPre(current->left, target);
    SearchPre(current->right, target);
}
// Pre / In / Post 중 선택해서 원하는 값 있는지 검색하기->index
void Search(Node* start, int target){
    //1. 어떤 방식으로 검색할지 물어보기->귀찮으니 결정
    int searchType = 1; // 1Pre 2In 3Post
    //2. 몇 번만에 찾았는지도 하고 싶으면...->전역변수
    // 2. 검색 구현
    // 단, 전역함수인 cnt와 find를 반드시 초기화해줘야 함
    cnt = 0;
    find = 0;
    if(searchType==1);{
        SearchPre(start,target); // index 위치는 얘가 알려줌
        // 몇 번만에 찾았는지, 못 찾았는지 구현
    if(find==0){
            // 못 찾음....->몇 번만에 못 찾았는지 알려주기
            printf("Target Can't Find.\n");
            printf("Try Cnt: %d\n", cnt);
            printf("-------------------------\n");
        }
        else{
            // 찾은 경우임. 인덱스는 이미 출력되었음
            printf("> Try Cnt: %d\n", cnt);
        }
    }
    cnt=0;
    find=0;
    //else if(searchType==2){}
    //else if(searchType==3){}
    //else {} 
}

// 모든 트리를 초기화시키는 함수
void Free(Node* current){
    if(current==NULL) return;
    Free(current->left);
    Free(current->right);
    free(current);
}

// <이진 탐색 트리(Binary Search Tree)>
// 트리를 효율적으로 관리하기 위한 알고리즘
// 수동으로 트리에 데이터를 넣을 경우, 매우 비효율적임
void InsertBst(Node** mainHead, int data){
    // 1. 비어있으면 거기가 내 자리(메인의 head일 수도 있음)
    if(*mainHead==NULL){
        *mainHead = CreateNode(data);
        return;
    }
    // 2. 비어있지 않다면, 나(data)보다 비교하는 놈이 더 크면, 나 왼쪽
    if(data<(*mainHead)->data){
        // 내가 비교하는 놈보다 작은 상황
        // &((*mainHead))->left Node**
        InsertBst(&((*mainHead)->left), data);
        // 3. 나(data)보다 비교하는 놈이 작으면, 나 오른쪽
    } else if(data>(*mainHead)->data){
        InsertBst(&((*mainHead)->right), data);
    }
    // 4. 근데 같으면 무시.
    else{
        printf("Already Exist!\n");
    }
}


// =========================================================
int main(){
    Node* head = NULL;
//    head=CreateNode(10);
  //  head->left=CreateNode(5);
    //head->right=CreateNode(15);
    //head->left->left=CreateNode(2);
    //head->left->right=CreateNode(7);
    //head->right->left=CreateNode(12);
    //head->right->right=CreateNode(18);
    //PrintPre(head);
    //printf("\n---------------\n");
    //PrintIn(head);
    //printf("\n---------------\n");
    //PrintPost(head);

    // ----------------------------------------------------
    // 이진탐색트리 코드 완성 후, 진행
    // 10 5 15 2 7 12 18
    int ary[] = {10, 5, 15, 2, 7, 12, 18};
    for(int i=0; i<sizeof(ary)/4; i++){
        InsertBst(&head, ary[i]);
    }
    
    Search(head, 18);
    printf("\n\n");
    PrintPre(head);
}// ========================================================
/*----------------------------------------------------------
6일차 숙제
이진탐색트리를 이용한 트리 관리 시스템 만들기
아래 기능 포함
1. 트리 출력
-> 1. 전위 2. 중위 3. 후위 물어본 후 출력
    +) 만약 트리가 처음부터 비어있으면 아예 물어보지도 말기
2. 데이터 삽입
-> 데이터 입력받고 BST알고리즘을 이용해서 추가하기
3. 트리 초기화하기
4. 검색하기
-> 1. 전위 2. 중위 3. 후위 물어본 후 Search 진행
5. 종료하기
----------------------------------------------------------*/