// 구조체 배열을 사용하여 스택 만들기

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct{
    int student_Num;
    char name[MAX_STRING];
    char address[MAX_STRING];
} element;

element stack[MAX_STACK_SIZE];
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
    else stack[++top] = item;
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
    element ie = {20190001, "Hong", "Gachon Univ."};
    element oe;

    push(ie);
    oe = pop();

    printf("학번 : %d\n", oe.student_Num);
    printf("이름 : %s\n", oe.name);
    printf("학교 : %s\n", oe.address);
    return 0;
}