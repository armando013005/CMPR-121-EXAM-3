// Armando, Christopher, Duc, Thi
// CMPR121 - Professor Quach
// Exam 3

#include "Rational.h"
#include "input.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void setColor(const string& color);
void displayMenu();
void vectorMenu(vector<Rational>& rationals);
void displayVectorMenu(const vector<Rational>& rationals);
void displayLinkedListMenu(const list<Rational>& rationals);
void linkedListMenu(list<Rational>& rationals);
void displayStackMenu(const stack<Rational>& rationals);
void stackMenu(stack<Rational>& rationals);
void displayQueueMenu(const queue<Rational>& rationals);
void queueMenu(queue<Rational>& rationals);
void displayVectorElements(const vector<Rational>& rationals, int index = 0);
void displayListElements(const list<Rational>& rationals, list<Rational>::const_iterator it);
void displayStackElements(stack<Rational> rationals);
void displayQueueElements(queue<Rational> rationals);

void setColor(const string& color) {
    if (color == "red")
        cout << "\033[31m";
    else if (color == "yellow")
        cout << "\033[33m";
    else if (color == "blue")
        cout << "\033[34m";
    else if (color == "green")
        cout << "\033[32m";
    else
        cout << "\033[0m";  // Reset to default
}

void displayMenu() {
    // Stack and Queue section
    setColor("blue");
    cout << "\t" + string(70, ' ') + string(1, char(186)) + "  in/out  " + string(1, char(186)) + "            " + string(1, char(186)) + "   in     " + string(1, char(186));
    cout << "\n\t" + string(70, ' ') + string(1, char(186)) + string(1, char(218)) + string(6, char(196)) + string(1, char(191)) + " " + string(12, ' ') + string(1, char(186)) + string(1, char(218)) + string(6, char(196)) + string(1, char(191));
    cout << "\n\t" + string(66, ' ') + "top" + string(1, char(187)) + string(1, char(186)) + " " + string(1, char(179)) + string(2, ' ') + string(6, ' ') + " " + string(1, char(186)) + "       rear" + string(1, char(187)) + string(1, char(186)) + " " + string(1, char(179)) + string(2, ' ') + string(6, ' ') + " " + string(1, char(186));
    cout << "\n\t" + string(70, ' ') + string(1, char(186)) + string(1, char(195)) + string(6, char(196)) + string(1, char(180)) + " " + string(12, ' ') + string(1, char(186)) + string(1, char(195)) + string(6, char(196)) + string(1, char(180));

    // Vector section
    setColor("red");
    cout << "\n\t" + string(8, ' ') + string(1, char(218)) + string(6, char(196)) + string(1, char(194)) + string(6, char(196)) + string(1, char(194)) + string(6, char(196)) + string(1, char(191)) + "      ";
    setColor("yellow");
    cout << string(1, char(218)) + string(6, char(196)) + string(1, char(194)) + string(6, char(196)) + string(1, char(194)) + string(6, char(196)) + string(1, char(191)) + "        ";
    setColor("blue");
    cout << string(1, char(186)) + " " + string(1, char(179)) + " " + string(2, ' ') + string(6, ' ') + " " + string(1, char(186)) + "            " + string(1, char(179)) + " " + string(2, ' ') + string(6, ' ') + " " + string(1, char(186));
    cout << "\n\t" + string(8, ' ') + string(1, char(179)) + " ";
    setColor(""); cout << "-13/24"; setColor("red"); cout << " " + string(1, char(179)) + " " + string(1, char(179)) + " " + string(1, ' ') + "  3/94" + string(1, char(179)) + " " + string(1, char(179)) + " " + string(1, ' ') + "-25/36" + string(1, char(179)) + "    ";
    setColor("yellow");
    cout << string(1, char(195)) + string(6, char(196)) + string(1, char(194)) + string(6, char(196)) + string(1, char(194)) + string(6, char(196)) + string(1, char(180)) + "        ";
    setColor("blue");
    cout << string(1, char(186)) + " " + string(1, char(179)) + " " + string(2, ' ') + string(6, ' ') + " " + string(1, char(186)) + "            " + string(1, char(179)) + " " + string(2, ' ') + string(6, ' ') + " " + string(1, char(186));
    cout << "\n\t" + string(8, ' ') + string(1, char(192)) + string(6, char(196)) + string(1, char(193)) + string(6, char(196)) + string(1, char(193)) + string(6, char(196)) + string(1, char(217)) + "    ";
    setColor("yellow");
    cout << string(1, char(179)) + " " + string(2, ' ') + " " + string(1, char(179)) + " " + string(2, ' ') + string(1, char(179)) + "        ";
    setColor("blue");
    cout << string(1, char(186)) + " " + string(1, char(179)) + " " + string(2, ' ') + string(6, ' ') + " " + string(1, char(186)) + "            " + string(1, char(179)) + " " + string(2, ' ') + string(6, ' ') + " " + string(1, char(186));
    cout << "\n\t" + string(8, ' ') + " " + string(1, char(192)) + " " + string(2, ' ') + "0" + string(1, ' ') + string(2, ' ') + "1" + string(1, ' ') + string(2, ' ') + "2" + string(1, ' ') + string(6, ' ') + "           ";
    setColor("yellow");
    cout << string(1, char(179)) + " " + string(2, ' ') + string(6, ' ') + " " + string(1, char(179)) + "                                ";
    setColor("blue");
    cout << string(1, char(186)) + " " + string(1, char(179)) + " " + string(2, ' ') + string(6, ' ') + " " + string(1, char(186)) + "            " + string(1, char(179)) + " " + string(2, ' ') + string(6, ' ') + " " + string(1, char(186));
    cout << "\n\t" + string(70, ' ') + string(1, char(179)) + "            " + string(1, char(179)) + "   out    " + string(1, char(179));
    cout << "\n\t" + string(70, ' ') + string(1, char(192)) + string(6, char(196)) + string(1, char(193)) + string(6, char(196)) + string(1, char(217)) + " " + string(6, ' ') + string(1, char(192)) + string(6, char(196)) + string(1, char(217));

    // Header
    cout << "\n\t" + string(90, char(205)) << endl;
    setColor("");
    cout << "\n\tA container is a holder object that stores a collection of other objects (its elements). They"
        << "\n\tare implemented as class templates, which allows great flexibility in the types supported as"
        << "\n\telements. The container manages the storage space for its elements and provides member functions"
        << "\n\tto access them, either directly or through iterators(reference objects with similar properties"
        << "\n\tto pointers)."
        << "\n\nCMPR121 Exam3: STL (Standard Template Library) Containers and Container Adaptors by Armando, Chris, Duc, & Thi"
        << "\n\t" + string(90, char(205));

    setColor("red");
    cout << "\n\tV. Vector Container";
    setColor("yellow");
    cout << "\n\tL. List Container";
    setColor("blue");
    cout << "\n\tS. Stack (LIFO) Container Adaptor";
    setColor("green");
    cout << "\n\tQ. Queue (FIFO) Container Adaptor";
    setColor("");
    cout << "\n\t" + string(90, char(196))
        << "\n\tX. Exit\n"
        << "\n\t" + string(90, char(205));

}

void vectorMenu(vector<Rational>& rationals) {
    char option;
    do {
        displayVectorMenu(rationals);
        option = inputChar("\n\tChoose an option (1-6, 0): ", "1234560");

        switch (option) {
        case '1': {

            break;
        }
        case '2': {

            break;
        }
        case '3': {

            break;
        }
        case '4': {

            break;
        }
        case '5': {

            break;
        }
        case '6': {

            break;
        }
        case '0': {
            return;
        }
        default:
            cout << "\n\tInvalid option. Please try again." << endl;
        }
    } while (option != '0');
}

void displayVectorMenu(const vector<Rational>& rationals) {
    cout << "\n\tVectors (array) are same as dynamic arrays with the ability to resize itself automatically"
        << "\n\twhen an element is inserted or deleted, that contains their storage being handled automatically"
        << "\n\tby the container. Vector elements are placed in contiguous storage so that they can be accessed"
        << "\n\tand traversed using iterators or indexes.";

    if (rationals.empty()) {
        cout << "\n\tThe current vector is empty.";
    }
    else {
        cout << "\n\tThe current vector elements are: ";
        displayVectorElements(rationals);
    }

    setColor("red");
    cout << "\n\tVector (list array) Menu Options";
    cout << "\n\t" + string(90, char(205));
    setColor("");
    cout << "\n\t1. Add an element"
        << "\n\t2. Insert an element at index"
        << "\n\t3. Retrieve an element from index"
        << "\n\t4. Erase element(s)"
        << "\n\t5. Sort the vector elements in ascending order"
        << "\n\t6. Clear all elements";
    setColor("red");
    cout << "\n\t" + string(90, char(196));
    setColor("");
    cout << "\n\t0. Return";
    setColor("red");
    cout << "\n\t" + string(90, char(205));
    setColor("");
    cout << "\n\tOption: ";
}

void displayVectorElements(const vector<Rational>& rationals, int index) {
    if (index >= rationals.size()) {
        return;
    }
    cout << "\n\t" << index << ": " << rationals[index];
    displayVectorElements(rationals, index + 1);
}

void displayLinkedListMenu(const list<Rational>& rationals) {
    cout << "\n\tLinked lists are sequence containers that allow non-contiguous memory allocation. As compared to"
        << "\n\tvector, the linked list has slow traversal, but once a position has been found, insertion and"
        << "\n\tdeletion are quicker.";

    if (rationals.empty()) {
        cout << "\n\tThe current list is empty." << endl;
    }
    else {
        cout << "\n\tThe current list elements are:";
        displayListElements(rationals, rationals.begin());
    }

    setColor("yellow");
    cout << "\n\tLinked List Menu Options";
    cout << "\n\t" + string(90, char(205));
    setColor("");
    cout << "\n\t1. Add (push) an element"
        << "\n\t2. Insert an element after"
        << "\n\t3. Remove element(s)"
        << "\n\t4. Sort the elements in ascending order"
        << "\n\t5. Clear all elements";
    setColor("yellow");
    cout << "\n\t" + string(90, char(196));
    setColor("");
    cout << "\n\t0. Return";
    setColor("yellow");
    cout << "\n\t" + string(90, char(205));
    setColor("");
}

void linkedListMenu(list<Rational>& rationals) {
    char option;
    do {
        displayLinkedListMenu(rationals);
        option = inputChar("\n\tOption (1-5, 0): ", "123450");

        switch (option) {
        case '1': {

            break;
        }
        case '2': {

            break;
        }
        case '3': {

            break;
        }
        case '4': {

            break;
        }
        case '5': {

            break;
        }
        case '0': {
            return;
        }
        default:
            cout << "\n\tInvalid option. Please try again." << endl;
        }
    } while (option != '0');
}

void displayListElements(const list<Rational>& rationals, list<Rational>::const_iterator it) {
    if (it == rationals.end()) {
        return;
    }
    cout << "\n\t" << distance(rationals.begin(), it) << ": " << *it;
    displayListElements(rationals, ++it);
}

void displayStackMenu(const stack<Rational>& rationals) {
    cout << "\n\tStacks are type of container adaptors with LIFO (Last In First Out) type of working, where a new"
        << "\n\telement is added (pushed) at one end (top) and an element is removed (popped) from that end (top)"
        << "\n\tonly. Stack uses an encapsulated object of either vector or deque (by default) or list (sequential"
        << "\n\tcontainer class) as its underlying container, providing a specific set of member functions to"
        << "\n\taccess its elements.";

    if (rationals.empty()) {
        cout << "\n\tThe current stack is empty.";
    }
    else {
        cout << "\n\tThe current stack elements are (from top to bottom):";
        displayStackElements(rationals);
    }

    setColor("blue");
    cout << "\n\tStack Menu Options";
    cout << "\n\t" + string(90, char(205));
    setColor("");
    cout << "\n\t1. Push"
        << "\n\t2. Top"
        << "\n\t3. Pop";
    setColor("blue");
    cout << "\n\t" + string(90, char(196));
    setColor("");
    cout << "\n\t0. Return";
    setColor("blue");
    cout << "\n\t" + string(90, char(205));
    setColor("");
}

void stackMenu(stack<Rational>& rationals) {
    char option;
    do {
        displayStackMenu(rationals);
        option = inputChar("\n\tOption (1-3, 0): ", "1230");

        switch (option) {
        case '1': {

            break;
        }
        case '2': {

            break;
        }
        case '3': {

            break;
        }
        case '0': {
            return;
        }
        default:
            cout << "\n\tInvalid option. Please try again." << endl;
        }
    } while (option != '0');
}

void displayStackElements(stack<Rational> rationals) {
    if (rationals.empty()) {
        return;
    }
    Rational topElement = rationals.top();
    rationals.pop();
    cout << "\n\t" << topElement;
    displayStackElements(rationals);
}

void displayQueueMenu(const queue<Rational>& rationals) {
    cout << "\n\tQueues are type of container adaptors that operate in a first in first out (FIFO) type of"
        << "\n\tarrangement. Elements are inserted/pushed (enqueued) at the rear and are removed/popped (dequeued)"
        << "\n\tfrom the front. Queues use an encapsulated object of deque or list (sequential container class)"
        << "\n\tas its underlying container, providing a specific set of member functions to access elements.";

    if (rationals.empty()) {
        cout << "\n\tThe current queue is empty.";
    }
    else {
        cout << "\n\tThe current queue elements are (from front to rear):";
        displayQueueElements(rationals);
    }

    setColor("green");
    cout << "\n\tQueue Menu Options";
    cout << "\n\t" + string(90, char(205));
    setColor("");
    cout << "\n\t1. Enqueue (push into the rear)"
        << "\n\t2. Rear (back)"
        << "\n\t3. Front"
        << "\n\t4. Dequeue (pop from the front)";
    setColor("green");
    cout << "\n\t" + string(90, char(196));
    setColor("");
    cout << "\n\t0. Return";
    setColor("green");
    cout << "\n\t" + string(90, char(205));
    setColor("");
}

void queueMenu(queue<Rational>& rationals) {
    char option;
    do {
        displayQueueMenu(rationals);
        option = inputChar("\n\tOption (1-4, 0): ", "12340");

        switch (option) {
        case '1': {

            break;
        }
        case '2': {

            break;
        }
        case '3': {

            break;
        }
        case '4': {

            break;
        }
        case '0': {
            return;
        }
        default:
            cout << "\n\tInvalid option. Please try again." << endl;
        }
    } while (option != '0');
}

void displayQueueElements(queue<Rational> rationals) {
    if (rationals.empty()) {
        return;
    }
    Rational frontElement = rationals.front();
    rationals.pop();
    cout << "\n\t" << frontElement;
    displayQueueElements(rationals);
}

int main() {
    char option;
    vector<Rational> rationalsVector;
    list<Rational> rationalsList;
    stack<Rational> rationalsStack;
    queue<Rational> rationalsQueue;

    do {
        system("cls"); // Clear screen
        displayMenu();
        option = inputChar("\n\tOption (V, L, S, Q, X): ", "VLSQX");
        option = toupper(option); // Convert to uppercase

        switch (option) {
        case 'V': {
            system("cls");
            vectorMenu(rationalsVector);
            break;
        }
        case 'L': {
            system("cls");
            linkedListMenu(rationalsList);
            break;
        }
        case 'S': {
            system("cls");
            stackMenu(rationalsStack);
            break;
        }
        case 'Q': {
            system("cls");
            queueMenu(rationalsQueue);
            break;
        }
        case 'X': {
            cout << "\n\tExiting..." << endl;
            break;
        }
        default:
            cout << "\n\tInvalid option. Please try again." << endl;
        }
    } while (option != 'X');

    return 0;
}

