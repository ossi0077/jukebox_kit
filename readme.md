# Gongzipsa 주크박스 키트 제작
- NFC, RFID 모듈을 사용한 버전과 Reed switch와 자석을 이용한 버전 두가지
- 각 버전별로 라이브러리가 다릅니다.

## Reed swtich version

- Reed switch를 이용하여 자석이 근처에 있을 시 수동부저로 노래 출력
	- 자석이 인식될 때마다 다른 노래 재생
	- 15가지의 노래 준비

- [여기](https://github.com/robsoncouto/arduino-songs)에서 각 곡들을 따와서 라이브러리를 제작하여 사용하기 쉽게 만들었습니다.

- 아두이노 나노에서 동작 가능하게 하기 위해 flash memory를 사용하도록 buzzer_song 라이브러리를 제작하였습니다.

### 사용부품
- Arduino Nano
- Passive Buzzer
- Reed switch module(예정)
- 자석 3개(예정)
	
### 라이브러리
- buzzer_song	:	설치 필요(zip파일로 설치)

### 사용 방법
1. 회로 연결
2. 아두이노 pc 연결 후 라이브러리 설치
3. main_code.ino 업로드
- 이후 자석 태그 시 설정된 노래가 재생되는 것을 확인할 수 있습니다.
- 노래 재생 중 자석이 멀어질 시 노래 정지
- 정지 이후 자석 태그 시 다음 노래 재생
- 노래가 정지되지 않고 완곡된 경우 자석이 멀어졌다가 다시 태그되면 다음 노래 재생

### 결선이미지
<img src="./img/schematic_reed.png" width="50%" height="50%">

### 제품사진
<img src="./img/picture1.jpg" width="50%" height="50%">


## NFC, RFID version

- nfc스티커 3개를 이용하여 스티커가 입력되었을 시 수동부저로 노래 출력
	- 각 스티커별 다른 노래 재생
	- 15가지의 노래 준비

- [여기](https://github.com/robsoncouto/arduino-songs)에서 각 곡들을 따와서 라이브러리를 제작하여 사용하기 쉽게 만들었습니다.

- 아두이노 나노에서 동작 가능하게 하기 위해 flash memory를 사용하도록 buzzer_song 라이브러리를 제작하였습니다.

### 사용부품
- Arduino Nano
- Passive Buzzer
- RFID-RC522
- NFC 스티커 3개
	
### 라이브러리
- MFRC522		:	설치 필요(라이브러리 매니저에서 검색하여 설치)
- SPI			:	기본 설치 라이브러리
- buzzer_song	:	설치 필요(zip파일로 설치)

### 사용 방법
1. 회로 연결
2. 아두이노 pc 연결 후 라이브러리 설치
3. 예제 ReadNUID 업로드 후 시리얼 모니터 실행
4. 스티커 태그 후 dec값 확인
5. main_code.ino에 NFC 스티커 아이디 변수에 해당 값 입력
6. main_code.ino 업로드
- 이후 스티커 태그 시 설정된 노래가 재생되는 것을 확인할 수 있습니다.
- 노래 재생 중 현재 재생곡이 담긴 스티커가 아닌 다른 스티커 태그시 노래 정지
- 정지 이후 리더기에 정지에 이용된 스티커가 아닌 다른 스티커 태그시 해당 노래 재생.
- 노래가 정지되지 않고 완곡된 경우 다른 노래의 스티커를 태그시 노래 재생
	->완곡된 노래 스티커 태그시 노래 재생 X

### 결선이미지
<img src="./img/schematic_RC522.png" width="50%" height="50%">

### 제품사진
<img src="./img/picture1.jpg" width="50%" height="50%">

## 일자별 진행상황
|날짜|진행사항|특이사항|
|--|--|--|
|2022/10/26|코드 작성 완료||
|2022/10/31|코드 수정|다른태그 입력시 노래 중지. 이후 스티커 태그 시 해당 노래 재생.|
|2022/11/02|코드 수정|노래를 정지시키지 않을 시 완곡 후 반복재생되는 문제 해결|
|2022/12/05|연결사진, 제품사진 업로드|Update readme|
|2022/12/12|Reed swtich 사용 버전 업로드|리드 스위치 실제 테스트 후 readme파일 수정 필요|
