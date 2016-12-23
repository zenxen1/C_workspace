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
			System.out.println("클라이언트 기다리는중");
			
			while(true){
				Socket client=server.accept();
				System.out.println("클라이언트 접속!!!");
				
				ServerThread st = new ServerThread(client,this);
				st.start();
				list.add(st);
				System.out.println("현재 "+ list.size()+"접속!!");
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
