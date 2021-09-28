package week9;
import java.util.*;
import java.io.*;

class LibraryFullException extends Exception
{
	public LibraryFullException()
	{
		super();
	}
}

class NoBookException extends Exception
{
	public NoBookException()
	{
		super();
	}
}

class BorrowBookException extends Exception
{
	public BorrowBookException()
	{
		super();
	}
}

class Book
{
	private String bookname;
	private boolean state;
	
	public Book(String _bookname)
	{
		this.bookname=_bookname;
		this.state=true;
	}
	
	public String getbookname()
	{
		return this.bookname;
	}
	
	public boolean isstate()
	{
		return this.state;
	}
	
	public void borrowed()
	{
		this.state=false;
	}
	
	public void returned()
	{
		this.state=true;
	}
}

class Library
{
	int numberofbook=0;
	Book[] bookArray;
	
	public Library(int _numberofbook)
	{
		bookArray = new Book[_numberofbook];
	}
	
	public void addBook(Book newbook) throws LibraryFullException
	{
		int i=0;
		for(i=0;i<bookArray.length;i++)
		{
			if(bookArray[i]==null) 
			{
				bookArray[i]=newbook;
				break;
			}
		}
		if(i==bookArray.length)
		{
			throw new LibraryFullException();
		}
	}
	
	public void findBook(String bookname) throws NoBookException
	{
		int i=0;
		for(i=0;i<bookArray.length;i++)
		{
			if(bookArray[i].getbookname()==bookname&&bookArray[i].isstate()==true)
				System.out.println("Found");
		}
		if(i==bookArray.length)
		{
			throw new NoBookException();
		}
	}
	
	public void borrowBook(String bookname) throws NoBookException, BorrowBookException
	{
		int i=0;
		for(i=0;i<bookArray.length;i++)
		{
			if(bookArray[i].getbookname()==bookname&&bookArray[i].isstate()==true)
			{
				System.out.println("Found Book");
				bookArray[i].borrowed();
				break;
			}
			else if(bookArray[i].getbookname()==bookname&&bookArray[i].isstate()==false)
			{
				throw new BorrowBookException();
			}
		}
		if(i==bookArray.length)
		{
			throw new NoBookException();
		}
	}
	
	public void returnBook(String bookname) throws NoBookException, BorrowBookException
	{
		int i=0;
		for(i=0;i<bookArray.length;i++)
		{
			if(bookArray[i].getbookname()==bookname&&bookArray[i].isstate()==false)
			{
				bookArray[i].returned();
			}
			else if(bookArray[i].getbookname()==bookname&&bookArray[i].isstate()==true)
			{
				throw new BorrowBookException();
			}
		}
		if(i==bookArray.length)
		{
			throw new NoBookException();
		}
	}
	
}

public class LibrarySystem 
{
	public static void main(String[] args) 
	{
		Library lib = new Library(1);
		
		try
		{
			lib.addBook(new Book("K&R"));
		}
		catch (LibraryFullException e)
		{
			System.out.println("Library is Full");
		}
		
		try
		{
			lib.addBook(new Book("2046"));
		}
		catch (LibraryFullException e)
		{
			System.out.println("Library is Full");
		}
		
		try
		{
			lib.findBook("Window is garbage");
		}
		catch (NoBookException e)
		{
			System.out.println("No book with that name");
		}
		
		try
		{
			lib.borrowBook("Window is garbage");
		}
		catch (NoBookException e)
		{
			System.out.println("No book with that name");
		}
		catch (BorrowBookException e)
		{
			System.out.println("Book is already borrowed");
		}
		
		try
		{
			lib.borrowBook("K&R");
		}
		catch (NoBookException e)
		{
			System.out.println("No book with that name");
		}
		catch (BorrowBookException e)
		{
			System.out.println("Book is already borrowed");
		}
		
		try
		{
			lib.returnBook("2045");
		}
		catch (NoBookException e)
		{
			System.out.println("No book with that name");
		}
		catch (BorrowBookException e)
		{
			System.out.println("Book is not borrowed");
		}
	}
}
