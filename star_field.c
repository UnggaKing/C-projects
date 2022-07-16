#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>



#define one_sec 1000


int main(void) {

	int width = 0;
	int height = 0;
	int star = 0;
	float delay = 0;

	printf("하늘의 폭을 설정하세요(최대 40칸, 최소 3칸) : ");
	scanf_s("%d", &width);
	printf("하늘의 높이을 설정하세요(최대 10칸, 최소 2칸) : ");
	scanf_s("%d", &height);
	printf("별의 개수를 설정하세요(최대 5개, 최소 1개) : ");
	scanf_s("%d", &star);
	printf("딜레이(초)를 설정하세요(최대 3초, 최소 1초) : ");
	scanf_s("%f", &delay);

	if (width > 40) {
		width = 40;
	}
	if (width < 3) {
		width = 3;
	}
	if (height > 10) {
		height = 10;
	}
	if (height < 2) {
		height = 2;
	}
	if (star > 5) {
		star = 5;
	}
	if (star < 1) {
		star = 1;
	}
	if (star > 3) {
		star = 3;
	}
	if (star < 1) {
		star = 1;
	}

	system("cls");

	srand(time(NULL));
	char* square[10][40]; // 최대 높이 10칸, 최대 너비 40칸

	for (int j = 0; j <= height - 1; j++) {
		for (int k = 0; k <= width - 1; k++) {
			square[j][k] = "  ";
		}
	}


	while (1) {


		char* issquare[10][40];
		for (int j = 0; j <= height - 1; j++) {
			for (int k = 0; k <= width - 1; k++) {
				issquare[j][k] = "  ";
			}
		}

		for (int i = 1; i < 2; i++) {
			int y = rand() % height;
			int x = rand() % width;
			issquare[y][x] = "★";
			if (square[y][x] == "★") {
				issquare[y][x] = "  ";
				i--;
				continue;
			}
		}
		for (int j = 0; j < star - 1; j++) {
			int y2 = rand() % height;
			int x2 = rand() % width;
			
			if ( issquare[y2][x2] == "★") {
				
				j--;
				continue;
			}

			else if (square[y2][x2] == "★") {
				
				j--;
				continue;
			}

			else {
				issquare[y2][x2] = "★";
			}
		}

		for (int j = 0; j <= height - 1; j++) {
		
			for (int k = 0; k <= width - 1; k++) {
				square[j][k]=issquare[j][k];
			}
		}

		printf("┌");
		for (int i = 0; i < width; i++) {
			printf("──");
		}
		printf("┐\n");
		
		for (int j = 0; j <= height - 1; j++) {
			printf("│");
			for (int k = 0; k <= width - 1; k++) {
				printf("%s",square[j][k]);
			}
			printf("│");
			printf("\n");
		}

		printf("└");
		for (int i = 0; i < width; i++) {
			printf("──");
		}
		printf("┘");

		printf("\n가로 : %d   세로 : %d   별 : %d개   딜레이 : %.1f초 ",width,height,star,delay);
		Sleep(delay*1000);
		system("cls");
		
	};
	return 1;
}

