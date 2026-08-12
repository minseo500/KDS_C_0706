// C19_Struct.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
// =========================================================
// < 구조체 자리 >
// =========================================================
struct Array{
    int ary[10];
    int size;
};

// < 실습 >
//   구조체를 만들고, 안에 데이터 넣는놈 만들고, 출력하는놈 만들고
//   이후, 메인에서 만들고 세팅하고 출력하고 진행
// ------------------------------------------------
// Weapon > int power, int price, weaponType int
struct Weapon{
    int power;
    int price;
    int weaponType;
};
// Armor > int defense, int price, int armorType
// InitArmor, PrintArmor
struct Armor{
    int defense;
    int price;
    int armorType;
};

// Monster > int power, int money
// InitMonster, PrintMonster
struct Monster{
    int power;
    int money;
};

// Player > char name[100]=입력! int level, int power
// InitPlayer, PrintPlayer
struct Player{
    char name[100];
    int level;
    int power;
};

// struct Gun은 아래와 같이 구현
// int bullet[30]
// int currentBullet;
// int maxBullet;
// 이후 아래 함수 구현
// InitGun > Bullet의 모든 배열에 1채우기(1있음0없음)
//         > currentBullet을 30, maxBullet을 30
// Reload  > 모든 Bullet의 모든 배열에 1다시 채우기
//         > currentBullet을 30으로 변경 + 효과 추가 선택사항.
// Fire    > currentBullet이 0만 아니라면, 배열요소중 하나를 0으로
//         > currentBullet을 1감소시키고, "빵"출력
//         > 이후 currentBullet 이 만약 0이 됐다면, Reload호출
// BulletStatus > 현재 남은 총알 개수 리턴 및 출력
struct Gun{
    int bullet[30];
    int currentBullet;
    int maxBullet;
};
void InitGun(struct Gun* g){
    (*g).currentBullet = 30; // 29 28 27 26.. -> 29 28 27 26
    (*g).maxBullet = 30; // 절대 변하지 않음.

    for(int i=0; i<(*g).maxBullet; i++){
        // g의 bullet에 모든 요소 1로 만들기
        (*g).bullet[i] = 1;
    }
}
void Reload(struct Gun* g){ // 원본 요소를 바꿔야하니까 *
    // InitGun와 똑같지만, 효과를 주기 위해 별도로 준비함.
    printf("[RELOAD] "); // 효과
    int cur = (*g).currentBullet;
    for(int i=cur; i<(*g).maxBullet; i++){
        // g의 bullet에 모든 요소 1로 만들기
        (*g).bullet[i] = 1;
        Sleep(100); // 효과 추가
        printf("> ");
    }
    printf("\n");
    (*g).currentBullet = 30;
}
void Fire(struct Gun* g){ // currentBullet조정해야해서 *
    printf("Boom!!\n");

    (*g).bullet[ (*g).currentBullet-1 ] = 0;

    (*g).currentBullet--;
    if( (*g).currentBullet ==0 ){
        // 다시 초기화
        Reload(g);
    }
}
int BulletStatus(struct Gun g){ // 내용변경 안하니 * 필없음
    printf("Current Bullet : %d\n", g.currentBullet);
    printf("[Capacity] : ");
    for(int i=0; i<g.maxBullet; i++){
        printf("%d",g.bullet[i]);
    }   
    printf("\n");
    return g.currentBullet;
}



// =========================================================
// < 함수 자리 >
// =========================================================
void PrintAry(int* ary, int size){
    for(int i=0; i<size; i++){
        printf("%d ", ary[i]);
    }   printf("\n");
}
void PrintArray(struct Array a){ // 값 복사
    for(int i=0; i<a.size; i++){
        printf("%d ", a.ary[i]);
    }   printf("\n");
}
void ResizeArray(struct Array* a, int size){
    // 안전장치 제외. 현 size보다 큰 sizeㄴ느 거부
    (*a).size = size;
    // 참 뭣같은데, .이 *보다 우선순위 높음
}
// -----------------------------------------
void InitWeapon(struct Weapon* w,int seed){
    int random = rand(); // 0~32767
    int power = 0;
    int weaponType = rand()%4 + 1; // 1~4
    int price = rand()%1000+ 100;
    if(random%seed == 0){
        // 당첨!
        power = 1000;
        price -= 300;
        if(price<0){
            price=0;
        }
    }else{
        // 일반
        power = 500;
    }
    // ----------------------
    (*w).power = power;
    (*w).price = price;
    (*w).weaponType = weaponType;
}
void PrintWeapon(struct Weapon w){
    printf("---------------\n");
    printf("Power      : %d\n", w.power);
    printf("price      : %d\n", w.price);
    printf("weaponType : %d\n", w.weaponType);
    printf("---------------\n");
}

// InitArmor, PrintArmor
void InitArmor(struct Armor* a,int seed){
    int armorType = rand()%4+1;
    int defense = rand()%30+10;
    int price = rand()%1000+300;
    if(rand()%seed == 0){
        defense += 10;
        price -= 100;
    }
    (*a).price = price;
    (*a).defense = defense;
    (*a).armorType = armorType;
}
void PrintArmor(struct Armor a){
    printf("defense   : %d\n", a.defense)   ;
    printf("price     : %d\n", a.price)   ;
    printf("armorType : %d\n", a.armorType)   ;
    printf("--------------\n");
}
// InitMonster, PrintMonster

// InitPlayer, PrintPlayer
void InitPlayer(struct Player* p){
    int flag = 0;
    if(flag==1){
        // 이름 입력받기.
        printf("Input Name : ");
        scanf("%s", (*p).name );
    }else{
        // 이름 입력 안받고, 고정값 삽입
        strcpy((*p).name, "Guest");
    }
    (*p).level = 1 ;
    (*p).power = 10;
}
void PrintPlayer(struct Player p){
    printf("Name  : %s\n", p.name);
    printf("Level : %d\n", p.level);
    printf("Power : %d\n", p.power);
}

// =========================================================
int main(){
    srand(time(NULL));
    // ----------------------------------------------------
    {
        struct Array ary = {{1,2,3,4,5,6,7,8,9,10},10};
    PrintAry(ary.ary, ary.size);
    PrintArray(ary);
    
    ResizeArray(&ary, 8);
    PrintArray(ary);

    ResizeArray(&ary, 3);
    PrintArray(ary);
}
    // ---------------------------------
    {
    struct Weapon sward;
    InitWeapon(&sward, 2);
    PrintWeapon(sward);
    }
    // ---------------------------------
    {
    struct Armor chest;
    InitArmor(&chest, 3);
    PrintArmor(chest);
    }
    // ---------------------------------
    {
    struct Player player1;
    InitPlayer(&player1);
    PrintPlayer(player1);
    }
    // ---------------------------------
    struct Gun glock;
    InitGun(&glock);
    // for(int i=0; i<glock.maxBullet + 10 ; i++){
    //     Fire(&glock);
    //     Sleep(100); // 0.1초
    // }
    // BulletStatus(glock);
    // -------------------------------------------
    // SYSTEM? > 유기적으로 프로그램 사용할 수 있게 UI 구현
    // 시작 진행 종료를 사용자가 모두 컨트롤 할 수 있게
    for(;1;){
        int choice = 0;
        // 1 발사, 2 잔탄확인 3 리로드 4 종료
        printf("Choice Menu(1~4) : ");
        scanf("%d", &choice);
        // ----------------------------------
        if(choice==1){
            Fire(&glock);
        }else if(choice==2){
            BulletStatus(glock);
        }else if(choice==3){
            Reload(&glock);
        }else if(choice==4){
            printf("System Out\n");
            break;
        }else{
            printf("Wrong Number\n");
            continue;
        }
    }



}// ========================================================
/*----------------------------------------------------------
구조체 Struct
 구조체는 본인의 데이터 공간에 여러 변수들을 담을 수 있음
 한번에 관리가 필요한 여러 변수들을 기존에는 따로 사용해야 했는데
  이제는 구조체로 묶어서, 전달도, 관리도 한번에 가능하게 됨
 
  다만, 구조체 안에는 함수를 넣을 수 없으며, 구조체 자체에서
  초기화 값을 설정할 순 없다.
----------------------------------------------------------*/