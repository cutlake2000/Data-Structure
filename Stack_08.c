// 미로 탐색 프로그램

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAZE_SIZE 6

typedef struct{
    short r;
    short c;
} element;

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

// ===== 스택 코드의 끝 ===== //

element here = { 1, 0 }, entry = { 1, 0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
    { '1', '1', '1', '1', '1', '1' },
    { 'e', '0', '1', '0', '0', '1' },
    { '1', '0', '0', '0', '1', '1' },
    { '1', '0', '1', '0', '1', '1' },
    { '1', '0', '1', '0', '0', 'x' },
    { '1', '1', '1', '1', '1', '1' },
    };

void push_loc(StackType* s, int r, int c){
    if (r < 0 || c < 0) return;
    if (maze[r][c] != '1' && maze[r][c] != '.') {
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]){
    printf("\n");
    for (int r = 0; r < MAZE_SIZE; r++) {
    for (int c = 0; c < MAZE_SIZE; c++) {
        printf("%c", maze[r][c]);
    }
    printf("\n");
    }
}

int main(void){
    int r, c;
    StackType s;
    
    init_Stack(&s);
    here = entry;
    while (maze[here.r][here.c] != 'x') {
        r = here.r;
        c = here.c;
        maze[r][c] = '.';
        maze_print(maze);
        push_loc(&s, r - 1, c);
        push_loc(&s, r + 1, c);
        push_loc(&s, r, c - 1);
        push_loc(&s, r, c + 1);
        if (is_Empty(&s)) {
            printf("실패\n");
        }
        else here = pop(&s);
    }
    printf("성공\n");
    return 0;
}
