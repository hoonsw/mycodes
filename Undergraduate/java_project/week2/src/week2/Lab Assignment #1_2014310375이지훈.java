import java.util.Scanner;

public class practice
{
	public static void main(String[] args)
	{
		int[] binary = new int[100];
		int[] octal = new int[100];
		char[] hex = new char[100];
		int count=0;
		
		Scanner scn = new Scanner(System.in);
		System.out.print("");
		int num = scn.nextInt();
		scn.nextLine(); //buffer clear
		int temp = num;
		
		while(num>1)
		{
			binary[count]=num%2;
			count++;
			num/=2;
		}
		
		binary[count]=1;
		
		System.out.print("b ");
		for(int i=count;i>=0;i--)
			System.out.print(binary[i]);
		
		System.out.println();
		num=temp; 
		count=0;
		
		while(num>7)
		{
			octal[count]=num%8;
			count++;
			num/=8;
		}
		
		octal[count]=num;
		
		System.out.print("o ");
		for(int i=count;i>=0;i--)
			System.out.print(octal[i]);
		
		System.out.println();
		num=temp; 
		count=0;
		
		while(num>15)
		{
			temp = num%16;
			switch(temp)
			{
			case 10:
				hex[count]='a';
				break;
			case 11:
				hex[count]='b';
				break;
			case 12:
				hex[count]='c';
				break;
			case 13:
				hex[count]='d';
				break;
			case 14:
				hex[count]='e';
				break;
			case 15:
				hex[count]='f';
				break;
			default:
				hex[count]=(char)(temp+'0');
			}
			count++;
			num/=16;
		}
		
		if(num>9)
			hex[count]=(char)(num+87);
		else 
			hex[count]=(char)(num+'0');
		
		System.out.print("h ");
		for(int i=count;i>=0;i--)
			System.out.print(hex[i]);
	}
}