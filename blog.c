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
	int message_count;				// 받은 메시지 개수
};
int login(int* login_state, int* login_user_num, struct user USER[]) {
	struct user is_user;
	printf(" 아이디를  입력하세요 :");
	gets_s(is_user.id, 11);
	printf("비밀번호를 입력하세요 :");
	gets_s(is_user.pw, 11);
	for (int i = 0; i < 3; i++) {
		if (strcmp(is_user.id, USER[i].id) == 0 && strcmp(is_user.pw, USER[i].pw) == 0) {
			printf("%s님 어서오세요.\n", USER[i].name);
			*login_user_num = USER[i].user_num;
			*login_state = 1;
			Sleep(1000);
			return 1;
		}
		if (i == 2) {
			printf("해당하는 계정이 없습니다.\n");
			Sleep(1000);
			return 0;
		}
	}
}
void print_title(int* login_state, int login_user_num, struct user USER[]) {
	printf("===========================================================\n");
	printf("                       정보통신 TALK                       \n");
	printf("===========================================================\n");
	if (*login_state) {
		printf("[ %s ] 로그인 상태 \n", USER[login_user_num].name);
	}
	else {
		printf("로그인 필요...\n");
	}
}
void print_message(int login_state, int login_user_num, struct user USER[]) {
	if (login_state) {
		if (USER[login_user_num].message_count == 0) {
			printf("받은 메시지가 없습니다.\n");
		}
		else {
			printf("+----------------------------------------------------------+\n");
			for (int i = 0; i < USER[login_user_num].message_count; i++) {
				printf("%s 가\n", USER[login_user_num].messages[i].sender);
				printf("%s\n", USER[login_user_num].messages[i].contents);
				printf("%s 에게\n", USER[login_user_num].messages[i].receiver);
				printf("%s\n", USER[login_user_num].messages[i].date);
				printf("+----------------------------------------------------------+\n");
			}
		}
	}
	else return;
}
void write_message(int login_state, int login_user_num, struct user* USER[]) {
	if (login_state) {
		struct message MESSAGE = { "","","","" };		// 보낼 메시지
		int receiver_num = -1;
		printf("메시지를 보낼 사람 :");
		gets_s(MESSAGE.receiver, sizeof(MESSAGE.receiver) - 1);
		for (int i = 0; i < 3; i++) {
			if (strcmp(MESSAGE.receiver, USER[i]->name) == 0) {
				strcpy(MESSAGE.receiver, USER[login_user_num]->name);
				printf("파박!!\n");
				break;
			}
			if (i == 2) {
				printf("수신자 입력이 잘못되었습니다.\n");
			}
		}
		printf("   메시지  내용    :");
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
	int login_state = 0;	// 0-비로그인   1-로그인

	strcpy(USER[0].name, "김진현");
	strcpy(USER[0].id, "kim12");
	strcpy(USER[0].pw, "kim12");
	strcpy(USER[1].name, "홍성은");
	strcpy(USER[1].id, "hong12");
	strcpy(USER[1].pw, "hong12");
	strcpy(USER[2].name, "유저1");
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
		printf("로그인 실패");
	}

	strcpy(USER[0].messages[0].receiver, "김진현");
	strcpy(USER[0].messages[0].sender, "엄준식");
	strcpy(USER[0].messages[0].contents, "야 너 오늘 생일이라며 축하한다 새~끼야!!ㅋㅋ");
	strcpy(USER[0].messages[0].date, "2022 11 5");
	USER[0].message_count++;
	strcpy(USER[0].messages[1].receiver, "김진현");
	strcpy(USER[0].messages[1].sender, "허준식");
	strcpy(USER[0].messages[1].contents, "엄엄엄ㅇ멍ㅁ엄ㅇ멍멍엄ㅇ");
	strcpy(USER[0].messages[1].date, "2022 11 4");
	USER[0].message_count++;
	strcpy(USER[0].messages[2].receiver, "김진현");
	strcpy(USER[0].messages[2].sender, "한재소쿠");
	strcpy(USER[0].messages[2].contents, "Amogus aaaaaaaaaaaaaaaaaaaaaaaaa");
	strcpy(USER[0].messages[2].date, "2022 11 7");
	USER[0].message_count++;

	print_message(login_state, login_user_num, USER);
}