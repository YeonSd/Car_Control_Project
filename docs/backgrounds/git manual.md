github commands


< branch 별 기능 >

develop : docs, media, readme 등 관리

	
main : 최종 완성 때 develop에서 main으로 merge해줌



<초기설정> =========================================================================

1. git 설치
홈페이지에서 x64 download

cmd > git --version

2. git 기본설정

처음에 딱 한 번만, "내가 누군지" Git에 알려야 함 (cmd)
git config --global user.name "이름"
git config --global user.email "이메일@example.com"
( 여기 입력한 이름/이메일이 나중에 "커밋한 사람"으로 기록됨 )

3. 프로젝트 폴더 준비

ex) 문서 > car_control_project 폴더 생성


4. Git 초기화

프로젝트 폴더 안에서 터미널(cmd) 열고: git init
=> 폴더가 Git이 추적할 수 있는 "저장소(repository)"가 됨.


5. 로컬 코드 GitHub에 연결
깃허브가 알려주는 "원격 저장소 URL" 복사하고:
git remote add origin https://github.com/YeonSd/STM32_Car_Control_Project.git
(내 컴퓨터 코드와 GitHub 리포지터리가 연결됨)

6. 원격에서 내 로컬로 가져오기

 git fetch origin


<commands> =========================================================================

1. 매번 작업 시작 전

- git pull origin 브랜치명		->다른 사람이 수정했을 수도 있으니까 먼저 가져오기)



2. 작업 후
- git checkout 브랜치명		-> 원하는브랜치로 이동했는지 재차확인
  git add 특정폴더이름 			-> 특정폴더만추가 ( git add . 하면 모든 폴더 추가됨)
  git commit -m "원하는 메세지 입력 ex) Add RF communication"
  git push origin 브랜치명		-> 이동했던 브랜치명



2-1. upstream 옵션

처음 브랜치를 푸시할 땐 반드시 -u 옵션 사용하는 게 좋음
로컬 브랜치와 원격 브랜치를 추적 관계(upstream)로 설정하는거임

- git push -u origin 브랜치명

이 명령을 한 번만 실행하면, 이후에는:

- git push
- git pull

만 입력해도 자동으로 추적관계가 설정됨

+ git push -set-upstream origin branch명 이건뭔가?

fork
남의 저장소를 복제해서 내 저장소로 만드는 기능
앞에서 말한 클론은 깃허브  저장소에 있는 내용을 내컴퓨터로 복사해오는거고, fork는 남의 깃허브 저장소를 복사해서 내 깃허브 계정에 저장소를 하나 새로 만드는 것이다.

PR (Pull Request)
fork로 남의 저장소를 내 저장소로 복제한 후. 이 코드를 가지고 내가 이런저런 작업들을 진행한다.
근데 이렇게 내가 작업한 내용들이 내가 복사해온 원본 저장소에도 내용이 업데이트 되길 원할경우
해당 저장소로 pull request를 하고, 해당 저장소에서는 이 요청을 검토해서 승인되면 내가 작업한내용이 원본 저장소에도 업데이트가 된다.


※ 유의사항
명확한 커밋 메시지 달기
Pull 먼저, Push는 나중에 : 같이 하는 사람 코드가 최신일 수도 있음. 덮어쓰는 사고 방지
기능별로 커밋 자주하기 : 한 번에 너무 많은 걸 몰아서 커밋하지 말기.



<원격(깃헙페이지)에서 수정하고 로컬(pc 디렉토리)로 동기화하는 법>

1. 깃헙페이지에서 연필모양으로 내용 수정
2. git checkout 브랜치명 		-> 수정했던 브랜치로 이동 (같은 브랜치에 있어야 pull 시 충돌 없이 동기화됨)
3. git pull origin 브랜치명		-> 원격(origin)의 develop 브랜치 변경사항을 가져오고, 현재 로컬 브랜치에 병합

결과 -> 수정 내용이 로컬에도 반영되며, .git 폴더 내 히스토리도 최신 상태로 동기화됨

+ 만약 로컬 파일을 동시에 수정 중이었다면?
-> git pull 도중 merge conflict(병합 충돌) 발생가능 -> 이 경우 git이 충돌 부분을 표시하고, 수동으로 해결해야함

! 충돌 발생 시 해결 법 



------------------------------------------------------------------------------------------------------------------------


기타

- git checkout 기존브랜치이름	-> 원하는 브랜치로 이동

- git checkout -b 생성할이름		-> 새로운 branch 추가 (상위 develop branch에서 생성해야 종속관계가됨)

- git branch				-> 로컬의 현재 존재하는 브랜치 목록 보기

- git branch -a				-> 로컬 + origin 포함한 원격까지 전부 다 보기

- 						-> 원격의 branch 내의 파일이나 폴더 삭제

- git status					-> 현재 브랜치와 변경 상태 확인

- git log --online				-> 최근 커밋 내역 확인

- git diff origin/브랜치명		-> 브랜치명의 원격과 로컬 차이 비교


