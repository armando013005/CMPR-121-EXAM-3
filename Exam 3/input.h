#ifndef INPUT_H
#define INPUT_H
//
// originally made by Prof. Quach from the Santa Ana College.
// modfied by Armando Orozco
// october:
// + Clear screen function to not depend in "System"
// + Read Files, wich retunrs a vector of the desire data type 
//	- missing specific cases, ex: want to read after a space and not after a end of line
//

#include <iostream>
#include <algorithm>
#include <Windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <map>
using namespace std;

bool manualOrRandom();
void pos(short C, short R);
//clear the console without acsesing to "system"
void cls();

void challengeHeaderOutput(int challengeNumber, string challengeName);

//PreCondition: spaces (boolean true or false)
//PostCondition: returns a string including space character(s) or without space character 
//string inputString(string prompt, bool spaces);

string inputString(string prompt, bool spaces, istream& in);
//PreCondition: valid string of options
//PostCondition: returns an uppercase  of the option (char)
char inputChar(string prompt, string options);

//PreCondition: valid yes (char) or no (char)
//PostCondition: returns an uppercase  yes (char) or no (char) 
char inputChar(string prompt, char yes, char no);
//PreCondition: valid yes (char) or no (char)
//PostCondition: returns an uppercase  yes (char) or no (char) 
char inputChar(string prompt, char a, char b, char c);

//PreCondition: alphaOrDigit (boolean true or false)
//PostCondition: returns an alphabet or a digit character
char inputChar(string prompt, bool alphaOrDigit);
//PreCondition: NA
//PostCondition: returns any character
char inputChar(string prompt);

//PreCondition: NA
//PostCondition: returns any integer value
int inputInteger(string prompt);


int inputInteger(string prompt, int startRange, int endRange, istream& in);

int inputInteger(string prompt, istream& in);
//PreCondition: posNeg (boolean true or false)
//PostCondition: returns a positive integer value (posNeg = true) or a negative integer value (poseNeg = false)
int inputInteger(string prompt, bool posNeg);

//PreCondition: start (integer) and greater (boolean true or false)
//PostCondition: returns an integer value greater than start or lesser than start
int inputInteger(string prompt, int start, bool greater);

//PreCondition: startRange (integer) and endRange (integer)
//PostCondition: returns an integer value within range (startRannge and endRange)
int inputInteger(string prompt, int startRange, int endRange);

//PreCondition: NA
//PostCondition: returns any double value
double inputDouble(string prompt);

double inputDouble(string prompt, istream& in);
//PreCondition: posNeg (boolean true or false)
//PostCondition: returns a positive double value (posNeg = true) or a negative double value (poseNeg = false)
double inputDouble(string prompt, bool posNeg);

//PreCondition: start(integer) and greater(boolean true or false)
//PostCondition: returns an integer value greater than start or lesser than start
//double inputDouble(string prompt, double start, bool posNeg);

//PreCondition: startRange (integer) and endRange (integer)
//PostCondition: returns an integer value within range (startRannge and endRange)
double inputDouble(string prompt, double startRange, double endRange);
//PreCondition: startRange (integer) and endRange (integer)
//PostCondition: returns an integer value within range (startRannge and endRange)
double inputDouble(string prompt, double startRange, double endRange, istream& in);

//Precondition: when detected an end of line will create another 
vector<int> inputFileInt(string fileName);
//Precondition: when detected an end of line will create another 
vector<string> inputFileString(string fileName);

//Precondition: when detected an end of line will create another 
//Postcondition: check the maximum characters for each row
vector<string> inputFileString(string fileName, int rowLimit);
vector<char> inputFileChar(string fileName);
//check for the existance of a file and return the name of these
string checkFileName();

#endif