#include <stdio.h>

void pointEX() {
	int a = 3;

	//a�� ���� �޸� �ּҰ��� ��� & ������
	printf("%p\n", &a);

	*&a = 5; //a�� �ּҰ��� ����Ű�� �޸��� ���� 5
	int *p = &a; //* ��ȣ


	printf("%d\n", *p); //* ��������������
						//���� ���� ������!!
}

void swap(int *a, int *b) {
	/*
	printf("��ȯ�� %d,%d",a,b);
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("�ٲﰪ %d,%d", a, b);
	*/
	int temp=0;
	temp = *a;
	*a = *b;
	*b = temp;

}

void flute() {
	char *str[] = {"�ٳ���","���","������", "����", "����", "¥��", "������", "����", "���", "��"};
	int len = sizeof(str) / sizeof(char);
	for (int i = 0; i < 10; i++) {
		printf("%s\n", *(str + i));
	}

	void *pt; // �Լ�, ���� �����͸� ���� �� ������, �ּ� ���� �� ������ ������ �Ұ�....
	          // �ϴ� �ּҰ��� ��� ���� �������� ����ϵ�, �� ������Ÿ���� ���Ŀ� ���� �ϰ��� �Ҷ�..
}

int myFunc(int a, char b) {
	printf("myfunc ȣ���� %d,%c \n", a, b);
}

void test(int(*pp)(int, char)) {
	pp(2, 'g');
}

//����ü

struct member {
	char name[20];
	int age;
};

void createMember() {
	struct member m1; //����ü ���� ����
	struct member m2;

	scanf("%s",m1.name);
	scanf("%d",&m1.age);

	//m1.name = "������";
	//m1.age = 23;

	printf("name %s, age %d \n", m1.name, m1.age);

}

int main() {
	
	createMember();
	
	//�Լ��� ����Ʈ�� ��ƺ���
	int (*fp)(int, char) = myFunc;
	fp(3,'A');

	test(fp);
	test(myFunc);

	//����Ʈ�� ����Ͽ� ������ �ٲܼ� �ִ�.
	int a = 10;
	int b = 20;
	printf("��ȯ�� %d,%d\n", a, b);
	swap(&a,&b);
	printf("�ٲﰪ %d,%d\n", a, b);

	//flute();
	return 0;
}