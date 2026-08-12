#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
// =========================================================
// < 구조체 자리 >
// =========================================================
int Fact(int num){
    // 5 x 5-1 -> 4* 4-1 -> 3* 3-1 .... 1 -> 1
    if(num < 1){
        return 1;
    }
    else{
       printf("Num %d\n", num);
        return num*Fact(num-1);
    }
}

int Fibo(int num){
    if (num<=2){
        return 1;
    }
    else{
        return Fibo(num-1)+Fibo(num-2);
    }
}

int Fimo(int num){
    if (num<=3){
        return 1;
    }
    else{
        return Fimo(num-1)+Fimo(num-2)+Fimo(num-3);
    }
}

void Reverse(int num){
    if(num==0) return;
    else{
        printf("%d", num%10);
        Reverse(num/10);
    }
}

// 문자 뒤집기
// Hello World -> dlroW olleH
void ReverseString(char str[]){
    if (str[0] == '\0'){
        // 마지막 글자. 출력하고 끝내면 됨
        printf("\n");
        return;
    }
    else{
        ReverseString(str+1);
        printf("%c", str[0]);
    }
}

// 진법 변환하기 10->2
void Format10_2(int num){ //19
    int mock = num/2; //9
    int nam = num%2; //1

    if(mock==0){
        printf("%d", nam);
        return;
    }
    // 아직 더 나눌 게 있단 소리
    Format10_2(mock);
    printf("%d", nam);
}

int Format2_10(int num){
    static int base = 1;
    int mock = num/10;
    int nam = (num%10) * base;
    base *=2;
    // 내가 만약 마지막 숫자인가?
    if(mock==0){
        return nam;
    }
    // 아니다.
    return nam + Format2_10(mock);
}

int Sum(int num){
    if (num<1){
        return 0;
    }
    else{
        return num + Sum(num-1);
    }
}

// =========================================================
// < 함수 자리 >
// =========================================================

// =========================================================
int main(){
    srand(time(NULL));
    printf("Fact(5) : %d\n", Fact(5));
    printf("\n");
    // ----------------------------------------------------
    printf("Fibo(5), %d\n", Fibo(5));
    printf("Fimo(8), %d\n", Fimo(8));
    Reverse(12345678);

    ReverseString("Hello World\n");
    printf("\n");
    Format10_2(19);
    printf("%d\n",  Format2_10(10011));
    printf("%d\n", Sum(5));
}// ========================================================
/*----------------------------------------------------------

----------------------------------------------------------*/