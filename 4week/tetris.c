#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

// 키 매핑
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32
#define P 80
#define p 112
#define ESC 27

// 블록/맵 상태
#define EMPTY 0
#define WALL 1
#define CEILLING -1
#define ACTIVE_BLOCK -2
#define INACTIVE_BLOCK 2

// 게임판 크기
#define MAIN_X 11
#define MAIN_Y 23
#define MAIN_X_ADJ 3
#define MAIN_Y_ADJ 1
#define STATUS_X_ADJ MAIN_X_ADJ + MAIN_X + 1

// 전역 변수
int main_org[MAIN_Y][MAIN_X];
int main_cpy[MAIN_Y][MAIN_X];

int bx, by;              // 블록 위치
int b_type, b_rotation;  // 현재 블록
int b_type_next;         // 다음 블록

int key;
int score, level, cnt, speed;
int crush_on, new_block_on, space_key_on;

// 블록 정의 [7종류][4회전][4행][4열]
int blocks[7][4][4][4] = {
    // O
    {{{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}}},
    // I
    {{{0,0,0,0},{1,1,1,1},{0,0,0,0},{0,0,0,0}},
     {{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}},
     {{0,0,0,0},{1,1,1,1},{0,0,0,0},{0,0,0,0}},
     {{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}}},
    // S
    {{{0,0,0,0},{0,1,1,0},{1,1,0,0},{0,0,0,0}},
     {{0,0,0,0},{1,0,0,0},{1,1,0,0},{0,1,0,0}},
     {{0,0,0,0},{0,1,1,0},{1,1,0,0},{0,0,0,0}},
     {{0,0,0,0},{1,0,0,0},{1,1,0,0},{0,1,0,0}}},
    // Z
    {{{0,0,0,0},{1,1,0,0},{0,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,1,0,0},{1,1,0,0},{1,0,0,0}},
     {{0,0,0,0},{1,1,0,0},{0,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,1,0,0},{1,1,0,0},{1,0,0,0}}},
    // T
    {{{0,0,0,0},{1,1,1,0},{0,1,0,0},{0,0,0,0}},
     {{0,0,0,0},{0,1,0,0},{1,1,0,0},{0,1,0,0}},
     {{0,0,0,0},{0,1,0,0},{1,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,1,0,0},{0,1,1,0},{0,1,0,0}}},
    // L
    {{{0,0,0,0},{1,1,1,0},{1,0,0,0},{0,0,0,0}},
     {{0,0,0,0},{1,1,0,0},{0,1,0,0},{0,1,0,0}},
     {{0,0,0,0},{0,0,1,0},{1,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,1,0,0},{0,1,0,0},{0,1,1,0}}},
    // J
    {{{0,0,0,0},{1,1,1,0},{0,0,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,1,0,0},{0,1,0,0},{1,1,0,0}},
     {{0,0,0,0},{1,0,0,0},{1,1,1,0},{0,0,0,0}},
     {{0,0,0,0},{0,1,1,0},{0,1,0,0},{0,1,0,0}}}
};

// 함수 선언
void gotoxy(int x, int y);
void reset_main(void);
void reset_main_cpy(void);
void draw_main(void);
void new_block(void);
int check_crush(int bx, int by, int rotation);
void move_block(int dir);
void drop_block(void);
void check_line(void);

// 콘솔 커서 이동
void gotoxy(int x, int y) {
    COORD pos = {2 * x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 게임판 초기화
void reset_main(void) {
    int i, j;
    for (i=0;i<MAIN_Y;i++){
        for (j=0;j<MAIN_X;j++){
            main_org[i][j] = EMPTY;
            main_cpy[i][j] = 100;
        }
    }
    for (j=1;j<MAIN_X;j++) main_org[3][j] = CEILLING;
    for (i=1;i<MAIN_Y-1;i++){ main_org[i][0]=WALL; main_org[i][MAIN_X-1]=WALL; }
    for (j=0;j<MAIN_X;j++) main_org[MAIN_Y-1][j]=WALL;
}

// 복사 배열 초기화
void reset_main_cpy(void) {
    int i,j;
    for (i=0;i<MAIN_Y;i++) for (j=0;j<MAIN_X;j++) main_cpy[i][j]=100;
}

// 화면 출력
void draw_main(void) {
    int i,j;
    for (j=1;j<MAIN_X-1;j++) if (main_org[3][j]==EMPTY) main_org[3][j]=CEILLING;
    for (i=0;i<MAIN_Y;i++){
        for (j=0;j<MAIN_X;j++){
            if (main_cpy[i][j]!=main_org[i][j]){
                gotoxy(MAIN_X_ADJ+j, MAIN_Y_ADJ+i);
                switch(main_org[i][j]){
                    case EMPTY: printf("  "); break;
                    case CEILLING: printf(". "); break;
                    case WALL: printf("▩"); break;
                    case INACTIVE_BLOCK: printf("□"); break;
                    case ACTIVE_BLOCK: printf("■"); break;
                }
            }
        }
    }
    for (i=0;i<MAIN_Y;i++) for (j=0;j<MAIN_X;j++) main_cpy[i][j]=main_org[i][j];
}

// 새 블록 생성
void new_block(void) {
    int i,j;
    bx=(MAIN_X/2)-1; by=0;
    b_type=b_type_next;
    b_type_next=rand()%7;
    b_rotation=0;
    new_block_on=0;
    for (i=0;i<4;i++) for (j=0;j<4;j++)
        if (blocks[b_type][b_rotation][i][j]==1)
            main_org[by+i][bx+j]=ACTIVE_BLOCK;
}

// 충돌 검사
int check_crush(int bx,int by,int rotation){
    int i,j;
    for (i=0;i<4;i++) for (j=0;j<4;j++)
        if (blocks[b_type][rotation][i][j]==1 &&
            main_org[by+i][bx+j]>0) return 0;
    return 1;
}

// 블록 이동
void move_block(int dir){
    int i,j;
    for (i=0;i<4;i++) for (j=0;j<4;j++)
        if (blocks[b_type][b_rotation][i][j]==1)
            main_org[by+i][bx+j]=EMPTY;
    switch(dir){
        case LEFT: bx--; break;
        case RIGHT: bx++; break;
        case DOWN: by++; break;
        case UP: b_rotation=(b_rotation+1)%4; break;
    }
    for (i=0;i<4;i++) for (j=0;j<4;j++)
        if (blocks[b_type][b_rotation][i][j]==1)
            main_org[by+i][bx+j]=ACTIVE_BLOCK;
}

// 블록 낙하
void drop_block(void){
    int i,j;
    if (check_crush(bx,by+1,b_rotation)) move_block(DOWN);
    else {
        for (i=0;i<MAIN_Y;i++) for (j=0;j<MAIN_X;j++)
            if (main_org[i][j]==ACTIVE_BLOCK)
                main_org[i][j]=INACTIVE_BLOCK;
        new_block_on=1;
        check_line();
    }
}

// 줄 제거
void check_line(void){
    int i,j,k,l,block_amount;
    for (i=MAIN_Y-2;i>3;){
        block_amount=0;
        for (j=1;j<MAIN_X-1;j++) if (main_org[i][j]>0) block_amount++;
        if (block_amount==MAIN_X-2){
            score+=100; cnt++;
            for (k=i;k>1;k--) for (l=1;l<MAIN_X-1;l++)
                main_org[k][l]=(main_org[k-1][l]==CEILLING)?EMPTY:main_org[k-1][l];
        } else i--;
    }
}

int main(){
    srand((unsigned)time(NULL));
    reset_main();
    score=0; level=1; cnt=0; speed=200;
    b_type_next=rand()%7;
    new_block();
    while(1){
        if (_kbhit()){
            key=_getch();
            if (key==224) key=_getch();
            switch(key){
                case LEFT: if(check_crush(bx-1,by,b_rotation)) move_block(LEFT); break;
                case RIGHT: if(check_crush(bx+1,by,b_rotation)) move_block(RIGHT); break;
                case DOWN: if(check_crush(bx,by+1,b_rotation)) move_block(DOWN); break;
                case UP: if(check_crush(bx,by,(b_rotation+1)%4)) move_block(UP); break;
                case ESC: exit(0);
            }
        }
        draw_main();
        Sleep(speed);
        drop_block();
        if (new_block_on) new_block();
    }
    return 0;
}
