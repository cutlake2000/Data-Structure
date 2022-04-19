#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;
#define MAX_STACK_SIZE 100

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
        return;
    }
    else s->data[++(s->top)] = item;
}

// 삭제 함수
element pop(StackType* s){
    if (is_Empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[s->top];
}

// 피크 함수
element peek(StackType* s){
    if (is_Empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[s->top];
}

// ===== 스택 코드의 끝 ===== //

int prec(char op){
    switch (op){
        case '(' : case ')' : return 0;
        case '+' : case '-' : return 1;
        case '*' : case '/' : return 2;
    }
    return -1;
}

// 중위 표기 수식 -> 후위 표기 수식
void infix_to_postfix(const char exp[]){
    int i = 0;
    char ch, top_op;
    int len = strlen(exp);
    StackType s;

    init_Stack(&s); // 스택 초기화
    for (i = 0 ; i < len ; i++){
        ch = exp[i];
        switch (ch){
            case '+' : case '-' : case '*' : case '/' :
            while (!is_Empty(&s) && (prec(ch) <= prec(peek(&s))))
                printf("%c", pop(&s));
            push(&s, ch);
        }
    }

}