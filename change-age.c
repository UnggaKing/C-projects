#include <stdio.h>
#include <Windows.h>

void print_security(char name[], int age, int password) {
	printf("NAME : %s\nAGE : %d\nPASSWORD : %d\n", name, age, password);
}

void change_age(int* a) {
	int age;
	printf("기존 나이: %d    바꿀 나이: ", *a);
	scanf_s("%d", &age);
	*a = age;
	system("cls");

}


int main(void) {
	char name[10] = "김미정";
	int age = 19;
	int password = 123;
	int code = 0;
	for (int i = 0; i < 1; i++) {
		print_security(name, age, password);
		printf("(2)나이 변경 (4)종료 - ");
		scanf_s("%d", &code);
		
		if (code == 2) {
			change_age(&age);
			i--;
			continue;
		}
		else {
			break;
		}
	}
	

	return 0;
}