#pragma once
#include <iostream>
#include <stdio.h>
#include <Windows.h> // knihovna pro funkci sleep
#include <conio.h> // knihovna pro sanzší získávání vstupního inputu z "šipek"
#include <stdlib.h>
#include <time.h>

#define RADKY 16
#define SLOUPCE 32
char pole[RADKY][SLOUPCE];

time_t cas;
time_t timestamp;
time_t rozdil;
bool tempDirection;
