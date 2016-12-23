#include <stdio.h>
#include <string.h>
#include <winsock2.h>
/*c�� ������ �����Ѵ�!!*/

void errorHandler(char *);
#define MSG_SIZE 1024 //��ũ�λ��

int main() {
	WSADATA wsadata; //0�ܰ�
	SOCKET serverSocket, clientSocket; //1�ܰ�
	SOCKADDR_IN serverAddr, clientAddr; //2�ܰ�
	int port = 8888; //2�ܰ�
	char msg[MSG_SIZE];//6�ܰ� �迭 ����� const ���Ұ�, ������ ���ͷ��� ���
	int strLen;//6�ܰ�

	//0�ܰ� : ���̺귯�� �ʱ�ȭ
	int startResult = WSAStartup(MAKEWORD(1,3),&wsadata);
	if (startResult != 0) {
		errorHandler("���̺귯�� �ʱ�ȭ�� ����");
	}
	//1�ܰ� : ���� ����(������, Ŭ���̾�Ʈ��)
	serverSocket=socket(PF_INET, SOCK_STREAM, 0);
	if (serverSocket == INVALID_SOCKET) {
		errorHandler("���� ������ ����!!");
	}
	//2�ܰ� : �ּҼ���
	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family=PF_INET;
	serverAddr.sin_addr.s_addr=htonl(INADDR_ANY); //��� �ּҸ� �޾Ƶ��̰ڴ�
	serverAddr.sin_port=htons(port);
	//3�ܰ� : ���ϰ� �ּҸ� ���ε�!!(����������....) bind
	int bindResult = bind(serverSocket,(SOCKADDR *)&serverAddr,sizeof(serverAddr));
	if (bindResult == SOCKET_ERROR) {
		errorHandler("���ε� ����");
	}
	//4�ܰ� : Ŭ���̾�Ʈ�� ������ ���� �غ� listen
	int listenResult=listen(serverSocket,10);
	if (listenResult == SOCKET_ERROR) {
		errorHandler("���� ���� �غ�");
	}
	//5�ܰ� : ���� ��� accept()
	int clientAddrSize=sizeof(clientAddr);
	clientSocket=accept(serverSocket,(SOCKADDR *)&clientAddr,&clientAddrSize);
	if (clientSocket == INVALID_SOCKET) {
		errorHandler("������ ��� ����");
	}
	else {
		printf("������ �߰�\n");
		//6�ܰ� : ��ȭ������
		while ((strLen = recv(clientSocket, msg, MSG_SIZE, 0))!=0) {
			send(clientSocket,msg,strlen(msg),0);
		}
		closesocket(clientSocket);
	}
	//7�ܰ� : �ڿ����� (���ϴݱ�)
	closesocket(serverSocket);
	return 0;
}

void errorHandler(char * message) {
	fputs(message,stderr); //���� ��Ʈ���� ���....
	fputc('\n',stderr);
}

