#include <stdio.h>

int fibo_cal(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    
    int num01 = 0;
    int num02 = 1;
    int result = 0;

    for (int i = 2 ; i <= n ; i++){
        result = num01 + num02;
        num01 = num02;
        num02 = result;
    }

    return result;
}

int main(){
    int input, result;
    input = result = 0;

    printf("Insert Interger : ");
    scanf("%d", &input);

    result = fibo_cal(input);
    printf("\nThe result is : %d\n", result);
}