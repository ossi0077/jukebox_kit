#include <buzzer_song.h>  // buzzer �뷡 ���̺귯�� �߰�, buzzer pin number D7 ����
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);

MFRC522::MIFARE_Key key;

//NFC ��ƼĿ ���̵� �Է�
byte first_id[] = { 84, 66, 131, 234};
byte second_id[] = { 212, 64, 130, 234};
byte third_id[] = { 132, 127, 124, 234};

byte nuidPICC[4];
int first_id_check = 1;
int second_id_check = 1;
int third_id_check = 1;
int checking = 1;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }
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
  Serial.println(F("The NUID tag is:"));
  Serial.print(F("In hex: "));
  printHex(rfid.uid.uidByte, rfid.uid.size);
  Serial.println();
  Serial.print(F("In dec: "));
  printDec(rfid.uid.uidByte, rfid.uid.size);
  Serial.println();
  Serial.println();
  for (int i = 0; i < 4; i++) {
    checking = rfid.uid.uidByte[i] + checking;
  }
  Serial.print(F("ù ��° �±��� �ĺ� ��ȣ : "));
  Serial.println(first_id_check);
  Serial.print(F("�� ��° �±��� �ĺ� ��ȣ : "));
  Serial.println(second_id_check);
  Serial.print(F("�� ��° �±��� �ĺ� ��ȣ : "));
  Serial.println(third_id_check);
  Serial.print(F("�Էµ� �±��� �ĺ� ��ȣ : "));
  Serial.println(checking);
  Serial.println(F("=========================���� ����========================="));

  
/* 15�� ���� ����
** caribbean();       ��ȭ ĳ������� ���� ost
** harrypotter();     ��ȭ �ظ����� ost
** pacman();          ���� �Ѹ� �׸�
** starWars();        ��ȭ ��Ÿ���� ost
** mario();           ���� ���۸����� �׸�
** tetris();          ���� ��Ʈ���� �׸�
** minuetG();         Ŭ���� Minuet in G major/����
** lionKing();        ��ȭ ���̿�ŷ ost
** symphonyNo9();     Ŭ���� ����� 9��/���亥
** jigglypuff();      ���� ���ϸ��� Ǫ���뷡
** starTrek();        ��� star trek ost
** badinerie();       Ŭ���� �ٵ�׸�/����
** godFather();       ��ȭ ��� ost
** zeldaTheme();      ���� ������ ���� �׸�
** cannon();          Ŭ���� ĳ���ְ�/���ﺧ
*/
// RFID ID�� �뷡 ���� �κ�
  if (checking == first_id_check)       //ù ��° ID�±� �뷡 ����
    caribbean();
  else if (checking == second_id_check) //�� ��° ID�±� �뷡 ����
    mario();
  else if(checking == third_id_check)   //�� ��° ID�±� �뷡 ����
    lionKing();

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  Serial.println(F("=========================���� ��========================="));
}

void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

void printDec(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], DEC);
  }
}