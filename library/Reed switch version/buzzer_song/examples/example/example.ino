#include <buzzer_song.h>
#define buzzer 7
#define reed 2

//�뷡 �Լ��� �ι�° ���ڴ� ���� ����ġ�� on,off ���� �Ǵ� �μ�

void setup()
{
	mario(buzzer, digitalRead(reed));
}

 void loop(){}