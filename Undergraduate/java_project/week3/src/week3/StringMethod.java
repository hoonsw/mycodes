

public class StringMethod 
{
	// Returns the string created by adding 's2' after position 'index' of 's1'.
	static String addString(String s1, int index, String s2) 
	{
		String s3 = s1.substring(0,index+1).concat(s2).concat(s1.substring(index+1,s1.length()));
		return s3;
	}

	// Returns reversed string of 's'
	static String reverse(String s) 
	{
		char[] stringtochar = s.toCharArray();
		
		for(int i=0;i<s.length()/2;i++)
		{
			char temp;
			temp=stringtochar[i]; 
			stringtochar[i]=stringtochar[s.length()-i-1];
			stringtochar[s.length()-i-1] = temp;
		}
		
		return String.valueOf(stringtochar);
		
	}

	// Returns a string with all 's2's removed from 's1'
	static String removeString (String s1, String s2) 
	{
		String remover[] = s1.split(s2);
		String s3 = s1.split(s2)[0];
		
		for(int i=1;i<remover.length;i++)
			s3=s3.concat(remover[i]);

		return s3; 
	}

	public static void main(String[] args) 
	{
		System.out.println(addString("0123456",3,"-"));
		System.out.println(reverse("abc"));
		System.out.println(removeString("01001000","00"));
	}
}