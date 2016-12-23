package com.sds.server;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Vector;

public class ServerMain implements Runnable {
	Vector <ServerThread> list;
	Thread connectThread;
	ServerSocket server;
	int port = 7777;
	
	
	public ServerMain() {
		list = new Vector<ServerThread>();
		connectThread = new Thread(this);
		connectThread.start();
	}
	
	public void run() {
		try {
			server = new ServerSocket(port);
			System.out.println("Ŭ���̾�Ʈ ��ٸ�����");
			
			while(true){
				Socket client=server.accept();
				System.out.println("Ŭ���̾�Ʈ ����!!!");
				
				ServerThread st = new ServerThread(client,this);
				st.start();
				list.add(st);
				System.out.println("���� "+ list.size()+"����!!");
			}
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	
	public static void main(String[] args){
		new ServerMain();
	}

}
