// 일반적인 배열 스택 프로그램
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct{
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

// 스택 초기화 함수
void init_Stack(StackType* s){
    s->top = -1;
}

// 공백 상태 검출 함수
int is_Empty(StackType* s){
    return (s->top == -1);
}

// 포화 상태 검출 함수
int is_Full(StackType* s){
    return (s->top == (MAX_STACK_SIZE - 1));
}

// 삽입 함수
void push(StackType* s, element item){
    if (is_Full(s)){
        fprintf(stderr, "스택 포화 에러\n");
        exit(1);
    }
    else s->data[++(s->top)] = item;
}

// 삭제 함수
element pop(StackType* s){
    if (is_Empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

// 피크 함수
element peek(StackType* s){
    if (is_Empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[s->top];
}

// ===== 스택 코드 끝 ===== //

int main(void){
    StackType s;

    init_Stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
}