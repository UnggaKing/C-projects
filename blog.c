#include <stdio.h>
#include <string.h>
#include <Windows.h>
#pragma warning(disable:4996)
struct message
{
	char sender[10];
	char receiver[10];
	char contents[50];
	char date[11];
};
struct user {
	int user_num;
	char name[10];
	char id[12];
	char pw[12];
	struct message messages[6];
	int message_count;				// ���� �޽��� ����
};
int login(int* login_state, int* login_user_num, struct user USER[]) {
	struct user is_user;
	printf(" ���̵�  �Է��ϼ��� :");
	gets_s(is_user.id, 11);
	printf("��й�ȣ�� �Է��ϼ��� :");
	gets_s(is_user.pw, 11);
	for (int i = 0; i < 3; i++) {
		if (strcmp(is_user.id, USER[i].id) == 0 && strcmp(is_user.pw, USER[i].pw) == 0) {
			printf("%s�� �������.\n", USER[i].name);
			*login_user_num = USER[i].user_num;
			*login_state = 1;
			Sleep(1000);
			return 1;
		}
		if (i == 2) {
			printf("�ش��ϴ� ������ �����ϴ�.\n");
			Sleep(1000);
			return 0;
		}
	}
}
void print_title(int* login_state, int login_user_num, struct user USER[]) {
	printf("===========================================================\n");
	printf("                       ������� TALK                       \n");
	printf("===========================================================\n");
	if (*login_state) {
		printf("[ %s ] �α��� ���� \n", USER[login_user_num].name);
	}
	else {
		printf("�α��� �ʿ�...\n");
	}
}
void print_message(int login_state, int login_user_num, struct user USER[]) {
	if (login_state) {
		if (USER[login_user_num].message_count == 0) {
			printf("���� �޽����� �����ϴ�.\n");
		}
		else {
			printf("+----------------------------------------------------------+\n");
			for (int i = 0; i < USER[login_user_num].message_count; i++) {
				printf("%s ��\n", USER[login_user_num].messages[i].sender);
				printf("%s\n", USER[login_user_num].messages[i].contents);
				printf("%s ����\n", USER[login_user_num].messages[i].receiver);
				printf("%s\n", USER[login_user_num].messages[i].date);
				printf("+----------------------------------------------------------+\n");
			}
		}
	}
	else return;
}
void write_message(int login_state, int login_user_num, struct user* USER[]) {
	if (login_state) {
		struct message MESSAGE = { "","","","" };		// ���� �޽���
		int receiver_num = -1;
		printf("�޽����� ���� ��� :");
		gets_s(MESSAGE.receiver, sizeof(MESSAGE.receiver) - 1);
		for (int i = 0; i < 3; i++) {
			if (strcmp(MESSAGE.receiver, USER[i]->name) == 0) {
				strcpy(MESSAGE.receiver, USER[login_user_num]->name);
				printf("�Ĺ�!!\n");
				break;
			}
			if (i == 2) {
				printf("������ �Է��� �߸��Ǿ����ϴ�.\n");
			}
		}
		printf("   �޽���  ����    :");
		gets_s(MESSAGE.contents, sizeof(MESSAGE.contents) - 1);
		USER[login_user_num]->messages[USER[login_user_num]->message_count] = MESSAGE;
		USER[login_user_num]->message_count++;
	}
	else return;
}
int main(void) {
	int login_user_num = 7;
	int f_result = 7;
	struct user USER[3];
	struct user* user_p;
	user_p = USER;
	int login_state = 0;	// 0-��α���   1-�α���

	strcpy(USER[0].name, "������");
	strcpy(USER[0].id, "kim12");
	strcpy(USER[0].pw, "kim12");
	strcpy(USER[1].name, "ȫ����");
	strcpy(USER[1].id, "hong12");
	strcpy(USER[1].pw, "hong12");
	strcpy(USER[2].name, "����1");
	strcpy(USER[2].id, "user1");
	strcpy(USER[2].pw, "user1");
	write_message(1, 1, user_p);

	for (int i = 0; i < 3; i++) {
		USER[i].user_num = i;
		USER[i].message_count = 0;
	}
	print_title(&login_state, login_user_num, USER);
	f_result = login(&login_state, &login_user_num, USER);
	if (f_result) {
		system("cls");
		print_title(&login_state, login_user_num, USER);
	}
	else {
		printf("�α��� ����");
	}

	strcpy(USER[0].messages[0].receiver, "������");
	strcpy(USER[0].messages[0].sender, "���ؽ�");
	strcpy(USER[0].messages[0].contents, "�� �� ���� �����̶�� �����Ѵ� ��~����!!����");
	strcpy(USER[0].messages[0].date, "2022 11 5");
	USER[0].message_count++;
	strcpy(USER[0].messages[1].receiver, "������");
	strcpy(USER[0].messages[1].sender, "���ؽ�");
	strcpy(USER[0].messages[1].contents, "���������ۤ������۸۾���");
	strcpy(USER[0].messages[1].date, "2022 11 4");
	USER[0].message_count++;
	strcpy(USER[0].messages[2].receiver, "������");
	strcpy(USER[0].messages[2].sender, "�������");
	strcpy(USER[0].messages[2].contents, "Amogus aaaaaaaaaaaaaaaaaaaaaaaaa");
	strcpy(USER[0].messages[2].date, "2022 11 7");
	USER[0].message_count++;

	print_message(login_state, login_user_num, USER);
}