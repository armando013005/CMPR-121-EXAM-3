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
        option = inputChar("\n\tChoose an option: ");
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
    cout << setw(76) << string(1, char(186)) << "  in / out    " << string(1, char(186)) << setw(12)  << string(1, char(186)) << "       in      " << string(1, char(186)) << endl;
    cout << setw(76) << string(1, char(186)) << " " << string(1, char(218)) << string(10, char(196)) << string(1, char(191)) << " " << string(1, char(186)) << setw(12) << string(1, char(186)) << " " << string(1, char(218)) << string(11, char(196)) << string(1, char(191)) << " " << string(1, char(186)) << endl;
    cout << setw(71) << " " << "top" << "»" << string(1, char(186)) << " " << string(1, char(179)) << setw(8) << "- 10 / 21 " << string(1, char(179)) << " " << string(1, char(186)) << setw(6) << " " << "rear" << "\u00BB" << string(1, char(186)) << " " << string(1, char(179)) << setw(8) << "- 57 / 61 " << " " << string(1, char(179)) << " " << string(1, char(186)) << endl;
    cout << setw(75) << " " << string(1, char(186)) << " " << string(1, char(195)) << string(5, char(196)) << string(1, char(196)) << string(4, char(196)) << string(1, char(180)) << " " << string(1, char(186)) << setw(11) << " " << string(1, char(186)) << " " << string(1, char(195)) << string(6, char(196)) << string(1, char(196)) << string(4, char(196)) << string(1, char(180)) << " " << string(1, char(186)) << endl;
    cout << setw(3) << string(1, char(218)) << string(8, char(196)) << string(1, char(194)) << string(6, char(196)) << string(1, char(194)) << string(8, char(196)) << string(1, char(191)) << setw(6) << string(1, char(218)) << string(9, char(196)) << string(1, char(179)) << " " << string(1, char(218)) << string(7, char(196)) << string(3, char(196)) << string(1, char(179)) << " " << string(1, char(218)) << string(7, char(196)) << string(1, char(196)) << string(1, char(196)) << string(1, char(196)) << string(1, char(186)) << setw(6) << string(1, char(186)) << " " << string(1, char(179)) << "- 31 / 41 " << string(1, char(179)) << " " << string(1, char(186)) << setw(11) << " " << string(1, char(186)) << " " << string(1, char(179)) << "  39 / 49  " << string(1, char(179)) << " " << string(1, char(186)) << endl;
    cout << setw(2) << " " << string(1, char(179)) << "- 13/24 " << string(1, char(179)) << " 3/94 " << string(1, char(179)) << "- 25/36 " << string(1, char(179)) << setw(5) << string(1, char(187)) << string(1, char(179)) << " 11 / 23 " << string(1, char(186)) << string(1, char(187)) << string(1, char(179)) << "- 23 / 41 " << string(1, char(186)) << string(1, char(187)) << string(1, char(179)) << "- 53 / 61 " << string(1, char(186)) << setw(6) << string(1, char(186)) << " " << string(1, char(195)) << string(10, char(196)) << string(1, char(180)) << " " << string(1, char(186)) << setw(12) << string(1, char(186)) << " " << string(1, char(195)) << string(11, char(196)) << string(1, char(180)) << " " << string(1, char(186)) << endl;
    cout << setw(3) << string(1, char(218)) << string(8, char(196)) << string(1, char(194)) << string(6, char(196)) << string(1, char(194)) << string(8, char(196)) << string(1, char(191)) << setw(6) << string(1, char(218)) << string(9, char(196)) << string(1, char(179)) << " " << string(1, char(218)) << string(7, char(196)) << string(3, char(196)) << string(1, char(179)) << " " << string(1, char(218)) << string(7, char(196)) << string(1, char(196)) << string(1, char(196)) << string(1, char(196)) << string(1, char(186)) << setw(6) << string(1, char(186)) << " " << string(1, char(179)) << "  73 / 61 " << string(1, char(179)) << " " << string(1, char(186)) << setw(11) << " " << string(1, char(186)) << " " << string(1, char(179)) << "- 71 / 72  " << string(1, char(179)) << " " << string(1, char(186)) << endl;
    cout << setw(3) << "0" << setw(9) << "1" << setw(7) << "2" << setw(18) << "head" << setw(39) ;
    res;
    cout << "\n\tVector" << setw(30) << "Linked List" << setw(40) << "Stack" << setw(30) << "Queue";
    cout << "\n\n\tA container is a holder object that stores a collection of other objects (its elements). They"
        << "\n\tare implemented as class templates, which allows great flexibility in the types supported as"
        << "\n\telements. The container manages the storage space for its elements and provides member functions"
        << "\n\tto access them, either directly or through iterators(reference objects with similar properties"
        << "\n\tto pointers)."
        << "\n\tCMPR121 Exam3 : STL(Standard Template Library) Containers and Container Adaptors by Armando, Chris, Duc, Thi"
        << "\n\t" + string(90, char(205)) << "\n";

    red;
    cout << "\n\tV. Vector Container\n";
    yellow;
    cout << "\n\tL. List Container\n";
    blue;
    cout << "\n\tS. Stack (LIFO) Container Adaptor\n";
    green;
    cout << "\n\tQ. Queue (FIFO) Container Adaptor\n";
    res;
    cout << "\n\t" + string(84, char(196)) << "\n"
        << "\n\tX. Exit\n"
        << "\n\t" + string(90, char(205)) << "\n";
}
