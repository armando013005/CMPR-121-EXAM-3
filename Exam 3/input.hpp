//
// originally made by Prof. Quach from the Santa Ana College.
// modfied by Armando Orozco
// october:
// + Clear screen function to not depend in "System"
// + Read Files, wich retunrs a vector of the desire data type 
//	- missing specific cases, ex: want to read after a space and not after a end of line
//
#include "input.h"
#include <iostream>
#include <algorithm>
#include <Windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;


bool manualOrRandom()//true random, false mannual
{
	char option = inputChar("\t\tR - random or C - console(manual) input ?: ", 'R', 'C');
	if (toupper(option) == 'R')
		return true;
	return false;
}

void pos(short C, short R)
{
	COORD xy;
	xy.X = C;
	xy.Y = R;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

//clear the console without acsesing to "system"
void cls()
{
	pos(0, 0);
	for (int j = 0; j < 100; j++)
		cout << string(100, ' ');
	pos(0, 0);
}


void challengeHeaderOutput(int challengeNumber, string challengeName)
{
	cls();

	cout << "\t Challenge " + to_string(challengeNumber) + ". " + challengeName + "\n\t" + string(40, char(196)) + '\n';
	return;
}

//PreCondition: spaces (boolean true or false)
//PostCondition: returns a string including space character(s) or without space character 
//string inputString(string prompt, bool spaces)
//{
//	string input = "";
//
//	cout << "\n\t" + prompt;
//	if (spaces)
//		getline(cin, input);
//	else
//	{
//		cin >> input;
//		cin.clear();
//		cin.ignore(999, '\n');
//	}
//	return input;
//}

string inputString(string prompt, bool spaces, istream& in)
{
	string input = "";

	cout << prompt;
	if (spaces)
		getline(in, input);
	else
	{
		in >> input;
		in.clear();
		in.ignore(999, '\n');
	}
	return input;
}

//PreCondition: valid string of options
//PostCondition: returns an uppercase  of the option (char)
char inputChar(string prompt, string options)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
		{
			bool found = false;
			for (int i = 0; i < options.length(); i++)
				if ((toupper(options.at(i))) == toupper(input))
				{
					found = true;
					break;
				}
			if (found)
			{
				cin.clear();
				cin.ignore(999, '\n');
				break;
			}
			else
				cout << "ERROR: Invalid input. Must be one of '" << options << "' character.\n";
		}
	} while (true);
	return toupper(input);
}

//PreCondition: valid yes (char) or no (char)
//PostCondition: returns an uppercase  yes (char) or no (char) 
char inputChar(string prompt, char yes, char no)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');

		}
		else if (tolower(input) != tolower(yes) && tolower(input) != tolower(no))
		{
			cout << "ERROR: Invalid input. Must be a '" << static_cast<char>(toupper(yes)) << "' or '" << static_cast<char>(toupper(no)) << "' character.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
		{
			cin.clear();
			cin.ignore(999, '\n');
			break;
		}
		cin.clear();
	} while (true);
	return toupper(input);
}
//PreCondition: valid yes (char) or no (char)
//PostCondition: returns an uppercase  yes (char) or no (char) 
char inputChar(string prompt, char a, char b, char c)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cin.clear();
			cin.ignore(999, '\n');
			cls();
			cout << "\n\t\tERROR: Invalid input. Must be a character type.\n";
		}
		else if (tolower(input) != tolower(a) && tolower(input) != tolower(b) && tolower(input) != tolower(c))
		{
			cin.clear();
			cin.ignore(999, '\n');
			cls();
			cout << "\n\t\tERROR: Invalid input. Must be a '" << static_cast<char>(toupper(a)) << "' , '" << static_cast<char>(toupper(b)) << "' or '" << static_cast<char>(toupper(c)) << "' character.\n";
			continue;
		}
		else
		{
			cin.clear();
			cin.ignore(999, '\n');
			break;
		}
		cin.clear();
	} while (true);
	return toupper(input);
}

//PreCondition: alphaOrDigit (boolean true or false)
//PostCondition: returns an alphabet or a digit character
char inputChar(string prompt, bool alphaOrDigit)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (alphaOrDigit && !isalpha(input))
			cout << "ERROR: Invalid input. Must be an alphabet character.\n";
		else if (!alphaOrDigit && !isdigit(input))
			cout << "ERROR: Invalid input. Must be a digit character.\n";
		else
		{
			cin.clear();
			cin.ignore(999, '\n');
			break;
		}
		cin.clear();
	} while (true);
	return input;
}

//PreCondition: NA
//PostCondition: returns any character
char inputChar(string prompt)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return toupper(input);
}


//PreCondition: NA
//PostCondition: returns any integer value
int inputInteger(string prompt)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: asks a stream object to validate input
//PostCondition: returns any integer value
int inputInteger(string prompt, istream& in)
{
	int input;
	do
	{
		cout << prompt;
		if (!(in >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			in.clear();
			in.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	in.clear();
	in.ignore(999, '\n');
	return input;
}

//PreCondition: posNeg (boolean true or false)
//PostCondition: returns a positive integer value (posNeg = true) or a negative integer value (poseNeg = false)
int inputInteger(string prompt, bool posNeg)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input < 0)
			cout << "ERROR: Invalid input. Must be a positive number.\n";
		else if (!posNeg && input >= 0)
			cout << "ERROR: Invalid input. Must be a negative number.\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: start (integer) and greater (boolean true or false)
//PostCondition: returns an integer value greater than start or lesser than start
int inputInteger(string prompt, int start, bool greater)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (greater && input < start)
			cout << "ERROR: Invalid input. Must be a greater than or equal to " << start << ".\n";
		else if (!greater && input > start)
			cout << "ERROR: Invalid input. Must be a lesser than or equal to " << start << ".\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: startRange (integer) and endRange (integer)
//PostCondition: returns an integer value within range (startRannge and endRange)
int inputInteger(string prompt, int startRange, int endRange)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
			cout << "ERROR: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}
int inputInteger(string prompt, int startRange, int endRange, istream& in)
{
	int input;
	do
	{
		cout << prompt;
		if (!(in >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			in.clear();
			in.ignore(999, '\n');
		}
		else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
			cout << "ERROR: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
		else
			break;
	} while (true);
	in.clear();
	in.ignore(999, '\n');
	return input;
}

//PreCondition: NA
//PostCondition: returns any double value
double inputDouble(string prompt)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

double inputDouble(string prompt, istream& in)
{
	double input;
	do
	{
		cout << prompt;
		if (!(in >> input))
		{
			cout << "ERROR: Invalid input. Must be a double type.\n";
			in.clear();
			in.ignore(999, '\n');
		}
		else
			break;
	} while (true);
	in.clear();
	in.ignore(999, '\n');
	return input;
}

//PreCondition: posNeg (boolean true or false)
//PostCondition: returns a positive double value (posNeg = true) or a negative double value (poseNeg = false)
double inputDouble(string prompt, bool posNeg)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (posNeg && input < 0.0)
			cout << "ERROR: Invalid input. Must be a positive number.\n";
		else if (!posNeg && input >= 0.0)
			cout << "ERROR: Invalid input. Must be a negative number.\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//PreCondition: start(integer) and greater(boolean true or false)
//PostCondition: returns an integer value greater than start or lesser than start
//double inputDouble(string prompt, double start, bool posNeg)
//{
//	double input;
//	do
//	{
//		cout << prompt;
//		if (!(cin >> input))
//		{
//			cout << "ERROR: Invalid input. Must be a double type.\n";
//			cin.clear();
//			cin.ignore(999, '\n');
//		}
//		else if (posNeg && input < start)
//			cout << "ERROR: Invalid input. Must be greater than or equal to " << start << ".\n";
//		else if (!posNeg && input > start)
//			cout << "ERROR: Invalid input. Must be lesser than or equal to " << start << ".\n";
//		else
//			break;
//	} while (true);
//	cin.clear();
//	cin.ignore(999, '\n');
//	return input;
//}

//PreCondition: startRange (integer) and endRange (integer)
//PostCondition: returns an integer value within range (startRannge and endRange)
double inputDouble(string prompt, double startRange, double endRange)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
			cout << "ERROR: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}
//PreCondition: startRange (integer) and endRange (integer)
//PostCondition: returns an integer value within range (startRannge and endRange)
double inputDouble(string prompt, double startRange, double endRange, istream& in)
{
	double input;
	do
	{
		cout << prompt;
		if (!(in >> input))
		{
			cout << "ERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
			cout << "ERROR: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
		else
			break;
	} while (true);
	cin.clear();
	cin.ignore(999, '\n');
	return input;
}

//Precondition: when detected an end of line will create another 
vector<int> inputFileInt(string fileName)
{
	vector<int> fileCopy;
	ifstream file;
	file.open(fileName);

	while (file.fail())
	{
		cout << "\nERROR: " << fileName << ", cannot be found";
		fileName = inputString("\nEnter the name of the file: ", false);
		file.open(fileName);
	}

	int aux;
	while (file >> aux)
	{
		fileCopy.push_back(aux);
	}

	file.close();

	return fileCopy;
}

//Precondition: when detected an end of line will create another 
vector<string> inputFileString(string fileName)
{
	vector<string> fileCopy;
	ifstream file;
	file.open(fileName);

	while (file.fail())
	{
		cout << "\nERROR: " << fileName << ", cannot be found";
		fileName = inputString("\nEnter the name of the file: ", false);
		file.open(fileName);
	}

	string aux;
	while (getline(file, aux))
	{
		fileCopy.push_back(aux);
	}

	file.close();

	return fileCopy;
}

//Precondition: when detected an end of line will create another 
//Postcondition: check the maximum characters for each row
vector<string> inputFileString(string fileName, int rowLimit)
{
	vector<string> fileCopy;
	ifstream file;
	file.open(fileName);

	while (file.fail())
	{
		cout << "\nERROR: " << fileName << ", cannot be found";
		fileName = inputString("\nEnter the name of the file: ", false);
		file.open(fileName);
	}

	string aux;
	while (file >> aux)
	{
		fileCopy.push_back(aux);
		if (aux.size() > rowLimit)
		{
			cout << "\nERROR: bad formating, modify the file and try again";
			file.close();
			exit(-1);
		}
	}

	file.close();

	return fileCopy;
}

vector<char> inputFileChar(string fileName)
{
	vector<char> fileCopy;
	ifstream file;
	file.open(fileName);

	while (file.fail())
	{
		cout << "\nERROR: " << fileName << ", cannot be found";
		fileName = inputString("\nEnter the name of the file: ", false);
		file.open(fileName);
	}

	char aux;
	while (file >> aux)
	{
		fileCopy.push_back(aux);
	}

	file.close();

	return fileCopy;
}

//check for the existance of a file and return the name of these
string checkFileName()
{
	string fileName;
	fstream file;
	do {
		fileName = inputString("\n\tEnter the binary chemistry data file (ex: UNSORTED.DAT): ", false);
		file.open(fileName, ios::in);
		if (file.fail())
		{
			if (inputChar("\n\tFILE DOES NOT EXIST: try again?(Y/N) ", 'Y', 'N') == 'Y')
			{
				file.close();
				continue;
			}
			else {
				file.close();
				return "-1";
			}
		}
		else
		{
			file.close();
			return fileName;
		}
	} while (true);
	return fileName;
}