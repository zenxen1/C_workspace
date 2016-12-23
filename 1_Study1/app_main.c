//컴파일이 되기 전에 헤더파일의 위치를 찾아가서, 그 파일의 소스를 현재 파일로 가져다가 붙여넣기 한다. 컴파일 전에 수행 된다고 하여 전처리기라 한다...

#include <stdio.h>

//5단 출력
void printDan() {
	//printf("c언어 테스트!!");
	int dan = 5;


	for (int i = 1; i <= 9; i++) {
		printf("%d * %d = %d \n", dan, i, dan * i);
	}

	//system("pause");
}

//원하는 수를 입력받아 구구단 출력
void printDan2() {
	int dan = 0;

	while (1) {
		scanf("%d", &dan);//입력한 값을 실제 메모리에 생선된 dan 변수의 주소값을 찾아가 변경해 버린다..
		if (dan == 1)break;
		printf("당신이 입력한 값은 ? %d", dan);

		for (int i = 1; i <= 9; i++) {
			printf("%d * %d = %d \n", dan, i, dan * i);
		}
	}
}

//자료형 조사 c언어는 자료형의 크기가 틀리다...하지만 외우지 말자 c언어는 자료형의 크키를 알려주는 연산자가 지원된다...
//sizeof() 연산자 <--- 주의 함수 아님!!
void getTypeInfo() {
	char c = 'A';
	printf("아스키코드는 %d 이고 문자는 %c 이다. 크기는%d \n", c, c,sizeof(char));
	printf("자료형의 크기는 %d \n", sizeof(float));
	printf("자료형의 크기는 %d \n", sizeof(double));
	printf("자료형의 크기는 %d \n", sizeof(long double));

	const int UPLOAD_SIZE = 1024; //상수 만드는법
	
}

/*
C의 배열 기초 학습......
*/
void basicArray() {
	int arr[5] = {1,2,3,4,5};
	int arr2[5] = { 6,7,8,9,10 };

	int len = sizeof(arr) / sizeof(int);
	//printf("배열의 길이는 %d",len);

	//자바는 배열을 객체취급하므로, 즉 레퍼런스의 변경은 가능하였다..
	//증명: c에서 배열명은 곧 생성된 배열요소의 첫번째 주소값으로 대채된다
	//c언어에서 배열명은 상수다
	printf("arr 주소값은 %p, arr[0] 의 주소값은 %p", arr, &arr[0]);

	int a = 3;
	//printf("a의 주소값은 %p",&a);

	//변수가 아닌 실제 주소값으로도 a의 값을 접근할 수 있다.
	*&a=5;
	//printf("a의 값은 %d", a);
}

void getsum() {
	int arr[3];

	//키보드로 부터 입력받아 순서대로 0,1,2번째 요소에 값을 넣고, 그합계를 출력하는 프로그램...
	printf("첫번째 수 입력\n");
	scanf("%d", &arr[0]);
	printf("두번째 수 입력\n");
	scanf("%d", &arr[1]);
	printf("세번째 수 입력\n");
	scanf("%d", &arr[2]);

	printf("세수의 합은 %d", arr[0] + arr[1] + arr[2]);

}


void getstr() {
	
	//원칙
	char str[5];
	str[0] = 'k';
	str[1] = 'o';
	str[2] = 'r';
	str[3] = 'e';
	str[4] = 'a';
	
	//문자열과 그길이를 출력
	printf("길이 %d \n", sizeof(str) / sizeof(char));

	for (int i = 0; i < sizeof(str) / sizeof(char); i++) {
		printf("문자열 %c\n", str[i]);
	}
	
	//방식2
	char str2[5] = {'k','o', 'r', 'e', 'a'};

	//문자열과 그길이를 출력
	printf("길이%d\n", sizeof(str2) / sizeof(char));
	for (int i = 0; i < sizeof(str2) / sizeof(char); i++) {
		printf("문자열 %c\n", str2[i]);
	}

	//초기화 값만큼 배열의 길이를 계산하므로 생략이 가능...
	char str3[] = { 'k','o', 'r', 'e', 'a' };

	//방식4
	//문자열 상수를 이용시 길이가 +1 더 되는 이유?? 
	//배열에 일일이 담는 방식이 아니기 때문에, 문자열의 끝임을 알수 있는 표시가 필요했던 것이다..따라서 자동으로 \0으로 표시되는 null문자가 삽입된다.
	char str4[] = "korea";
	printf("%d\n",sizeof(str4)/sizeof(char));
	printf("%s\n", str4);
	int i = 0;
	while (str4[i] != '\0') {
		printf("%c",str4[i]);
		i++;
	}


	//방식5
	char *str5 = "korea";
	int len = 0;
	int j = 0;
	while (str5[j] !='\0') {
		len++;
		j++;
	}
	printf("str5의 길이는 %d \n",len);
	printf("%s \n",str5);



	//포인터 맛배기
	//포인터형의 크기는 4이다. 앞의 자료형은 종류만 결정 한다
	int a = 5;
	int *pt = &a;

	char test[] = "ABC";
	printf("%d\n", sizeof(test) / sizeof(char));
	


}

//문자열 상수의 메모리 생성 관련
//C에서 문자열은 데이터 영역에 올라가고, 동일한 문자열은 재사용....

void stringInfo() {
	char * ch1 = "apple"; //문자열 상수
	char * ch2 = "apple";
	char * ch3 = "apple";
	char * ch4 = "apple";
	char * ch5 = "apple";

	printf("%p\n", ch1);
	printf("%p\n", ch2);
	printf("%p\n", ch3);
	printf("%p\n", ch4);
	printf("%p\n", ch5);

	printf("%c\n","apple"[0]); //문자열상수는 첫벗째글자의 문자의 주소값이 된다.

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
	return 0; //정상 수행 0, 비정상 0 아닌값
}