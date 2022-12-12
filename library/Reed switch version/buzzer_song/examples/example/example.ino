#include <buzzer_song.h>
#define buzzer 7
#define reed 2

//노래 함수의 두번째 인자는 리드 스위치의 on,off 여부 판단 인수

void setup()
{
	mario(buzzer, digitalRead(reed));
}

 void loop(){}