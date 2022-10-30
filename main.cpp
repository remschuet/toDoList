#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <list>

using namespace std;


void displayTitle(int y, string line, bool endLine)
{
	if (endLine)
		cout << "\n\n";
	cout << setw(y) << "" << line;
}


void deleteElementFile(string input)
{
	string element;
	int x = 0; //x - "counter" to check if user entered wrong name
	ifstream aFaireFile("aFaire.txt");
	ofstream saveFile("Save.txt"); //temp file for input of every student except the one user wants to delete

	while (aFaireFile >> element)
	{
		if (input != element)
		{
			saveFile << element << endl;
		}
		if (input == element)
		{
			x = 1;
		}
	}
	aFaireFile.clear(); //clear eof and fail bits
	aFaireFile.seekg(0, ios::beg);
	aFaireFile.close();
	saveFile.close();
	remove("aFaire.txt");
	rename("Save.txt", "aFaire.txt");
	ofstream outfile("Save.txt");
	if (x == 0) 
	{ //x was set to 0 at start, so if it didn't change, it means user entered the wrong name
		cout << "There is no student with name you entered." << endl;
	}
	else 
	{ //x is not 0, it means user entered the correct name, print message that students data has been deleted
		cout << "Student data has been deleted." << endl;
	}
}


void openFile(int x, string fileName, bool endLine)
{
	// C:\Users\remsc\OneDrive\Desktop\Project1\Project1
	fstream is(fileName);
	string line;

	while (getline(is, line)) 
	{
		displayTitle(x, line, endLine);
	}
}


void addItemInList(string input)
{
	fstream is("AFaire.txt", ios::app);
	string line;
	is << "\n" << input;
	is.close();

}


int TakeNomberLine()
{
	int count = 0;
	string line;

	ifstream is("AFaire.txt");
	while (is.peek() != EOF)
	{
		getline(is, line);
		count++;
	}
	return count;
	_getch();
}


void displayInformation()
{
	int x = 120 / (1 + 6);
	int y = 30;
	bool endLine = false;

	openFile(x, "numbers.txt", endLine);

	endLine = true;
	openFile(y, "AFaire.txt", endLine);
}


int main()
{
	bool toDoList = true;
	string input;

	while (toDoList)
	{
		system("cls");
		displayInformation();
		int count = TakeNomberLine();
		count = 15 - count;
		for (int i = 1; i <= count; i++)
		{
			cout << "\n";
		}
		cout << "Command : \"Add\" \"Kill\" \"Number\" \"Exit\" \n > ";

		getline(cin, input);
		if (input == "Add")			// add in file
		{
			cout << "> ";
			getline(cin, input);
			addItemInList(input);
		}
		else if (input == "Kill")	// Kill item in file
		{
			cout << "> ";
			getline(cin, input);
			deleteElementFile(input);
		}
		else if (input == "Number")	// Take number item in the file
		{
			cout << "> ";
			int count = TakeNomberLine();
			cout << "Il y a : " << count << " item dans le fichier.";

		}
		else if (input == "Exit")	// Exit todolist
		{
			toDoList = false;
		}

		// reset input
		input = ""; 
	}
	return 0;
}