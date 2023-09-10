// Trying functions
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum (int x, int y);

int main (){
    int adds = sum(4, 6);
    printf("Sum is %d", adds);


    return 0;
}


int sum(int x, int y){
    int sum;

    printf("Enter two numbers: ");
    //scanf("%d %d", &a, &b);
    sum = x + y;
    //printf("Sum is %d", sum);
    return sum;
}