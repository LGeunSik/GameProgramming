12주차 학습
🎮 유니티를 활용하여 게임 만들기!

Unity는 전 세계적으로 가장 널리 사용되는 게임 엔진 중 하나로,
2D·3D 게임 제작, 물리 엔진, 애니메이션, UI, 사운드, 스크립트 기능을 모두 제공하는 강력한 툴입니다.
이 문서는 Unity를 활용해 게임을 제작할 때 필요한 핵심 흐름을 정리한 가이드 입니다.

📌 1. Unity란 무엇인가?

Unity는 초보자부터 전문가까지 사용할 수 있는 크로스 플랫폼 게임 엔진입니다.

주요 특징:

2D/3D 게임 모두 제작 가능

C# 스크립트 기반

강력한 에셋 관리 기능

PC, 모바일, 콘솔 등 다중 플랫폼 빌드 가능

풍부한 에셋 스토어 제공

🎯 2. 게임 개발의 기본 흐름
1) 프로젝트 생성

Unity Hub를 실행 → 새 프로젝트 생성

2D 또는 3D 템플릿 선택

프로젝트 폴더 구조 자동 생성됨

2) 씬(Scene) 구성

씬은 게임의 한 화면 또는 레벨 역할을 함.

게임 오브젝트(GameObject) 배치

카메라, UI, 배경 등 구성

Inspector에서 각 오브젝트의 컴포넌트(Component) 설정

3) 게임 오브젝트와 컴포넌트

Unity의 모든 요소는 게임 오브젝트 + 컴포넌트 구조

예:

Sprite Renderer → 이미지 표시

Rigidbody → 물리 기반 운동

Collider → 충돌 처리

Script → 동작을 C#으로 구현

4) C# 스크립팅

게임의 핵심 로직은 C#으로 작성됨.

예: 오브젝트 이동

public class Move : MonoBehaviour
{
    public float speed = 5f;

    void Update()
    {
        transform.Translate(Vector3.right * speed * Time.deltaTime);
    }
}

5) UI 제작

Unity의 UI 시스템을 사용해 다음 요소 구현:

HP 바

점수 표시

메뉴 버튼

타이머

UI는 Canvas 안에서 관리됨.

6) 애니메이션(Animation)

Animation Clip + Animator Controller를 활용하여
캐릭터의 걷기, 공격, 사망 등 상태를 표현.

7) 사운드(SFX/BGM)

AudioSource 컴포넌트로 재생

버튼 클릭, 총소리, 배경음악 등 구현 가능

8) 빌드(Build)

게임 완성 후 다음 플랫폼으로 빌드 가능:

PC(Windows/Mac)

Android

iOS

WebGL

🧩 3. 게임 개발시 자주 사용하는 기능
✔ Collision & Physics

충돌 감지 및 물리 기반 움직임

✔ Prefab

반복 생성되는 오브젝트(적, 총알, 버튼 등)를 프리팹으로 관리

✔ ScriptableObject

유닛 정보, 스탯, 설정값 저장에 사용

✔ Coroutines

시간 지연, 반복적인 행동 제어에 유용함

🚀 4. Unity로 무엇을 만들 수 있을까?

2D 횡스크롤 액션 게임

3D FPS

RPG / 로그라이크

모바일 캐주얼 게임

패즐 / 전략 게임

시뮬레이션 게임

Unity는 거의 모든 장르의 게임 제작을 지원함.

📚 5. Unity 개발 팁

구조 설계 먼저 하고 개발하기

프리팹을 적극적으로 활용

Update()는 최소한으로 사용 (최적화)

GitHub로 버전 관리

작은 기능 단위로 구현 + 테스트 반복

🏁 결론

Unity는 게임 제작에 필요한 모든 기능을 제공하는 강력한 엔진이며,
씬 구성 → 오브젝트 배치 → 스크립트 작성 → UI → 애니메이션 → 빌드 의 흐름만 이해하면
초보자도 충분히 게임을 만들 수 있습니다.
