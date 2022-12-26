// reed switch version
/* 15곡 선택 가능
** caribbean(buzzer, reed_switch_pin);       영화 캐리비안의 해적 ost
** harrypotter(buzzer, reed_switch_pin);     영화 해리포터 ost
** pacman(buzzer, reed_switch_pin);          게임 팩맨 테마
** starWars(buzzer, reed_switch_pin);        영화 스타워즈 ost
** mario(buzzer, reed_switch_pin);           게임 슈퍼마리오 테마
** tetris(buzzer, reed_switch_pin);          게임 테트리스 테마
** minuetG(buzzer, reed_switch_pin);         클래식 Minuet in G major/바흐
** lionKing(buzzer, reed_switch_pin);        영화 라이온킹 ost
** symphonyNo9(buzzer, reed_switch_pin);     클래식 교향곡 9번/베토벤
** jigglypuff(buzzer, reed_switch_pin);      게임 포켓몬스터 푸린노래
** starTrek(buzzer, reed_switch_pin);        드라마 star trek ost
** badinerie(buzzer, reed_switch_pin);       클래식 바디네리/바흐
** godFather(buzzer, reed_switch_pin);       영화 대부 ost
** zeldaTheme(buzzer, reed_switch_pin);      게임 젤다의 전설 테마
** cannon(buzzer, reed_switch_pin);          클래식 캐논변주곡/파헬벨
*/
#include <buzzer_song.h>

int buzzer = 7;  //buzzer 핀 번호
int reed = 12;   //reed switch digital pin number
int state = 0;
int number = 0;

void setup() {
  pinMode(reed, INPUT);
  Serial.begin(9600);
  Serial.println(F("Serial start"));
  Serial.println(F("========================================================"));
}

void loop() {
  if (digitalRead(reed) == HIGH) {
    if (state == 0) {
      Serial.println(F("===================== Music Start ====================="));
      switch (number) {
        case 0:
          Serial.println(F("First song"));
          godFather(buzzer, reed);
          number += 1;
          break;
        case 1:
          Serial.println(F("Second song"));
          zeldaTheme(buzzer, reed);
          number += 1;
          break;
        case 2:
          Serial.println(F("Third song"));
          cannon(buzzer, reed);
          number = 0;
          break;
      }
      Serial.println(F("====================== Music End ======================"));
      state = 1;
    } else return;
  } else if (digitalRead(reed) == LOW) {
    state = 0;
  }
}