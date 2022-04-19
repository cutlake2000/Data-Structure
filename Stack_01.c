// 전역 변수로 구현하는 방법

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element; // 데이터의 자료형
#define MAX_STACK_SIZE 100 // 스택의 최대 크기
element stack[MAX_STACK_SIZE]; // 1차원 배열
int top = -1;

// 공백 상태 검출 함수
int is_Empty(){
    return (top == -1);
}

// 포화 상태 검출 함수
int is_Full(){
    return (top == (MAX_STACK_SIZE - 1));
}

// 삽입 함수
void push(element item){
    if (is_Full()){
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else{
        stack[++top] = item;
    }
}

// 삭제 함수
element pop(){
    if (is_Empty()){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top--];
}

// 피크 함수
element peek(){
    if (is_Empty()){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top];
}

int main(void){
    push(1);
}