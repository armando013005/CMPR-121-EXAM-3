#include "Declarations.h"

void displayQueueMenu(const queue<Rational>& rationals) {
    cls();
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

    green;
    cout << "\n\n\t\t\tQueue Menu Options\n";
    cout << "\t" + string(90, char(205)) << "\n";
    res;
    cout << "\t\t\t1. Enqueue (push into the rear)\n"
        << "\t\t\t2. Rear (back)\n"
        << "\t\t\t3. Front\n"
        << "\t\t\t4. Dequeue (pop from the front)\n";
    green;
    cout << "\t" + string(90, char(196)) << "\n";
    res;
    cout << "\t\t\t0. Return\n";
    green;
    cout << "\t" + string(90, char(205)) << "\n";
    res;
}

void queueMenu(queue<Rational>& rationals) {
    char option;
    do {
        displayQueueMenu(rationals);
        option = inputChar("\n\tChoose an option (1-4, 0): ");

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
        case '0': {
            return;
        }
        default:
            cout << "\n\tInvalid option. Please try again." << endl;
        }
        system("PAUSE");
    } while (option != '0');
}
