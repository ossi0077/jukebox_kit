#include <buzzer_song.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

int buzzer = 7;  //buzzer 핀 번호

MFRC522 rfid(SS_PIN, RST_PIN);

//NFC 스티커 아이디 입력
byte first_id[] = { 84, 66, 131, 234 };
byte second_id[] = { 212, 64, 130, 234 };
byte third_id[] = { 132, 127, 124, 234 };

byte nuidPICC[4];
int first_id_check = 1;
int second_id_check = 1;
int third_id_check = 1;
int checking = 1;
int past_checking = 2;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  for (int i = 0; i < 4; i++) {
    first_id_check = first_id_check + first_id[i];
    second_id_check = second_id_check + second_id[i];
    third_id_check = third_id_check + third_id[i];
  }
  Serial.println(F("Serial start"));
  Serial.println(F("========================================================"));
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent())
    return;
  if (!rfid.PICC_ReadCardSerial())
    return;

  checking = 1;

  for (int i = 0; i < 4; i++)
    checking = rfid.uid.uidByte[i] + checking;

  if (past_checking == checking)
    return;

  Serial.print(F("첫 번째 태그의 식별 번호 : "));
  Serial.println(first_id_check);
  Serial.print(F("두 번째 태그의 식별 번호 : "));
  Serial.println(second_id_check);
  Serial.print(F("세 번째 태그의 식별 번호 : "));
  Serial.println(third_id_check);
  Serial.print(F("입력된 태그의 식별 번호 : "));
  Serial.println(checking);
  Serial.println(F("=========================연주 시작========================="));


  /* 15곡 선택 가능
** caribbean(buzzer, n번째 체크);       영화 캐리비안의 해적 ost
** harrypotter(buzzer, n번째 체크);     영화 해리포터 ost
** pacman(buzzer, n번째 체크);          게임 팩맨 테마
** starWars(buzzer, n번째 체크);        영화 스타워즈 ost
** mario(buzzer, n번째 체크);           게임 슈퍼마리오 테마
** tetris(buzzer, n번째 체크);          게임 테트리스 테마
** minuetG(buzzer, n번째 체크);         클래식 Minuet in G major/바흐
** lionKing(buzzer, n번째 체크);        영화 라이온킹 ost
** symphonyNo9(buzzer, n번째 체크);     클래식 교향곡 9번/베토벤
** jigglypuff(buzzer, n번째 체크);      게임 포켓몬스터 푸린노래
** starTrek(buzzer, n번째 체크);        드라마 star trek ost
** badinerie(buzzer, n번째 체크);       클래식 바디네리/바흐
** godFather(buzzer, n번째 체크);       영화 대부 ost
** zeldaTheme(buzzer, n번째 체크);      게임 젤다의 전설 테마
** cannon(buzzer, n번째 체크);          클래식 캐논변주곡/파헬벨
*/
  // RFID ID별 노래 설정 부분
  if (checking == first_id_check) {  //첫 번째 ID태그 노래 설정
    past_checking = tetris(buzzer, first_id_check);
  } else if (checking == second_id_check) {  //두 번째 ID태그 노래 설정
    past_checking = symphonyNo9(buzzer, second_id_check);
  } else if (checking == third_id_check) {  //세 번째 ID태그 노래 설정
    past_checking = jigglypuff(buzzer, third_id_check);
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  Serial.println(F("=========================연주 끝========================="));
}