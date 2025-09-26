#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 12
#define HEIGHT 22

#define EMPTY 0
#define WALL 1
#define BLOCK 2

// 블록 정의 (4x4, 7종)
int tetromino[7][4][4] = {
    { {0,0,0,0}, {1,1,1,1}, {0,0,0,0}, {0,0,0,0} }, // I
    { {1,1}, {1,1} },                               // O
    { {0,1,0}, {1,1,1}, {0,0,0} },                  // T
    { {1,0,0}, {1,1,1}, {0,0,0} },                  // L
    { {0,0,1}, {1,1,1}, {0,0,0} },                  // J
    { {0,1,1}, {1,1,0}, {0,0,0} },                  // S
    { {1,1,0}, {0,1,1}, {0,0,0} }                   // Z
};

int board[HEIGHT][WIDTH];
int bx, by;       // 블록 위치
int shape;        // 블록 종류
int rotation;     // 회전 상태

void gotoxy(int x,int y) {
    COORD pos = {x*2,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 보드 초기화
void init_board() {
    for (int y=0;y<HEIGHT;y++){
        for (int x=0;x<WIDTH;x++){
            if (x==0 || x==WIDTH-1 || y==HEIGHT-1) board[y][x]=WALL;
            else board[y][x]=EMPTY;
        }
    }
}

// 보드 출력
void draw_board() {
    gotoxy(0,0);
    for (int y=0;y<HEIGHT;y++){
        for (int x=0;x<WIDTH;x++){
            if (board[y][x]==EMPTY) printf("  ");
            else if (board[y][x]==WALL) printf("▩");
            else if (board[y][x]==BLOCK) printf("■");
        }
        printf("\n");
    }
}

// 블록 충돌 검사
int check_collision(int nx,int ny,int r) {
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if (tetromino[shape][i][j]){
                int x=nx+j, y=ny+i;
                if (board[y][x]!=EMPTY) return 1;
            }
        }
    }
    return 0;
}

// 블록 보드에 그리기
void place_block(int val) {
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if (tetromino[shape][i][j]){
                board[by+i][bx+j]=val;
            }
        }
    }
}

// 줄 지우기
void clear_lines() {
    for (int y=HEIGHT-2;y>0;y--){
        int full=1;
        for (int x=1;x<WIDTH-1;x++){
            if (board[y][x]==EMPTY) {full=0; break;}
        }
        if (full){
            for (int ny=y;ny>0;ny--){
                for (int x=1;x<WIDTH-1;x++){
                    board[ny][x]=board[ny-1][x];
                }
            }
            y++;
        }
    }
}

// 새 블록 생성
void new_block() {
    shape=rand()%7;
    bx=WIDTH/2-2; by=0;
    if (check_collision(bx,by,rotation)){
        system("cls");
        printf("GAME OVER!\n");
        exit(0);
    }
}

int main(){
    srand(time(NULL));
    init_board();
    new_block();

    while(1){
        // 블록 내리기
        place_block(EMPTY);
        if (!check_collision(bx,by+1,rotation)) by++;
        else {
            place_block(BLOCK);
            clear_lines();
            new_block();
        }
        place_block(BLOCK);

        // 입력 처리
        if (_kbhit()){
            char key=_getch();
            place_block(EMPTY);
            if (key==75 && !check_collision(bx-1,by,rotation)) bx--;     // ←
            if (key==77 && !check_collision(bx+1,by,rotation)) bx++;     // →
            if (key==80 && !check_collision(bx,by+1,rotation)) by++;     // ↓
            place_block(BLOCK);
        }

        draw_board();
        Sleep(300);
    }
    return 0;
}
