package week12;

import java.io.*;
import java.net.*;
import java.util.*;

public class TCPClient 
{
	public static void main(String[] args)
	{
		String serverIP = "localhost";
		Socket soc;
		try
		{
			soc = new Socket(serverIP, 5000);
			InputStream in = soc.getInputStream();
			DataInputStream dis = new DataInputStream(in);
			while(true)
			{
				System.out.println(dis.readUTF());
			}
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
	}
}
