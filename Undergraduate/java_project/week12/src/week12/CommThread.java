package week12;

import java.io.*;
import java.net.*;
import java.text.SimpleDateFormat;
import java.util.*;

public class CommThread extends Thread
{
	private Socket soc;
	private int id;
	public CommThread (Socket soc,int id)
	{
		this.soc=soc;
		this.id=id;
	}
	
	public void run()
	{
		try
		{
			OutputStream os = soc.getOutputStream();
			DataOutputStream dos = new DataOutputStream(os);
			
			dos.writeUTF("messagefrom server ("+id+")");
			System.out.println(Server.getLog("message is sent ("+id+")"));
			
			dos.close();
			this.soc.close();
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
	}
}

