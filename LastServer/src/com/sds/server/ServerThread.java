package com.sds.server;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;

public class ServerThread extends Thread{
	
	Socket client;
	BufferedReader buffr;
	BufferedWriter buffw;
	ServerMain sm;
	
	public ServerThread(Socket client, ServerMain sm) {
		this.client = client;
		this.sm = sm;
		
		try {
			buffr = new BufferedReader(new InputStreamReader(client.getInputStream(),"utf-8"));
			buffw = new BufferedWriter(new OutputStreamWriter(client.getOutputStream(),"utf-8"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void listen(){
		String msg = null;
		
		try {
			msg = buffr.readLine();
			System.out.println("클라이언트말"+msg);
			send(msg);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void send(String msg){
		try {
			for(int i=0;i<sm.list.size();i++){
				ServerThread st = sm.list.get(i);
				st.buffw.write(msg+"\n");
				st.buffw.flush();
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void run(){
		while(true){
			listen();
		}
	}

}
