package week5;

class SuperClass
{
	int age;
	
	SuperClass()
	{
		this.age=1;
	}
	
	SuperClass(int age)
	{
		this.age=age;
	}
	
	public void getAge()
	{
		System.out.println("the value is " + age);
	}
}

public class SubClass extends SuperClass
{
	SubClass(int age)
	{
		super(age);
	}
	
	public static void main(String[] args)
	{
		SubClass s = new SubClass(24);
		s.getAge();
	}
}
