#include <stdio.h>
#include <math.h>
#include <windows.h>   // Beep 함수 사용

// 옥타브별 도~시(흰 건반) 인덱스 (도=0, 레=2, 미=4, 파=5, 솔=7, 라=9, 시=11, 도=12)
int indexArr[] = {0, 2, 4, 5, 7, 9, 11, 12};

// 옥타브와 음계 index를 받아 주파수(Hz) 반환
int calc_frequency(int octave, int idx) {
    // 라(A4) = 440Hz 기준
    double a = 440.0;
    // 12평균율: 한 반음 차이는 2^(1/12) 배
    double freq = a * pow(2.0, (octave - 4) * 12 + indexArr[idx] - 9 / 12.0);

    return (int)(freq + 0.5);  // 반올림 후 정수형 변환
}

int main() {
    int octave = 4;  // 옥타브 4 (기본)
    int delay = 500; // 각 음 길이 (0.5초)

    printf("옥타브 %d 음계 주파수 출력:\n", octave);

    // 도레미파솔라시도
    for (int i = 0; i < 8; i++) {
        int freq = calc_frequency(octave, i);
        printf("음계 %d : %d Hz\n", i, freq);
        Beep(freq, delay);
    }

    // 도시라솔파미레도 (역순)
    for (int i = 7; i >= 0; i--) {
        int freq = calc_frequency(octave, i);
        Beep(freq, delay);
    }

    return 0;
}
