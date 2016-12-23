#include <stdio.h>

void pointEX() {
	int a = 3;

	//a의 실제 메모리 주소값을 얻기 & 연산자
	printf("%p\n", &a);

	*&a = 5; //a의 주소값이 가리키는 메모리의 값을 5
	int *p = &a; //* 기호


	printf("%d\n", *p); //* 간접참조연산자
						//간접 참조 연산자!!
}

void swap(int *a, int *b) {
	/*
	printf("교환전 %d,%d",a,b);
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("바뀐값 %d,%d", a, b);
	*/
	int temp=0;
	temp = *a;
	*a = *b;
	*b = temp;

}

void flute() {
	char *str[] = {"바나나","사과","오렌지", "우유", "딸기", "짜장", "떡복이", "수박", "멜론", "귤"};
	int len = sizeof(str) / sizeof(char);
	for (int i = 0; i < 10; i++) {
		printf("%s\n", *(str + i));
	}

	void *pt; // 함수, 변수 포인터를 담을 수 있지만, 주소 연산 및 참조값 변경은 불가....
	          // 일단 주소값을 담아 놓을 목적으로 사용하되, 그 데이터타입을 추후에 결정 하고자 할때..
}

int myFunc(int a, char b) {
	printf("myfunc 호출함 %d,%c \n", a, b);
}

void test(int(*pp)(int, char)) {
	pp(2, 'g');
}

//구조체

struct member {
	char name[20];
	int age;
};

void createMember() {
	struct member m1; //구조체 변수 선언
	struct member m2;

	scanf("%s",m1.name);
	scanf("%d",&m1.age);

	//m1.name = "ㅋㅋㅋ";
	//m1.age = 23;

	printf("name %s, age %d \n", m1.name, m1.age);

}

int main() {
	
	createMember();
	
	//함수를 포인트에 담아보자
	int (*fp)(int, char) = myFunc;
	fp(3,'A');

	test(fp);
	test(myFunc);

	//포인트를 사용하여 원복을 바꿀수 있다.
	int a = 10;
	int b = 20;
	printf("교환전 %d,%d\n", a, b);
	swap(&a,&b);
	printf("바뀐값 %d,%d\n", a, b);

	//flute();
	return 0;
}