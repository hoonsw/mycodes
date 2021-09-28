package week12;

import java.io.*;
import java.net.*;
import java.text.SimpleDateFormat;
import java.util.*;

public class ServerThread extends Thread
{
	private String name = null;
	private static SimpleDateFormat sdfDate = new SimpleDateFormat ("yyy-MM-dd HH:mm:SSS");
	private static String getLog (String msg)
	{
		return "["+sdfDate.format(new Date())+"] Server thread : "+msg;
	}
	
	public ServerThread()
	{
		this.name="ServerThread";
	}
	
	public void run()
	{
		ServerSocket ss = null;
		try
		{
			ss = new ServerSocket(5000);
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
		Scanner sn = new Scanner(System.in);
		
		Socket soc = null;
		OutputStream out = null;
		try
		{
			soc = ss.accept();
			System.out.println(ServerThread.getLog("new connection arrived"));
			out = soc.getOutputStream();
			DataOutputStream dos = new DataOutputStream(out);
			while(true)
			{
				dos.writeUTF(sn.nextLine());
			}
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
	}

}
