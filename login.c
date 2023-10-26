#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

int main(void) {
	char password[20] = "";
	char id[20] = "";
	int code = 0;
	int login = 0;


	for (int j = 0; j < 1; j++) {

		char epassword[20] = "";
		char eid[20] = "";
		int code = 0;
		system("cls");


		if (login == 0) {
			printf("홈페이지---\n로그인(1) 회원가입(2) : ");
			scanf_s("%d", &code);
			if (code == 1) {
				for (int k = 0; k < 1; k++) {
					system("cls");
					printf("홈페이지---\n아이디를 입력하세요. (엔터를 누르면 작성이 완료됩니다.): ");
					for (int i = 0; i < 20; i++) {
						eid[i] = _getch();
						if (eid[i] == 13) {
							break;
						};
						printf("%c", eid[i]);
					}
					printf("\n아이디가 작성되었습니다.\n");
					Sleep(1000);

					printf("비밀번호를 입력하세요. (엔터를 누르면 작성이 완료됩니다.): ");
					for (int i = 0; i < 20; i++) {
						epassword[i] = _getch();
						if (epassword[i] == 13) {
							break;
						};
						printf("%c", epassword[i]);
					}
					printf("\n비밀번호가 작성되었습니다.\n");
					Sleep(1000);
					if (strcmp(id, eid) == 0 && strcmp(password, epassword) == 0) {
						printf("로그인되었습니다!\n");
						login = 1;
						Sleep(1000);
						j--;
					}
					else {
						printf("아이디 또는 비밀번호가 잘못되었습니다!\n");
						Sleep(1000);
						k--;
					}
				}

			}

			else if (code == 2) {
				// 회원가입
				system("cls");
				printf("홈페이지---\n아이디를 입력하세요. (엔터를 누르면 작성이 완료됩니다.): ");
				for (int i = 0; i < 20; i++) {
					id[i] = _getch();
					if (id[i] == 13) {
						break;
					};
					printf("%c", id[i]);
				}
				printf("아이디가 작성되었습니다.\n");
				Sleep(1000);

				printf("비밀번호를 입력하세요. (엔터를 누르면 작성이 완료됩니다.): ");
				for (int i = 0; i < 20; i++) {
					password[i] = _getch();
					if (password[i] == 13) {
						break;
					};
					printf("%c", password[i]);
				}
				printf("비밀번호가 작성되었습니다.\n");
				Sleep(1000);
				j--;
			}
		}
		else {
			printf("홈페이지---\nid : %s\npassword : %s\n로그아웃(1) : ", id, password);
			scanf_s("%d", &code);
			if (code == 1) {
				printf("로그아웃 되었습니다!\n");
				login = 0;
				Sleep(1000);
				j--;
			}
		}
	}



}