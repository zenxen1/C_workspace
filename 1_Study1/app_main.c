//�������� �Ǳ� ���� ��������� ��ġ�� ã�ư���, �� ������ �ҽ��� ���� ���Ϸ� �����ٰ� �ٿ��ֱ� �Ѵ�. ������ ���� ���� �ȴٰ� �Ͽ� ��ó����� �Ѵ�...

#include <stdio.h>

//5�� ���
void printDan() {
	//printf("c��� �׽�Ʈ!!");
	int dan = 5;


	for (int i = 1; i <= 9; i++) {
		printf("%d * %d = %d \n", dan, i, dan * i);
	}

	//system("pause");
}

//���ϴ� ���� �Է¹޾� ������ ���
void printDan2() {
	int dan = 0;

	while (1) {
		scanf("%d", &dan);//�Է��� ���� ���� �޸𸮿� ������ dan ������ �ּҰ��� ã�ư� ������ ������..
		if (dan == 1)break;
		printf("����� �Է��� ���� ? %d", dan);

		for (int i = 1; i <= 9; i++) {
			printf("%d * %d = %d \n", dan, i, dan * i);
		}
	}
}

//�ڷ��� ���� c���� �ڷ����� ũ�Ⱑ Ʋ����...������ �ܿ��� ���� c���� �ڷ����� ũŰ�� �˷��ִ� �����ڰ� �����ȴ�...
//sizeof() ������ <--- ���� �Լ� �ƴ�!!
void getTypeInfo() {
	char c = 'A';
	printf("�ƽ�Ű�ڵ�� %d �̰� ���ڴ� %c �̴�. ũ���%d \n", c, c,sizeof(char));
	printf("�ڷ����� ũ��� %d \n", sizeof(float));
	printf("�ڷ����� ũ��� %d \n", sizeof(double));
	printf("�ڷ����� ũ��� %d \n", sizeof(long double));

	const int UPLOAD_SIZE = 1024; //��� ����¹�
	
}

/*
C�� �迭 ���� �н�......
*/
void basicArray() {
	int arr[5] = {1,2,3,4,5};
	int arr2[5] = { 6,7,8,9,10 };

	int len = sizeof(arr) / sizeof(int);
	//printf("�迭�� ���̴� %d",len);

	//�ڹٴ� �迭�� ��ü����ϹǷ�, �� ���۷����� ������ �����Ͽ���..
	//����: c���� �迭���� �� ������ �迭����� ù��° �ּҰ����� ��ä�ȴ�
	//c���� �迭���� �����
	printf("arr �ּҰ��� %p, arr[0] �� �ּҰ��� %p", arr, &arr[0]);

	int a = 3;
	//printf("a�� �ּҰ��� %p",&a);

	//������ �ƴ� ���� �ּҰ����ε� a�� ���� ������ �� �ִ�.
	*&a=5;
	//printf("a�� ���� %d", a);
}

void getsum() {
	int arr[3];

	//Ű����� ���� �Է¹޾� ������� 0,1,2��° ��ҿ� ���� �ְ�, ���հ踦 ����ϴ� ���α׷�...
	printf("ù��° �� �Է�\n");
	scanf("%d", &arr[0]);
	printf("�ι�° �� �Է�\n");
	scanf("%d", &arr[1]);
	printf("����° �� �Է�\n");
	scanf("%d", &arr[2]);

	printf("������ ���� %d", arr[0] + arr[1] + arr[2]);

}


void getstr() {
	
	//��Ģ
	char str[5];
	str[0] = 'k';
	str[1] = 'o';
	str[2] = 'r';
	str[3] = 'e';
	str[4] = 'a';
	
	//���ڿ��� �ױ��̸� ���
	printf("���� %d \n", sizeof(str) / sizeof(char));

	for (int i = 0; i < sizeof(str) / sizeof(char); i++) {
		printf("���ڿ� %c\n", str[i]);
	}
	
	//���2
	char str2[5] = {'k','o', 'r', 'e', 'a'};

	//���ڿ��� �ױ��̸� ���
	printf("����%d\n", sizeof(str2) / sizeof(char));
	for (int i = 0; i < sizeof(str2) / sizeof(char); i++) {
		printf("���ڿ� %c\n", str2[i]);
	}

	//�ʱ�ȭ ����ŭ �迭�� ���̸� ����ϹǷ� ������ ����...
	char str3[] = { 'k','o', 'r', 'e', 'a' };

	//���4
	//���ڿ� ����� �̿�� ���̰� +1 �� �Ǵ� ����?? 
	//�迭�� ������ ��� ����� �ƴϱ� ������, ���ڿ��� ������ �˼� �ִ� ǥ�ð� �ʿ��ߴ� ���̴�..���� �ڵ����� \0���� ǥ�õǴ� null���ڰ� ���Եȴ�.
	char str4[] = "korea";
	printf("%d\n",sizeof(str4)/sizeof(char));
	printf("%s\n", str4);
	int i = 0;
	while (str4[i] != '\0') {
		printf("%c",str4[i]);
		i++;
	}


	//���5
	char *str5 = "korea";
	int len = 0;
	int j = 0;
	while (str5[j] !='\0') {
		len++;
		j++;
	}
	printf("str5�� ���̴� %d \n",len);
	printf("%s \n",str5);



	//������ �����
	//���������� ũ��� 4�̴�. ���� �ڷ����� ������ ���� �Ѵ�
	int a = 5;
	int *pt = &a;

	char test[] = "ABC";
	printf("%d\n", sizeof(test) / sizeof(char));
	


}

//���ڿ� ����� �޸� ���� ����
//C���� ���ڿ��� ������ ������ �ö󰡰�, ������ ���ڿ��� ����....

void stringInfo() {
	char * ch1 = "apple"; //���ڿ� ���
	char * ch2 = "apple";
	char * ch3 = "apple";
	char * ch4 = "apple";
	char * ch5 = "apple";

	printf("%p\n", ch1);
	printf("%p\n", ch2);
	printf("%p\n", ch3);
	printf("%p\n", ch4);
	printf("%p\n", ch5);

	printf("%c\n","apple"[0]); //���ڿ������ ù��°������ ������ �ּҰ��� �ȴ�.

}

void showMSG(char *str, char content[]) {
	
	printf("%s %s", str,content);
}

int main() {
	char ch[] = { 'd','d','\0' };
	showMSG("zzzzzzzz", ch);
	//stringInfo();
	//getstr();
	//getsum();
	//getTypeInfo();
	//basicArray();
	return 0; //���� ���� 0, ������ 0 �ƴѰ�
}