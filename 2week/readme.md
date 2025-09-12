게임프로그래밍 2주차입니다
📘 게임 프로그래밍 (C언어) - 정리
📌 개발 환경

사용 IDE: Orwell Dev-C++

🖱 커서 제어

gotoxy(x, y) 함수로 콘솔 내 커서 위치 이동

COORD 구조체와 SetConsoleCursorPosition() API 사용

응용: 구구단 출력, 위치 기반 출력

🖥 화면 제어

system("cls"); → 화면 지우기

getchar, getch, getche → 입력 버퍼 제어

getch: 입력 즉시 반환 (에코 없음)

getche: 입력 즉시 반환 (에코 있음)

getchar: Enter 입력 후 반환

🔡 ASCII Code & Scan Code

아스키 코드: 문자에 대한 약속된 코드 값

스캔 코드: 키보드의 키 자체에 대한 코드 값

방향키, Home, End 등은 확장키 코드 (2바이트)

getch()로 확장키 처리 가능 (0 또는 0xE0 반환 후 재호출)

⬆️ 화살표 키 입력 처리

방향키 코드

↑ : 72

↓ : 80

← : 75

→ : 77

move_arrow_key() 함수로 좌표 이동 및 경계 조건 검사

⬛ 도형 출력

텍스트 모드에서 확장 완성형 문자(─, │, ┌, ┘) 사용

정사각형/직사각형 그리기: 반복문으로 테두리 출력

예제: draw_square(int size)

📑 메뉴 제작

system("cls") + printf()로 메뉴 출력

getch()를 통한 메뉴 선택 처리

예제

메인 메뉴 → 햄버거, 스파게티, 종료

서브 메뉴 → 치킨버거, 치즈버거 / 토마토, 크림 스파게티

🎲 난수(Random) 생성

rand() % n + 시작값

예제

주사위(1~6)

로또 번호(1~45)

중복 없는 로또 번호 생성 + 정렬(selection_sort)

➕ 가변 인수 (Variable Arguments)

정의: 인수 개수가 고정되지 않은 함수

stdarg.h → va_list, va_start, va_arg, va_end 사용

예제

double sum(int count, ...);
printf("합계 = %lf\n", sum(2, 10.5, 20.23));
