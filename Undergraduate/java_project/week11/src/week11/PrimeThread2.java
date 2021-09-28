package week11;

import java.util.*;
import java.io.*;

class inputException extends Exception
{
	public inputException()
	{
		super();
	}
}

class threadException extends Exception
{
	public threadException()
	{
		super();
	}
}

class Prime implements Runnable
{
	int s=0;
	int e=0;
	
	Prime(int start,int end)
	{
		this.s=start;
		this.e=end;
	}
	
	public void run() 
	{
			int cnt=0;
			boolean[] isPrime = new boolean[e+1]; // false = Prime, true = not Prime;
			ArrayList<Integer> list = new ArrayList<>();
			
			for(int i=2;i<=e;i++)
			{
				if(!isPrime[i])
				{
					list.add(i);
					for(int j=1;i*j<=e;j++)
						isPrime[i*j]=true;
				}
			}
			
			for(int i=0;i<s+1;i++)
			{
				if(list.get(i)<=s+1)
					cnt++;
				else if(list.get(i)>s+1)
					break;
			}
				
			System.out.println(list.size()-cnt);
	}
}

public class PrimeThread2 
{	
	int numofthreads=0;
	int start=0;
	int end=30000;
	
	public void primemain() throws inputException, threadException
	{	
		Scanner scan = new Scanner(System.in);
		System.out.print("How many threads do you want? ");
		this.numofthreads = scan.nextInt();
		System.out.print("Start Number : ");
		this.start = scan.nextInt();
		System.out.print("End Number : ");
		this.end = scan.nextInt();
		
		if(this.end-this.start<20000)
		{
			throw new inputException();
		}
		
		if(this.numofthreads<1||this.numofthreads>4)
		{
			throw new threadException();
		}
	}
	
	public void realrealmain()
	{
		Prime test = new Prime(start,end);
		while(true)
		{
			try
			{
				primemain();
				break;
			}
			catch (inputException e1)
			{
				System.out.println("difference between start and end must be more than 20000");
			}
			catch(threadException e2)
			{
				System.out.println("numbers of threads must be 1~4");
			}
		}
	}
	
	public static void main(String[] args)
	{
		PrimeThread2 main1 = new PrimeThread2();
		main1.realrealmain();
		int ss=main1.start;
		int ee=main1.end;
		int nn=main1.numofthreads;
		
		if(nn==1)
		{
			Runnable d = new Prime(ss,ss + (ee-ss)/nn);
			Thread thread = new Thread(d);
			thread.start();
		}
		else if(nn==2)
		{
			Runnable d = new Prime(ss,ss + (ee-ss)/nn);
	        Runnable d1 = new Prime(ss + (ee-ss)/nn,ss + 2*(ee-ss)/nn);
	        Thread thread = new Thread(d);
	        Thread thread1 = new Thread(d1);
		}
		else if(nn==3)
		{
			Runnable d = new Prime(ss,ss + (ee-ss)/nn);
	        Runnable d1 = new Prime(ss + (ee-ss)/nn,ss + 2*(ee-ss)/nn);
	        Runnable d2 = new Prime(ss + 2*(ee-ss)/nn,ss + 3*(ee-ss)/nn);
	        
	        Thread thread = new Thread(d);
	        Thread thread1 = new Thread(d1);
	        Thread thread2 = new Thread(d2);
	        
	        thread.start();
	        thread1.start();
	        thread2.start();
		}
		else if(nn==4)
		{
			Runnable d = new Prime(ss,ss + (ee-ss)/nn);
	        Runnable d1 = new Prime(ss + (ee-ss)/nn,ss + 2*(ee-ss)/nn);
	        Runnable d2 = new Prime(ss + 2*(ee-ss)/nn,ss + 3*(ee-ss)/nn);
	        Runnable d3 = new Prime(ss + 3*(ee-ss)/nn,ss + 4*(ee-ss)/nn);

	        Thread thread = new Thread(d);
	        Thread thread1 = new Thread(d1);
	        Thread thread2 = new Thread(d2);
	        Thread thread3 = new Thread(d3);

	        thread.start();
	        thread1.start();
	        thread2.start();
	        thread3.start();
		}
	}
}
