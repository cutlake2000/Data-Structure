// 하노이 탑

#include <stdio.h>

void hanoi(int n, char from, char tmp, char to){
    if (n == 1) printf("1번을 %c에서 %c으로 이동.\n", from, to);
    else{
        hanoi(n - 1, from, to, tmp);
        printf("%d번을 %c에서 %c으로 이동.\n", n, from, to);
        hanoi(n - 1, tmp, from, to);
    }
}

int main(){
    hanoi(4, 'A', 'B', 'C');
    return 0;
}