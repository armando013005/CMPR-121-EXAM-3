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

//displays a single square of ratipnal
static void displaySingle(Rational r);

//vector
void vectorMenu(vector<Rational>& rationals);
void displayVectorMenu(const vector<Rational>& rationals);

//linked list
void displayLinkedListMenu(const list<Rational>& rationals);
void linkedListMenu(list<Rational>& rationals);

//stack
void displayStackMenu(const stack<Rational>& rationals);
void stackMenu(stack<Rational>& rationals);

//queue
void displayQueueMenu(const queue<Rational>& rationals);
void queueMenu(queue<Rational>& rationals);