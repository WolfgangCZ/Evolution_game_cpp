#pragma once
#include "../include/raylib.h"
#define RAND_INT(min, max) GetRandomValue(min, max)
#define RAND_CHAR (unsigned char)(GetRandomValue(0, 255))
#define RAND_FLOAT(min, max) (float)(GetRandomValue(min, max))

/*float rand_float(int min, int max)*/
/*{*/
/*    const float num = (float)GetRandomValue(min*100, max*100);*/
/*    return num / 100;*/
/*}*/
/*unsigned char rand_char() */
/*{*/
/*    return (char)GetRandomValue(0, 255);*/
/*}*/
/*int rand_int(int min, int max)*/
/*{*/
/*    return GetRandomValue(min, max);*/
/*}*/
/**/
