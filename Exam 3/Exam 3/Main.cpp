// Armando, Christopher, Duc, Thi
// CMPR121 - Professor Quach
// Exam 3

#include "Rational.h"
#include "input.h" // Include the custom input functions header
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>

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
    // Header
    cout << "\n\t" + string(90, char(205)) << endl;

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

    setColor("");
    cout << "\n\tA container is a holder object that stores a collection of other objects (its elements). They\n"
        << "\tare implemented as class templates, which allows great flexibility in the types supported as\n"
        << "\telements. The container manages the storage space for its elements and provides member functions\n"
        << "\tto access them, either directly or through iterators(reference objects with similar properties\n"
        << "\tto pointers).\n"
        << "\n\tCMPR121 Exam3: STL (Standard Template Library) Containers and Container Adaptors by Prof Q (5-13-2024)\n"
        << "\t" + string(90, char(205)) << "\n";

    setColor("red");
    cout << "\t\t\tV. Vector Container\n";
    setColor("yellow");
    cout << "\t\t\tL. List Container\n";
    setColor("blue");
    cout << "\t\t\tS. Stack (LIFO) Container Adaptor\n";
    setColor("green");
    cout << "\t\t\tQ. Queue (FIFO) Container Adaptor\n";
    setColor("");
    cout << "\t" + string(90, char(196)) << "\n"
        << "\t\t\tX. Exit\n"
        << "\t" + string(90, char(205)) << "\n"
        << "\t\t\tOption: ";
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
    cout << "\n\tVectors (array) are same as dynamic arrays with the ability to resize itself automatically\n"
        << "\twhen an element is inserted or deleted, that contains their storage being handled automatically\n"
        << "\tby the container. Vector elements are placed in contiguous storage so that they can be accessed\n"
        << "\tand traversed using iterators or indexes.\n";

    if (rationals.empty()) {
        cout << "\n\tThe current vector is empty.\n";
    }
    else {
        cout << "\n\tThe current vector elements are:\n";
        for (size_t i = 0; i < rationals.size(); ++i) {
            cout << "\t" << i << ": " << rationals[i] << "\n";
        }
    }

    setColor("red");
    cout << "\n\n\t\t\tVector (list array) Menu Options\n";
    cout << "\t" + string(90, char(205)) << "\n";
    setColor("");
    cout << "\t\t\t1. Add an element\n"
        << "\t\t\t2. Insert an element at index\n"
        << "\t\t\t3. Retrieve an element from index\n"
        << "\t\t\t4. Erase element(s)\n"
        << "\t\t\t5. Sort the vector elements in ascending order\n"
        << "\t\t\t6. Clear all elements\n";
    setColor("red");
    cout << "\t" + string(90, char(196)) << "\n";
    setColor("");
    cout << "\t\t\t0. Return\n";
    setColor("red");
    cout << "\t" + string(90, char(205)) << "\n";
    setColor("");
    cout << "\t\t\tOption: ";
}

void displayLinkedListMenu(const list<Rational>& rationals) {
    cout << "\n\tLinked lists are sequence containers that allow non-contiguous memory allocation. As compared to\n"
        << "\tvector, the linked list has slow traversal, but once a position has been found, insertion and\n"
        << "\tdeletion are quicker.\n";

    if (rationals.empty()) {
        cout << "\n\tThe current list is empty.\n";
    }
    else {
        cout << "\n\tThe current list elements are:\n";
        int index = 0;
        for (const auto& r : rationals) {
            cout << "\t" << index++ << ": " << r << "\n";
        }
    }

    setColor("yellow");
    cout << "\n\n\t\t\tLinked List Menu Options\n";
    cout << "\t" + string(90, char(205)) << "\n";
    setColor("");
    cout << "\t\t\t1. Add (push) an element\n"
        << "\t\t\t2. Insert an element after\n"
        << "\t\t\t3. Remove element(s)\n"
        << "\t\t\t4. Sort the elements in ascending order\n"
        << "\t\t\t5. Clear all elements\n";
    setColor("yellow");
    cout << "\t" + string(90, char(196)) << "\n";
    setColor("");
    cout << "\t\t\t0. Return\n";
    setColor("yellow");
    cout << "\t" + string(90, char(205)) << "\n";
    setColor("");
    cout << "\t\t\tOption: ";
}

void linkedListMenu(list<Rational>& rationals) {
    char option;
    do {
        displayLinkedListMenu(rationals);
        option = inputChar("\n\tChoose an option (1-5, 0): ", "123450");

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

void displayStackMenu(const stack<Rational>& rationals) {
    cout << "\n\tStacks are type of container adaptors with LIFO (Last In First Out) type of working, where a new\n"
        << "\telement is added (pushed) at one end (top) and an element is removed (popped) from that end (top)\n"
        << "\tonly. Stack uses an encapsulated object of either vector or deque (by default) or list (sequential\n"
        << "\tcontainer class) as its underlying container, providing a specific set of member functions to\n"
        << "\taccess its elements.\n";

    if (rationals.empty()) {
        cout << "\n\tThe current stack is empty.\n";
    }
    else {
        cout << "\n\tThe current stack elements are (from top to bottom):\n";
        // Display stack elements
        stack<Rational> tempStack = rationals;
        while (!tempStack.empty()) {
            cout << "\t" << tempStack.top() << "\n";
            tempStack.pop();
        }
    }

    setColor("blue");
    cout << "\n\n\t\t\tStack Menu Options\n";
    cout << "\t" + string(90, char(205)) << "\n";
    setColor("");
    cout << "\t\t\t1. Push\n"
        << "\t\t\t2. Top\n"
        << "\t\t\t3. Pop\n";
    setColor("blue");
    cout << "\t" + string(90, char(196)) << "\n";
    setColor("");
    cout << "\t\t\t0. Return\n";
    setColor("blue");
    cout << "\t" + string(90, char(205)) << "\n";
    setColor("");
    cout << "\t\t\tOption: ";
}

void stackMenu(stack<Rational>& rationals) {
    char option;
    do {
        displayStackMenu(rationals);
        option = inputChar("\n\tChoose an option (1-3, 0): ", "1230");

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

void displayQueueMenu(const queue<Rational>& rationals) {
    cout << "\n\tQueues are type of container adaptors that operate in a first in first out (FIFO) type of\n"
        << "\tarrangement. Elements are inserted/pushed (enqueued) at the rear and are removed/popped (dequeued)\n"
        << "\tfrom the front. Queues use an encapsulated object of deque or list (sequential container class)\n"
        << "\tas its underlying container, providing a specific set of member functions to access elements.\n";

    if (rationals.empty()) {
        cout << "\n\tThe current queue is empty.\n";
    }
    else {
        cout << "\n\tThe current queue elements are (from front to rear):\n";
        // Display queue elements
        queue<Rational> tempQueue = rationals;
        while (!tempQueue.empty()) {
            cout << "\t" << tempQueue.front() << "\n";
            tempQueue.pop();
        }
    }

    setColor("green");
    cout << "\n\n\t\t\tQueue Menu Options\n";
    cout << "\t" + string(90, char(205)) << "\n";
    setColor("");
    cout << "\t\t\t1. Enqueue (push into the rear)\n"
        << "\t\t\t2. Rear (back)\n"
        << "\t\t\t3. Front\n"
        << "\t\t\t4. Dequeue (pop from the front)\n";
    setColor("green");
    cout << "\t" + string(90, char(196)) << "\n";
    setColor("");
    cout << "\t\t\t0. Return\n";
    setColor("green");
    cout << "\t" + string(90, char(205)) << "\n";
    setColor("");
    cout << "\t\t\tOption: ";
}

void queueMenu(queue<Rational>& rationals) {
    char option;
    do {
        displayQueueMenu(rationals);
        option = inputChar("\n\tChoose an option (1-4, 0): ", "12340");

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

int main() {
    char option;
    vector<Rational> rationalsVector;
    list<Rational> rationalsList;
    stack<Rational> rationalsStack;
    queue<Rational> rationalsQueue;

    do {
        displayMenu();
        option = inputChar("\n\tChoose an option (V, L, S, Q, X): ", "VLSQX");

        switch (option) {
        case 'V': {
            vectorMenu(rationalsVector);
            break;
        }
        case 'L': {
            linkedListMenu(rationalsList);
            break;
        }
        case 'S': {
            stackMenu(rationalsStack);
            break;
        }
        case 'Q': {
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
