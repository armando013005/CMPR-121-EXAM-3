#include "Declarations.h"

static void displayContent(stack<Rational> rationals)
{
    if(rationals.empty())
        return;
    cout << "\t" << rationals.top() << "->";
    rationals.pop();
    return displayContent(rationals);
}

void displayStackMenu(const stack<Rational>& rationals) {

    cls();
    cout << "\n\tStacks are type of container adaptors with LIFO (Last In First Out) type of working, where a new\n"
        << "\telement is added (pushed) at one end (top) and an element is removed (popped) from that end (top)\n"
        << "\tonly. Stack uses an encapsulated object of either vector or deque (by default) or list (sequential\n"
        << "\tcontainer class) as its underlying container, providing a specific set of member functions to\n"
        << "\taccess its elements.\n";

    if (rationals.empty())
        cout << "\n\tThe current stack is empty.\n";
    else {
        cout << "\n\tThe current stack elements are (from top to bottom):\n";
        // Display stack elements
        displayContent(rationals);
    }

    blue;
    cout << "\n\n\t\t\tStack Menu Options\n";
    cout << "\t" + string(90, char(205)) << "\n";
    res;
    cout << "\t\t\t1. Push\n"
        << "\t\t\t2. Top\n"
        << "\t\t\t3. Pop\n";
    blue;
    cout << "\t" + string(90, char(196)) << "\n";
    res;
    cout << "\t\t\t0. Return\n";
    blue;
    cout << "\t" + string(90, char(205)) << "\n";
    res;
}

void stackMenu(stack<Rational>& rationals) {
    char option;
    do {
        displayStackMenu(rationals);
        option = inputChar("\n\tOption (1-3, 0): ");

        switch (toupper(option)) {
        case '1': {
            Rational temp;
            cin >> temp;
            
            rationals.push(temp);
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
        system("PAUSE");
    } while (option != '0');
}