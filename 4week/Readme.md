4주차 요약입니다
📘 Game Programming with C (경성대학교)
📌 주요 학습 주제

숫자의 변환과 표현

재귀적 호출 활용

디지털 숫자 출력

슬라이드 바 (수평/수직) 구현

도형의 연속적인 이동과 회전

🔢 숫자의 변환과 표현
문자열 처리

입력된 숫자를 문자열로 저장 → 각 자리 분리 출력

strlen() 함수 활용

char number[20];
scanf("%s", number);
for(int i=0; i<strlen(number); i++) {
    printf("%c\n", number[i]);
}

정수 처리

나눗셈 /, 나머지 % 연산 활용

log10(), pow() 함수로 자리수 계산

void serial_number(long number) {
    int length = (int)(log10(number)+1);
    for(int i=length; i>=1; i--) {
        int num = number / (long)pow(10, i-1);
        printf("%d\n", num);
        number -= num * (long)pow(10, i-1);
    }
}

🔁 재귀적 호출

자기 자신을 호출해 자리수 분리 출력 가능

void serial_number(long number) {
    if(number > 0) {
        serial_number(number/10);
        printf("%ld\n", number%10);
    }
}

🔟 디지털 숫자 출력

0~9까지 숫자를 **배열 패턴(1/0)**으로 정의

1 → ■, 0 → 공백 출력

void digit_print(int dim[], int line) {
    for(int i=line*4; i<=line*4+3; i++)
        printf(dim[i]==1 ? "■" : "  ");
}


입력된 숫자 → 각 line별 출력 (number_check 함수에서 재귀 호출)

🎚 슬라이드 바 구현

수평/수직 슬라이드바 출력 + 제어

draw_rectangle()으로 bar 그리기

방향키 입력 (getch()) 처리

←/→ : 수평 이동

↑/↓ : 수직 이동

void move_arrow_key(char key, int *x, int *y, int xmax, int ymax) {
    switch(key) {
        case 72: (*y)--; if(*y<1) *y=1; break; // 위
        case 80: (*y)++; if(*y>ymax) *y=ymax; break; // 아래
        case 75: (*x)--; if(*x<1) *x=1; break; // 왼쪽
        case 77: (*x)++; if(*x>xmax) *x=xmax; break; // 오른쪽
    }
}

⬛ 도형 이동 & 회전

도형을 2차원 배열(3x3)로 표현

방향키 → 상하좌우 이동

스페이스 키 → 시계방향 90도 회전

void rotation_right(int m[][3]) {
    int temp[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            temp[j][2-i] = m[i][j];
    memcpy(m, temp, sizeof(temp));
}

📖 Reference

명품 C언어 프로젝트, 생능출판, 안기수
