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
			printf("Ȩ������---\n�α���(1) ȸ������(2) : ");
			scanf_s("%d", &code);
			if (code == 1) {
				for (int k = 0; k < 1; k++) {
					system("cls");
					printf("Ȩ������---\n���̵� �Է��ϼ���. (���͸� ������ �ۼ��� �Ϸ�˴ϴ�.): ");
					for (int i = 0; i < 20; i++) {
						eid[i] = _getch();
						if (eid[i] == 13) {
							break;
						};
						printf("%c", eid[i]);
					}
					printf("\n���̵� �ۼ��Ǿ����ϴ�.\n");
					Sleep(1000);

					printf("��й�ȣ�� �Է��ϼ���. (���͸� ������ �ۼ��� �Ϸ�˴ϴ�.): ");
					for (int i = 0; i < 20; i++) {
						epassword[i] = _getch();
						if (epassword[i] == 13) {
							break;
						};
						printf("%c", epassword[i]);
					}
					printf("\n��й�ȣ�� �ۼ��Ǿ����ϴ�.\n");
					Sleep(1000);
					if (strcmp(id, eid) == 0 && strcmp(password, epassword) == 0) {
						printf("�α��εǾ����ϴ�!\n");
						login = 1;
						Sleep(1000);
						j--;
					}
					else {
						printf("���̵� �Ǵ� ��й�ȣ�� �߸��Ǿ����ϴ�!\n");
						Sleep(1000);
						k--;
					}
				}

			}

			else if (code == 2) {
				// ȸ������
				system("cls");
				printf("Ȩ������---\n���̵� �Է��ϼ���. (���͸� ������ �ۼ��� �Ϸ�˴ϴ�.): ");
				for (int i = 0; i < 20; i++) {
					id[i] = _getch();
					if (id[i] == 13) {
						break;
					};
					printf("%c", id[i]);
				}
				printf("���̵� �ۼ��Ǿ����ϴ�.\n");
				Sleep(1000);

				printf("��й�ȣ�� �Է��ϼ���. (���͸� ������ �ۼ��� �Ϸ�˴ϴ�.): ");
				for (int i = 0; i < 20; i++) {
					password[i] = _getch();
					if (password[i] == 13) {
						break;
					};
					printf("%c", password[i]);
				}
				printf("��й�ȣ�� �ۼ��Ǿ����ϴ�.\n");
				Sleep(1000);
				j--;
			}
		}
		else {
			printf("Ȩ������---\nid : %s\npassword : %s\n�α׾ƿ�(1) : ", id, password);
			scanf_s("%d", &code);
			if (code == 1) {
				printf("�α׾ƿ� �Ǿ����ϴ�!\n");
				login = 0;
				Sleep(1000);
				j--;
			}
		}
	}



}