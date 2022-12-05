#include <SPI.h>
#include <MFRC522.h>
 
#define RST_PIN   9                            // reset���� 9������ ����
#define SS_PIN    10                           // SS���� 10������ ����
                                               // SS���� �����͸� �ְ�޴� ������ ��( SS = Slave Selector )
 
MFRC522 mfrc(SS_PIN, RST_PIN);                 // MFR522�� �̿��ϱ� ���� mfrc��ü�� ������ �ݴϴ�.
 
void setup(){
  Serial.begin(9600);                         // �ø��� ���, �ӵ��� 9600
  SPI.begin();                                // SPI �ʱ�ȭ
                                              // (SPI : �ϳ��� �����Ϳ� �ټ��� SLAVE(�������� ��Ȱ)���� ��� ���)
  mfrc.PCD_Init();                               
}
 
void loop(){
  if ( !mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial() ) {   
                                               // �±� ������ ���� �ʾ����� �Ǵ� ID�� �������� �ʾ�����
    delay(500);                                // 0.5�� ������ 
    return;                                    // return
  } 
    
  Serial.print("Card UID:");                  // �±��� ID���
  
  for (byte i = 0; i < 4; i++) {               // �±��� ID����ϴ� �ݺ���.�±��� ID������(4)����
    Serial.print(mfrc.uid.uidByte[i]);        // mfrc.uid.uidByte[0] ~ mfrc.uid.uidByte[3]���� ���
    Serial.print(" ");                        // id ������ ���� ���
  }
  Serial.println(); 
}
