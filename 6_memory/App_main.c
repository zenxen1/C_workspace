#include <stdio.h>
#include <stdlib.h>

void test() {
	//�޸� �Ҵ��� ��!!
	//int *p =(int *) malloc(sizeof(int));
	int *p =(int *) calloc(5,sizeof(int)); //�μ�1 - �迭�� ������, �μ�2 - �迭�� �ڷ���
	if (p == NULL) exit(1); //�޸��Ҵ翡 �׻� �����ϴ°Ǿƴϱ� ������ ����ó���� �� �ؾ��Ѵ�.

	*p = 8;
	printf("%d",p[0]);
	//�ø��ų� ���̰� �ʹ�..
	//�޸� ������ �����ϴٸ� �ڵ����� �޸� �ַθ� ���� �Ҵ�޾� ���� �������� �Űܰ���
	p=(int *)realloc(p, sizeof(int)*6);

	free(p); // �Ҵ�� �޸� ����

	/*malloc �� calloc ��ǰ���
	������ calloc�� ������ �޸� ������ 0���� �ʱ�ȭ �����ش�!!
	�ʱ�ȭ �۾��� ���� �ʱ�ȭ ������� �ϸ鼭 �ڿ��� ������ �ʿ�� �����Ƿ�, �ʿ信 ���� ������ ����ϸ� �ȴ�.*/
}

//C���̺귯�� �Լ� �� ��Ʈ�� ���� �Լ� �н�
void stringFunc() {
	char str[20];
	str[0] = 'a';
	str[1] = 'p';
	str[2] = 'p';
	str[3] = 'l';
	str[4] = '/0';

	strcpy(str, "japan");
	printf("%s", str);

	//putchar : ����͵��� ǥ�� ��½�Ʈ���� ���
	//fputc : ǥ�� ��� ��Ʈ���Ӹ� �ƴ϶�, ���Ͽ��� ����� ����
}

int main() {
	stringFunc();
	//test();
	return 0;
}