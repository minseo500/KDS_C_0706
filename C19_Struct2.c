// C19_Struct2.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
// =========================================================
// < 구조체 자리 >
// =========================================================
struct ABCD{
    int a;    int b;
    int c;    int d;
};
struct X{
    int x1;    int x2;
    int x3;    int x4;
    int x5;    int x6;
    int x7;    int x8;
    int x9;    int x10;
};
struct Ary{
    int ary1[10]; 
    int ary2[20]; 
    int ary3[30]; 
    int ary4[40]; 
    int ary5[50];
    int size[5 ];
};
// =========================================================
// < 함수 자리 >
// =========================================================
void PrintABCD(int a,int b,int c,int d){
    printf("%d \n",a); printf("%d \n",b);
    printf("%d \n",c); printf("%d \n",d);
}
void PrintX(int x1, int x2, int x3, int x4, int x5,
            int x6, int x7, int x8, int x9, int x10){
    printf("%d \n",x1);
    printf("%d \n",x2);
    printf("%d \n",x3);
    printf("%d \n",x4);
    printf("%d \n",x5);
    printf("%d \n",x6);
    printf("%d \n",x7);
    printf("%d \n",x8);
    printf("%d \n",x9);
    printf("%d \n",x10);
}
void PrintX(struct X x){
    printf("%d \n",x.x1 );    printf("%d \n",x.x2 );
    printf("%d \n",x.x3 );    printf("%d \n",x.x4 );
    printf("%d \n",x.x5 );    printf("%d \n",x.x6 );
    printf("%d \n",x.x7 );    printf("%d \n",x.x8 );
    printf("%d \n",x.x9 );    printf("%d \n",x.x10);
}// =========================================================
int main(){
    srand(time(NULL));
    // ----------------------------------------------------
    int a=10, b=20, c=30, d=40;
    PrintABCD(a,b,c,d);
    int aa=10, bb=20, cc=30, dd=40;
    int x1=10, x2=20, x3=30, x4=40, x5=50, x6=60, x7=70,x8=80,x9=90, x10=100;
    // int y1=10, y2=20, y3=30, y4=40, y5=50, x6=60, x7=70,x8=80,x9=90, x10=100;
    PrintX(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10);
    // ----------------------------------
    struct ABCD abcd1;
    struct ABCD abcd2;
    struct ABCD abcd3;
    struct ABCD abcd4;
    struct X X1; // 10개
    struct X X2; // 10개
    struct X X3; // 10개
    struct X X4; // 10개
    struct X X5; // 10개
    struct X X6; // 10개
    // -------------------------------------
    int  ary[10] = {0};
    int ary2[20] = {0};
    int ary3[30] = {0};
    int ary4[40] = {0};
    int ary5[50] = {0};
    PrintAry(ary,10,ary2,20,ary3,30,ary4,40,ary5,50);
}// ========================================================
/*----------------------------------------------------------
< 구조체 >
왜 써야해? -> 안써도됨. 여러 변수를 묶어서 관리할때 씀
    안쓰고 싶다면 계속, 따로따로 만들어서 따로 전달
----------------------------------------------------------*/