package week6;

import java.util.Scanner;

abstract class Object
{
	int x,y;
	
	public Object() {}
	
	public Object(int x, int y)
	{
		this.x=x;
		this.y=y;
	}
	public boolean overlap(Object o)
	{
		if(this.x==o.x&&this.y==o.y)
			return true; 
		else 
			return false;
	}
	abstract void move();
	abstract char shape();
}

class Packman extends Object
{
	Scanner scanner = new Scanner(System.in);
	
	public Packman(int x, int y)
	{
		 this.x=x;
		 this.y=y;
	}
	public void move()
	{
		String key = scanner.nextLine();
		if(key=="a")
			this.x-=1;
		else if(key=="s")
			this.y+=1;
		else if(key=="w")
			this.y-=1;
		else if(key=="d")
			this.x+=1;
	}
	public char shape()
	{
		return 'P';
	}
}

class Ghost extends Object
{
	public Ghost(int x, int y)
	{
		 this.x=x;
		 this.y=y;
	}
	public void move()
	{
	}
	public void move(Packman P)
	{
		double d = Math.random();
		
		if(d<=0.2)
		{	
		}
		else if(d>0.2&&d<=0.5)
		{
			if(P.x-this.x<0)
				this.x-=1;
			else if(P.x-this.x>0)
				this.x+=1;
		}
		else if(d>0.5&&d<=0.6)
		{
			if(P.x-this.x<0)
				this.x-=2;
			else if(P.x-this.x>0)
				this.x+=2;
		}
		else if(d>0.6&&d<=0.9)
		{
			if(P.y-this.y<0)
				this.y-=1;
			else if(P.y-this.y>0)
				this.y+=1;
		}
		else
		{
			if(P.y-this.y<0)
				this.y-=2;
			else if(P.y-this.y>0)
				this.y+=2;
		}
		
	}
	public char shape()
	{
		 return 'G';
	}
}

class Star extends Object
{
	public Star(int x, int y)
	{
		 this.x=x;
		 this.y=y;
	}
	public void move()
	{
	}
	public char shape()
	{
		 return 'S';
	}
}


public class Game 
{
	public static void main(String[] args) 
	{
		char[][] map = new char[5][5];
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				map[i][j]='.';
		
		Packman P = new Packman(1,4);
		Ghost G = new Ghost(3,3);
		Star S = new Star(1,3);
		System.out.println("Game Start");
		
		while(true) 
		{
			map[S.x][S.y]=S.shape();
			map[P.x][P.y]=P.shape();
			map[G.x][G.y]=G.shape();
			
			for(int i=0;i<5;i++)
			{
				for(int j=0;j<5;j++)
					{
						System.out.print(map[i][j]);
					}
			System.out.println();
			
			}
			
			System.out.println("Please Input direction :");
			P.move();
			G.move(P);
			
			if(P.x==G.x&&P.y==G.y)
			{
				System.out.println("Game Over");
				System.exit(0);
			// If Packman collides with Ghost 
			}
				
			else if(P.x==S.x&&P.y==S.y)
			{
				System.out.println("Success");
				System.exit(0);
			// If Packman collides with Star 
			}
			
			else if((P.x==S.x&&S.x==G.x)&&(P.y==G.y&&G.y==S.y))
			{
				System.out.println("Draw");
				System.exit(0);
				// If Packman collides with Ghost and Star 
			}
		}
	}
}
