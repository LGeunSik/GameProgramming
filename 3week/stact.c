#include <stdio.h>
#include <stdlib.h>

#define MAX 10  // 스택 크기

typedef struct {
    int data[MAX]; // 스택 데이터 저장
    int top;       // 스택의 현재 위치 (맨 위 인덱스)
} Stack;

// 스택 초기화
void init(Stack *s) {
    s->top = -1;
}

// 스택이 비었는지 확인
int isEmpty(Stack *s) {
    return (s->top == -1);
}

// 스택이 가득 찼는지 확인
int isFull(Stack *s) {
    return (s->top == MAX - 1);
}

// push: 스택에 데이터 삽입
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("스택이 가득 찼습니다! push 불가\n");
        return;
    }
    s->data[++(s->top)] = value;
    printf("push: %d\n", value);
}

// pop: 스택에서 데이터 꺼내기
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("스택이 비었습니다! pop 불가\n");
        return -1;  // 오류값
    }
    int value = s->data[(s->top)--];
    printf("pop: %d\n", value);
    return value;
}

// 스택 출력 (디버깅용)
void printStack(Stack *s) {
    printf("현재 스택: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

// 메인 함수 (테스트)
int main() {
    Stack s;
    init(&s);

    // push 테스트
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printStack(&s);

    // pop 테스트
    pop(&s);
    printStack(&s);

    pop(&s);
    pop(&s);
    pop(&s); // 빈 스택에서 pop 시도

    return 0;
}
