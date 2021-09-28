package week10;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class GUI_2 
{
	public static void main(String[] args)
	{
		ColorChange c = new ColorChange();
	}
}

class ColorChange extends JFrame
{
	int r=255;
	int g=255;
	int b=255;
	
	Container c = getContentPane();
	JLabel notice = new JLabel("<Enter>를 누르면 색이 바뀝니다");
	Random random = new Random();
	
	ColorChange()
	{
		setTitle("GUI_2");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		c.setLayout(new FlowLayout());
		c.addKeyListener(new MyKeyListener ());
		c.add(notice);
		
		setSize(400,400);
		setVisible(true);
		
		c.requestFocus();
		
	}
	
	class MyKeyListener extends KeyAdapter
	{
		public void keyPressed(KeyEvent e)
		{
			int key = e.getKeyCode();
			if(key==KeyEvent.VK_ENTER)
			{
				r=random.nextInt(255);
				g=random.nextInt(255);
				b=random.nextInt(255);
				notice.setText("r="+r+","+"g="+g+","+"b="+b);
				c.setBackground(new Color(r,g,b));
			}
			else if(key==KeyEvent.VK_Q)
				System.exit(0);
		}
	}
}
