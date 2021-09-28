
import java.io.*;
import java.util.*;

public class FileVector {
	public static void main(String[] args)
	{
		Vector<String> word = new Vector<String>(30);
		try
		{
			BufferedReader br = new BufferedReader (new FileReader ("C:\\Users\\Desktop\\input.txt"));
			for(int i=0;i<4;i++)
				word.add(i, br.readLine());
			
			FileOutputStream fos = new FileOutputStream("C:\\Users\\Desktop\\output.txt");
			OutputStreamWriter osw = new OutputStreamWriter(fos);
			BufferedWriter bw = new BufferedWriter(osw);
			
			for(int i=0;i<4;i++)
				bw.write(i+1+" : "+word.get(3-i)+"\n");
			
			br.close();
			bw.flush();
			bw.close();
		}
		catch (FileNotFoundException e) {e.printStackTrace();}
		catch (IOException e) {e.printStackTrace();}
	}

}
