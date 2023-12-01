#include "knihovny/main.h"
#include "knihovny/snakeLogic.h"


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

char had = 'O';

int hadPosX = 10;
int hadPosY = 10;
int ch;
enum Direction direction = RIGHT;

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
	system("cls");
	pole[hadPosY][hadPosX] = ' ';
	switch (direction) {
	case UP:

		hadPosY--;
		break;

	case DOWN:
		hadPosY++;
		break;

	case LEFT:
		hadPosX--;
		break;
	case RIGHT:
		hadPosX++;
		break;
	default:
		break;
	}

	pole[hadPosY][hadPosX] = had;
}
void tiskPole() {
	for (int x = 0; x < RADKY; x++) {

		for (int y = 0; y < SLOUPCE; y++) {

			printf("%c", pole[x][y]);

		}
		printf("\n");
	}
}


void nasyceniPole() {
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
int main() {

	nasyceniPole();
	pole[hadPosX][hadPosY] = had;
	tiskPole();
	Sleep(1000);
	cas = time(NULL);
	timestamp = cas;

	while (true) {

			getDir();
			getPos();
			tiskPole();
			Sleep(150);
		}

	}
	