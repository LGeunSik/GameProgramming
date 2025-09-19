📖 Game Programming (C언어)
📌 트럼프 카드 구현

트럼프 카드는 4가지 무늬(♠, ◆, ♥, ♣) × 13장 = 총 52장

구조체로 카드 표현

typedef struct {
    int order;      // 카드 우선순위 (♠=0, ◆=1, ♥=2, ♣=3)
    char shape[3];  // 카드 모양
    int number;     // 카드 숫자(또는 문자: A,J,Q,K)
} trump;


순위(order)

♠: 0

◆: 1

♥: 2

♣: 3

📌 카드 생성 함수

무늬는 2차원 배열에 저장

반복문을 통해 order, shape, number 저장

switch-case 문으로 A,J,Q,K 처리

void make_card(trump m_card[]) {
    int i, j;
    char shape[4][3] = {"♠", "◆", "♥", "♣"};

    for (i = 0; i < 4; i++) {
        for (j = i * 13; j < i * 13 + 13; j++) {
            m_card[j].order = i;
            strcpy(m_card[j].shape, shape[i]);
            m_card[j].number = j % 13 + 1;

            switch(m_card[j].number) {
                case 1:  m_card[j].number = 'A'; break;
                case 11: m_card[j].number = 'J'; break;
                case 12: m_card[j].number = 'Q'; break;
                case 13: m_card[j].number = 'K'; break;
            }
        }
    }
}

📌 카드 출력

숫자가 10 이상일 때는 문자 출력 방식 주의

형식 지정자

문자: "%-2c"

숫자: "%-2d"

if (number == 'A' || number == 'J' || number == 'Q' || number == 'K')
    printf("%s %-2c", shape, number);
else
    printf("%s %-2d", shape, number);

📌 카드 섞기

난수를 발생시켜 서로 교환

방법 1: i번째 카드와 rnd번째 카드 교환
→ 단, rnd == i면 교환 안 됨

방법 2: rnd == i일 경우 새 난수 다시 발생시켜 반드시 교환

void shuffle_card(trump m_card[]) {
    int i, rnd;
    trump temp;

    srand((unsigned)time(NULL));
    for (i = 0; i < 52; i++) {
        do {
            rnd = rand() % 52;
        } while (rnd == i);

        temp = m_card[i];
        m_card[i] = m_card[rnd];
        m_card[rnd] = temp;
    }
}

📌 음계와 피아노 건반

컴퓨터에서 기계적 소리를 주파수로 표현

기준: A (라) = 440Hz

12평균율: 한 옥타브를 12개의 반음(semitone)으로 나눔

반음 간격 = 2^(1/12) ≈ 1.0594배

옥타브는 1:2 주파수 비율

📌 주파수 계산
int index[] = {0, 2, 4, 5, 7, 9, 11, 12}; // 도~시
int calc_frequency(int octave, int idx) {
    return (int)(440.0 * pow(2.0, (octave - 4) * 12 + index[idx] - 9) / 12.0);
}

📌 소리 출력

Windows: Beep(주파수, 시간)

예시: 옥타브 4의 도~도

for (int i=0; i<8; i++) {
    int freq = calc_frequency(4, index[i]);
    Beep(freq, 500);
}

📌 키보드 입력으로 연주

scanf 대신 getch() 사용 → Enter 없이 바로 반응

입력 키 '1'~'8' → 도~높은 도 연주

'q' 입력 시 종료

📌 자료구조 개념

선형 구조: 연결 리스트, 스택, 큐, 덱

비선형 구조: 트리, 그래프

연결 리스트 응용: 게임 리플레이 저장

스택 응용: 카드 게임(버리는 더미, 가져오기)

📌 동적 메모리 관리

배열은 크기 고정 → 낭비 발생

실행 중 필요한 만큼만 동적 할당/해제하여 사용

C에서는 malloc, free로 구현

✅ 요약

이 강의 자료에서는

트럼프 카드 구조체 설계, 생성, 출력, 섞기

피아노 음계(12평균율)와 주파수 계산, Beep 출력

자료구조(연결리스트, 스택) 및 게임 응용

동적 메모리 관리

를 C언어 코드 예제와 함께 다루고 있습니다.3주차 강의내용입니다.
