#include <stdio.h>

/*
파일 스트림을 얻어와서, 텍스트 메모장에 무언가를 써보자
인수1 - 파일 경로
인수2 - 옵션 wt,rt
*/

void stdWrite() {
	char str[20];
	//scanf("%s", str);
	printf("표준 출력 스트림으로 출력");

	//file 포인터로 스트림을 제어할 수 있다..
	FILE *file = fopen("C:/c_workspace/files/memo.txt","wt");
	if (file == NULL) {
		printf("스트림을 얻지 못했네요..");
		exit(1);
	}
	//출력은 출력이되, 파일을 대상으로 한 출력 함수!!
	//putchar,fputc
	//fputc('M', file);
	fputs("파일을 씁니다.", file);
	fclose(file);
	
}

void readFile() {
	char * path = "C:/c_workspace/files/memo.txt";
	FILE *file=fopen(path,"rt");
	if (file==NULL) {
		printf("스트림 생성 실패\n");
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