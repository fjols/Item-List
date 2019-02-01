#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

void WriteFile(vector<string> vectorToWrite) //!< File writing function.
{
	ofstream file("List.txt", ofstream::app); //Open a file called List.
	for (const auto &item : vectorToWrite) file << item << "\n"; //!< Using this line of code we are able to write all the items to the list.
}

void ReadFile(string fileName)
{
	string sLine;
	ifstream file(fileName);
	if (file.is_open())
	{
		while (getline(file, sLine))
		{
			cout << sLine << endl;
		}
		file.close();
	}
	else {
		cout << "ERROR CANNOT READ FILE" << endl;
	}
}

void ClearFile(string fileName)
{
	std::ofstream file(fileName, ofstream::out | ofstream::trunc);
	file.close();
}

int main()
{
	bool bRunLoop = true;
	char cChoice;
	string item;
	std::vector<std::string>ItemList; //!< A vector of strings to store items. A vector is better than array as it is dynamic.

	while (bRunLoop) //!< This loop will run until the user tells it to stop.
	{
		cout << "1. Enter an Item" << endl;
		cout << "2. Finish and write to list." << endl;
		cout << "3. Read file and print to console." << endl;
		cout << "4. Clear the file." << endl;
		cout << "5. End Program." << endl;
		cin >> cChoice; //!< This input will decide which case to use.
		switch (cChoice) {
		case '1':
			cout << "Enter an item to put into the list: ";
			cin >> item;
			ItemList.push_back(item); //!< Add the item to the back of the list.
			break;
		case '2':
			WriteFile(ItemList); //!< Run the file writing function.
			break;
		case '3':
			ReadFile("List.txt");
			break;
		case '4':
			ClearFile("List.txt");
			break;
		case '5':
			bRunLoop = false; //!< Set the loop variable to false so the loop will stop running.
			break;
		default: //!< If the user inputs an invalid input then output the error message.
			cout << "INVALID NUMBER!" << endl;
		}

	}



}

/*
A program that lets you fill a list and save it to a file.
Reads list file and outputs it.
*/