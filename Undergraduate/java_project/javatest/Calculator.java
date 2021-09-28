
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.EventQueue;

import javax.swing.DefaultListModel;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import javax.swing.JTextField;

import java.awt.GridLayout;

import javax.swing.JList;
import javax.swing.event.ListSelectionListener;

import java.awt.Font;

import javax.swing.SwingConstants;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.KeyListener;
import java.awt.event.KeyEvent;

import java.util.*;


// You can add the listener which you need 
public class Calculator extends JFrame implements ActionListener, KeyListener {

	/**
	 * You can define your own variable 
	 */

	JPanel contentPane;
	JPanel pnDisplay;
	JPanel pnInput;
	JPanel pnHistory;
	JTextField textField;
	JButton btn7;
	JButton btn8;
	JButton btn9;
	JButton btnAdd;
	JButton btnClearAll;
	JButton btn4;
	JButton btn5;
	JButton btn6;
	JButton btnMinus;
	JButton btnClearText;
	JButton btn1;
	JButton btn2;
	JButton btn3;
	JButton btnMultiply;
	JButton btnOpenBracket;
	JButton btn0;
	JButton btnDot;
	JButton btnEqual;
	JButton btnDivide;
	JButton btnCloseBracket;
	JList list;
	DefaultListModel<String> listData; 

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Calculator frame = new Calculator();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public Calculator() {

		setTitle("Simple Calculator");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);
		
		pnDisplay = new JPanel();
		contentPane.add(pnDisplay, BorderLayout.NORTH);
		pnDisplay.setLayout(new GridLayout(0, 1, 0, 0));

		textField = new JTextField();
		textField.setHorizontalAlignment(SwingConstants.RIGHT);
		textField.setFont(new Font("Courier New", Font.PLAIN, 28));
		pnDisplay.add(textField);
		textField.setColumns(10);

		pnInput = new JPanel();
		contentPane.add(pnInput, BorderLayout.CENTER);
		pnInput.setLayout(new GridLayout(4, 5, 5, 5));

		btn7 = new JButton("7");
		btn7.setFont(new Font("±¼¸²", Font.BOLD, 14));
		btn7.addActionListener(this); // You must addActionListner to each button 
		pnInput.add(btn7);

		btn8 = new JButton("8");
		btn8.setFont(new Font("±¼¸²", Font.BOLD, 14));
		btn8.addActionListener(this);
		pnInput.add(btn8);

		btn9 = new JButton("9");
		btn9.setFont(new Font("±¼¸²", Font.BOLD, 14));
		btn9.addActionListener(this);
		pnInput.add(btn9);

		btnAdd = new JButton("+");
		btnAdd.setFont(new Font("±¼¸²", Font.BOLD, 14));
		btnAdd.addActionListener(this);
		pnInput.add(btnAdd);

		btnClearAll = new JButton("C");
		btnClearAll.setFont(new Font("±¼¸²", Font.BOLD, 14));
		btnClearAll.addActionListener(this);
		pnInput.add(btnClearAll);

		btn4 = new JButton("4");
		btn4.setFont(new Font("±¼¸²", Font.BOLD, 14));
		btn4.addActionListener(this);
		pnInput.add(btn4);

		btn5 = new JButton("5");
		btn5.setFont(new Font("±¼¸²", Font.BOLD, 14));
		btn5.addActionListener(this);
		pnInput.add(btn5);

		btn6 = new JButton("6");
		btn6.setFont(new Font("±¼¸²", Font.BOLD, 14));
		btn6.addActionListener(this);
		pnInput.add(btn6);

		btnMinus = new JButton("-");
		btnMinus.setFont(new Font("±¼¸²", Font.BOLD, 14));
		btnMinus.addActionListener(this);
		pnInput.add(btnMinus);

		btnClearText = new JButton("CE");
		btnClearText.setFont(new Font("±¼¸²", Font.BOLD, 14));
		btnClearText.addActionListener(this);
		pnInput.add(btnClearText);

		btn1 = new JButton("1");
		btn1.setFont(new Font("±¼¸²", Font.BOLD, 14));
		btn1.addActionListener(this);
		pnInput.add(btn1);

		btn2 = new JButton("2");
		btn2.setFont(new Font("±¼¸²", Font.BOLD, 14));
		btn2.addActionListener(this);
		pnInput.add(btn2);

		btn3 = new JButton("3");
		btn3.setFont(new Font("±¼¸²", Font.BOLD, 14));
		btn3.addActionListener(this);
		pnInput.add(btn3);

		btnMultiply = new JButton("x");
		btnMultiply.setFont(new Font("±¼¸²", Font.BOLD, 14));
		btnMultiply.addActionListener(this);
		pnInput.add(btnMultiply);

		btnOpenBracket = new JButton("(");
		btnOpenBracket.setFont(new Font("±¼¸²", Font.BOLD, 14));
		btnOpenBracket.addActionListener(this);
		pnInput.add(btnOpenBracket);

		btn0 = new JButton("0");
		btn0.setFont(new Font("±¼¸²", Font.BOLD, 14));
		btn0.addActionListener(this);
		pnInput.add(btn0);

		btnDot = new JButton(".");
		btnDot.setFont(new Font("±¼¸²", Font.BOLD, 14));
		btnDot.addActionListener(this);
		pnInput.add(btnDot);

		btnEqual = new JButton("=");
		btnEqual.setFont(new Font("±¼¸²", Font.BOLD, 14));
		btnEqual.addActionListener(this);
		pnInput.add(btnEqual);

		btnDivide = new JButton("/");
		btnDivide.setFont(new Font("±¼¸²", Font.BOLD, 14));
		btnDivide.addActionListener(this);
		pnInput.add(btnDivide);

		btnCloseBracket = new JButton(")");
		btnCloseBracket.setFont(new Font("±¼¸²", Font.BOLD, 14));
		btnCloseBracket.addActionListener(this);
		pnInput.add(btnCloseBracket);

		pnHistory = new JPanel();
		contentPane.add(pnHistory, BorderLayout.EAST);
		pnHistory.setPreferredSize(new Dimension(120, 200));

		listData = new DefaultListModel();
		pnHistory.setLayout(new BorderLayout(5, 5));
		list = new JList(listData);
		pnHistory.add(list);

		/*
		 * End of GUI code
		 */
	}
	
	public void keyPressed(KeyEvent e) 
	{
		char inputKey = e.getKeyChar();
		int inputCode = e.getKeyCode();
		
		StringBuilder output = new StringBuilder();
		
		output.append(inputKey);
		
		textField.setText(output.toString());

	}
	public void keyReleased(KeyEvent e) {}
	public void keyTyped(KeyEvent e) {}
		
	public void actionPerformed(ActionEvent e) // Write your own actionPerformed 
	{
		String s = e.getActionCommand(); // Get the string from the button 
		int n=textField.getText().length();
		String gesan = textField.getText().toString();
		
		switch(s)
		{
		case "1":
			textField.setText(textField.getText() + "1");
			textField.setBackground(Color.WHITE);
			break;
		case "2":
			textField.setText(textField.getText() + "2");
			textField.setBackground(Color.WHITE);
			break;
		case "3":
			textField.setText(textField.getText() + "3");
			textField.setBackground(Color.WHITE);
			break;
		case "4":
			textField.setText(textField.getText() + "4");
			textField.setBackground(Color.WHITE);
			break;
		case "5":
			textField.setText(textField.getText() + "5");
			textField.setBackground(Color.WHITE);
			break;
		case "6":
			textField.setText(textField.getText() + "6");
			textField.setBackground(Color.WHITE);
			break;
		case "7":
			textField.setText(textField.getText() + "7");
			textField.setBackground(Color.WHITE);
			break;
		case "8":
			textField.setText(textField.getText() + "8");
			textField.setBackground(Color.WHITE);
			break;
		case "9":
			textField.setText(textField.getText() + "9");
			textField.setBackground(Color.WHITE);
			break;
		case "0":
			textField.setText(textField.getText() + "0");
			textField.setBackground(Color.WHITE);
			break;
		case "+":
			textField.setText(textField.getText() + "+");
			textField.setBackground(Color.GRAY);
			break;
		case "-":
			textField.setText(textField.getText() + "-");
			textField.setBackground(Color.GRAY);
			break;
		case "x":
			textField.setText(textField.getText() + "x");
			textField.setBackground(Color.GRAY);
			break;
		case "/":
			textField.setText(textField.getText() + "/");
			textField.setBackground(Color.GRAY);
			break;
		case "(":
			textField.setText(textField.getText() + "(");
			textField.setBackground(Color.GRAY);
			break;
		case ")":
			textField.setText(textField.getText() + ")");
			textField.setBackground(Color.GRAY);
			break;
		case ".":
			textField.setText(textField.getText() + ".");
			textField.setBackground(Color.WHITE);
			break;
		case "CE":
			textField.setText("");
			textField.setBackground(Color.WHITE);
			// and do something more
			break;
		case "C":
			textField.setText("");
			textField.setBackground(Color.WHITE);
			break;
		case "=":
			textField.setText(textField.getText() + "=");
			textField.setBackground(Color.GRAY);
			break;
		}
	}
}

