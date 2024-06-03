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
    cout << "\t" + string(70, ' ') + string(1, char(186)) + "  in/out  " + string(1, char(186)) + "            " + string(1, char(186)) + "   in     " + string(1, char(186));
    cout << "\n\t" + string(70, ' ') + string(1, char(186)) + string(1, char(218)) + string(6, char(196)) + string(1, char(191)) + " " + string(12, ' ') + string(1, char(186)) + string(1, char(218)) + string(6, char(196)) + string(1, char(191));
    cout << "\n\t" + string(66, ' ') + "top" + string(1, char(187)) + string(1, char(186)) + " " + string(1, char(179)) + string(2, ' ') + string(6, ' ') + " " + string(1, char(186)) + "       rear" + string(1, char(187)) + string(1, char(186)) + " " + string(1, char(179)) + string(2, ' ') + string(6, ' ') + " " + string(1, char(186));
    cout << "\n\t" + string(70, ' ') + string(1, char(186)) + string(1, char(195)) + string(6, char(196)) + string(1, char(180)) + " " + string(12, ' ') + string(1, char(186)) + string(1, char(195)) + string(6, char(196)) + string(1, char(180));

    // Vector section
    red;
    cout << "\n\t" + string(8, ' ') + string(1, char(218)) + string(6, char(196)) + string(1, char(194)) + string(6, char(196)) + string(1, char(194)) + string(6, char(196)) + string(1, char(191)) + "      ";
    yellow;
    cout << string(1, char(218)) + string(6, char(196)) + string(1, char(194)) + string(6, char(196)) + string(1, char(194)) + string(6, char(196)) + string(1, char(191)) + "        ";
    blue;
    cout << string(1, char(186)) + " " + string(1, char(179)) + " " + string(2, ' ') + string(6, ' ') + " " + string(1, char(186)) + "            " + string(1, char(179)) + " " + string(2, ' ') + string(6, ' ') + " " + string(1, char(186));
    cout << "\n\t" + string(8, ' ') + string(1, char(179)) + " ";
    res; cout << "-13/24"; red; cout << " " + string(1, char(179)) + " " + string(1, char(179)) + " " + string(1, ' ') + "  3/94" + string(1, char(179)) + " " + string(1, char(179)) + " " + string(1, ' ') + "-25/36" + string(1, char(179)) + "    ";
    yellow;
    cout << string(1, char(195)) + string(6, char(196)) + string(1, char(194)) + string(6, char(196)) + string(1, char(194)) + string(6, char(196)) + string(1, char(180)) + "        ";
    blue;
    cout << string(1, char(186)) + " " + string(1, char(179)) + " " + string(2, ' ') + string(6, ' ') + " " + string(1, char(186)) + "            " + string(1, char(179)) + " " + string(2, ' ') + string(6, ' ') + " " + string(1, char(186));
    cout << "\n\t" + string(8, ' ') + string(1, char(192)) + string(6, char(196)) + string(1, char(193)) + string(6, char(196)) + string(1, char(193)) + string(6, char(196)) + string(1, char(217)) + "    ";
    yellow;
    cout << string(1, char(179)) + " " + string(2, ' ') + " " + string(1, char(179)) + " " + string(2, ' ') + string(1, char(179)) + "        ";
    blue;
    cout << string(1, char(186)) + " " + string(1, char(179)) + " " + string(2, ' ') + string(6, ' ') + " " + string(1, char(186)) + "            " + string(1, char(179)) + " " + string(2, ' ') + string(6, ' ') + " " + string(1, char(186));
    cout << "\n\t" + string(8, ' ') + " " + string(1, char(192)) + " " + string(2, ' ') + "0" + string(1, ' ') + string(2, ' ') + "1" + string(1, ' ') + string(2, ' ') + "2" + string(1, ' ') + string(6, ' ') + "           ";
    yellow;
    cout << string(1, char(179)) + " " + string(2, ' ') + string(6, ' ') + " " + string(1, char(179)) + "                                ";
    blue;
    cout << string(1, char(186)) + " " + string(1, char(179)) + " " + string(2, ' ') + string(6, ' ') + " " + string(1, char(186)) + "            " + string(1, char(179)) + " " + string(2, ' ') + string(6, ' ') + " " + string(1, char(186));
    cout << "\n\t" + string(70, ' ') + string(1, char(179)) + "            " + string(1, char(179)) + "   out    " + string(1, char(179));
    cout << "\n\t" + string(70, ' ') + string(1, char(192)) + string(6, char(196)) + string(1, char(193)) + string(6, char(196)) + string(1, char(217)) + " " + string(6, ' ') + string(1, char(192)) + string(6, char(196)) + string(1, char(217));

    res;
    cout << "\n\tA container is a holder object that stores a collection of other objects (its elements). They\n"
        << "\tare implemented as class templates, which allows great flexibility in the types supported as\n"
        << "\telements. The container manages the storage space for its elements and provides member functions\n"
        << "\tto access them, either directly or through iterators(reference objects with similar properties\n"
        << "\tto pointers).\n"
        << "\n\tCMPR121 Exam3: STL (Standard Template Library) Containers and Container Adaptors by Prof Q (5-13-2024)\n"
        << "\t" + string(90, char(205)) << "\n";

    red;
    cout << "\t\t\tV. Vector Container\n";
    yellow;
    cout << "\t\t\tL. List Container\n";
    blue;
    cout << "\t\t\tS. Stack (LIFO) Container Adaptor\n";
    green;
    cout << "\t\t\tQ. Queue (FIFO) Container Adaptor\n";
    res;
    cout << "\t" + string(90, char(196)) << "\n"
        << "\t\t\tX. Exit\n"
        << "\t" + string(90, char(205));
}


