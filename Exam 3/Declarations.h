#pragma once
#include "Rational.h"
#include "input.h" // Include the custom input functions header
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

//this is a macro for the colors, instead of write the full text just "color" should be enogh to output the color
//write the desired color of your output before the cout to set the color
//res to go back to the default console color
#define red cout << "\033[31m"
#define yellow cout << "\033[33m"
#define blue cout << "\033[34m"
#define green cout << "\033[32m"
#define res cout << "\033[0m"

//main menu
void displayMenu();

//displays a single square of ratuibak
static void displaySingle(Rational r) {
    cout << "\n\t";
    cout << char(218) << string(7, char(196)) << char(191) << '\n';//top line

    //rational
    cout << "\t" << string(1, char(179));
    cout << setw(3) << right << r;
    if (r.getNumerator() > 10 && r.getDenominator() < 10)
        cout << right << setw(3) << string(1, char(179));
    else if (r.getNumerator() > 10 || r.getDenominator() > 10)
        cout << right << setw(2) << right << string(1, char(179));
    else
        cout << right << setw(3) << string(1, char(179));

    cout<< '\n';
    cout << '\t' << char(192) << string(7, char(196)) << char(217) << '\n';//bottom line

}


void displayTopLines(int size);
void displayContent(Rational);
void displayBottom(int);

//vector
void vectorMenu(vector<Rational>& rationals);
void displayVectorMenu(const vector<Rational>& rationals);
void outOfRange(const string& errorMessage);    // throw an errormessage if out of range
void displayElements(const vector<Rational>& rationals, int index, int size); // display elements by recursion


//linked list
void displayLinkedListMenu(list<Rational>& rlist);
void addElement(Rational& r, list<Rational>& rlist);
void insertElement(Rational& r, list<Rational>& rlist);
void removeElement(Rational& r, list<Rational>& rlist);
void sortElement(list<Rational>& rlist);
void clearElement(list<Rational>& rlist);
void showListHelper(list<Rational>::iterator it, list<Rational>::iterator end);
void showList(list<Rational>& rlist);

//stack
void displayStackMenu(const stack<Rational>& rationals);
void stackMenu(stack<Rational>& rationals);

//queue
void displayQueueMenu(const queue<Rational>& rationals);
void queueMenu(queue<Rational>& rationals);