#include <stdio.h>
#include <WinSock2.h>
#include <string.h>
//#include <sys/socket.h>

/*
OS에 따라 네트워크 소스가 약간 틀리다

유닉스계열 : 컴퓨터의 역사 그 자체 우리가 알고 있는 시스템 프로그래밍 기술 및 네트워크 기술은 
			사실 모두 유닉스에서 출발한다...
			솔라리스, mac os, 리눅스

공개,무료 + 빠르고 + 작고 + 인터넷 = 리눅스
90년대 핀란드 헬싱키 대학 리누스 토발즈..
배포판-레드햇, CEntos, 우분투..

버클리 대학 네트워크 프로그래밍 기술 고안 
BSD는 산업표준....

-------------------------------------------------------------------------------------
윈도우계열
- BSD를 따른다..
- but 완전 똑같지 않고 유닉스 계열과 차이가 있다. 
windsock.h 라이브러리를 사용해야한다..
DLL
*/
void errorHandler(char *);

int main() {
	// 소켓 라이브러 초기화 구조체
	WSADATA wsaData;
	SOCKET clientSocket; //소켓
	SOCKADDR_IN serverAddr;

	char msg[1024]; //대화용 메시지 담을 배열
	int strLen; //메세지 주고 받을때 문자열 길이 관련 정보...
	const int BUF_SIZE = 1024;

	//나 윈소켓 2.2 쓸꺼에요!!
	int startResult = WSAStartup(MAKEWORD(2,2),&wsaData);
	if (startResult != 0) {
		errorHandler("라이브러리 초기화에 실패하였습니다.");
	}

	//2단계 소켓을 준비한다
	//자바에서는 소켓 생성이 곧 접속이지만 c언어는 그렇지 않다
	clientSocket=socket(PF_INET, SOCK_STREAM, 0);
	if (clientSocket == INVALID_SOCKET) {
		errorHandler("소켓 생성 실패!!");
	}

	//3단계 : 주소 초기화 (ip);
	memset(&serverAddr,0,sizeof(serverAddr));
	serverAddr.sin_family=PF_INET;
	serverAddr.sin_addr.s_addr = inet_addr("70.12.112.94");
	serverAddr.sin_port = htons(8888);

	//4단계 : 접속
	int connectResult = connect(clientSocket,(SOCKADDR *)&serverAddr,sizeof(serverAddr));
	if (connectResult == SOCKET_ERROR) {
		errorHandler("접속 실패!!");
	}
	else {
		puts("접속에 성공하였습니다");
	}

	//5단계 : 대화 주고 받기!!
	while (1) {
		//키보드로부터 입력 받음!!
		fgets(msg,BUF_SIZE,stdin);

		//send, recv은 winsocket에서 지원
		//서버에 보내기
		send(clientSocket, msg, strlen(msg), 0);

		//받기!!
		strLen = recv(clientSocket, msg, BUF_SIZE - 1, 0);
		msg[strLen] = 0;
		puts(msg); //화면의 출력
	}
	return 0;
}

void errorHandler(char * message) {
	//f가 붙으면 대상이 표준입출력 + 파일 까지도 섭렵 가능하다
	fputs(message,stderr);
	fputc("\n",stderr);
	exit(1);
}