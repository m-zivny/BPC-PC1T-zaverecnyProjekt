#pragma once
#include <iostream>
#include <stdio.h>
#include <Windows.h> // knihovna pro funkci sleep
#include <conio.h> // knihovna pro sanz�� z�sk�v�n� vstupn�ho inputu z "�ipek"
#include <stdlib.h>
#include <time.h>

#define RADKY 16
#define SLOUPCE 32
char pole[RADKY][SLOUPCE];

time_t cas;
time_t timestamp;
time_t rozdil;
bool tempDirection;

struct bodyPart {

	int posX = 0;
	int posY = 0;
	bodyPart* next = NULL;

};

enum Direction {
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};