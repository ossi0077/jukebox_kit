#include "Arduino.h"
#include "avr/pgmspace.h"

int buzzer = 7;            //buzzer pin number

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST 0

//Mario
const int melody_mario_raw[] PROGMEM = {
        NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,8, //1
        NOTE_G5,4, REST,4, NOTE_G4,8, REST,4,
        NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 3
        NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
        NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
        REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
        NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 3
        NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
        NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
        REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,


        REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//7
        REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
        REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
        NOTE_C5,2, REST,2,

        REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//repeats from 7
        REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
        REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
        NOTE_C5,2, REST,2,

        NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4,//11
        NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,

        NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8,//13
        REST,1,
        NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4,
        NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,
        NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,4,
        NOTE_G5,4, REST,4, NOTE_G4,4, REST,4,
        NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 19

        NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
        NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
        REST,8, NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

        NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 19
        NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
        NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
        REST,8, NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

        NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,//23
        NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
        NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,

        NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //26
        NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
        NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
        NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
        NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,

        NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,//repeats from 23
        NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
        NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,

        NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //26
        NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
        NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
        NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
        NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,
        NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8,
        REST,1,

        NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4, //33
        NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,
        NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,4,
        NOTE_G5,4, REST,4, NOTE_G4,4, REST,4,
        NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
        NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
        NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,

        NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //40
        NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
        NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
        NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
        NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,

        NOTE_C5,-4, NOTE_G4,-4, NOTE_E4,4, //45
        NOTE_A4,-8, NOTE_B4,-8, NOTE_A4,-8, NOTE_GS4,-8, NOTE_AS4,-8, NOTE_GS4,-8,
        NOTE_G4,8, NOTE_D4,8, NOTE_E4,-2,

};
const int num_mario = sizeof(melody_mario_raw) / sizeof(melody_mario_raw[0]);

//Pachelbel's Cannon
const int melody_cannon_raw[] PROGMEM = {
    NOTE_FS4,2, NOTE_E4,2,
    NOTE_D4,2, NOTE_CS4,2,
    NOTE_B3,2, NOTE_A3,2,
    NOTE_B3,2, NOTE_CS4,2,
    NOTE_FS4,2, NOTE_E4,2,
    NOTE_D4,2, NOTE_CS4,2,
    NOTE_B3,2, NOTE_A3,2,
    NOTE_B3,2, NOTE_CS4,2,
    NOTE_D4,2, NOTE_CS4,2,
    NOTE_B3,2, NOTE_A3,2,
    NOTE_G3,2, NOTE_FS3,2,
    NOTE_G3,2, NOTE_A3,2,

    NOTE_D4,4, NOTE_FS4,8, NOTE_G4,8, NOTE_A4,4, NOTE_FS4,8, NOTE_G4,8,
    NOTE_A4,4, NOTE_B3,8, NOTE_CS4,8, NOTE_D4,8, NOTE_E4,8, NOTE_FS4,8, NOTE_G4,8,
    NOTE_FS4,4, NOTE_D4,8, NOTE_E4,8, NOTE_FS4,4, NOTE_FS3,8, NOTE_G3,8,
    NOTE_A3,8, NOTE_G3,8, NOTE_FS3,8, NOTE_G3,8, NOTE_A3,2,
    NOTE_G3,4, NOTE_B3,8, NOTE_A3,8, NOTE_G3,4, NOTE_FS3,8, NOTE_E3,8,
    NOTE_FS3,4, NOTE_D3,8, NOTE_E3,8, NOTE_FS3,8, NOTE_G3,8, NOTE_A3,8, NOTE_B3,8,

    NOTE_G3,4, NOTE_B3,8, NOTE_A3,8, NOTE_B3,4, NOTE_CS4,8, NOTE_D4,8,
    NOTE_A3,8, NOTE_B3,8, NOTE_CS4,8, NOTE_D4,8, NOTE_E4,8, NOTE_FS4,8, NOTE_G4,8, NOTE_A4,2,
    NOTE_A4,4, NOTE_FS4,8, NOTE_G4,8, NOTE_A4,4,
    NOTE_FS4,8, NOTE_G4,8, NOTE_A4,8, NOTE_A3,8, NOTE_B3,8, NOTE_CS4,8,
    NOTE_D4,8, NOTE_E4,8, NOTE_FS4,8, NOTE_G4,8, NOTE_FS4,4, NOTE_D4,8, NOTE_E4,8,
    NOTE_FS4,8, NOTE_CS4,8, NOTE_A3,8, NOTE_A3,8,

    NOTE_CS4,4, NOTE_B3,4, NOTE_D4,8, NOTE_CS4,8, NOTE_B3,4,
    NOTE_A3,8, NOTE_G3,8, NOTE_A3,4, NOTE_D3,8, NOTE_E3,8, NOTE_FS3,8, NOTE_G3,8,
    NOTE_A3,8, NOTE_B3,4, NOTE_G3,4, NOTE_B3,8, NOTE_A3,8, NOTE_B3,4,
    NOTE_CS4,8, NOTE_D4,8, NOTE_A3,8, NOTE_B3,8, NOTE_CS4,8, NOTE_D4,8, NOTE_E4,8,
    NOTE_FS4,8, NOTE_G4,8, NOTE_A4,2,


};
const int num_cannon = sizeof(melody_cannon_raw) / sizeof(melody_cannon_raw[0]);

//The legend of Zelda theme
const int melody_zeldaTheme_raw[] PROGMEM = {
    NOTE_AS4,-2,  NOTE_F4,8,  NOTE_F4,8,  NOTE_AS4,8,//1
    NOTE_GS4,16,  NOTE_FS4,16,  NOTE_GS4,-2,
    NOTE_AS4,-2,  NOTE_FS4,8,  NOTE_FS4,8,  NOTE_AS4,8,
    NOTE_A4,16,  NOTE_G4,16,  NOTE_A4,-2,
    REST,1,

    NOTE_AS4,4,  NOTE_F4,-4,  NOTE_AS4,8,  NOTE_AS4,16,  NOTE_C5,16, NOTE_D5,16, NOTE_DS5,16,//7
    NOTE_F5,2,  NOTE_F5,8,  NOTE_F5,8,  NOTE_F5,8,  NOTE_FS5,16, NOTE_GS5,16,
    NOTE_AS5,-2,  NOTE_AS5,8,  NOTE_AS5,8,  NOTE_GS5,8,  NOTE_FS5,16,
    NOTE_GS5,-8,  NOTE_FS5,16,  NOTE_F5,2,  NOTE_F5,4,

    NOTE_DS5,-8, NOTE_F5,16, NOTE_FS5,2, NOTE_F5,8, NOTE_DS5,8, //11
    NOTE_CS5,-8, NOTE_DS5,16, NOTE_F5,2, NOTE_DS5,8, NOTE_CS5,8,
    NOTE_C5,-8, NOTE_D5,16, NOTE_E5,2, NOTE_G5,8,
    NOTE_F5,16, NOTE_F4,16, NOTE_F4,16, NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,8, NOTE_F4,16,NOTE_F4,8,

    NOTE_AS4,4,  NOTE_F4,-4,  NOTE_AS4,8,  NOTE_AS4,16,  NOTE_C5,16, NOTE_D5,16, NOTE_DS5,16,//15
    NOTE_F5,2,  NOTE_F5,8,  NOTE_F5,8,  NOTE_F5,8,  NOTE_FS5,16, NOTE_GS5,16,
    NOTE_AS5,-2, NOTE_CS6,4,
    NOTE_C6,4, NOTE_A5,2, NOTE_F5,4,
    NOTE_FS5,-2, NOTE_AS5,4,
    NOTE_A5,4, NOTE_F5,2, NOTE_F5,4,

    NOTE_FS5,-2, NOTE_AS5,4,
    NOTE_A5,4, NOTE_F5,2, NOTE_D5,4,
    NOTE_DS5,-2, NOTE_FS5,4,
    NOTE_F5,4, NOTE_CS5,2, NOTE_AS4,4,
    NOTE_C5,-8, NOTE_D5,16, NOTE_E5,2, NOTE_G5,8,
    NOTE_F5,16, NOTE_F4,16, NOTE_F4,16, NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,8, NOTE_F4,16,NOTE_F4,8

};
const int num_zeldaTheme = sizeof(melody_zeldaTheme_raw) / sizeof(melody_zeldaTheme_raw[0]);

// The Godfather
const int melody_godFather_raw[] PROGMEM = {
    REST, 4, REST, 8, REST, 8, REST, 8, NOTE_E4, 8, NOTE_A4, 8, NOTE_C5, 8, //1
    NOTE_B4, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_A4, 8, NOTE_B4, 8, NOTE_A4, 8, NOTE_F4, 8, NOTE_G4, 8,
    NOTE_E4, 2, NOTE_E4, 8, NOTE_A4, 8, NOTE_C5, 8,
    NOTE_B4, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_A4, 8, NOTE_E4, 8, NOTE_DS4, 8,

    NOTE_D4, 2, NOTE_D4, 8, NOTE_F4, 8, NOTE_GS4, 8, //5
    NOTE_B4, 2, NOTE_D4, 8, NOTE_F4, 8, NOTE_GS4, 8,
    NOTE_A4, 2, NOTE_C4, 8, NOTE_C4, 8, NOTE_G4, 8,
    NOTE_F4, 8, NOTE_E4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_F4, 8, NOTE_E4, 8, NOTE_E4, 8, NOTE_GS4, 8,

    NOTE_A4, 2, REST,8, NOTE_A4, 8, NOTE_A4, 8, NOTE_GS4, 8, //9
    NOTE_G4, 2, NOTE_B4, 8, NOTE_A4, 8, NOTE_F4, 8,
    NOTE_E4, 2, NOTE_E4, 8, NOTE_G4, 8, NOTE_E4, 8,
    NOTE_D4, 2, NOTE_D4, 8, NOTE_D4, 8, NOTE_F4, 8, NOTE_DS4, 8,

    NOTE_E4, 2, REST, 8, NOTE_E4, 8, NOTE_A4, 8, NOTE_C5, 8, //13

    //repeats from 2
    NOTE_B4, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_A4, 8, NOTE_B4, 8, NOTE_A4, 8, NOTE_F4, 8, NOTE_G4, 8, //2
    NOTE_E4, 2, NOTE_E4, 8, NOTE_A4, 8, NOTE_C5, 8,
    NOTE_B4, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_A4, 8, NOTE_E4, 8, NOTE_DS4, 8,

    NOTE_D4, 2, NOTE_D4, 8, NOTE_F4, 8, NOTE_GS4, 8, //5
    NOTE_B4, 2, NOTE_D4, 8, NOTE_F4, 8, NOTE_GS4, 8,
    NOTE_A4, 2, NOTE_C4, 8, NOTE_C4, 8, NOTE_G4, 8,
    NOTE_F4, 8, NOTE_E4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_F4, 8, NOTE_E4, 8, NOTE_E4, 8, NOTE_GS4, 8,

    NOTE_A4, 2, REST,8, NOTE_A4, 8, NOTE_A4, 8, NOTE_GS4, 8, //9
    NOTE_G4, 2, NOTE_B4, 8, NOTE_A4, 8, NOTE_F4, 8,
    NOTE_E4, 2, NOTE_E4, 8, NOTE_G4, 8, NOTE_E4, 8,
    NOTE_D4, 2, NOTE_D4, 8, NOTE_D4, 8, NOTE_F4, 8, NOTE_DS4, 8,

    NOTE_E4, 2 //13
};
const int num_godFather = sizeof(melody_godFather_raw) / sizeof(melody_godFather_raw[0]);

//Bach - Badinerie
const int melody_badinerie_raw[] PROGMEM = {
     NOTE_B5,-8, NOTE_D6,16, NOTE_B5,16,
     NOTE_FS5,-8, NOTE_B5,16, NOTE_FS5,16, NOTE_D5,-8, NOTE_FS5,16, NOTE_D5,16,
     NOTE_B4,4,NOTE_F4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
     NOTE_CS5,16, NOTE_B4,16, NOTE_CS5,16, NOTE_B4,16, NOTE_AS4,16, NOTE_CS5,16, NOTE_E5,16, NOTE_CS5,16,
     NOTE_D5,8, NOTE_B4,8, NOTE_B5,-8, NOTE_D6,16, NOTE_B5,16,
     NOTE_FS5,-8, NOTE_B5,16, NOTE_FS5,16, NOTE_D5,-8, NOTE_FS5,16, NOTE_D5,16,
     //6
     NOTE_B4,4, NOTE_D5,16, NOTE_CS5,-16, NOTE_D5,-8,
     NOTE_D5,16, NOTE_CS5,-16, NOTE_D5,-8, NOTE_B5,-8, NOTE_D5,-8,
     NOTE_D5,8, NOTE_CS5,-8, NOTE_FS5,-16, /*MI#*/ NOTE_F5,16, NOTE_FS5,-8,
     NOTE_FS5,-16, /* MI#??*/NOTE_F5,16, NOTE_FS5,-8, NOTE_D6,-8, NOTE_FS5,-8,
     NOTE_FS5,8, /*MI#*/ NOTE_F5,8, NOTE_CS5,16, NOTE_FS5,16, NOTE_A5,16, NOTE_FS5,16,
     NOTE_GS5,16, NOTE_FS5,16, NOTE_GS5,16, NOTE_FS5,16, NOTE_F5,16, NOTE_G5,16, NOTE_B5,16, NOTE_G5,16,
     //12
     NOTE_A5,16, NOTE_GS5,16, NOTE_A5,16, NOTE_G5,16, NOTE_F5,16, NOTE_A5,16, NOTE_FS5,16, NOTE_F5,16,
     NOTE_FS5,16, NOTE_B5,16,  NOTE_FS5,16, NOTE_F5,16, NOTE_FS5,16, NOTE_C6,16, NOTE_FS5,16, NOTE_E5,16,
     NOTE_FS5,16, NOTE_D6,16, NOTE_FS5,16, NOTE_F5,16, NOTE_FS5,16, NOTE_D6,16, NOTE_C6,16, NOTE_B5,16,
     NOTE_C6,16, NOTE_A5,16, NOTE_GS5,16, NOTE_FS5,16, NOTE_A5,8, NOTE_G5,8,
     NOTE_FS5,4, REST,4, NOTE_FS5,-8, NOTE_A5,16, NOTE_FS5,16,
     //18
     NOTE_CS5,-4, NOTE_FS5,16, NOTE_CS5,16, NOTE_A4,-8, NOTE_CS5,16, NOTE_A4,16,
     NOTE_F4,4,   NOTE_C5,8, NOTE_B4,8,
     NOTE_E5,8, NOTE_DS5,16, NOTE_FS5,16, NOTE_A5,8, NOTE_GS5,16, NOTE_FS5,16,
     NOTE_GS5,8, NOTE_D5,8, NOTE_GS5,-8, NOTE_B5,16, NOTE_GS5,8,
     NOTE_E5,-8, NOTE_GS5,16, NOTE_E5,16, NOTE_CS5,-8, NOTE_E5,16, NOTE_CS5,16,
     NOTE_A4,4, NOTE_A4,16, NOTE_D5,16, NOTE_FS5,16, NOTE_D5,16,
     //24
     NOTE_E5,16, NOTE_D5,16, NOTE_E5,16, NOTE_D5,16, NOTE_CS5,16, NOTE_E5,16, NOTE_G5,16, NOTE_E5,16,
     NOTE_FS5,16, NOTE_E5,16, NOTE_FS5,16, NOTE_E5,16, NOTE_D5,16, NOTE_FS5,16, NOTE_D5,16, NOTE_CS5,16,
     NOTE_D5,16, NOTE_G5,16, NOTE_D5,16, NOTE_CS5,16, NOTE_D5,16, NOTE_A5,16, NOTE_D5,16, NOTE_CS5,16,
     NOTE_D5,16, NOTE_B5,16, NOTE_D5,16, NOTE_CS5,16, NOTE_D5,16, NOTE_B5,16, NOTE_A5,16, NOTE_G5,16,
     NOTE_A5,16, NOTE_FS5,16, NOTE_E5,16, NOTE_D5,16, NOTE_FS5,8, NOTE_E5,16,
     //29
     NOTE_D5,4, NOTE_FS5,16, NOTE_E5,16, NOTE_FS5,-8,
     NOTE_FS5,16, NOTE_E5,16, NOTE_FS5,-8, NOTE_D6,-8, NOTE_FS5,-8,
     NOTE_FS5,8, NOTE_E5,8, NOTE_E5,16, NOTE_D5,16, NOTE_E5,-8,
     NOTE_E5,16, NOTE_D5,16, NOTE_E5,-8, NOTE_D6,-8, NOTE_E5,-8,
     NOTE_E5,8, NOTE_D5,8, NOTE_B5,-8, NOTE_D6,16, NOTE_B5,16,
     NOTE_B5,8, NOTE_G5,4, NOTE_G5,4, NOTE_B5,32, NOTE_A5,32, NOTE_G5,32, NOTE_FS5,32,
     //35
     NOTE_E5,4, NOTE_E5,8, NOTE_G5,32, NOTE_FS5,32, NOTE_E5,32, NOTE_D5,32,
     NOTE_C5,16, NOTE_E5,16, NOTE_G5,16, NOTE_E5,16, NOTE_CS5,16, NOTE_B4,16, NOTE_CS5,16, NOTE_A4,16,
     NOTE_AS4,-8, NOTE_A4,-8, NOTE_G4,8, NOTE_F4,8,
     NOTE_A4,8, NOTE_AS4,16, NOTE_CS5,16, NOTE_E5,8, NOTE_D5,16, NOTE_CS5,16,
     //39
     NOTE_D5,8, NOTE_B4,32, NOTE_CS5,32, NOTE_D5,32, NOTE_E5,32, NOTE_FS5,8, NOTE_D5,16, NOTE_FS5,16,
     NOTE_B5,8, NOTE_FS5,8, NOTE_E5,16, NOTE_D5,16, NOTE_CS5,16, NOTE_D5,16,
     NOTE_CS5,8, NOTE_B4,4
};
const int num_badinerie = sizeof(melody_badinerie_raw) / sizeof(melody_badinerie_raw[0]);

//Jigglypuff's Song
const int melody_jigglypuff_raw[] PROGMEM = {
    NOTE_D5,-4, NOTE_A5,8, NOTE_FS5,8, NOTE_D5,8,
    NOTE_E5,-4, NOTE_FS5,8, NOTE_G5,4,
    NOTE_FS5,-4, NOTE_E5,8, NOTE_FS5,4,
    NOTE_D5,-2,
    NOTE_D5,-4, NOTE_A5,8, NOTE_FS5,8, NOTE_D5,8,
    NOTE_E5,-4, NOTE_FS5,8, NOTE_G5,4,
    NOTE_FS5,-1,
    NOTE_D5,-4, NOTE_A5,8, NOTE_FS5,8, NOTE_D5,8,
    NOTE_E5,-4, NOTE_FS5,8, NOTE_G5,4,

    NOTE_FS5,-4, NOTE_E5,8, NOTE_FS5,4,
    NOTE_D5,-2,
    NOTE_D5,-4, NOTE_A5,8, NOTE_FS5,8, NOTE_D5,8,
    NOTE_E5,-4, NOTE_FS5,8, NOTE_G5,4,
    NOTE_FS5,-1,

};
const int num_jigglypuff = sizeof(melody_jigglypuff_raw) / sizeof(melody_jigglypuff_raw[0]);

//Ode to Joy - Beethoven's Symphony No. 9
const int melody_symphonyNo9_raw[] PROGMEM = {
  NOTE_E4,4,  NOTE_E4,4,  NOTE_F4,4,  NOTE_G4,4,//1
  NOTE_G4,4,  NOTE_F4,4,  NOTE_E4,4,  NOTE_D4,4,
  NOTE_C4,4,  NOTE_C4,4,  NOTE_D4,4,  NOTE_E4,4,
  NOTE_E4,-4, NOTE_D4,8,  NOTE_D4,2,

  NOTE_E4,4,  NOTE_E4,4,  NOTE_F4,4,  NOTE_G4,4,//4
  NOTE_G4,4,  NOTE_F4,4,  NOTE_E4,4,  NOTE_D4,4,
  NOTE_C4,4,  NOTE_C4,4,  NOTE_D4,4,  NOTE_E4,4,
  NOTE_D4,-4,  NOTE_C4,8,  NOTE_C4,2,

  NOTE_D4,4,  NOTE_D4,4,  NOTE_E4,4,  NOTE_C4,4,//8
  NOTE_D4,4,  NOTE_E4,8,  NOTE_F4,8,  NOTE_E4,4, NOTE_C4,4,
  NOTE_D4,4,  NOTE_E4,8,  NOTE_F4,8,  NOTE_E4,4, NOTE_D4,4,
  NOTE_C4,4,  NOTE_D4,4,  NOTE_G3,2,

  NOTE_E4,4,  NOTE_E4,4,  NOTE_F4,4,  NOTE_G4,4,//12
  NOTE_G4,4,  NOTE_F4,4,  NOTE_E4,4,  NOTE_D4,4,
  NOTE_C4,4,  NOTE_C4,4,  NOTE_D4,4,  NOTE_E4,4,
  NOTE_D4,-4,  NOTE_C4,8,  NOTE_C4,2

};
const int num_symphonyNo9 = sizeof(melody_symphonyNo9_raw) / sizeof(melody_symphonyNo9_raw[0]);

//The Lion sleeps tonight (A-weema-weh)
const int melody_lion_raw[] PROGMEM = {
    NOTE_F4, 4, NOTE_G4, 4, NOTE_A4, 8, NOTE_G4, 4, NOTE_A4, 8, //1
    NOTE_AS4, 4, NOTE_A4, 4, NOTE_G4, 8, NOTE_F4, 4, NOTE_G4, 8,
    NOTE_A4, 4, NOTE_C4, 8, NOTE_C4, 4, NOTE_C4, 8, NOTE_C4, 4,
    NOTE_C4, 1, //1st ending

    NOTE_F4, 4, NOTE_G4, 4, NOTE_A4, 8, NOTE_G4, 4, NOTE_A4, 8, //repeats from 1
    NOTE_AS4, 4, NOTE_A4, 4, NOTE_G4, 8, NOTE_F4, 4, NOTE_G4, 8,
    NOTE_A4, 4, NOTE_C4, 8, NOTE_C4, 4, NOTE_C4, 8, NOTE_C4, 4,
    NOTE_C4, -2,  REST, -8, NOTE_A4, 16, //2nd ending

    NOTE_A4, -8, NOTE_A4, 16, NOTE_A4, -8, NOTE_A4, 16, NOTE_A4, -8, NOTE_A4, 16, NOTE_A4, -8, NOTE_A4, 16, //6
    NOTE_AS4, -8, NOTE_AS4, 16, NOTE_AS4, -8, NOTE_AS4, 16, NOTE_AS4, -8, NOTE_AS4, 16, NOTE_AS4, -8, NOTE_AS4, 16,
    NOTE_A4, -8, NOTE_A4, 16, NOTE_A4, -8, NOTE_A4, 16, NOTE_A4, -8, NOTE_A4, 16, NOTE_A4, -8, NOTE_A4, 16,
    NOTE_G4, -8, NOTE_G4, 16, NOTE_G4, -8, NOTE_G4, 16, NOTE_G4, -8, NOTE_G4, 16, NOTE_G4, -8, NOTE_G4, 16,

    NOTE_A4, -8, NOTE_A4, 16, NOTE_A4, -8, NOTE_A4, 16, NOTE_A4, -8, NOTE_A4, 16, NOTE_A4, -8, NOTE_A4, 16, //10
    NOTE_AS4, -8, NOTE_AS4, 16, NOTE_AS4, -8, NOTE_AS4, 16, NOTE_AS4, -8, NOTE_AS4, 16, NOTE_AS4, -8, NOTE_AS4, 16,
    NOTE_A4, -8, NOTE_A4, 16, NOTE_A4, -8, NOTE_A4, 16, NOTE_A4, -8, NOTE_A4, 16, NOTE_A4, -8, NOTE_A4, 16,
    NOTE_G4, -8, NOTE_G4, 16, NOTE_G4, -8, NOTE_G4, 16, NOTE_G4, -8, NOTE_G4, 16, NOTE_G4, -8, NOTE_G4, 16,

    NOTE_F4, 4, NOTE_G4, 4, NOTE_A4, 8, NOTE_G4, 4, NOTE_A4, 8, //14
    NOTE_AS4, 4, NOTE_A4, 4, NOTE_G4, 8, NOTE_F4, 4, NOTE_G4, 8,
    NOTE_A4, 4, NOTE_G4, 4, NOTE_F4, 4, NOTE_A4, 4,
    NOTE_G4, 1,
    NOTE_C5, 4, NOTE_A4, 4, NOTE_G4, 8, NOTE_A4, 4, NOTE_C5, 8,
    NOTE_AS4, 4, NOTE_A4, 4, NOTE_G4, 8, NOTE_F4, 4, NOTE_G4, 8,
    NOTE_A4, 4, NOTE_G4, 4, NOTE_F4, 4, NOTE_A4, 4,
    NOTE_G4, 1,

    NOTE_C5, 1, //22
    NOTE_C5, 4, NOTE_AS4, 8, NOTE_C5, 8, NOTE_AS4, 2,
    NOTE_A4, 4, NOTE_C4, 8, NOTE_C4, 4, NOTE_C4, 8, NOTE_C4, 4,
    NOTE_C4, 1,

    REST, 4, NOTE_A4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_E4, 8, NOTE_D4, 8, NOTE_C4, 8,
    NOTE_D4, 1,
    REST, 4, NOTE_A4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_E4, 8, NOTE_D4, 8, NOTE_C4, 8,
    NOTE_D4, 1,

    NOTE_F4, 4, NOTE_G4, 4, NOTE_A4, 8, NOTE_G4, 4, NOTE_A4, 8, //repeats from 14
    NOTE_AS4, 4, NOTE_A4, 4, NOTE_G4, 8, NOTE_F4, 4, NOTE_G4, 8,
    NOTE_A4, 4, NOTE_G4, 4, NOTE_F4, 4, NOTE_A4, 4,
    NOTE_G4, 1,
    NOTE_C5, 4, NOTE_A4, 4, NOTE_G4, 8, NOTE_A4, 4, NOTE_C5, 8,
    NOTE_AS4, 4, NOTE_A4, 4, NOTE_G4, 8, NOTE_F4, 4, NOTE_G4, 8,
    NOTE_A4, 4, NOTE_G4, 4, NOTE_F4, 4, NOTE_A4, 4,
    NOTE_G4, 1,

    NOTE_C5, 1, //22
    NOTE_C5, 4, NOTE_AS4, 8, NOTE_C5, 8, NOTE_AS4, 2,
    NOTE_A4, 4, NOTE_C4, 8, NOTE_C4, 4, NOTE_C4, 8, NOTE_C4, 4,
    NOTE_C4, 1,

    REST, 4, NOTE_A4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_E4, 8, NOTE_D4, 8, NOTE_C4, 8,
    NOTE_D4, 1,
    REST, 4, NOTE_A4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_E4, 8, NOTE_D4, 8, NOTE_C4, 8,
    NOTE_D4, 1,

    NOTE_F4, 4, NOTE_G4, 4, NOTE_A4, 8, NOTE_G4, 4, NOTE_A4, 8, //30
    NOTE_AS4, 4, NOTE_A4, 4, NOTE_G4, 8, NOTE_F4, 4, NOTE_G4, 8,
    NOTE_A4, 4, NOTE_C4, 8, NOTE_C4, 4, NOTE_C4, 8, NOTE_C4, 4,
    NOTE_C4, 1,

    NOTE_F4, 4, NOTE_G4, 4, NOTE_A4, 8, NOTE_G4, 4, NOTE_A4, 8, //repeats from 14 (again)
    NOTE_AS4, 4, NOTE_A4, 4, NOTE_G4, 8, NOTE_F4, 4, NOTE_G4, 8,
    NOTE_A4, 4, NOTE_G4, 4, NOTE_F4, 4, NOTE_A4, 4,
    NOTE_G4, 1,
    NOTE_C5, 4, NOTE_A4, 4, NOTE_G4, 8, NOTE_A4, 4, NOTE_C5, 8,
    NOTE_AS4, 4, NOTE_A4, 4, NOTE_G4, 8, NOTE_F4, 4, NOTE_G4, 8,
    NOTE_A4, 4, NOTE_G4, 4, NOTE_F4, 4, NOTE_A4, 4,
    NOTE_G4, 1,

    NOTE_C5, 1, //22
    NOTE_C5, 4, NOTE_AS4, 8, NOTE_C5, 8, NOTE_AS4, 2,
    NOTE_A4, 4, NOTE_C4, 8, NOTE_C4, 4, NOTE_C4, 8, NOTE_C4, 4,
    NOTE_C4, 1,

    REST, 4, NOTE_A4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_E4, 8, NOTE_D4, 8, NOTE_C4, 8,
    NOTE_D4, 1,
    REST, 4, NOTE_A4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_E4, 8, NOTE_D4, 8, NOTE_C4, 8,
    NOTE_D4, 1,

    NOTE_F4, 4, NOTE_G4, 4, NOTE_A4, 8, NOTE_G4, 4, NOTE_A4, 8, //30
    NOTE_AS4, 4, NOTE_A4, 4, NOTE_G4, 8, NOTE_F4, 4, NOTE_G4, 8,
    NOTE_A4, 4, NOTE_C4, 8, NOTE_C4, 4, NOTE_C4, 8, NOTE_C4, 4,
    NOTE_C4, 1,

};
const int num_lion = sizeof(melody_lion_raw) / sizeof(melody_lion_raw[0]);

//Minuet in G - C. Petzold
const int melody_minuetG_raw[] PROGMEM = {
    NOTE_D5,4, NOTE_G4,8, NOTE_A4,8, NOTE_B4,8, NOTE_C5,8, //1
    NOTE_D5,4, NOTE_G4,4, NOTE_G4,4,
    NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8, NOTE_FS5,8,
    NOTE_G5,4, NOTE_G4,4, NOTE_G4,4,
    NOTE_C5,4, NOTE_D5,8, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8,

    NOTE_B4,4, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8, NOTE_G4,8,//6
    NOTE_FS4,4, NOTE_G4,8, NOTE_A4,8, NOTE_B4,8, NOTE_G4,8,
    NOTE_A4,-2,
    NOTE_D5,4, NOTE_G4,8, NOTE_A4,8, NOTE_B4,8, NOTE_C5,8,
    NOTE_D5,4, NOTE_G4,4, NOTE_G4,4,
    NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8, NOTE_FS5,8,

    NOTE_G5,4, NOTE_G4,4, NOTE_G4,4,
    NOTE_C5,4, NOTE_D5,8, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8, //12
    NOTE_B4,4, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8, NOTE_G4,8,
    NOTE_A4,4, NOTE_B4,8, NOTE_A4,8, NOTE_G4,8, NOTE_FS4,8,
    NOTE_G4,-2,

    //repeats from 1

    NOTE_D5,4, NOTE_G4,8, NOTE_A4,8, NOTE_B4,8, NOTE_C5,8, //1
    NOTE_D5,4, NOTE_G4,4, NOTE_G4,4,
    NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8, NOTE_FS5,8,
    NOTE_G5,4, NOTE_G4,4, NOTE_G4,4,
    NOTE_C5,4, NOTE_D5,8, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8,

    NOTE_B4,4, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8, NOTE_G4,8,//6
    NOTE_FS4,4, NOTE_G4,8, NOTE_A4,8, NOTE_B4,8, NOTE_G4,8,
    NOTE_A4,-2,
    NOTE_D5,4, NOTE_G4,8, NOTE_A4,8, NOTE_B4,8, NOTE_C5,8,
    NOTE_D5,4, NOTE_G4,4, NOTE_G4,4,
    NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8, NOTE_FS5,8,

    NOTE_G5,4, NOTE_G4,4, NOTE_G4,4,
    NOTE_C5,4, NOTE_D5,8, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8, //12
    NOTE_B4,4, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8, NOTE_G4,8,
    NOTE_A4,4, NOTE_B4,8, NOTE_A4,8, NOTE_G4,8, NOTE_FS4,8,
    NOTE_G4,-2,

    //continues from 17

    NOTE_B5,4, NOTE_G5,8, NOTE_A5,8, NOTE_B5,8, NOTE_G5,8,//17
    NOTE_A5,4, NOTE_D5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_D5,8,
    NOTE_G5,4, NOTE_E5,8, NOTE_FS5,8, NOTE_G5,8, NOTE_D5,8,
    NOTE_CS5,4, NOTE_B4,8, NOTE_CS5,8, NOTE_A4,4,
    NOTE_A4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_E5,8, NOTE_FS5,8,

    NOTE_G5,4, NOTE_FS5,4, NOTE_E5,4, //22
    NOTE_FS5,4, NOTE_A4,4, NOTE_CS5,4,
    NOTE_D5,-2,
    NOTE_D5,4, NOTE_G4,8, NOTE_FS5,8, NOTE_G4,4,
    NOTE_E5,4,  NOTE_G4,8, NOTE_FS4,8, NOTE_G4,4,
    NOTE_D5,4, NOTE_C5,4, NOTE_B4,4,

    NOTE_A4,8, NOTE_G4,8, NOTE_FS4,8, NOTE_G4,8, NOTE_A4,4, //28
    NOTE_D4,8, NOTE_E4,8, NOTE_FS4,8, NOTE_G4,8, NOTE_A4,8, NOTE_B4,8,
    NOTE_C5,4, NOTE_B4,4, NOTE_A4,4,
    NOTE_B4,8, NOTE_D5,8, NOTE_G4,4, NOTE_FS4,4,
    NOTE_G4,-2,





};
const int num_minuetG = sizeof(melody_minuetG_raw) / sizeof(melody_minuetG_raw[0]);

//Tetris melody
const int melody_tetris_raw[] PROGMEM = {
    NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
    NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
    NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
    NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

    NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
    NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
    NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
    NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,

    NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
    NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
    NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
    NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

    NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
    NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
    NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
    NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,


    NOTE_E5,2,  NOTE_C5,2,
    NOTE_D5,2,   NOTE_B4,2,
    NOTE_C5,2,   NOTE_A4,2,
    NOTE_GS4,2,  NOTE_B4,4,  REST,8,
    NOTE_E5,2,   NOTE_C5,2,
    NOTE_D5,2,   NOTE_B4,2,
    NOTE_C5,4,   NOTE_E5,4,  NOTE_A5,2,
    NOTE_GS5,2,

};
const int num_tetris = sizeof(melody_tetris_raw) / sizeof(melody_tetris_raw[0]);

//Star Wars melody
const int melody_starWars_raw[] PROGMEM = {
    NOTE_AS4,8, NOTE_AS4,8, NOTE_AS4,8,//1
    NOTE_F5,2, NOTE_C6,2,
    NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,
    NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,
    NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,8, NOTE_C5,8, NOTE_C5,8,
    NOTE_F5,2, NOTE_C6,2,
    NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,

    NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4, //8  
    NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,-8, NOTE_C5,16,
    NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
    NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C5,-8, NOTE_C5,16,
    NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,

    NOTE_C6,-8, NOTE_G5,16, NOTE_G5,2, REST,8, NOTE_C5,8,//13
    NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
    NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C6,-8, NOTE_C6,16,
    NOTE_F6,4, NOTE_DS6,8, NOTE_CS6,4, NOTE_C6,8, NOTE_AS5,4, NOTE_GS5,8, NOTE_G5,4, NOTE_F5,8,
    NOTE_C6,1

};
const int num_starWars = sizeof(melody_starWars_raw) / sizeof(melody_starWars_raw[0]);

//harry potter melody
const int melody_harry_raw[] PROGMEM = {
    REST, 2, NOTE_D4, 4,
    NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
    NOTE_G4, 2, NOTE_D5, 4,
    NOTE_C5, -2,
    NOTE_A4, -2,
    NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
    NOTE_F4, 2, NOTE_GS4, 4,
    NOTE_D4, -1,
    NOTE_D4, 4,

    NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4, //10
    NOTE_G4, 2, NOTE_D5, 4,
    NOTE_F5, 2, NOTE_E5, 4,
    NOTE_DS5, 2, NOTE_B4, 4,
    NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
    NOTE_CS4, 2, NOTE_B4, 4,
    NOTE_G4, -1,
    NOTE_AS4, 4,

    NOTE_D5, 2, NOTE_AS4, 4,//18
    NOTE_D5, 2, NOTE_AS4, 4,
    NOTE_DS5, 2, NOTE_D5, 4,
    NOTE_CS5, 2, NOTE_A4, 4,
    NOTE_AS4, -4, NOTE_D5, 8, NOTE_CS5, 4,
    NOTE_CS4, 2, NOTE_D4, 4,
    NOTE_D5, -1,
    REST,4, NOTE_AS4,4,

    NOTE_D5, 2, NOTE_AS4, 4,//26
    NOTE_D5, 2, NOTE_AS4, 4,
    NOTE_F5, 2, NOTE_E5, 4,
    NOTE_DS5, 2, NOTE_B4, 4,
    NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
    NOTE_CS4, 2, NOTE_AS4, 4,
    NOTE_G4, -1,

};
const int num_harry = sizeof(melody_harry_raw) / sizeof(melody_harry_raw[0]);

//Pacman melody
const int melody_pacman_raw[] PROGMEM = {
    NOTE_B4, 16, NOTE_B5, 16, NOTE_FS5, 16, NOTE_DS5, 16, //1
    NOTE_B5, 32, NOTE_FS5, -16, NOTE_DS5, 8, NOTE_C5, 16,
    NOTE_C6, 16, NOTE_G6, 16, NOTE_E6, 16, NOTE_C6, 32, NOTE_G6, -16, NOTE_E6, 8,

    NOTE_B4, 16,  NOTE_B5, 16,  NOTE_FS5, 16,   NOTE_DS5, 16,  NOTE_B5, 32,  //2
    NOTE_FS5, -16, NOTE_DS5, 8,  NOTE_DS5, 32, NOTE_E5, 32,  NOTE_F5, 32,
    NOTE_F5, 32,  NOTE_FS5, 32,  NOTE_G5, 32,  NOTE_G5, 32, NOTE_GS5, 32,  NOTE_A5, 16, NOTE_B5, 8
};
const int num_pacman = sizeof(melody_pacman_raw) / sizeof(melody_pacman_raw[0]);

//Start trek Intro
const int melody_starTrek_raw[] PROGMEM = {
    NOTE_D4, -8, NOTE_G4, 16, NOTE_C5, -4,
    NOTE_B4, 8, NOTE_G4, -16, NOTE_E4, -16, NOTE_A4, -16,
    NOTE_D5, 2,
};
const int num_starTrek = sizeof(melody_starTrek_raw) / sizeof(melody_starTrek_raw[0]);

//Caribbean's pirate melody
const int notes_pirate_raw[] PROGMEM = {
    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4, 0,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4, 0,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
    NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,

    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_D5, NOTE_E5, NOTE_A4, 0,
    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
    NOTE_C5, NOTE_A4, NOTE_B4, 0,

    NOTE_A4, NOTE_A4,
    //Repeat of first part
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4, 0,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4, 0,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
    NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,

    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_D5, NOTE_E5, NOTE_A4, 0,
    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
    NOTE_C5, NOTE_A4, NOTE_B4, 0,
    //End of Repeat

    NOTE_E5, 0, 0, NOTE_F5, 0, 0,
    NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
    NOTE_D5, 0, 0, NOTE_C5, 0, 0,
    NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4,

    NOTE_E5, 0, 0, NOTE_F5, 0, 0,
    NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
    NOTE_D5, 0, 0, NOTE_C5, 0, 0,
    NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4 };
const int num_pirate = sizeof(notes_pirate_raw) / sizeof(notes_pirate_raw[0]);
const int durations_raw[] PROGMEM = {
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 125,

    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 125,

    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 125, 250, 125,

    125, 125, 250, 125, 125,
    250, 125, 250, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 375,

    250, 125,
    //Rpeat of First Part
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 125,

    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 125,

    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 125, 250, 125,

    125, 125, 250, 125, 125,
    250, 125, 250, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 375,
    //End of Repeat

    250, 125, 375, 250, 125, 375,
    125, 125, 125, 125, 125, 125, 125, 125, 375,
    250, 125, 375, 250, 125, 375,
    125, 125, 125, 125, 125, 500,

    250, 125, 375, 250, 125, 375,
    125, 125, 125, 125, 125, 125, 125, 125, 375,
    250, 125, 375, 250, 125, 375,
    125, 125, 125, 125, 125, 500 };
const int num_durations = sizeof(durations_raw) / sizeof(durations_raw[0]);


void mario() {  //Mario melody
    int melody_mario[num_mario];
    for (int i = 0; i < num_mario; i++) {
        melody_mario[i] = pgm_read_word(&melody_mario_raw[i]);
    }

    int tempo_mario = 200;

    int notes_mario = sizeof(melody_mario) / sizeof(melody_mario[0]) / 2;

    int wholenote_mario = (60000 * 4) / tempo_mario;

    int divider_mario = 0, noteDuration_mario = 0;

    for (int thisNote = 0; thisNote < notes_mario * 2; thisNote = thisNote + 2) {

        divider_mario = melody_mario[thisNote + 1];
        if (divider_mario > 0) {
            noteDuration_mario = (wholenote_mario) / divider_mario;
        }
        else if (divider_mario < 0) {
            noteDuration_mario = (wholenote_mario) / abs(divider_mario);
        }
        tone(buzzer, melody_mario[thisNote], noteDuration_mario * 0.9);

        delay(noteDuration_mario);

        noTone(buzzer);
    }
}

void harrypotter() {
    int melody_harry[num_harry];
    for (int i = 0; i < num_harry; i++) {
        melody_harry[i] = pgm_read_word(&melody_harry_raw[i]);
    }
    
    int tempo_harry = 144;

    int notes_harry = sizeof(melody_harry) / sizeof(melody_harry[0]) / 2;

    int wholenote_harry = (60000 * 4) / tempo_harry;

    int divider_harry = 0, noteDuration_harry = 0;

    for (int thisNote = 0; thisNote < notes_harry * 2; thisNote = thisNote + 2) {
        divider_harry = melody_harry[thisNote + 1];
        if (divider_harry > 0) {
            noteDuration_harry = (wholenote_harry) / divider_harry;
        }
        else if (divider_harry < 0) {
            noteDuration_harry = (wholenote_harry) / abs(divider_harry);
        }
        tone(buzzer, melody_harry[thisNote], noteDuration_harry * 0.9);

        delay(noteDuration_harry);

        noTone(buzzer);
    }
}

void caribbean(){
    int notes_pirate[num_pirate];
    for (int i = 0; i < num_pirate; i++) {
        notes_pirate[i] = pgm_read_word(&notes_pirate_raw[i]);
    }

    int durations[num_durations];
    for (int i = 0; i < num_durations; i++) {
        durations[i] = pgm_read_word(&durations_raw[i]);
    }

    const float tempo_pirate = 1.0;
    const int totalNotes = sizeof(notes_pirate) / sizeof(int);
    for (int i = 0; i < totalNotes; i++)
    {
        const int currentNote = notes_pirate[i];
        float wait = durations[i] / tempo_pirate;
        if (currentNote != 0)
        {
            tone(buzzer, notes_pirate[i], wait);
        }
        else
        {
            noTone(buzzer);
        }
        delay(wait);
    }
}

void pacman() {
    int melody_pacman[num_pacman];
    for (int i = 0; i < num_pacman; i++) {
        melody_pacman[i] = pgm_read_word(&melody_pacman_raw[i]);
    }

    int tempo_pacman = 105;

    int notes_pacman = sizeof(melody_pacman) / sizeof(melody_pacman[0]) / 2;

    int wholenote_pacman = (60000 * 4) / tempo_pacman;

    int divider_pacman = 0, noteDuration_pacman = 0;

    for (int thisNote = 0; thisNote < notes_pacman * 2; thisNote = thisNote + 2) {
        divider_pacman = melody_pacman[thisNote + 1];
        if (divider_pacman > 0) {
            noteDuration_pacman = (wholenote_pacman) / divider_pacman;
        }
        else if (divider_pacman < 0) {
            noteDuration_pacman = (wholenote_pacman) / abs(divider_pacman);
            noteDuration_pacman *= 1.5;
        }
        tone(buzzer, melody_pacman[thisNote], noteDuration_pacman * 0.9);
        delay(noteDuration_pacman);
        noTone(buzzer);
    }
}

void starWars() {
    int melody_starWars[num_starWars];
    for (int i = 0; i < num_starWars; i++) {
        melody_starWars[i] = pgm_read_word(&melody_starWars_raw[i]);
    }

    int tempo_starWars = 158;

    int notes_starWars = sizeof(melody_starWars) / sizeof(melody_starWars[0]) / 2;

    int wholenote_starWars = (60000 * 4) / tempo_starWars;

    int divider_starWars = 0, noteDuration_starWars = 0;

    for (int thisNote = 0; thisNote < notes_starWars * 2; thisNote = thisNote + 2) {
        divider_starWars = melody_starWars[thisNote + 1];
        if (divider_starWars > 0) {
            noteDuration_starWars = (wholenote_starWars) / divider_starWars;
        }
        else if (divider_starWars < 0) {
            noteDuration_starWars = (wholenote_starWars) / abs(divider_starWars);
            noteDuration_starWars *= 1.5;
        }
        tone(buzzer, melody_starWars[thisNote], noteDuration_starWars * 0.9);
        delay(noteDuration_starWars);
        noTone(buzzer);
    }
}

void tetris() {
    int melody_tetris[num_tetris];
    for (int i = 0; i < num_tetris; i++) {
        melody_tetris[i] = pgm_read_word(&melody_tetris_raw[i]);
    }

    int tempo_tetris = 144;

    int notes_tetris = sizeof(melody_tetris) / sizeof(melody_tetris[0]) / 2;

    int wholenote_tetris = (60000 * 4) / tempo_tetris;

    int divider_tetris = 0, noteDuration_tetris = 0;

    for (int thisNote = 0; thisNote < notes_tetris * 2; thisNote = thisNote + 2) {

        divider_tetris = melody_tetris[thisNote + 1];
        if (divider_tetris > 0) {
            noteDuration_tetris = (wholenote_tetris) / divider_tetris;
        }
        else if (divider_tetris < 0) {
            noteDuration_tetris = (wholenote_tetris) / abs(divider_tetris);
            noteDuration_tetris *= 1.5;
        }

        tone(buzzer, melody_tetris[thisNote], noteDuration_tetris * 0.9);

        delay(noteDuration_tetris);

        noTone(buzzer);
    }
}

void minuetG() {
    int melody_minuetG[num_minuetG];
    for (int i = 0; i < num_minuetG; i++) {
        melody_minuetG[i] = pgm_read_word(&melody_minuetG_raw[i]);
    }

    int tempo_minuetG = 140;

    int notes_minuetG = sizeof(melody_minuetG) / sizeof(melody_minuetG[0]) / 2;

    int wholenote_minuetG = (60000 * 4) / tempo_minuetG;

    int divider_minuetG = 0, noteDuration_minuetG = 0;

    for (int thisNote = 0; thisNote < notes_minuetG * 2; thisNote = thisNote + 2) {

        divider_minuetG = melody_minuetG[thisNote + 1];
        if (divider_minuetG > 0) {
            noteDuration_minuetG = (wholenote_minuetG) / divider_minuetG;
        }
        else if (divider_minuetG < 0) {
            noteDuration_minuetG = (wholenote_minuetG) / abs(divider_minuetG);
            noteDuration_minuetG *= 1.5;
        }

        tone(buzzer, melody_minuetG[thisNote], noteDuration_minuetG * 0.9);

        delay(noteDuration_minuetG);

        noTone(buzzer);
    }
}

void lionKing() {
    int melody_lion[num_lion];
    for (int i = 0; i < num_lion; i++) {
        melody_lion[i] = pgm_read_word(&melody_lion_raw[i]);
    }

    int tempo_lion = 122;

    int notes_lion = sizeof(melody_lion) / sizeof(melody_lion[0]) / 2;

    int wholenote_lion = (60000 * 4) / tempo_lion;

    int divider_lion = 0, noteDuration_lion = 0;

    for (int thisNote = 0; thisNote < notes_lion * 2; thisNote = thisNote + 2) {

        divider_lion = melody_lion[thisNote + 1];
        if (divider_lion > 0) {
            noteDuration_lion = (wholenote_lion) / divider_lion;
        }
        else if (divider_lion < 0) {
            noteDuration_lion = (wholenote_lion) / abs(divider_lion);
            noteDuration_lion *= 1.5;
        }

        tone(buzzer, melody_lion[thisNote], noteDuration_lion * 0.9);

        delay(noteDuration_lion);

        noTone(buzzer);
    }
}

void symphonyNo9() {
    int melody_symphonyNo9[num_symphonyNo9];
    for (int i = 0; i < num_symphonyNo9; i++) {
        melody_symphonyNo9[i] = pgm_read_word(&melody_symphonyNo9_raw[i]);
    }

    int tempo_symphonyNo9 = 114;

    int notes_symphonyNo9 = sizeof(melody_symphonyNo9) / sizeof(melody_symphonyNo9[0]) / 2;

    int wholenote_symphonyNo9 = (60000 * 4) / tempo_symphonyNo9;

    int divider_symphonyNo9 = 0, noteDuration_symphonyNo9 = 0;

    for (int thisNote = 0; thisNote < notes_symphonyNo9 * 2; thisNote = thisNote + 2) {

        divider_symphonyNo9 = melody_symphonyNo9[thisNote + 1];
        if (divider_symphonyNo9 > 0) {
            noteDuration_symphonyNo9 = (wholenote_symphonyNo9) / divider_symphonyNo9;
        }
        else if (divider_symphonyNo9 < 0) {
            noteDuration_symphonyNo9 = (wholenote_symphonyNo9) / abs(divider_symphonyNo9);
            noteDuration_symphonyNo9 *= 1.5;
        }

        tone(buzzer, melody_symphonyNo9[thisNote], noteDuration_symphonyNo9 * 0.9);

        delay(noteDuration_symphonyNo9);

        noTone(buzzer);
    }
}

void jigglypuff() {
    int melody_jigglypuff[num_jigglypuff];
    for (int i = 0; i < num_jigglypuff; i++) {
        melody_jigglypuff[i] = pgm_read_word(&melody_jigglypuff_raw[i]);
    }

    int tempo_jigglypuff = 85;

    int notes_jigglypuff = sizeof(melody_jigglypuff) / sizeof(melody_jigglypuff[0]) / 2;

    int wholenote_jigglypuff = (60000 * 4) / tempo_jigglypuff;

    int divider_jigglypuff = 0, noteDuration_jigglypuff = 0;

    for (int thisNote = 0; thisNote < notes_jigglypuff * 2; thisNote = thisNote + 2) {

        divider_jigglypuff = melody_jigglypuff[thisNote + 1];
        if (divider_jigglypuff > 0) {
            noteDuration_jigglypuff = (wholenote_jigglypuff) / divider_jigglypuff;
        }
        else if (divider_jigglypuff < 0) {
            noteDuration_jigglypuff = (wholenote_jigglypuff) / abs(divider_jigglypuff);
            noteDuration_jigglypuff *= 1.5;
        }
        tone(buzzer, melody_jigglypuff[thisNote], noteDuration_jigglypuff * 0.9);

        delay(noteDuration_jigglypuff);

        noTone(buzzer);
    }
}

void starTrek() {
    int melody_starTrek[num_starTrek];
    for (int i = 0; i < num_starTrek; i++) {
        melody_starTrek[i] = pgm_read_word(&melody_starTrek_raw[i]);
    }

    int tempo_starTrek = 80;

    int notes_starTrek = sizeof(melody_starTrek) / sizeof(melody_starTrek[0]) / 2;

    int wholenote_starTrek = (60000 * 4) / tempo_starTrek;

    int divider_starTrek = 0, noteDuration_starTrek = 0;

    for (int thisNote = 0; thisNote < notes_starTrek * 2; thisNote = thisNote + 2) {

        divider_starTrek = melody_starTrek[thisNote + 1];
        if (divider_starTrek > 0) {
            noteDuration_starTrek = (wholenote_starTrek) / divider_starTrek;
        }
        else if (divider_starTrek < 0) {
            noteDuration_starTrek = (wholenote_starTrek) / abs(divider_starTrek);
            noteDuration_starTrek *= 1.5;
        }

        tone(buzzer, melody_starTrek[thisNote], noteDuration_starTrek * 0.9);

        delay(noteDuration_starTrek);

        noTone(buzzer);
    }
}

void badinerie() {
    int melody_badinerie[num_badinerie];
    for (int i = 0; i < num_badinerie; i++) {
        melody_badinerie[i] = pgm_read_word(&melody_badinerie_raw[i]);
    }

    int tempo_badinerie = 120;

    int notes_badinerie = sizeof(melody_badinerie) / sizeof(melody_badinerie[0]) / 2;

    int wholenote_badinerie = (60000 * 4) / tempo_badinerie;

    int divider_badinerie = 0, noteDuration_badinerie = 0;

    for (int thisNote = 0; thisNote < notes_badinerie * 2; thisNote = thisNote + 2) {

        divider_badinerie = melody_badinerie[thisNote + 1];
        if (divider_badinerie > 0) {
            noteDuration_badinerie = (wholenote_badinerie) / divider_badinerie;
        }
        else if (divider_badinerie < 0) {
            noteDuration_badinerie = (wholenote_badinerie) / abs(divider_badinerie);
            noteDuration_badinerie *= 1.5;
        }

        tone(buzzer, melody_badinerie[thisNote], noteDuration_badinerie * 0.9);

        delay(noteDuration_badinerie);

        noTone(buzzer);
    }
}

void godFather() {
    int melody_godFather[num_godFather];
    for (int i = 0; i < num_godFather; i++) {
        melody_godFather[i] = pgm_read_word(&melody_godFather_raw[i]);
    }

    int tempo_godFather = 80;

    int notes_godFather = sizeof(melody_godFather) / sizeof(melody_godFather[0]) / 2;

    int wholenote_godFather = (60000 * 4) / tempo_godFather;

    int divider_godFather = 0, noteDuration_godFather = 0;

    for (int thisNote = 0; thisNote < notes_godFather * 2; thisNote = thisNote + 2) {

        divider_godFather = melody_godFather[thisNote + 1];
        if (divider_godFather > 0) {
            noteDuration_godFather = (wholenote_godFather) / divider_godFather;
        }
        else if (divider_godFather < 0) {
            noteDuration_godFather = (wholenote_godFather) / abs(divider_godFather);
            noteDuration_godFather *= 1.5;
        }

        tone(buzzer, melody_godFather[thisNote], noteDuration_godFather * 0.9);

        delay(noteDuration_godFather);

        noTone(buzzer);
    }
}

void zeldaTheme() {
    int melody_zeldaTheme[num_zeldaTheme];
    for (int i = 0; i < num_zeldaTheme; i++) {
        melody_zeldaTheme[i] = pgm_read_word(&melody_zeldaTheme_raw[i]);
    }

    int tempo_zeldaTheme = 108;

    int notes_zeldaTheme = sizeof(melody_zeldaTheme) / sizeof(melody_zeldaTheme[0]) / 2;

    int wholenote_zeldaTheme = (60000 * 4) / tempo_zeldaTheme;

    int divider_zeldaTheme = 0, noteDuration_zeldaTheme = 0;

    for (int thisNote = 0; thisNote < notes_zeldaTheme * 2; thisNote = thisNote + 2) {

        divider_zeldaTheme = melody_zeldaTheme[thisNote + 1];
        if (divider_zeldaTheme > 0) {
            noteDuration_zeldaTheme = (wholenote_zeldaTheme) / divider_zeldaTheme;
        }
        else if (divider_zeldaTheme < 0) {
            noteDuration_zeldaTheme = (wholenote_zeldaTheme) / abs(divider_zeldaTheme);
            noteDuration_zeldaTheme *= 1.5;
        }
        tone(buzzer, melody_zeldaTheme[thisNote], noteDuration_zeldaTheme * 0.9);

        delay(noteDuration_zeldaTheme);

        noTone(buzzer);
    }
}

void cannon() {
    int melody_cannon[num_cannon];
    for (int i = 0; i < num_cannon; i++) {
        melody_cannon[i] = pgm_read_word(&melody_cannon_raw[i]);
    }

    int tempo_cannon = 140;

    int notes_cannon = sizeof(melody_cannon) / sizeof(melody_cannon[0]) / 2;

    int wholenote_cannon = (60000 * 4) / tempo_cannon;

    int divider_cannon = 0, noteDuration_cannon = 0;

    for (int thisNote = 0; thisNote < notes_cannon * 2; thisNote = thisNote + 2) {

        divider_cannon = melody_cannon[thisNote + 1];
        if (divider_cannon > 0) {
            noteDuration_cannon = (wholenote_cannon) / divider_cannon;
        }
        else if (divider_cannon < 0) {
            noteDuration_cannon = (wholenote_cannon) / abs(divider_cannon);
            noteDuration_cannon *= 1.5;
        }

        tone(buzzer, melody_cannon[thisNote], noteDuration_cannon * 0.9);

        delay(noteDuration_cannon);

        noTone(buzzer);
    }
}