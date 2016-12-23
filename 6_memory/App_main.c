#include <stdio.h>
#include <stdlib.h>

void test() {
	//메모리 할당해 줘!!
	//int *p =(int *) malloc(sizeof(int));
	int *p =(int *) calloc(5,sizeof(int)); //인수1 - 배열의 사이즈, 인수2 - 배열의 자료형
	if (p == NULL) exit(1); //메모리할당에 항상 성공하는건아니기 때문에 예외처리를 꼭 해야한다.

	*p = 8;
	printf("%d",p[0]);
	//늘리거나 줄이고 싶다..
	//메모리 영역이 부족하다면 자동으로 메모리 주로를 새로 할당받아 넓은 영역으로 옮겨간다
	p=(int *)realloc(p, sizeof(int)*6);

	free(p); // 할당된 메모리 해제

	/*malloc 와 calloc 사실같다
	하지만 calloc는 생성된 메모리 영역을 0으로 초기화 시켜준다!!
	초기화 작업이 굳이 초기화 연산까지 하면서 자원을 낭비할 필요는 없으므로, 필요에 따라 적절히 사용하면 된다.*/
}

//C라이브러리 함수 중 스트링 관련 함수 학습
void stringFunc() {
	char str[20];
	str[0] = 'a';
	str[1] = 'p';
	str[2] = 'p';
	str[3] = 'l';
	str[4] = '/0';

	strcpy(str, "japan");
	printf("%s", str);

	//putchar : 모니터등의 표준 출력스트림에 출력
	//fputc : 표준 출력 스트림뿐만 아니라, 파일에도 출력이 가능
}

int main() {
	stringFunc();
	//test();
	return 0;
}