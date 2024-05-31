#include "Declarations.h"

void vectorMenu(vector<Rational>& rationals) {
    char option;
    do {
        displayVectorMenu(rationals);
        option = inputChar("\t\t option (1-6, 0): ");

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
        case '6': {
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

void displayVectorMenu(const vector<Rational>& rationals) {
    cls();
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

    red;
    cout << "\n\n\t\t\tVector (list array) Menu Options\n";
    cout << "\t" + string(90, char(205)) << "\n";
    res;
    cout << "\t\t\t1. Add an element\n"
        << "\t\t\t2. Insert an element at index\n"
        << "\t\t\t3. Retrieve an element from index\n"
        << "\t\t\t4. Erase element(s)\n"
        << "\t\t\t5. Sort the vector elements in ascending order\n"
        << "\t\t\t6. Clear all elements\n";
    red;
    cout << "\t" + string(90, char(196)) << "\n";
    res;
    cout << "\t\t\t0. Return\n";
    red;
    cout << "\t" + string(90, char(205)) << "\n";
    res;
}