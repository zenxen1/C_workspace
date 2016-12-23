#include <stdio.h>
#include <WinSock2.h>
#include <string.h>
//#include <sys/socket.h>

/*
OS�� ���� ��Ʈ��ũ �ҽ��� �ణ Ʋ����

���н��迭 : ��ǻ���� ���� �� ��ü �츮�� �˰� �ִ� �ý��� ���α׷��� ��� �� ��Ʈ��ũ ����� 
			��� ��� ���н����� ����Ѵ�...
			�ֶ󸮽�, mac os, ������

����,���� + ������ + �۰� + ���ͳ� = ������
90��� �ɶ��� ���Ű ���� ������ �����..
������-������, CEntos, �����..

��Ŭ�� ���� ��Ʈ��ũ ���α׷��� ��� ��� 
BSD�� ���ǥ��....

-------------------------------------------------------------------------------------
������迭
- BSD�� ������..
- but ���� �Ȱ��� �ʰ� ���н� �迭�� ���̰� �ִ�. 
windsock.h ���̺귯���� ����ؾ��Ѵ�..
DLL
*/
void errorHandler(char *);

int main() {
	// ���� ���̺귯 �ʱ�ȭ ����ü
	WSADATA wsaData;
	SOCKET clientSocket; //����
	SOCKADDR_IN serverAddr;

	char msg[1024]; //��ȭ�� �޽��� ���� �迭
	int strLen; //�޼��� �ְ� ������ ���ڿ� ���� ���� ����...
	const int BUF_SIZE = 1024;

	//�� ������ 2.2 ��������!!
	int startResult = WSAStartup(MAKEWORD(2,2),&wsaData);
	if (startResult != 0) {
		errorHandler("���̺귯�� �ʱ�ȭ�� �����Ͽ����ϴ�.");
	}

	//2�ܰ� ������ �غ��Ѵ�
	//�ڹٿ����� ���� ������ �� ���������� c���� �׷��� �ʴ�
	clientSocket=socket(PF_INET, SOCK_STREAM, 0);
	if (clientSocket == INVALID_SOCKET) {
		errorHandler("���� ���� ����!!");
	}

	//3�ܰ� : �ּ� �ʱ�ȭ (ip);
	memset(&serverAddr,0,sizeof(serverAddr));
	serverAddr.sin_family=PF_INET;
	serverAddr.sin_addr.s_addr = inet_addr("70.12.112.94");
	serverAddr.sin_port = htons(8888);

	//4�ܰ� : ����
	int connectResult = connect(clientSocket,(SOCKADDR *)&serverAddr,sizeof(serverAddr));
	if (connectResult == SOCKET_ERROR) {
		errorHandler("���� ����!!");
	}
	else {
		puts("���ӿ� �����Ͽ����ϴ�");
	}

	//5�ܰ� : ��ȭ �ְ� �ޱ�!!
	while (1) {
		//Ű����κ��� �Է� ����!!
		fgets(msg,BUF_SIZE,stdin);

		//send, recv�� winsocket���� ����
		//������ ������
		send(clientSocket, msg, strlen(msg), 0);

		//�ޱ�!!
		strLen = recv(clientSocket, msg, BUF_SIZE - 1, 0);
		msg[strLen] = 0;
		puts(msg); //ȭ���� ���
	}
	return 0;
}

void errorHandler(char * message) {
	//f�� ������ ����� ǥ������� + ���� ������ ���� �����ϴ�
	fputs(message,stderr);
	fputc("\n",stderr);
	exit(1);
}