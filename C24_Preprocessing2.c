#include <stdio.h>
#define RELEASE

int main(){
    #ifdef DEBUG
        printf("[DEBUG] Activation\n");
    #endif
    for(int i=0; i<9; i++){
        #ifdef DEBUG
            printf("i:%d, val:%d\n",i, i+1);
        #else
            printf("%d ", i+1);
        #endif
    }
}