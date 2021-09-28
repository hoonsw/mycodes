package week12;

import java.io.*;
import java.net.*;
import java.util.*;

public class TCPServer 
{
	public static void main(String[] args)
	{
		ServerSocket ss;
		Scanner scn = new Scanner(System.in);
		System.out.println("server start");
		try
		{
			ss = new ServerSocket(5000);
			Socket soc = ss.accept();
			java.io.OutputStream out=soc.getOutputStream();
			DataOutputStream dos = new DataOutputStream(out);
			while(true)
			{
				dos.writeUTF(scn.nextLine());
			}
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
	}
}
