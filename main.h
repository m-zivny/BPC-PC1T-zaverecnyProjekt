#pragma once
#include <iostream>
#include <stdio.h>
#include <Windows.h> // knihovna pro funkci sleep
#include <conio.h> // knihovna pro sanzší získávání vstupního inputu z "šipek"
#include <stdlib.h>
#include <time.h>
#include <direct.h>
#include <string.h>


#define RADKY 16
#define SLOUPCE 32

#define MAX_LENGTH 10000 // Maximální délka naèítaného øetìzce
#define MAX_PEOPLE 10   // Maximální poèet osob

struct bodyPart {

	int posX = 0;
	int posY = 0;
	bodyPart* next = NULL;

};

struct Person {

	int position;
	char name[50];
	int score;
};

enum Direction {
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};


int startingPosX = 5;
int startingPosY = 5;
int appleX = 0;
int appleY = 0;
bool gameover = false;



int ch;
char restartVal[1];
char had = 'O';
char apple = 'X';
enum Direction direction = RIGHT;
struct bodyPart hlava;
struct bodyPart* last = &hlava;
int b = 0;
char myName[30];
int myScore = 0;

char pole[RADKY][SLOUPCE];

FILE* file;
char line[MAX_LENGTH];
struct Person people[MAX_PEOPLE];
int count = 0;
bool rewrite = false;
bool isBetter = false;
int pos = 0;




