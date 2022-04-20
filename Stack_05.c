// 동적 배열 스택 프로그램

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct{
    element* data; // data는 포인터로 정의된다.
    int capacity; // 현재 크기
    int top;
} StackType;

// 스택 생성 함수
void init_Stack(StackType* s){
    s->top = -1;
    s->capacity = 100;
    s->data = (element*) malloc(sizeof(element));
}

// 공백 상태 검출 함수
int is_Empty(StackType* s){
    return (s->top == -1);
}

// 포화 상태 검출 함수
int is_Full(StackType* s){
    return (s->data[s->top] == (s->capacity - 1));
}

// 삽입 함수
void push(StackType* s, element item){
    if (is_Full(s)){
        s->capacity *= 2;
        s->data = (element*) realloc(s->data, sizeof(element) * s->capacity);
    }
    s->data[++(s->top)] = item;
}

// 삭제 함수
int pop(StackType* s){
    if (is_Empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

int main(void){
    StackType s;
    init_Stack(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    free(s.data);
    return 0;
}