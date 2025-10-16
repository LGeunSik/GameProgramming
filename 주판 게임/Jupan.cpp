#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>

// ───────────────────────────────
//  ABACUS DUNGEON v3.7
//  - 타이머 표시 제거 (입력 안정판)
//  - 제한시간 로직은 그대로 유지
// ───────────────────────────────

void draw_rectangle(int c, int r, int x, int y);
void display_abacus(int m[], int x, int y, int showNumber);
void div_number(int mc[], long number);
void gotoxy(int x, int y);
void mode_basic();
void mode_calc();
void mode_quiz();
void show_title_screen();
void print_hp_bar(int x, int y, const char* name, int hp, int maxhp);

void show_title_screen()
{
    system("cls");
    SetConsoleOutputCP(CP_UTF8);

  printf("\n\n\n");
printf("██████████████████████████████████████████████████████████████\n");
printf("█                                                            █\n");
printf("█        ██╗██╗   ██╗██████╗  █████╗ ███╗   ██╗              █\n");
printf("█        ██║██║   ██║██╔══██╗██╔══██╗████╗  ██║              █\n");
printf("█        ██║██║   ██║██████╔╝███████║██╔██╗ ██║              █\n");
printf("█   ██   ██║██║   ██║██╔══╝  ██╔══██║██║╚██╗██║              █\n");
printf("█   ╚█████╔╝╚██████╔╝██║     ██║  ██║██║ ╚████║              █\n");
printf("█    ╚════╝  ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚═╝  ╚═══╝              █\n");
printf("█                                                            █\n");
printf("█           ───────  J U P A N   D U N G E O N  (v3.7)  ─────█\n");
printf("█                                                            █\n");
printf("█          🧮 던전을 통해 주판 읽는법을 배워보자  . 🧮       █\n");
printf("█                                                            █\n");
printf("█                [ P R E S S   S T A R T ]                   █\n");
printf("█                                                            █\n");
printf("█               © 2025  Geunseok Soft.  All rights reserved. █\n");
printf("█                                                            █\n");
printf("██████████████████████████████████████████████████████████████\n");
printf("\n\n");
_getch();

}
void gotoxy(int x, int y)
{
    COORD Pos = {(SHORT)(x - 1), (SHORT)(y - 1)};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_rectangle(int c, int r, int x, int y)
{
    gotoxy(x, y);
    printf("┏");
    for (int i = 0; i < c; i++) printf("━");
    printf("┓");

    for (int i = 1; i <= r; i++)
    {
        gotoxy(x, y + i);
        printf("┃");
        for (int j = 0; j < c; j++) printf(" ");
        printf("┃");
    }

    gotoxy(x, y + r + 1);
    printf("┗");
    for (int i = 0; i < c; i++) printf("━");
    printf("┛");
}

void div_number(int mc[], long number)
{
    for (int i = 0; i <= 8; i++)
    {
        mc[i] = (int)(number / pow(10, 8 - i));
        number -= (long)pow(10, 8 - i) * mc[i];
    }
}

void display_abacus(int m[], int x, int y, int showNumber)
{
    int i, j;
    if (showNumber)
    {
        gotoxy(x, y);
        for (i = 0; i <= 8; i++) printf("%2d ", m[i]);
    }

    gotoxy(x, y + 1);
    for (i = 0; i <= 8; i++)
        if (m[i] / 5) printf("● "); else printf("○ ");

    gotoxy(x, y + 2);
    printf("━━━━━━━━━━━━━━━━━━━━━━━");

    for (i = 0; i <= 8; i++) m[i] %= 5;

    for (i = 1; i <= 5; i++)
    {
        gotoxy(x, y + 2 + i);
        for (j = 0; j <= 8; j++)
            if (m[j] >= i) printf("● "); else printf("○ ");
    }
}

void print_hp_bar(int x, int y, const char* name, int hp, int maxhp)
{
    int width = 30;
    int filled = (int)((double)hp / maxhp * width);
    if (filled < 0) filled = 0;
    if (filled > width) filled = width;

    gotoxy(x, y);
    printf("%s HP: %3d/%3d [", name, hp, maxhp);
    for (int i = 0; i < filled; i++) putchar('#');
    for (int i = filled; i < width; i++) putchar(' ');
    printf("]");
}

void mode_basic()
{
    long number = 0;
    int mc[9];

    printf("입력된 숫자를 주판 모양으로 출력합니다.\n");
    printf("0을 입력하면 메뉴로 돌아갑니다.\n\n");

    while (1)
    {
        printf("숫자 입력> ");
        scanf("%ld", &number);
        if (number == 0) break;

        div_number(mc, number);
        system("cls");
        printf("입력된 값: %ld\n\n", number);
        draw_rectangle(27, 12, 3, 4);
        display_abacus(mc, 5, 5, 1);
        gotoxy(3, 20);
        printf("(Enter 키를 눌러 계속...)");
        _getch();
        system("cls");
    }
}

void mode_calc()
{
    long n1 = 0, n2 = 0, result = 0;
    int mc[9];
    int op;

    while (1)
    {
        system("cls");
        printf("========================================\n");
        printf("           🧮 주판 계산 모드\n");
        printf("========================================\n");
        printf(" 1. 덧셈  |  2. 뺄셈  |  0. 뒤로가기\n");
        printf("========================================\n");
        printf("선택> ");
        scanf("%d", &op);

        if (op == 0) break;
        if (op != 1 && op != 2)
        {
            printf("잘못된 선택입니다.\n");
            Sleep(800);
            continue;
        }

        printf("\n첫 번째 수 입력> ");
        scanf("%ld", &n1);
        printf("두 번째 수 입력> ");
        scanf("%ld", &n2);
        result = (op == 1) ? (n1 + n2) : (n1 - n2);

        system("cls");
        printf("첫 번째 수: %ld\n", n1);
        draw_rectangle(27, 12, 3, 4);
        div_number(mc, labs(n1));
        display_abacus(mc, 5, 5, 1);
        _getch();

        system("cls");
        printf("두 번째 수: %ld\n", n2);
        draw_rectangle(27, 12, 3, 4);
        div_number(mc, labs(n2));
        display_abacus(mc, 5, 5, 1);
        _getch();

        system("cls");
        printf("결과 (%s): %ld\n", (op == 1 ? "덧셈" : "뺄셈"), result);
        draw_rectangle(27, 12, 3, 4);
        div_number(mc, labs(result));
        display_abacus(mc, 5, 5, 1);
        _getch();
        system("cls");
    }
}

// ───────────────────────────────
//  [모드3] 던전 모드 (타이머 비표시)
// ───────────────────────────────
void mode_quiz()
{
    int mc[9];
    long num;
    char buf[64];
    int idx;
    long ans;

    long long score = 0;
    int streak = 0;
    int best_streak = 0;

    int playerHP = 100;
    const int playerMaxHP = 100;
    int enemyHP = 100 + rand() % 51;
    const int enemyMaxHP_init = enemyHP;

    // ───────────────────────────────
    //   [새 기능] 게임 규칙 안내 화면
    // ───────────────────────────────
    system("cls");
    printf("========================================\n");
    printf("             ⚔️  주판 던전 전투 규칙 ⚔️\n");
    printf("========================================\n");
    printf("1️⃣  주판에 표시된 숫자를 맞히면 적에게 피해를 줍니다.\n");
    printf("2️⃣  틀리거나 제한시간(10초)이 지나면 당신이 피해를 입습니다.\n");
    printf("3️⃣  적 체력이 30%% 이하일 때는 제한시간이 5초로 줄어듭니다.\n");
    printf("4️⃣  연속 정답 시 피해량이 2배씩 증가합니다.\n");
    printf("5️⃣  0을 입력하면 전투가 종료됩니다.\n");
    printf("========================================\n");
    printf("Enter 키를 눌러 전투를 시작하세요...\n");
    _getch();

    // ───────────────────────────────
    //            전투 루프 시작
    // ───────────────────────────────
    while (1)
    {
        if (playerHP <= 0)
        {
            system("cls");
            printf("💀 당신은 쓰러졌습니다... 전투 패배.\n");
            break;
        }

        if (enemyHP <= 0)
        {
            long long bonus = 50 + rand() % 51;
            score += bonus;
            enemyHP = 100 + rand() % 51;
            system("cls");
            printf("🎉 적을 처치했습니다! 보너스 +%lld점!\n", bonus);
            Sleep(1000);
        }

        system("cls");
        num = rand() % 1000000000;
        div_number(mc, num);
        long long dmg = 5LL << streak;

        double enemyHP_rate = (double)enemyHP / enemyMaxHP_init;
        int time_limit = (enemyHP_rate < 0.3) ? 5 : 10; // HP 30% 이하 → 5초 제한

        printf("🧮 주판 던전 - 전투 모드\n");
        printf("점수: %lld  |  연속 정답: %d\n\n", score, streak);
        print_hp_bar(3, 4, "플레이어", playerHP, playerMaxHP);
        print_hp_bar(3, 6, "적", enemyHP, enemyMaxHP_init);

        draw_rectangle(27, 12, 3, 8);
        display_abacus(mc, 5, 9, 0);

        gotoxy(3, 22);
        printf("정답 입력 (0 입력 시 종료, 제한시간 %d초)> ", time_limit);
        fflush(stdout);

        idx = 0;
        memset(buf, 0, sizeof(buf));

        time_t start = time(NULL);
        ans = 0;
        int expired = 0;

        // 제한시간 내 입력 처리
        while (1)
        {
            double elapsed = difftime(time(NULL), start);
            if (elapsed >= time_limit)
            {
                expired = 1;
                break;
            }

            if (_kbhit())
            {
                int ch = _getch();
                if (ch == 13) break; // Enter
                else if (ch == 8 && idx > 0)
                {
                    idx--;
                    printf("\b \b");
                }
                else if (ch >= '0' && ch <= '9' && idx < (int)sizeof(buf) - 1)
                {
                    buf[idx++] = (char)ch;
                    putchar(ch);
                }
            }

            Sleep(100);
        }

        if (expired)
        {
            int p_dmg = 10 + rand() % 11;
            playerHP -= p_dmg;
            streak = 0;
            gotoxy(3, 24);
            printf("\n⏰ 시간 초과! 당신은 %d 피해를 입었습니다. (HP: %d)\n", p_dmg, playerHP);
            gotoxy(3, 27);
            printf("(Enter 키를 눌러 계속)");
            _getch();
            continue;
        }

        if (idx == 0) continue;
        buf[idx] = '\0';
        ans = atol(buf);
        if (ans == 0) break; // 전투 종료

        gotoxy(3, 25);
        if (ans == num)
        {
            enemyHP -= (int)dmg;
            score += dmg;
            streak++;
            if (streak > best_streak) best_streak = streak;
            printf("✅ 정답! 적에게 %lld 피해! (적 HP: %d)\n", dmg, enemyHP);
        }
        else
        {
            int p_dmg = 10 + rand() % 11;
            playerHP -= p_dmg;
            streak = 0;
            printf("❌ 오답! 정답은 %ld | 당신은 %d 피해를 입었습니다. (HP: %d)\n", num, p_dmg, playerHP);
        }

        gotoxy(3, 27);
        printf("(Enter 키를 눌러 계속)");
        _getch();
    }

    system("cls");
    printf("===== 전투 결과 =====\n");
    printf("최종 점수: %lld\n", score);
    printf("최고 연속 정답: %d\n", best_streak);
    printf("=====================\n");
    printf("(Enter 키를 눌러 메뉴로 돌아가기)");
    _getch();
}


int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    srand((unsigned)time(NULL));

    int mode;
    show_title_screen();

    while (1)
    {
        system("cls");
        printf("\n");
        printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("┃              주판 던전               ┃\n");
        printf("┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
        printf("┃  1. 기본 주판 보기                   ┃\n");
        printf("┃  2. 계산 모드 (+ / -)               ┃\n");
        printf("┃  3. 던전 모드 (전투 퀴즈)           ┃\n");
        printf("┃  0. 종료                             ┃\n");
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        printf("\n메뉴 선택> ");
        scanf("%d", &mode);
        system("cls");

        if (mode == 0) break;
        switch (mode)
        {
            case 1: mode_basic(); break;
            case 2: mode_calc();  break;
            case 3: mode_quiz();  break;
            default:
                printf("잘못된 선택입니다.\n");
                Sleep(800);
                system("cls");
        }
    }

    system("cls");
    printf("프로그램을 종료합니다.\n");
    Sleep(800);
    return 0;
}
