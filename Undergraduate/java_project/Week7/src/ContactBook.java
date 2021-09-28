import java.util.*;

public class ContactBook 
{
	public static void main(String[] args)
	{
		HashMap<String,String> phonebook = new HashMap();
		Scanner scan = new Scanner(System.in);
		
		while(true)
		{
			System.out.print("Please enter a name (Exit:0) : ");
			String name = scan.nextLine();
			if(name.equals("0")) 
			{
				System.out.println("There is "+phonebook.size()+" members in Contact Book Currently, Bye!");
				System.exit(0); 
			}
			else
			{
				if(phonebook.containsKey(name))
				{
					System.out.println("Find Member, "+name+"'s phone number : " + phonebook.get(name));
					continue;
				}
				else
				{
					System.out.print("New Member, Please enter a number (Cancel:0) : ");
					String phoneNumber = scan.nextLine();
					if(phoneNumber.equals("0"))
					{
						System.out.println("Cancel Success");
						continue;
					}
					else
					{
						phonebook.put(name,phoneNumber);
						System.out.println("Save Success");
						continue;
					}
				}
			}
		}
	}
}
