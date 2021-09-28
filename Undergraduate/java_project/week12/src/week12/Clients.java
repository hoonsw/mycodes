package week12;

import java.io.*;
import java.net.*;
import java.text.SimpleDateFormat;
import java.util.*;

class Test extends Thread
{
	public void run()
	{
		try
		{
			Socket soc = new Socket("localhost",5000);
			DataInputStream dis = new DataInputStream(soc.getInputStream());
			
			System.out.println(dis.readUTF());
			
			dis.close();
			soc.close();
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
	}
}

public class Clients 
{
	public static void main(String[] args)
	{
		for(int i=0;i<100;i++)
		{
			new Test().start();
		}
	}
}
