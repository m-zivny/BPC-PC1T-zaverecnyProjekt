#include "main.h"
/*
13) Hra had
Vytvořte aplikaci odpovídající hře had známé z mobilních telefonů NOKIA. Hru bude možné ovládat
skrze směrová tlačítka klávesnice.
Základní parametry programu:
1. Had se bude samostatně pohybovat posledním zadaným směrem.
2. Po každém úspěšně získané položce (snědení jídla) se had zvětší o jeden článek.
3. Bude kontrolováno zda had narazil do sebe samého, poté hra skončí.
4. Hrany konzole budou pro hada neprůchozí.
5. Hra bude obsahovat statistiky nejlepších 10 hráčů, které budou uloženy v externím textovém
souboru.
Bonusový úkol: Implementujte možnost nahrání překážek do hracího pole z textového souboru.
*/

int startingPosX = 5;
int startingPosY = 5;
int appleX = 0;
int appleY = 0;
bool gameover = false;



int ch;
char had = 'O';
char apple = 'X';
enum Direction direction = RIGHT;
struct bodyPart hlava;
struct bodyPart* last = &hlava;
int b = 1;

void createPart() {


	struct bodyPart* newPart;

	newPart = (struct bodyPart*)malloc(sizeof(struct bodyPart));

	last->next = newPart;

	switch (direction) {
	case UP:
		newPart->posY = last->posY + 1;
		newPart->posX = last->posX;
		break;
	case DOWN:
		newPart->posY = last->posY - 1;
		newPart->posX = last->posX;
		break;
	case LEFT:
		newPart->posY = last->posY;
		newPart->posX = last->posX + 1;
		break;
	case RIGHT:
		newPart->posY = last->posY;
		newPart->posX = last->posX - 1;
		break;
	}

	newPart->next = NULL;

	last = newPart;

}
void getDir() {

	if (kbhit()) {
		ch = getch();
		if (ch = 0 || ch == 224) {
			switch (getch()) {
			case 72:
				if (direction != DOWN) {
					direction = UP;
				}
				break;
			case 80:
				if (direction != UP) {
					direction = DOWN;
				}
				break;
			case 77:
				if (direction != LEFT) {
					direction = RIGHT;
				}
				break;
			case 75:
				if (direction != RIGHT) {
					direction = LEFT;
				}
				break;
			}
		}
	}
	
		
}
void getPos() {



	bodyPart* act = &hlava;
	bodyPart* _tempLast;
	enum Direction tempDir;

	switch (direction) {
	case UP:
		act->posY--;
		break;
	case DOWN:
		act->posY++;
		break;
	case LEFT:
		act->posX--;
		break;
	case RIGHT:
		act->posX++;
		break;
	}
	if (hlava.posX == appleX && hlava.posY == appleY) {
		createPart();
		b = 1;
	}
	act = act->next;
	while (act) {

		if (act->posX == hlava.posX && act->posY == hlava.posY) {
			gameover = true;
		}
		act = act->next;

	}
	if (hlava.posX == 0 || hlava.posX == SLOUPCE - 1 || hlava.posY == RADKY - 1 || hlava.posY == 0) {
		gameover = true;
	}

	act = &hlava;
	_tempLast = act;
	act = act->next;

	tempDir = direction;

	while (act) {

		switch (tempDir){

		case UP:
			if (act->posX == _tempLast->posX) {
				act->posY--;
			}
			else if(act->posX < _tempLast->posX) {
				act->posX++;
				tempDir = RIGHT;
			}
			else {
				act->posX--;				
				tempDir = LEFT;
			}
			
			break;

		case DOWN:
			if (act->posX == _tempLast->posX) {
				act->posY++;
			}
			else if (act->posX < _tempLast->posX) {
				act->posX++;
				tempDir = RIGHT;
			}
			else {
				act->posX--;	
				tempDir = LEFT;
			}
			break;

		case LEFT:
			if (act->posY == _tempLast->posY) {
				act->posX--;
			}
			else if (act->posY < _tempLast->posY) {
				act->posY++;
				tempDir = DOWN;
			}
			else {
				act->posY--;
				tempDir = UP;
			}
			break;

		case RIGHT:
			if (act->posY == _tempLast->posY) {
				act->posX++;
			}
			else if (act->posY < _tempLast->posY) {
				act->posY++;
				tempDir = DOWN;
			}
			else {
				act->posY--;
				tempDir = UP;
			}
			break;

		}
		_tempLast = act;
		act = act->next;
	}

	act = hlava.next;
}
void printField() {

	bodyPart* act;
	act = &hlava;

	pole[appleY][appleX] = apple;

	while (act) {
		pole[act->posY][act->posX] = had;
		act = act->next;
	}

	for (int x = 0; x < RADKY; x++) {

		for (int y = 0; y < SLOUPCE; y++) {

			printf("%c", pole[x][y]);

		}
		printf("\n");
	}

	
}

void fillGameField() {
	for (int x = 0; x < RADKY; x++) {

		for (int y = 0; y < SLOUPCE; y++) {

			if (x == 0 || x == RADKY - 1) {

				if (y == 0 || y == SLOUPCE - 1) {
					pole[x][y] = '|';
				}
				else {
					pole[x][y] = '-';
				}
			}

			else {

				if (y == 0 || y == SLOUPCE - 1) {
					pole[x][y] = '|';
				}
				else {
					pole[x][y] = ' ';
				}

			}

		}
	}
}

void generateApple(){

	appleX = rand() % SLOUPCE -1;
	appleY = rand() % RADKY -1;

	while (appleX == 0 || appleY == 0) {
		appleX = rand() % SLOUPCE - 1;
		appleY = rand() % RADKY - 1;
	}
}

int main() {
	

	srand(time(NULL));
	hlava.posX = 10;
	hlava.posY = 10;
	generateApple();
	createPart();
	createPart();
	

	while (true) {

		system("cls");
		fillGameField();

		if (b) {
			generateApple();
			b = 0;
		}

		getDir();
		getPos();		
		if (gameover) {
			break;
		}
		printField();
		Sleep(200);

	}
	printf("GAMEOVER!");
	

	}
	