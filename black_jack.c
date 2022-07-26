#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

// ���� ��� �߰�
// ī�带 �ڵ�� ����. ����(0,1,2,3  ������� �����̵�, Ŭ�ι�, ��Ʈ, ���̾�) / ����(K,Q,J,A�� �� �ڵ�� 0.) / ������Ʈ ŷ => S00K ��Ʈ 9 => H090
// ī�带 ���� ������ chosedCard�迭�� �߰�

int cardNumber(int cardCode[2],int mypoint) {
	int pattern = 0;
	int number = 0;
	int aceCode = 0;
	
	// ���� �Ǻ�
	if (cardCode[0] == 0) {
		pattern = 1;
	}
	else if (cardCode[0] == 1) {
		pattern = 2;
	}
	else if (cardCode[0] == 2) {
		pattern = 3;
	}
	else if (cardCode[0] == 3) {
		pattern = 4;
	}

	// k,q,j,ace �Ǻ�
	if (cardCode[1] == 13) {
		printf("%s King ī�尡 ���Խ��ϴ�. 10�� ���մϴ�..\n", pattern == 1 ? "Spade" : (pattern == 2 ? "Clover" : (pattern == 3 ? "Heart" : "Diamond")));
		number = 10;
		return number;
	}
	else if (cardCode[1] == 12) {
		printf("%s Queen ī�尡 ���Խ��ϴ�. 10�� ���մϴ�..\n", pattern == 1 ? "Spade" : (pattern == 2 ? "Clover" : (pattern == 3 ? "Heart" : "Diamond")));
		number = 10;
		return number;
	}
	else if (cardCode[1] == 11) {
		printf("%s Jack ī�尡 ���Խ��ϴ�. 10�� ���մϴ�..\n", pattern == 1 ? "Spade" : (pattern == 2 ? "Clover" : (pattern == 3 ? "Heart" : "Diamond")));
		number = 10;
		return number;
	}

	// ace �Ͻ�
	else if (cardCode[1] == 1) {
		printf("%s Ace ī�尡 ���Խ��ϴ�. ���� ����Ʈ�� %d �Դϴ�. (1) 1���ϱ�  (2) 11���ϱ� : ", pattern == 1 ? "Spade" : (pattern == 2 ? "Clover" : (pattern == 3 ? "Heart" : "Diamond")),mypoint);
		for (int i = 0; i < 1; i++) {
			scanf_s("%d", &aceCode);
			if (aceCode < 1) {
				printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ��� : ");
				i--;
				continue;
			}
			else if (aceCode > 2) {
				printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ��� : ");
				i--;
				continue;
			}
			// 1 ���ϱ�
			if (aceCode == 1) {
				printf("1�� ���մϴ�.\n");
				number = 1;
				return number;
			}
			// 11 ���ϱ�
			else {
				printf("11�� ���մϴ�.\n");
				number = 11;
				return number;
			}
		}
		
	}

	// ���� ī���� ���� �Ǻ�
	if (cardCode[1] == 10) {
		number = 10;
		printf("%s 10 ī�尡 ���Խ��ϴ�. 10�� ���մϴ�..\n", pattern == 1 ? "Spade" : (pattern == 2 ? "Clover" : (pattern == 3 ? "Heart" : "Diamond")));
		return number;
	}
	else {
		number = cardCode[1];
		printf("%s %d ī�尡 ���Խ��ϴ�. %d�� ���մϴ�..\n", pattern == 1 ? "Spade" : (pattern == 2 ? "Clover" : (pattern == 3 ? "Heart" : "Diamond")), number, number);
		return number;
	}

}

void cardPrint(int cardCode[2]) {
	
	int pattern = 0;
	int number = 0;

	// ���� �Ǻ�
	if (cardCode[0] == 0) {
		pattern = 1;
	}
	else if (cardCode[0] == 1) {
		pattern = 2;
	}
	else if (cardCode[0] == 2) {
		pattern = 3;
	}
	else if (cardCode[0] == 3) {
		pattern = 4;
	}
	
	// ���� ī��� ���� ī�� ����
	if (cardCode[1] > 10) {  // ���� ī�� ���
		if (cardCode[1] == 11) {  // Jack ī��
			printf("����������\n");
			printf("�� J ��\n");
			printf("�� %s��\n", pattern == 1 ? "��" : (pattern == 2 ? "��" : (pattern == 3 ? "��" : "��")));
			printf("����������\n");
		}
		else if (cardCode[1] == 12) { // Queen ī��
			printf("����������\n");
			printf("�� Q ��\n");
			printf("�� %s��\n", pattern == 1 ? "��" : (pattern == 2 ? "��" : (pattern == 3 ? "��" : "��")));
			printf("����������\n");
		}
		else if (cardCode[1] == 13) {  // King ī��
			printf("����������\n");
			printf("�� K ��\n");
			printf("�� %s��\n", pattern == 1 ? "��" : (pattern == 2 ? "��" : (pattern == 3 ? "��" : "��")));
			printf("����������\n");
		}
		
	}
	else  // ���� ī�� ���
	{
		if (cardCode[1] == 10) { // 10 ī��
			number = 10;
			printf("����������\n");
			printf("��10 ��\n");
			printf("�� %s��\n",pattern==1?"��":(pattern==2?"��":(pattern==3?"��":"��")));
			printf("����������\n");
			
		}
		else {
			number = cardCode[1];
			if (number == 1) {  // ace ī��
				printf("����������\n");
				printf("�� A ��\n");
				printf("�� %s��\n", pattern == 1 ? "��" : (pattern == 2 ? "��" : (pattern == 3 ? "��" : "��")));
				printf("����������\n");
			}
			else { // ace �� �ƴ� ���� ī��
				printf("����������\n");
				printf("�� %d ��\n", number);
				printf("�� %s��\n", pattern == 1 ? "��" : (pattern == 2 ? "��" : (pattern == 3 ? "��" : "��")));
				printf("����������\n");
			}
		}
		
	}
	
	
}

int gameEnd(int myPoint, int enePoint) {
	if (21 - myPoint < 21 - enePoint) {
		printf("�� : %d p\n���� : %d p\n�¸��ϼ̽��ϴ�\n", myPoint, enePoint);
		return 1;
	}
	else if (21 - myPoint > 21 - enePoint) {
		printf("�� : %d p\n���� : %d p\n�й��ϼ̽��ϴ�\n", myPoint, enePoint);
		return 2;
	}
	else if (21 - myPoint == 21 - enePoint) {
		printf("�� : %d p\n���� : %d p\n���º��Դϴ�\n", myPoint, enePoint);
		return 0;
	}
	return 100;
}

int betCoin(int myCoin) {
	printf("���� ���� ���� : %d��\n������ ���� ������ �Է��ϼ��� : ",myCoin);
	int bet = 0;
	for (int i = 0; i < 1; i++) {
		scanf_s("%d", &bet);
		if (bet > myCoin) {
			printf("���� ���� ���κ��� ���� ������ �� �� �����ϴ�.\n���Է� : ");
			i--;
			continue;
		}
		else if (bet < 1) {
			printf("1�� ������ ������ �� �� �����ϴ�.\n���Է� : ");
			i--;
			continue;
		}
		else {
			printf("%d���� ������ �ɾ����ϴ�.\n", bet);
			Sleep(1000);
			system("cls");
			return bet;
		}
		return 0;
	}
}

// �����Լ� ***************************
int main(void) {

	HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(NULL));
	// �ʱ⼳��
	int gameState = 0; // 0 => ���� �̿Ϸ�    1 => ���� �Ϸ�     2 => �Ļ�     3 => ���� ����
	int winCount = 0;
	int loseCount = 0;
	int playCount = 0;
	int myCoin = 100;
	int myPoint = 0;
	int enePoint = 0;
	int stake = 0;
	int chosenCard[2];
	// ī�� �ʱ�ȭ
	int cards[4][13];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			cards[i][j] = j + 1;
			/*
				[0] {1,2,3,4,.........,12,13}
				[1] {1,2,3,4,.........,12,13}
				[2] ...
				[3] ...
			*/
		}
	}
	// ī�� �ʱ�ȭ
	// �ʱ⼳��
	
	// ���� ����
	for (int play = 0; play < 1; play++) {

		if (gameState == 3) {
			printf("������ �����մϴ�.\n");
			break;
		}

		//���� ���� �� �Ļ�
		if (myCoin < 1) {
			gameState = 2;
		}
		if (gameState == 2) {
			printf("�Ļ��ϼ̽��ϴ�! %d ȸ �¸�, %dȸ �й�\n", winCount, loseCount);
			break;
		}
		// ���� ���� �� �Ļ�

		// ���� �̿Ϸ� �� ����
		if (gameState == 0) {
			SetConsoleTextAttribute(h_console, 0x0004);
			printf("��������������������  Black Jack  ����������������������\n");
			SetConsoleTextAttribute(h_console, 0x07);
			printf("�� : %d  �� : %d\n", winCount, loseCount);
			stake = betCoin(myCoin);
			gameState = 1;
			enePoint = rand() % 10 + 12;
		}
		// ���� �̿Ϸ� �� ����

		// ī��̱�
		for (int j = 0; j < 1; j++) {
			int pattern = rand() % 4;
			int number = rand() % 13 + 1;
			chosenCard[0] = pattern;
			chosenCard[1] = number;
			if (cards[pattern][number - 1] == 0) {
				j--;
				continue;
			}
			cards[pattern][number - 1] = 0;
			printf("���� ���� ���� : %d��   �̹��ǿ� �ɸ� ���� : %d��%s\n", myCoin, stake,myCoin==stake?" (�й� �� �Ļ��մϴ�.)":" ������������������������");
			cardPrint(chosenCard);
			myPoint += cardNumber(chosenCard, myPoint);
			printf("���� ����Ʈ�� %d �Դϴ�.\n", myPoint);
		}
		// ī��̱�

		// 21 �ʰ� �� ���� ����.
		int choseCode = 0;
		if (myPoint > 21) {
			myCoin -= stake;
			loseCount++;
			printf("�� : %d p\n���� : %d p\n21�� �ʰ��� �й��ϼ̽��ϴ�\n", myPoint, enePoint);
			if (myCoin < 1) {
				SetConsoleTextAttribute(h_console, 0x0004);
				printf("�Ļ��ϼ̽��ϴ�! %d ȸ �¸�, %dȸ �й�\n", winCount, loseCount);
				SetConsoleTextAttribute(h_console, 0x07);
				break;
			}
			printf("�ٽ� �Ͻðڽ��ϱ�? (1) ��   (2) �ƴϿ� : ");
			for (int w = 0; w < 1; w++) {
				scanf_s("%d", &choseCode);
				if (choseCode < 1) {
					printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ��� : ");
					w--;
					continue;
				}
				else if (choseCode > 2) {
					printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ��� : ");
					w--;
					continue;
				}
				if (choseCode == 1) {
					printf("������ ������մϴ�.\n");
					// �ʱ⼳��
					gameState = 0; // 0 => ���� �̿Ϸ�    1 => ���� �Ϸ�     2 => �Ļ�     3 => ���� ����
					myPoint = 0;
					enePoint = 0;
					stake = 0;
					// ī�� �ʱ�ȭ

					for (int q = 0; q < 4; q++) {
						for (int r = 0; r < 13; r++) {
							cards[q][r] = r + 1;
							/*
								[0] {1,2,3,4,.........,12,13}
								[1] {1,2,3,4,.........,12,13}
								[2] ...
								[3] ...
							*/
						}
					}
					// ī�� �ʱ�ȭ
					// �ʱ⼳��
					Sleep(1000);
					play--;
					system("cls");
					break;
				}
				else {
					gameState = 3;
					play--;
				}
			}
			continue;
		}
		// 21 �ʰ� �� ���� ����.

		// ī��̱�, ���� ���� ����
		printf("ī�带 �����ðڽ��ϱ�? (1) ��   (2) �ƴϿ� : ");
		choseCode = 0;
		for (int k = 0; k < 1; k++) {
			
				scanf_s("%d", &choseCode);
				if (choseCode < 1) {
					printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ��� : ");
					k--;
					continue;
				}
				else if (choseCode > 2) {
					printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ��� : ");
					k--;
					continue;
				}
				// ���� ����, ���� ���� ���� 
				if (choseCode == 2) {
					int end = gameEnd(myPoint, enePoint); // 1 => �¸�     2 => �й�     0 => ���º� 
					if (end == 0) {
						printf("�ٽ� �Ͻðڽ��ϱ�? (1) ��   (2) �ƴϿ� : ");
						for (int w = 0; w < 1; w++) {
							scanf_s("%d", &choseCode);
							if (choseCode < 1) {
								printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ��� : ");
								w--;
								continue;
							}
							else if (choseCode > 2) {
								printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ��� : ");
								w--;
								continue;
							}
							if (choseCode == 1) {
								printf("������ ������մϴ�.\n");
								// �ʱ⼳��
								gameState = 0; // 0 => ���� �̿Ϸ�    1 => ���� �Ϸ�     2 => �Ļ�     3 => ���� ����
								myPoint = 0;
								enePoint = 0;
								stake = 0;
								// ī�� �ʱ�ȭ

								for (int q = 0; q < 4; q++) {
									for (int r = 0; r < 13; r++) {
										cards[q][r] = r + 1;
										/*
											[0] {1,2,3,4,.........,12,13}
											[1] {1,2,3,4,.........,12,13}
											[2] ...
											[3] ...
										*/
									}
								}
								// ī�� �ʱ�ȭ
								// �ʱ⼳��
								Sleep(1000);
								play--;
								system("cls");
								break;
							}
							else {
								gameState = 3;
							}
						}
					}
					if (end == 1) {
						printf("�ٽ� �Ͻðڽ��ϱ�? (1) ��   (2) �ƴϿ� : ");
						myCoin += stake;
						winCount++;
						for (int w = 0; w < 1; w++) {
							scanf_s("%d", &choseCode);
							if (choseCode < 1) {
								printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ��� : ");
								w--;
								continue;
							}
							else if (choseCode > 2) {
								printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ��� : ");
								w--;
								continue;
							}
							if (choseCode == 1) {
								printf("������ ������մϴ�.\n");
								// �ʱ⼳��
								gameState = 0; // 0 => ���� �̿Ϸ�    1 => ���� �Ϸ�     2 => �Ļ�     3 => ���� ����
								myPoint = 0;
								enePoint = 0;
								stake = 0;
								// ī�� �ʱ�ȭ

								for (int q = 0; q < 4; q++) {
									for (int r = 0; r < 13; r++) {
										cards[q][r] = r + 1;
										/*
											[0] {1,2,3,4,.........,12,13}
											[1] {1,2,3,4,.........,12,13}
											[2] ...
											[3] ...
										*/
									}
								}
								// ī�� �ʱ�ȭ
								// �ʱ⼳��
								Sleep(1000);
								play--;
								system("cls");
								break;
							}
							else {
								gameState = 3;
							}
						}
					}
					if (end == 2) {
						printf("�ٽ� �Ͻðڽ��ϱ�? (1) ��   (2) �ƴϿ� : ");
						myCoin -= stake;
						loseCount++;
						for (int w = 0; w < 1; w++) {
							scanf_s("%d", &choseCode);
							if (choseCode < 1) {
								printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ��� : ");
								w--;
								continue;
							}
							else if (choseCode > 2) {
								printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ��� : ");
								w--;
								continue;
							}
							if (choseCode == 1) {
								printf("������ ������մϴ�.\n");
								// �ʱ⼳��
								gameState = 0; // 0 => ���� �̿Ϸ�    1 => ���� �Ϸ�     2 => �Ļ�     3 => ���� ����
								myPoint = 0;
								enePoint = 0;
								stake = 0;
								// ī�� �ʱ�ȭ

								for (int q = 0; q < 4; q++) {
									for (int r = 0; r < 13; r++) {
										cards[q][r] = r + 1;
										/*
											[0] {1,2,3,4,.........,12,13}
											[1] {1,2,3,4,.........,12,13}
											[2] ...
											[3] ...
										*/
									}
								}
								// ī�� �ʱ�ȭ
								// �ʱ⼳��
								Sleep(1000);
								play--;
								system("cls");
								break;
							}
							else {
								gameState = 3;
							}
						}
					}
				}
				// ���� ����, ���� ���� ���� 
				else { // ī�� �̱� ����
					system("cls");
					play--;
				}
			}
			// ī��̱�, ���� ���� ����
		}
	// ���� ����
	}