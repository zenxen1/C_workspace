#include <stdio.h>
#include <string.h>
#include <winsock2.h>
/*c로 서버를 구축한다!!*/

void errorHandler(char *);
#define MSG_SIZE 1024 //매크로사용

int main() {
	WSADATA wsadata; //0단계
	SOCKET serverSocket, clientSocket; //1단계
	SOCKADDR_IN serverAddr, clientAddr; //2단계
	int port = 8888; //2단계
	char msg[MSG_SIZE];//6단계 배열 선언시 const 사용불가, 정수형 리터럴만 허용
	int strLen;//6단계

	//0단계 : 라이브러리 초기화
	int startResult = WSAStartup(MAKEWORD(1,3),&wsadata);
	if (startResult != 0) {
		errorHandler("라이브러리 초기화에 실패");
	}
	//1단계 : 소켓 생성(서버용, 클라이언트용)
	serverSocket=socket(PF_INET, SOCK_STREAM, 0);
	if (serverSocket == INVALID_SOCKET) {
		errorHandler("소켓 생성에 실패!!");
	}
	//2단계 : 주소설정
	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family=PF_INET;
	serverAddr.sin_addr.s_addr=htonl(INADDR_ANY); //모든 주소를 받아들이겠다
	serverAddr.sin_port=htons(port);
	//3단계 : 소켓과 주소를 바인딩!!(서버에서만....) bind
	int bindResult = bind(serverSocket,(SOCKADDR *)&serverAddr,sizeof(serverAddr));
	if (bindResult == SOCKET_ERROR) {
		errorHandler("바인딩 실패");
	}
	//4단계 : 클라이언트의 접속을 받을 준비 listen
	int listenResult=listen(serverSocket,10);
	if (listenResult == SOCKET_ERROR) {
		errorHandler("접속 받을 준비");
	}
	//5단계 : 접속 허용 accept()
	int clientAddrSize=sizeof(clientAddr);
	clientSocket=accept(serverSocket,(SOCKADDR *)&clientAddr,&clientAddrSize);
	if (clientSocket == INVALID_SOCKET) {
		errorHandler("접속자 허용 실패");
	}
	else {
		printf("접속자 발견\n");
		//6단계 : 대화나누기
		while ((strLen = recv(clientSocket, msg, MSG_SIZE, 0))!=0) {
			send(clientSocket,msg,strlen(msg),0);
		}
		closesocket(clientSocket);
	}
	//7단계 : 자원해제 (소켓닫기)
	closesocket(serverSocket);
	return 0;
}

void errorHandler(char * message) {
	fputs(message,stderr); //에러 스트림에 출력....
	fputc('\n',stderr);
}

