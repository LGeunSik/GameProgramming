📘 Git & GitHub 핵심 요약 (README)
🧩 Git이란?

로컬 컴퓨터에서 코드의 버전(변경 이력)을 관리하기 위한 도구.
프로젝트의 모든 변화를 기록하고, 이전 상태로 되돌리거나 여러 버전을 동시에 관리할 수 있다.

🧱 Git의 핵심 개념
1. 저장소(Repository)

프로젝트를 저장하는 공간

로컬(repo) ↔ 원격(repo, GitHub) 두 종류

2. 스테이징(Staging)

커밋하기 전에 “이번 버전에 포함할 파일”을 선택하는 단계

3. 커밋(Commit)

프로젝트의 특정 시점 스냅샷

하나의 의미 있는 변경 단위를 기록하며 메시지로 설명함

4. 브랜치(Branch)

여러 작업 흐름을 동시에 진행하기 위한 분기

대표: main 또는 master

5. 병합(Merge)

서로 다른 브랜치의 변경을 하나로 합침

🔗 GitHub란?

Git으로 관리되는 코드를 온라인에서 저장·공유·협업할 수 있게 해주는 서비스.

사용 목적:

백업

팀 협업

코드 리뷰

배포 자동화(CI/CD)

🛠️ 자주 사용하는 Git 명령어 요약
1. 저장소 시작
git init

2. 파일 변경 저장 과정
git add .
git commit -m "메시지"

3. 원격 저장소 연결
git remote add origin https://github.com/내아이디/저장소.git

4. 업로드(Push)
git push -u origin main

5. 다운로드(Pull)
git pull origin main

6. 브랜치 관리
git branch           # 목록
git checkout -b dev  # 생성 + 이동
git merge dev        # 병합

🧠 Git & GitHub 학습 핵심 포인트

Git은 버전 관리 도구, GitHub는 저장 & 공유 플랫폼

add → commit → push 흐름을 반드시 이해

main/dev 브랜치로 안전한 개발 구조 만들기

충돌(Conflict)은 협업에서 필수 경험 → 직접 해결이 실력

GitHub로 백업하면 컴퓨터 고장에도 안전

기초만 익혀도 협업 능력이 크게 향상됨

🎯 결론

Git은 코드의 타임머신, GitHub는 저장소 + 협업 공간
두 개만 제대로 다뤄도 프로젝트 관리 능력이 한 단계 성장한다.
