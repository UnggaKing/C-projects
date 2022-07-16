#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>



#define one_sec 1000


int main(void) {

	int width = 0;
	int height = 0;
	int star = 0;
	float delay = 0;

	printf("�ϴ��� ���� �����ϼ���(�ִ� 40ĭ, �ּ� 3ĭ) : ");
	scanf_s("%d", &width);
	printf("�ϴ��� ������ �����ϼ���(�ִ� 10ĭ, �ּ� 2ĭ) : ");
	scanf_s("%d", &height);
	printf("���� ������ �����ϼ���(�ִ� 5��, �ּ� 1��) : ");
	scanf_s("%d", &star);
	printf("������(��)�� �����ϼ���(�ִ� 3��, �ּ� 1��) : ");
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
	char* square[10][40]; // �ִ� ���� 10ĭ, �ִ� �ʺ� 40ĭ

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
			issquare[y][x] = "��";
			if (square[y][x] == "��") {
				issquare[y][x] = "  ";
				i--;
				continue;
			}
		}
		for (int j = 0; j < star - 1; j++) {
			int y2 = rand() % height;
			int x2 = rand() % width;
			
			if ( issquare[y2][x2] == "��") {
				
				j--;
				continue;
			}

			else if (square[y2][x2] == "��") {
				
				j--;
				continue;
			}

			else {
				issquare[y2][x2] = "��";
			}
		}

		for (int j = 0; j <= height - 1; j++) {
		
			for (int k = 0; k <= width - 1; k++) {
				square[j][k]=issquare[j][k];
			}
		}

		printf("��");
		for (int i = 0; i < width; i++) {
			printf("����");
		}
		printf("��\n");
		
		for (int j = 0; j <= height - 1; j++) {
			printf("��");
			for (int k = 0; k <= width - 1; k++) {
				printf("%s",square[j][k]);
			}
			printf("��");
			printf("\n");
		}

		printf("��");
		for (int i = 0; i < width; i++) {
			printf("����");
		}
		printf("��");

		printf("\n���� : %d   ���� : %d   �� : %d��   ������ : %.1f�� ",width,height,star,delay);
		Sleep(delay*1000);
		system("cls");
		
	};
	return 1;
}

