#include <stdio.h>

typedef struct member {
	char name[20];
	int age;
} Member;

/*����ü�� �н��Ѵ�..*/
int flag = 1;
int mode = 0;

Member list[20];
int count = 0;

void regist() {
	printf("����Ҳ���\n");

	Member dto;
	printf("�̸��� �Է�:\n");
	scanf("%s", dto.name);
	printf("���̸� �Է�:\n");
	scanf("%d", &dto.age);

	list[count] = dto;

	printf("��ϿϷ�\n");
	count++;
	printf("������� %d �� ��ϿϷ�\n",count);

}
void getList() {
	printf("��Ϻ����ٲ���\n");
	for (int i = 0; i < count; i++) {
		Member dto = list[i];
		printf("******************************************\n");
		printf("�̸�:%s����:%10d\n", dto.name, dto.age);
	}
	printf("******************************************\n");
}
void exit() {
	printf("�����Ҳ���\n");
	flag = 0;
}

void init() {
	while (flag) {
		printf("���Ͻô� ����� �����ϼ���?\n");
		printf("[1]���� [2]��� [3]����\n");
		scanf("%d",&mode);

		switch (mode){
			case 1:regist(); break;
			case 2:getList(); break;
			case 3:exit(); break;
			default:
				printf("���� �� �˰� ��!!!\n");
				flag = 0;
		}
	}
}

int main() {
	init();
	return 0;
}