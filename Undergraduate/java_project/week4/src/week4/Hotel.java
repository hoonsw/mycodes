
import java.util.Random; 
import java.util.Scanner;


public class Hotel 
{
	static Scanner scan = new Scanner(System.in);
	
	public static void main(String[] args)
	{
		int input_number;
		int roomnumber;
		int peoplenumber;
		
		Hotel hotelone = new Hotel();
		Room[] r = new Room[10];
		for(int i=0;i<r.length;i++)
			r[i] = new Room();
		
		System.out.println("Each Room's Capacity");
		for(int i=0;i<r.length;i++)
			System.out.print(r[i].getCapacity()+" ");
		
		System.out.print("\n");
		
		while(true)
		{
			System.out.println("Enter number (1: check in), (2 : check out), (3: Finish)");
			input_number=scan.nextInt();
			
			if(input_number==1)
			{
				System.out.println("Enter room number");
				roomnumber=scan.nextInt();
				System.out.println("How many people?");
				peoplenumber=scan.nextInt();
				hotelone.checkin(roomnumber,peoplenumber,r);
				continue;
			}
			
			if(input_number==2)
			{
				System.out.println("Enter room number");
				roomnumber=scan.nextInt();
				hotelone.checkout(roomnumber,r);
				continue;
			}
			
			if(input_number==3)
				break;
			
			else
			{
				System.out.println("ÀçÀÔ·Â");
				continue;
			}
		}
	}
	
	void checkin(int n, int j, Room[] r)
	{
		
		while(true)
		{
			if(r[n-1].isStates()!=false)
			{
				System.out.println("Already check in!");
				break;
			}
			r[n-1].setStates(true);

			if(r[n-1].getCapacity()<j)
			{
				System.out.println("Too many people!");
				break;
			}
			r[n-1].setCapacity(j);
			
			System.out.println("Check in Finish");
			break;
		}	
			
	}
	
	void checkout(int n, Room[] r)
	{
		
		while(true)
		{
			if(r[n-1].isStates()!=true)
			{
				System.out.println("Already check out!");
				break;
			}
			r[n-1].setStates(false);
			
			System.out.println("Check out Finish");
			break;
		}
	}
}

class Room
{
	private boolean states;
	private int capacity;
	Random random = new Random();
	
	public Room()
	{
		states=false;
		capacity=(random.nextInt(4)+1);
	}

	public boolean isStates() {
		return states;
	}

	public void setStates(boolean states) {
		this.states = states;
	}

	public int getCapacity() {
		return capacity;
	}

	public void setCapacity(int capacity) {
		this.capacity = capacity;
	}
	
}