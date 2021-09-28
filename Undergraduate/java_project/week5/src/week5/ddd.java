package week5;

class dd 
{
	int num=20;
	public void display()
	{
		System.out.println("display method of class dd");
	}
}

public class ddd extends dd
{
	int num=10;
	public void display()
	{
		System.out.println("display method of clas ddd");
	}
	public void myMethod()
	{
		this.display();
		super.display();
		
		System.out.println("num of dd is "+super.num);
		System.out.println("num of ddd is "+this.num);
	}
	
	public static void main(String[] args)
	{ 
		ddd obj = new ddd();
		obj.myMethod();
	}
}
