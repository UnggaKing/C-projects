
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>

#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75

int main()
{
	

	char* map[20][40];
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			map[i][j] = "  ";
		}
	}
	int x = 0, y = 0;
	map[y][x] = "고";

	for (int i = 0; i < 10; i++) {
		int tx = rand() % 30 + 10; // 10~39
		int ty = rand() % 15 + 5; // 5~19
		if (map[ty][tx] == "◎") {
			i--;
			continue;
		}
		map[ty][tx] = "◎";
	}
	for (int i = 0; i < 20; i++) {
		int tx = rand() % 35 + 5; // 10~39
		int ty = rand() % 17 + 3; // 5~19
		if (map[ty][tx] == "◆") {
			i--;
			continue;
		}
		map[ty][tx] = "◆";
	}
	int coin = 0;
	int fail = 0;

	while (1) {
		
		system("cls");
		
		if (coin == 10) {
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 40; j++) {
					map[i][j] = "냠";
					map[y][x] = "★";
				}
			}
		}
		if (fail == 1) {
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 40; j++) {
					map[i][j] = "엄";
					map[y][x] = "☆";
				}
			}
		}

		printf("┌");
		for (int i = 0; i < 80; i++) {
			printf("─");
		}
		printf("┐\n");
		for (int i = 0; i < 20; i++) {
			printf("│");
			for (int j = 0; j < 40; j++) {
				printf("%s",map[i][j]);
			}
			printf("│");
			printf("\n");
		}
		printf("└");
		for (int i = 0; i < 80; i++) {
			printf("─");
		}
		printf("┘\n");
		printf("먹은 코인 개수 : %d  남은 코인 개수 : %d ",coin,10-coin);

		if (coin == 10) {
			printf("\n클리어!!!!!!!!!!!!!!\n");
			break;
		}
		if (fail == 1) {
			printf("\n엄\n준\n식\nㅋㅋㅋ\n");
			break;
		}

		map[y][x] = "  ";

		int ch = _getch();

		if (ch == 224) {
			int ch2 = _getch();
			if (ch2 == UP) {
				y--;
				if (y < 0) {
					y=0;
				}
				if (map[y][x] == "◆") {

					fail++;
				}
				if (map[y][x] == "◎") {
					
					coin++;
				}
				map[y][x] = "▲";
			}
			else if (ch2 == DOWN) {
				y++;
				if (y > 19) {
					y = 19;
				}
				if (map[y][x] == "◆") {

					fail++;
				}
				if (map[y][x] == "◎") {
					
					coin++;
				}
				map[y][x] = "▼";
			}
			else if (ch2 == LEFT) {
				x--;
				if (x < 0) {
					x = 0;
				}
				if (map[y][x] == "◆") {

					fail++;
				}
				if (map[y][x] == "◎") {
					
					coin++;
				}
				map[y][x] = "◀";
			}
			else if (ch2 == RIGHT) {
				x++;
				if (x > 39) {
					x = 39;
				}
				if (map[y][x] == "◆") {
					
					fail++;
				}
				if (map[y][x] == "◎") {
				
					coin++;
				}
				map[y][x] = "▶";
			}
		}
		
	}

}
