#include <stdio.h>
#include <math.h>
#include <windows.h>   // Beep 함수 사용

// 흰 건반 인덱스 (도=0, 레=2, 미=4, 파=5, 솔=7, 라=9, 시=11, 도=12)
int indexArr[] = {0, 2, 4, 5, 7, 9, 11, 12};

// 옥타브와 음계 index를 받아 주파수 반환
int calc_frequency(int octave, int idx) {
    double a = 440.0; // 기준: A4 = 440Hz
    double freq = a * pow(2.0, ((octave - 4) * 12 + (indexArr[idx] - 9)) / 12.0);
    return (int)(freq + 0.5);
}

int main() {
    int delay = 400; // 기본 음 길이(ms)

    // "반짝반짝 작은 별" 멜로디 (도레미파솔라시 순서, 옥타브=4 기준)
    int melody[] = {
        0, 0, 7, 7, 9, 9, 7,   // 반짝반짝 작은별
        5, 5, 4, 4, 2, 2, 0,   // 아름답게 비치네
        7, 7, 5, 5, 4, 4, 2,   // 동쪽 하늘에서도
        7, 7, 5, 5, 4, 4, 2,   // 서쪽 하늘에서도
        0, 0, 7, 7, 9, 9, 7    // 반짝반짝 작은별
    };
    int length = sizeof(melody) / sizeof(melody[0]);

    printf("반짝반짝 작은별 연주 시작...\n");

    for (int i = 0; i < length; i++) {
        int freq = calc_frequency(4, melody[i]);  // 옥타브 4 사용
        Beep(freq, delay);
        Sleep(50); // 음 사이 간격
    }

    printf("연주 완료!\n");
    return 0;
}
