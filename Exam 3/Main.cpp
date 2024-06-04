// Armando, Christopher, Duc, Thi
// CMPR121 - Professor Quach
// Exam 3
#include "Declarations.h"

int main() {
    char option;
    vector<Rational> rationalsVector;
    list<Rational> rationalsList;
    stack<Rational> rationalsStack;
    queue<Rational> rationalsQueue;

    do {
        displayMenu();
        option = inputChar("\n\t\tChoose an option: ");
        switch (toupper(option)) {
        case 'V': {
            vectorMenu(rationalsVector);
            break;
        }
        case 'L': {
            displayLinkedListMenu(rationalsList);
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
        system("PAUSE");
    } while (option != 'X');

    return 0;
}

void displayMenu() {
    cls();

    // Stack and Queue section
    blue;
    cout << setw(84) << " " << string(1, char(186)) << "  in/out  " << string(1, char(186)) << "            " << string(1, char(186)) << "   in     " << string(1, char(186)) << endl;
    cout << setw(84) << " " << string(1, char(186)) << " " << string(1, char(218)) << string(6, char(196)) << string(1, char(191)) << " " << setw(12) << " " << string(1, char(186)) << " " << string(1, char(218)) << string(6, char(196)) << string(1, char(191)) << " " << string(1, char(186)) << endl;
    cout << setw(66) << " " << "top»" << string(1, char(186)) << " " << string(1, char(179)) << setw(7) << "-10/21" << string(1, char(179)) << " " << setw(12) << " " << string(1, char(186)) << " " << string(1, char(179)) << setw(7) << "-57/61" << string(1, char(179)) << " " << string(1, char(186)) << endl;
    cout << setw(70) << " " << string(1, char(186)) << " " << string(1, char(195)) << string(6, char(196)) << string(1, char(180)) << " " << setw(12) << " " << string(1, char(186)) << " " << string(1, char(195)) << string(6, char(196)) << string(1, char(180)) << " " << string(1, char(186)) << endl;

    // Vector section
    red;
    cout << setw(8) << " " << string(1, char(218)) << string(6, char(196)) << string(1, char(194)) << string(6, char(196)) << string(1, char(194)) << string(6, char(196)) << string(1, char(191)) << "      ";
    yellow;
    cout << string(1, char(218)) << string(6, char(196)) << string(1, char(194)) << string(6, char(196)) << string(1, char(194)) << string(6, char(196)) << string(1, char(191)) << "        ";
    blue;
    cout << string(1, char(186)) << " " << string(1, char(179)) << setw(2) << " " << setw(6) << " " << " " << string(1, char(186)) << "            " << string(1, char(179)) << setw(2) << " " << setw(6) << " " << " " << string(1, char(186)) << endl;
    cout << setw(8) << " " << string(1, char(179)) << " -13/24 " << string(1, char(179)) << " " << string(1, char(179)) << "  3/94 " << string(1, char(179)) << " " << string(1, char(179)) << " -25/36 " << string(1, char(179)) << "    ";
    yellow;
    cout << string(1, char(195)) << string(6, char(196)) << string(1, char(194)) << string(6, char(196)) << string(1, char(194)) << string(6, char(196)) << string(1, char(180)) << "        ";
    blue;
    cout << string(1, char(186)) << " " << string(1, char(179)) << setw(2) << " " << setw(6) << " " << " " << string(1, char(186)) << "            " << string(1, char(179)) << setw(2) << " " << setw(6) << " " << " " << string(1, char(186)) << endl;
    cout << setw(8) << " " << string(1, char(192)) << string(6, char(196)) << string(1, char(193)) << string(6, char(196)) << string(1, char(193)) << string(6, char(196)) << string(1, char(217)) << "    ";
    yellow;
    cout << string(1, char(179)) << setw(2) << " " << " " << string(1, char(179)) << " " << setw(2) << " " << string(1, char(179)) << "        ";
    blue;
    cout << string(1, char(186)) << " " << string(1, char(179)) << setw(2) << " " << setw(6) << " " << " " << string(1, char(186)) << "            " << string(1, char(179)) << setw(2) << " " << setw(6) << " " << " " << string(1, char(186)) << endl;
    cout << setw(8) << " " << " " << string(1, char(192)) << " " << setw(2) << " " << "0" << setw(2) << " " << "1" << setw(2) << " " << "2" << setw(6) << " " << "           ";
    yellow;
    cout << string(1, char(179)) << " " << setw(2) << " " << setw(6) << " " << " " << string(1, char(179)) << "                                ";
    blue;
    cout << string(1, char(186)) << " " << string(1, char(179)) << setw(2) << " " << setw(6) << " " << " " << string(1, char(186)) << "            " << string(1, char(179)) << setw(2) << " " << setw(6) << " " << " " << string(1, char(186)) << endl;
    cout << string(70, ' ') << string(1, char(179)) << "            " << string(1, char(179)) << "   out    " << string(1, char(179)) << endl;
    cout << string(70, ' ') << string(1, char(192)) << string(6, char(196)) << string(1, char(193)) << string(6, char(196)) << string(1, char(217)) << " " << setw(6) << " " << string(1, char(192)) << string(6, char(196)) << string(1, char(217)) << endl;

    res;
    cout << "\nVector" << "                    " << "Linked List" << "                           " << "Stack" << "                   " << "Queue";
    cout << "\n\nA container is a holder object that stores a collection of other objects (its elements). They\n"
        << "are implemented as class templates, which allows great flexibility in the types supported as\n"
        << "elements. The container manages the storage space for its elements and provides member functions\n"
        << "to access them, either directly or through iterators(reference objects with similar properties\n"
        << "to pointers).\n"
        << "\nCMPR121 Exam3: STL (Standard Template Library) Containers and Container Adaptors by Prof Q (5-13-2024)\n"
        << string(90, char(205)) << "\n";

    red;
    cout << "V. Vector Container\n";
    yellow;
    cout << "L. List Container\n";
    blue;
    cout << "S. Stack (LIFO) Container Adaptor\n";
    green;
    cout << "Q. Queue (FIFO) Container Adaptor\n";
    res;
    cout << string(90, char(196)) << "\n"
        << "X. Exit\n"
        << string(90, char(205)) << "\n"
        << "Option: ";
}


