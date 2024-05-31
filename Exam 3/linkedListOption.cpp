#include "Declarations.h"

void displayLinkedListMenu(const list<Rational>& rationals) {
    cls();
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

    yellow;
    cout << "\n\n\t\t\tLinked List Menu Options\n";
    cout << "\t" + string(90, char(205)) << "\n";
    res;
    cout << "\t\t\t1. Add (push) an element\n"
        << "\t\t\t2. Insert an element after\n"
        << "\t\t\t3. Remove element(s)\n"
        << "\t\t\t4. Sort the elements in ascending order\n"
        << "\t\t\t5. Clear all elements\n";
    yellow;
    cout << "\t" + string(90, char(196)) << "\n";
    res;
    cout << "\t\t\t0. Return\n";
    yellow;
    cout << "\t" + string(90, char(205)) << "\n";
    res;
}

void linkedListMenu(list<Rational>& rationals) {
    char option;
    do {
        displayLinkedListMenu(rationals);
        option = inputChar("\n\tOption (1-5, 0): ");

        switch (toupper(option)) {
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
        system("PAUSE");
    } while (option != '0');
}