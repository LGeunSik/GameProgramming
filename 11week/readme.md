11주차 강의 내역입니다.
🎮 Rolling Ball Game – Unity Basic Example

📘 교과목: 게임 프로그래밍 (경성대학교)
📅 실습 예제: RollingBall 프로젝트 만들기
🧩 엔진: Unity 2021.3.7f1

🧱 1️⃣ 프로젝트 개요

간단한 3D 물리 기반 게임으로, 공을 굴려 경사면을 따라 이동시키는 Unity 기초 예제입니다.

구성 요소:

바닥 (Floor)

벽 (Walls)

경사면 (Slopes)

공 (Ball)

카메라 (Main Camera)

조명 (Directional Light)

🪜 2️⃣ 기본 환경 설정
🔹 카메라(Camera)

Main Camera

Position: (0, 0, 0)

방향 Gizmo를 이용해 시점 조정

회전 시 X축이 오른쪽, Y축이 위쪽

🔹 바닥(Floor)

Hierarchy → Create → 3D Object → Cube

Name: Floor

Position: (0, 0, 0)

Scale: (10, 0.5, 5)

🧱 3️⃣ 벽(Walls) 만들기
Wall01

Create Cube → Rename: Wall01

Position: (-5.3, 4.6, 0)

Scale: (1, 10, 5)

Wall02 (복제)

Duplicate Wall01 → Rename: Wall02

Position: (5.3, 4.6, 0)

Wall03 (안쪽 벽)

Create Cube → Rename: Wall03

Position: (0, 4.6, 2)

Scale: (10, 10, 1)

🎥 4️⃣ 카메라 & 라이트 조정
Main Camera

Position: (0, 8, -11.9)

Rotation: (18, 0, 0)

Directional Light

Position: (0, 0, -11.9)

Rotation: (10, 0, 0)

🧗 5️⃣ 경사면(Slope) 만들기
이름	위치(Position)	회전(Rotation)	크기(Scale)
Slope01	(-1, 8.57, 1)	(0, 0, -10)	(8, 0.3, 2)
Slope02	(-1.5, 3.9, 1)	동일	동일
Slope03	(-3, 0.35, 1)	(0, 0, 0)	(5, 0.3, 2)
Slope04	(0.9, 6.2, 1)	(0, 0, 8)	(8, 0.3, 2.2)
Slope05	(0.9, 2.2, 1)	동일	동일
⚽ 6️⃣ 공(Ball) 만들기

Create → 3D Object → Sphere

Name: Ball

Position: (-4.4, 9.58, 0.7)

Scale: (0.4, 0.4, 0.4)

⚙️ 7️⃣ 물리 설정
Rigidbody 적용

Hierarchy → Ball 선택

Component → Physics → Rigidbody

✅ Use Gravity 체크

🧪 8️⃣ 물리 속성(Bounce)

Project → Create → Physic Material → Rename: Bounce

Inspector → Bounciness = 0.6

Ball의 Sphere Collider → Material → Bounce 적용

🎨 9️⃣ 공의 색상(Material)

Project → Create → Material → Rename: Ball

Inspector → Main Maps → Albedo → 원하는 색상 선택

Project의 Ball 머티리얼을 Hierarchy의 Ball 오브젝트로 드래그

▶️ 10️⃣ 실행 (Play)

Scene 저장 후 Play 버튼 클릭

공이 경사면을 따라 굴러가며 Bounce 효과 적용

📚 Reference

🔗 Unity 공식 사이트

📘 초보자를 위한 유니티 5 입문
(아라카와 다쿠야, 아사노 유이치 저 / 윤준 역 / 한빛미디어)

🧠 Tip:

Alt + 드래그 → 시점 회전

Ctrl + Alt + 드래그 → 시점 이동

F 키 → 선택된 오브젝트 중심으로 시점 맞추기
