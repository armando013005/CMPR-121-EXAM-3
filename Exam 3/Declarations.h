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

#define red cout << "\033[31m"
#define yellow cout << "\033[33m"
#define blue cout << "\033[34m"
#define green cout << "\033[32m"
#define res cout << "\033[0m"

void displayMenu();
void vectorMenu(vector<Rational>& rationals);
void displayVectorMenu(const vector<Rational>& rationals);
void displayLinkedListMenu(const list<Rational>& rationals);
void linkedListMenu(list<Rational>& rationals);
void displayStackMenu(const stack<Rational>& rationals);
void stackMenu(stack<Rational>& rationals);
void displayQueueMenu(const queue<Rational>& rationals);
void queueMenu(queue<Rational>& rationals);