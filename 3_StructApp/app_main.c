#include <stdio.h>

typedef struct member {
	char name[20];
	int age;
} Member;

/*구조체를 학습한다..*/
int flag = 1;
int mode = 0;

Member list[20];
int count = 0;

void regist() {
	printf("등록할께요\n");

	Member dto;
	printf("이름을 입력:\n");
	scanf("%s", dto.name);
	printf("나이를 입력:\n");
	scanf("%d", &dto.age);

	list[count] = dto;

	printf("등록완료\n");
	count++;
	printf("현재까지 %d 명 등록완료\n",count);

}
void getList() {
	printf("목록보여줄께요\n");
	for (int i = 0; i < count; i++) {
		Member dto = list[i];
		printf("******************************************\n");
		printf("이름:%s나이:%10d\n", dto.name, dto.age);
	}
	printf("******************************************\n");
}
void exit() {
	printf("종료할께요\n");
	flag = 0;
}

void init() {
	while (flag) {
		printf("원하시는 기능을 선택하세요?\n");
		printf("[1]가입 [2]목록 [3]종료\n");
		scanf("%d",&mode);

		switch (mode){
			case 1:regist(); break;
			case 2:getList(); break;
			case 3:exit(); break;
			default:
				printf("사용법 좀 알고 써!!!\n");
				flag = 0;
		}
	}
}

int main() {
	init();
	return 0;
}