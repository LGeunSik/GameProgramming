13주차 요약입니다.
📘 Unreal Engine 5 Beginner Guide — README.md 요약본
📌 EP1. 언리얼 엔진 설치 및 실행

Epic Games Launcher 설치

Epic Games 계정 로그인 후 Unreal Engine 탭 → Library

원하는 버전 선택 후 Install

설치 옵션에서 필요한 기능만 선택 가능

설치 후 Launch 버튼 클릭 → Unreal Project Browser 실행됨

📌 EP2. 프로젝트 생성과 기본 가이드
▶ Third Person Template 기반 새 프로젝트 생성

Games → Third Person 선택 → 프로젝트 이름 입력 → Create

▶ 언리얼 엔진 화면 구성 요소

Viewport: 게임 화면 / 오브젝트 배치

Menu & Toolbar: 실행/저장 등 주요 기능

Outliner: 계층 구조

Details: 선택한 오브젝트 상세 옵션

Content Browser: 모든 리소스 저장소

Actor Placement: UE가 제공하는 오브젝트들

▶ 기본 조작법

우클릭 + WASD : 카메라 이동

Q/W/E/R : 선택 / 이동 / 회전 / 스케일

카메라 속도 조절 가능

스냅 기능 On/Off

▶ 새 Level 만들기

Content Browser → 우클릭 → Folder 생성

폴더 안에서 우클릭 → Level 생성

더블클릭하면 검은 화면 (기본 레벨 상태)

▶ 기본 환경 넣기

방법 1: Environment Light Mixer 자동 생성

방법 2: Actor Placement에서 Sky, Fog, Cloud 등 수동 배치

예시 요소:

Directional Light: 태양광

Sky Light: 간접광

Sky Atmosphere: 대기 표현

Exponential Height Fog: 안개

📌 EP3. 블루프린트 기초
▶ 스크립팅 종류

Level Blueprint

상단 메뉴 → Blueprints → Open Level Blueprint

전체 레벨 동작 제어

일반 블루프린트 (Actor 기반)

Content Browser → 우클릭 → Blueprint Class → Actor

더블클릭해서 스크립트 작성 화면 진입

▶ 블루프린트 화면 구성

상태창(State Panel): 변수, 함수, 이벤트 확인

Event Graph: 실제 실행 로직

Details: 선택 노드 상세 설정

📌 EP3 실습 예제 — 키 입력으로 메시지 출력
1. Input Action 만들기

Content Browser → Input Action 생성

이름은 IA_키이름 형식 추천

키 매핑은 IMC_Default 내부에서 설정

2. 블루프린트에서 Print String 실행

Event Graph → Input Action 이벤트 연결

Print String 노드로 텍스트 표시
