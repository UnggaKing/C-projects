#include <stdio.h>
#include <Windows.h>

void print_security(char name[], int age, int password) {
	printf("NAME : %s\nAGE : %d\nPASSWORD : %d\n", name, age, password);
}

void change_age(int* a) {
	int age;
	printf("���� ����: %d    �ٲ� ����: ", *a);
	scanf_s("%d", &age);
	*a = age;
	system("cls");

}


int main(void) {
	char name[10] = "�����";
	int age = 19;
	int password = 123;
	int code = 0;
	for (int i = 0; i < 1; i++) {
		print_security(name, age, password);
		printf("(2)���� ���� (4)���� - ");
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