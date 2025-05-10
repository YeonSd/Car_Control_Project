#  05.10 Git 학습 일지

---

##  Git 내부 구조

작업 디렉토리 (Working Directory)  
↓ `git add`  
스테이징 영역 (Staging Area / Index)  
↓ `git commit`  
로컬 저장소 (Local Repository)  
↓ `git push`  
원격 저장소 (Remote Repository / GitHub)

---

##  Git 기본 명령어

### 주요 명령어

- `git add <파일이름>`  
  → *스테이징 영역에 파일 추가*

- `git commit -m "커밋할 메모 작성"`  
  → **커밋 수행**, 메시지로 변경 내역 설명

- `git push origin <브랜치이름>`  
  → **원격 저장소로 Push** (예: `develop` 브랜치)

- `git status`  
  → 현재 *스테이징 상태* 확인, 수정/추적/커밋 대기 파일 확인

- `git log`  
  → 전체 **커밋 히스토리** 확인

---

###  고급 명령어 및 복구 관련

- `git rm [파일명]`  
  → *Git의 추적 대상에서 파일을 제거하고, 실제 디스크에서도 삭제*

  - `git add -A`  
  → *변경된 모든 파일을 한꺼번에 스테이징*

- `git restore <파일이름>`  
  → *로컬에서 삭제된 파일을 복구 (웹에서 삭제한 파일 포함)*

- `git restore --staged <파일이름>`  
  → *잘못 스테이징한 파일을 다시 작업 디렉토리로 되돌림*

- `git reset HEAD^`  
  → *마지막 커밋 1개를 취소하고 변경 내용은 유지 (staged 상태로 복귀)*

- `git revert <커밋해시값>`  
  → *지정한 커밋의 반대 내용을 새 커밋으로 생성하여 되돌림 (히스토리 보존)*

---
# Cube IDE연동
### 환경 구축
https://m.blog.naver.com/musk95/221900982612  참조
<br>
### 인증 토큰 생성
https://github.com/settings/tokens
<br>
Repository access에 All repository 체크
<br>
Repository permissions, Account permissions 영역 모두 체크
<br>
read & write 에 체크, read 만 있으면 read만 체크<br>
생성 후 토큰 코드 복사
<br>
CubeIDE에서 패스워드 입력란에 토큰 코드 붙혀넣기, 아이디는 GitHub ID 입력

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
