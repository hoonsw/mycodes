package week10;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class GUI_1 
{
	public static void main(String[] args)
	{
		HelloFrame frame = new HelloFrame();
	}
}

class HelloFrame extends JFrame 
{
	JPanel panel = new JPanel();
	JLabel hello = new JLabel("HELLO");
	
	HelloFrame()
	{
		setTitle("GUI_1");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		setContentPane(panel);
		panel.setLayout(null);
		panel.addKeyListener(new MyKeyListener());
		
		hello.setLocation(50,50);
		hello.setSize(50,50);
		panel.add(hello);
		
		setSize(400,400);
		setVisible(true);
		
		panel.requestFocus();
	}
	
	class MyKeyListener implements KeyListener
	{
		
		public void keyPressed(KeyEvent e)
		{
			int direction = e.getKeyCode();
			switch(direction)
			{	
			case KeyEvent.VK_UP: 
				hello.setLocation(hello.getX(),hello.getY()-10); break;
			case KeyEvent.VK_DOWN: 
				hello.setLocation(hello.getX(),hello.getY()+10);  break;
			case KeyEvent.VK_LEFT: 
				hello.setLocation(hello.getX()-10,hello.getY());  break;	
			case KeyEvent.VK_RIGHT: 
				hello.setLocation(hello.getX()+10,hello.getY());  break;
			}
		}
		public void keyTyped(KeyEvent e) {}
		public void keyReleased(KeyEvent e) {}
	}
}


