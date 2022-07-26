#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

// 베팅 기능 추가
// 카드를 코드로 정함. 패턴(0,1,2,3  순서대로 스페이드, 클로버, 하트, 다이아) / 숫자(K,Q,J,A인 이 코드는 0.) / 스페이트 킹 => S00K 하트 9 => H090
// 카드를 뽑을 때마다 chosedCard배열에 추가

int cardNumber(int cardCode[2],int mypoint) {
	int pattern = 0;
	int number = 0;
	int aceCode = 0;
	
	// 문양 판별
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

	// k,q,j,ace 판별
	if (cardCode[1] == 13) {
		printf("%s King 카드가 나왔습니다. 10을 더합니다..\n", pattern == 1 ? "Spade" : (pattern == 2 ? "Clover" : (pattern == 3 ? "Heart" : "Diamond")));
		number = 10;
		return number;
	}
	else if (cardCode[1] == 12) {
		printf("%s Queen 카드가 나왔습니다. 10을 더합니다..\n", pattern == 1 ? "Spade" : (pattern == 2 ? "Clover" : (pattern == 3 ? "Heart" : "Diamond")));
		number = 10;
		return number;
	}
	else if (cardCode[1] == 11) {
		printf("%s Jack 카드가 나왔습니다. 10을 더합니다..\n", pattern == 1 ? "Spade" : (pattern == 2 ? "Clover" : (pattern == 3 ? "Heart" : "Diamond")));
		number = 10;
		return number;
	}

	// ace 일시
	else if (cardCode[1] == 1) {
		printf("%s Ace 카드가 나왔습니다. 현제 포인트는 %d 입니다. (1) 1더하기  (2) 11더하기 : ", pattern == 1 ? "Spade" : (pattern == 2 ? "Clover" : (pattern == 3 ? "Heart" : "Diamond")),mypoint);
		for (int i = 0; i < 1; i++) {
			scanf_s("%d", &aceCode);
			if (aceCode < 1) {
				printf("잘못된 입력입니다. 다시 입력하세요 : ");
				i--;
				continue;
			}
			else if (aceCode > 2) {
				printf("잘못된 입력입니다. 다시 입력하세요 : ");
				i--;
				continue;
			}
			// 1 더하기
			if (aceCode == 1) {
				printf("1을 더합니다.\n");
				number = 1;
				return number;
			}
			// 11 더하기
			else {
				printf("11을 더합니다.\n");
				number = 11;
				return number;
			}
		}
		
	}

	// 숫자 카드의 숫자 판별
	if (cardCode[1] == 10) {
		number = 10;
		printf("%s 10 카드가 나왔습니다. 10을 더합니다..\n", pattern == 1 ? "Spade" : (pattern == 2 ? "Clover" : (pattern == 3 ? "Heart" : "Diamond")));
		return number;
	}
	else {
		number = cardCode[1];
		printf("%s %d 카드가 나왔습니다. %d를 더합니다..\n", pattern == 1 ? "Spade" : (pattern == 2 ? "Clover" : (pattern == 3 ? "Heart" : "Diamond")), number, number);
		return number;
	}

}

void cardPrint(int cardCode[2]) {
	
	int pattern = 0;
	int number = 0;

	// 문양 판별
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
	
	// 숫자 카드와 문양 카드 구별
	if (cardCode[1] > 10) {  // 문양 카드 출력
		if (cardCode[1] == 11) {  // Jack 카드
			printf("┌───┐\n");
			printf("│ J │\n");
			printf("│ %s│\n", pattern == 1 ? "♠" : (pattern == 2 ? "♣" : (pattern == 3 ? "♥" : "◆")));
			printf("└───┘\n");
		}
		else if (cardCode[1] == 12) { // Queen 카드
			printf("┌───┐\n");
			printf("│ Q │\n");
			printf("│ %s│\n", pattern == 1 ? "♠" : (pattern == 2 ? "♣" : (pattern == 3 ? "♥" : "◆")));
			printf("└───┘\n");
		}
		else if (cardCode[1] == 13) {  // King 카드
			printf("┌───┐\n");
			printf("│ K │\n");
			printf("│ %s│\n", pattern == 1 ? "♠" : (pattern == 2 ? "♣" : (pattern == 3 ? "♥" : "◆")));
			printf("└───┘\n");
		}
		
	}
	else  // 숫자 카드 출력
	{
		if (cardCode[1] == 10) { // 10 카드
			number = 10;
			printf("┌───┐\n");
			printf("│10 │\n");
			printf("│ %s│\n",pattern==1?"♠":(pattern==2?"♣":(pattern==3?"♥":"◆")));
			printf("└───┘\n");
			
		}
		else {
			number = cardCode[1];
			if (number == 1) {  // ace 카드
				printf("┌───┐\n");
				printf("│ A │\n");
				printf("│ %s│\n", pattern == 1 ? "♠" : (pattern == 2 ? "♣" : (pattern == 3 ? "♥" : "◆")));
				printf("└───┘\n");
			}
			else { // ace 가 아닌 숫자 카드
				printf("┌───┐\n");
				printf("│ %d │\n", number);
				printf("│ %s│\n", pattern == 1 ? "♠" : (pattern == 2 ? "♣" : (pattern == 3 ? "♥" : "◆")));
				printf("└───┘\n");
			}
		}
		
	}
	
	
}

int gameEnd(int myPoint, int enePoint) {
	if (21 - myPoint < 21 - enePoint) {
		printf("나 : %d p\n딜러 : %d p\n승리하셨습니다\n", myPoint, enePoint);
		return 1;
	}
	else if (21 - myPoint > 21 - enePoint) {
		printf("나 : %d p\n딜러 : %d p\n패배하셨습니다\n", myPoint, enePoint);
		return 2;
	}
	else if (21 - myPoint == 21 - enePoint) {
		printf("나 : %d p\n딜러 : %d p\n무승부입니다\n", myPoint, enePoint);
		return 0;
	}
	return 100;
}

int betCoin(int myCoin) {
	printf("현제 코인 개수 : %d개\n배팅할 코인 개수를 입력하세요 : ",myCoin);
	int bet = 0;
	for (int i = 0; i < 1; i++) {
		scanf_s("%d", &bet);
		if (bet > myCoin) {
			printf("현제 보유 코인보다 많은 코인을 걸 수 없습니다.\n재입력 : ");
			i--;
			continue;
		}
		else if (bet < 1) {
			printf("1개 이하의 코인을 걸 수 없습니다.\n재입력 : ");
			i--;
			continue;
		}
		else {
			printf("%d개의 코인을 걸었습니다.\n", bet);
			Sleep(1000);
			system("cls");
			return bet;
		}
		return 0;
	}
}

// 메인함수 ***************************
int main(void) {

	HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(NULL));
	// 초기설정
	int gameState = 0; // 0 => 배팅 미완료    1 => 배팅 완료     2 => 파산     3 => 게임 종료
	int winCount = 0;
	int loseCount = 0;
	int playCount = 0;
	int myCoin = 100;
	int myPoint = 0;
	int enePoint = 0;
	int stake = 0;
	int chosenCard[2];
	// 카드 초기화
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
	// 카드 초기화
	// 초기설정
	
	// 게임 시작
	for (int play = 0; play < 1; play++) {

		if (gameState == 3) {
			printf("게임을 종료합니다.\n");
			break;
		}

		//코인 소진 시 파산
		if (myCoin < 1) {
			gameState = 2;
		}
		if (gameState == 2) {
			printf("파산하셨습니다! %d 회 승리, %d회 패배\n", winCount, loseCount);
			break;
		}
		// 코인 소진 시 파산

		// 배팅 미완료 시 배팅
		if (gameState == 0) {
			SetConsoleTextAttribute(h_console, 0x0004);
			printf("─────────┼  Black Jack  ┼──────────\n");
			SetConsoleTextAttribute(h_console, 0x07);
			printf("승 : %d  패 : %d\n", winCount, loseCount);
			stake = betCoin(myCoin);
			gameState = 1;
			enePoint = rand() % 10 + 12;
		}
		// 배팅 미완료 시 배팅

		// 카드뽑기
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
			printf("현제 보유 코인 : %d개   이번판에 걸린 코인 : %d개%s\n", myCoin, stake,myCoin==stake?" (패배 시 파산합니다.)":" ────────────");
			cardPrint(chosenCard);
			myPoint += cardNumber(chosenCard, myPoint);
			printf("현제 포인트는 %d 입니다.\n", myPoint);
		}
		// 카드뽑기

		// 21 초과 시 게임 종료.
		int choseCode = 0;
		if (myPoint > 21) {
			myCoin -= stake;
			loseCount++;
			printf("나 : %d p\n딜러 : %d p\n21점 초과로 패배하셨습니다\n", myPoint, enePoint);
			if (myCoin < 1) {
				SetConsoleTextAttribute(h_console, 0x0004);
				printf("파산하셨습니다! %d 회 승리, %d회 패배\n", winCount, loseCount);
				SetConsoleTextAttribute(h_console, 0x07);
				break;
			}
			printf("다시 하시겠습니까? (1) 예   (2) 아니오 : ");
			for (int w = 0; w < 1; w++) {
				scanf_s("%d", &choseCode);
				if (choseCode < 1) {
					printf("잘못된 입력입니다. 다시 입력하세요 : ");
					w--;
					continue;
				}
				else if (choseCode > 2) {
					printf("잘못된 입력입니다. 다시 입력하세요 : ");
					w--;
					continue;
				}
				if (choseCode == 1) {
					printf("게임을 재시작합니다.\n");
					// 초기설정
					gameState = 0; // 0 => 배팅 미완료    1 => 배팅 완료     2 => 파산     3 => 게임 종료
					myPoint = 0;
					enePoint = 0;
					stake = 0;
					// 카드 초기화

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
					// 카드 초기화
					// 초기설정
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
		// 21 초과 시 게임 종료.

		// 카드뽑기, 게임 종료 선택
		printf("카드를 뽑으시겠습니까? (1) 예   (2) 아니오 : ");
		choseCode = 0;
		for (int k = 0; k < 1; k++) {
			
				scanf_s("%d", &choseCode);
				if (choseCode < 1) {
					printf("잘못된 입력입니다. 다시 입력하세요 : ");
					k--;
					continue;
				}
				else if (choseCode > 2) {
					printf("잘못된 입력입니다. 다시 입력하세요 : ");
					k--;
					continue;
				}
				// 게임 승패, 게임 지속 여부 
				if (choseCode == 2) {
					int end = gameEnd(myPoint, enePoint); // 1 => 승리     2 => 패배     0 => 무승부 
					if (end == 0) {
						printf("다시 하시겠습니까? (1) 예   (2) 아니오 : ");
						for (int w = 0; w < 1; w++) {
							scanf_s("%d", &choseCode);
							if (choseCode < 1) {
								printf("잘못된 입력입니다. 다시 입력하세요 : ");
								w--;
								continue;
							}
							else if (choseCode > 2) {
								printf("잘못된 입력입니다. 다시 입력하세요 : ");
								w--;
								continue;
							}
							if (choseCode == 1) {
								printf("게임을 재시작합니다.\n");
								// 초기설정
								gameState = 0; // 0 => 배팅 미완료    1 => 배팅 완료     2 => 파산     3 => 게임 종료
								myPoint = 0;
								enePoint = 0;
								stake = 0;
								// 카드 초기화

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
								// 카드 초기화
								// 초기설정
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
						printf("다시 하시겠습니까? (1) 예   (2) 아니오 : ");
						myCoin += stake;
						winCount++;
						for (int w = 0; w < 1; w++) {
							scanf_s("%d", &choseCode);
							if (choseCode < 1) {
								printf("잘못된 입력입니다. 다시 입력하세요 : ");
								w--;
								continue;
							}
							else if (choseCode > 2) {
								printf("잘못된 입력입니다. 다시 입력하세요 : ");
								w--;
								continue;
							}
							if (choseCode == 1) {
								printf("게임을 재시작합니다.\n");
								// 초기설정
								gameState = 0; // 0 => 배팅 미완료    1 => 배팅 완료     2 => 파산     3 => 게임 종료
								myPoint = 0;
								enePoint = 0;
								stake = 0;
								// 카드 초기화

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
								// 카드 초기화
								// 초기설정
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
						printf("다시 하시겠습니까? (1) 예   (2) 아니오 : ");
						myCoin -= stake;
						loseCount++;
						for (int w = 0; w < 1; w++) {
							scanf_s("%d", &choseCode);
							if (choseCode < 1) {
								printf("잘못된 입력입니다. 다시 입력하세요 : ");
								w--;
								continue;
							}
							else if (choseCode > 2) {
								printf("잘못된 입력입니다. 다시 입력하세요 : ");
								w--;
								continue;
							}
							if (choseCode == 1) {
								printf("게임을 재시작합니다.\n");
								// 초기설정
								gameState = 0; // 0 => 배팅 미완료    1 => 배팅 완료     2 => 파산     3 => 게임 종료
								myPoint = 0;
								enePoint = 0;
								stake = 0;
								// 카드 초기화

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
								// 카드 초기화
								// 초기설정
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
				// 게임 승패, 게임 지속 여부 
				else { // 카드 뽑기 선택
					system("cls");
					play--;
				}
			}
			// 카드뽑기, 게임 종료 선택
		}
	// 게임 시작
	}