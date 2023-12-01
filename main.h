#pragma once
#include <iostream>
#include <stdio.h>
#include <Windows.h> // knihovna pro funkci sleep
#include <conio.h> // knihovna pro sanzší získávání vstupního inputu z "šipek"
#include <stdlib.h>
#include <time.h>
#include <direct.h>


#define RADKY 16
#define SLOUPCE 32
char pole[RADKY][SLOUPCE];



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