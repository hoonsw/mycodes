package week10;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import week10.ColorChange.MyKeyListener;

public class GUI_3 
{
	public static void main(String[] args)
	{
		new HelloMouse();
	}
}

class HelloMouse extends JFrame
{
	Container ContentPane = getContentPane();
	JLabel hello = new JLabel("HELLO");
	
	public HelloMouse()
	{
		setTitle("GUI_3");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		ContentPane.setLayout(new FlowLayout());
		ContentPane.addMouseListener(new MouseListener ());
		ContentPane.add(hello);
		
		setSize(400,400);
		setVisible(true);
		
		ContentPane.requestFocus();
	}
	
	class MouseListener extends MouseAdapter
	{
		public void mousePressed(MouseEvent e)
		{
			hello.setLocation(e.getX(), e.getY());
		}
	}
}
