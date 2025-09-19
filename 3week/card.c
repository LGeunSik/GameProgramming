#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 카드 구조체 정의
typedef struct {
    int order;      // 카드 순위 (♠=0, ◆=1, ♥=2, ♣=3)
    char shape[4];  // 카드 모양 (멀티바이트 문자 고려 → 최소 4바이트)
    int number;     // 카드 숫자 (1~13)
    char face[3];   // "A", "2", ..., "10", "J", "Q", "K"
} trump;

// 카드 생성 함수
void make_card(trump m_card[]) {
    int i, j;
    char shape[4][4] = {"♠", "◆", "♥", "♣"};

    for (i = 0; i < 4; i++) {
        for (j = i * 13; j < i * 13 + 13; j++) {
            m_card[j].order = i;
            strcpy(m_card[j].shape, shape[i]);
            m_card[j].number = j % 13 + 1;

            // 숫자를 face 문자열로 변환
            switch (m_card[j].number) {
                case 1:  strcpy(m_card[j].face, "A"); break;
                case 11: strcpy(m_card[j].face, "J"); break;
                case 12: strcpy(m_card[j].face, "Q"); break;
                case 13: strcpy(m_card[j].face, "K"); break;
                default: sprintf(m_card[j].face, "%d", m_card[j].number);
            }
        }
    }
}

// 카드 출력 함수
void print_card(trump m_card[]) {
    int i;
    for (i = 0; i < 52; i++) {
        printf("%s %-2s ", m_card[i].shape, m_card[i].face);

        if ((i + 1) % 13 == 0) printf("\n");
    }
}

// 카드 섞기 함수
void shuffle_card(trump m_card[]) {
    int i, rnd;
    trump temp;

    srand((unsigned)time(NULL));
    for (i = 0; i < 52; i++) {
        do {
            rnd = rand() % 52;
        } while (rnd == i);   // 자기 자신과 교환 방지

        temp = m_card[i];
        m_card[i] = m_card[rnd];
        m_card[rnd] = temp;
    }
}

// 메인 함수
int main() {
    trump m_card[52];

    // 카드 생성
    make_card(m_card);

    printf("===== 생성된 카드 =====\n");
    print_card(m_card);

    // 카드 섞기
    shuffle_card(m_card);

    printf("\n===== 섞은 카드 =====\n");
    print_card(m_card);

    return 0;
}
