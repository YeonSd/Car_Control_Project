# 05.10 Git & CubeIDE 연동 시도

## CubeIDE 연동

### 환경 구축
Git과 STM32CubeIDE를 연동하여 프로젝트 버전 관리를 원활하게 하기 위해 아래의 가이드를 참고하여 환경을 구성  
➡ 참고 블로그: https://m.blog.naver.com/musk95/221900982612  
<br>

### 인증 토큰 생성

GitHub에서는 보안 강화를 위해 2021년부터 **패스워드 인증 방식 대신 Personal Access Token(PAT)**을 사용하도록 권장하고 있음.  
STM32CubeIDE에서 GitHub와 연동하려면, GitHub 계정의 패스워드 대신 이 토큰을 사용하여 인증을 수행.

➡ 토큰 생성 페이지: https://github.com/settings/tokens  
<br>

#### 토큰 생성 시 설정

- **Repository access**: All repositories 체크  
- **Repository permissions**: 전체 항목 체크 (읽기/쓰기 권한 필요)  
- **Account permissions**: 전체 항목 체크  
- 일반적으로 read & write 권한을 부여해야 하지만, **읽기 전용 용도일 경우 read만 체크**  
<br>

#### 생성 후 사용 방법

- 생성이 완료되면 토큰 문자열이 제공됨 → **복사해둘 것 (다시 볼 수 없음)**  
- STM32CubeIDE에서 Git 기능 사용 시 로그인 창이 뜨면,  
  - **Username**: GitHub ID  
  - **Password**: 방금 생성한 토큰 문자열을 붙여넣기  
<br>

이 과정을 통해 GitHub 저장소에 안전하게 접근하고, CubeIDE 내부에서 **Push, Pull, Clone 등의 Git 기능을 직접 사용할 수 있음.**

---
# Cube IDE에서 Push 시도 요약

## 1. Push 작업 시도
- STM32CubeIDE에서 `Push` 버튼을 눌러 GitHub 원격 저장소로 커밋을 업로드 시도함.

## 2. 문제 발생
- 다음과 같은 오류 발생:
git-receive-pack not permitted on ...
- GitHub 저장소에 연결은 되었지만, **Push 권한이 거부됨**.

## 3. 해결 시도
- GitHub에서 **Fine-grained Personal Access Token** 새로 발급
- 저장소 전체에 대한 **Read and Write 권한** 부여
- Cube IDE 로그인 창에 GitHub 계정과 토큰을 입력하여 인증 시도

## 4. 문제 지속
- Token 설정 및 권한은 정상적으로 보이지만
- Cube IDE에서는 여전히 동일 오류 발생 (Push 불가)

## 5. 추가 확인
- 동일 토큰을 이용해 **관리자의 링크로부터 fork한 내 저장소에서는 Push 성공**
- GitHub 웹에서 수동 업로드도 문제 없이 수행됨

## ✅ 결론
- **GitHub 정책상 Fine-grained Token은 CubeIDE에서의 Push를 제한하는 것을 알게 됨**
- **CubeIDE에서는 토큰 기반 인증은 지원하나 관리자의 저장소로 다이렉트한 Push 작업이 제한됨**
---
  
  # 해결 방법:
- `git bash`에서 Push 수행
- 또는 PR(Pull Request) 방식으로 기여 (협업의 표준 방식)

---
## PR 요청 흐름
1. fork한 본인 저장소에서 작업 & push
2. GitHub 웹에서 Pull Request 생성 -> 관리자에게 메세지 전송
3. 관리자가 병합

---
### 두가지 방식 채택 가능
1. CubeIDE에서 스테이징 후 Gitbash를 통해 관리자 저장소로 Push하는 방식
2. CubeIDE에서 본인 저장소로 Push 후 PR 요청 방식<br><br>
관리자는 CubeIDE에서 관리자 저장소로 바로 Push 가능
