#include <stdio.h>

/*
���� ��Ʈ���� ���ͼ�, �ؽ�Ʈ �޸��忡 ���𰡸� �Ẹ��
�μ�1 - ���� ���
�μ�2 - �ɼ� wt,rt
*/

void stdWrite() {
	char str[20];
	//scanf("%s", str);
	printf("ǥ�� ��� ��Ʈ������ ���");

	//file �����ͷ� ��Ʈ���� ������ �� �ִ�..
	FILE *file = fopen("C:/c_workspace/files/memo.txt","wt");
	if (file == NULL) {
		printf("��Ʈ���� ���� ���߳׿�..");
		exit(1);
	}
	//����� ����̵�, ������ ������� �� ��� �Լ�!!
	//putchar,fputc
	//fputc('M', file);
	fputs("������ ���ϴ�.", file);
	fclose(file);
	
}

void readFile() {
	char * path = "C:/c_workspace/files/memo.txt";
	FILE *file=fopen(path,"rt");
	if (file==NULL) {
		printf("��Ʈ�� ���� ����\n");
		exit(1);
	}
	//fgets
	char buff[100];
	fgets(buff,sizeof(buff),file);
	printf("%s",buff);
	fclose(file);
}

int main() {
	stdWrite();
	readFile();
	return 0;
}