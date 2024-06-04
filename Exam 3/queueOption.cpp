#include "Declarations.h"

// Function to recursively display elements in the queue
void displayQueueElements(queue<Rational>& rationals) {
    if (rationals.empty()) {
        return;
    }
    auto rational = rationals.front();
    rationals.pop();
    cout << "│ " << setw(3) << rational.getNumerator() << "/" << setw(2) << rational.getDenominator() << " │";
    if (!rationals.empty()) {
        cout << " » ";
    }
    displayQueueElements(rationals);
}

// Display the queue menu
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
        cout << "\n\tThe current queue contains " << static_cast<int>(rationals.size()) << " element(s):\n";
        cout << "\n\t" + string(8, char(205)) << "\n";
        cout << "\n\t" + string(1, char(218)) + string(6, char(196)) + string(1, char(191)) << "\n";
        cout << " in(rear) » ";
        queue<Rational> tempQueue = rationals;
        displayQueueElements(tempQueue);
        cout << " » out(front)";
        cout << "\n\t" + string(1, char(192)) + string(6, char(196)) + string(1, char(217)) << "\n";
        cout << "\n\t" + string(8, char(205)) << "\n";
    }

    green;
    cout << "\n\tQueue Menu Options\n";
    cout << "\n\t" + string(90, char(205)) << "\n";
    res;
    cout << "\n\t1. Enqueue (push into the rear)\n"
        << "\n\t2. Rear (back)\n"
        << "\n\t3. Front\n"
        << "\n\t4. Dequeue (pop from the front)\n";
    green;
    cout << "\n\t" + string(90, char(196)) << "\n";
    res;
    cout << "\n\t0. Return\n";
    green;
    cout << "\n\t" + string(90, char(205)) << "\n";
    res;
    cout << "\n\tOption: ";
}

// Enqueue a new element into the queue
void enqueue(queue<Rational>& rationals) {
    Rational r;
    cin >> r; // Uses the overloaded >> operator from Rational.h

    rationals.push(r);
    cout << "\n\t " + string(1, char(218)) + string(6, char(196)) + string(1, char(191)) << "\n";
    cout << "\n\t " + string(1, char(179)) << " " << setw(3) << r.getNumerator() << "/" << setw(2) << r.getDenominator() << " " + string(1, char(179)) << " will be enqueued (pushed) onto the queue.\n";
    cout << "\n\t " + string(1, char(192)) + string(6, char(196)) + string(1, char(217)) << "\n";

    cout << "\nPress any key to continue . . .";
    cin.ignore();
    cin.get();
}

// Display the rear element of the queue
void displayRear(queue<Rational>& rationals) {
    displayQueueMenu(rationals);
    if (rationals.empty()) {
        cout << "\nThe queue is empty.\n";
    }
    else {
        auto rational = rationals.back();
        cout << "\n\t " + string(1, char(218)) + string(6, char(196)) + string(1, char(191)) << "\n";
        cout << "\n\t " + string(1, char(179)) << " " << setw(3) << rational.getNumerator() << "/" << setw(2) << rational.getDenominator() << " " + string(1, char(179)) << " is at the back of the queue.\n";
        cout << "\n\t " + string(1, char(192)) + string(6, char(196)) + string(1, char(217)) << "\n";
    }
    cout << "\nPress any key to continue . . .";
    cin.ignore();
    cin.get();
}

// Display the front element of the queue
void displayFront(queue<Rational>& rationals) {
    displayQueueMenu(rationals);
    if (rationals.empty()) {
        cout << "\nThe queue is empty.\n";
    }
    else {
        auto rational = rationals.front();
        cout << "\n\t " + string(1, char(218)) + string(6, char(196)) + string(1, char(191)) << "\n";
        cout << "\n\t " + string(1, char(179)) << " " << setw(3) << rational.getNumerator() << "/" << setw(2) << rational.getDenominator() << " " + string(1, char(179)) << " is at the front of the queue.\n";
        cout << "\n\t " + string(1, char(192)) + string(6, char(196)) + string(1, char(217)) << "\n";
    }
    cout << "\nPress any key to continue . . .";
    cin.ignore();
    cin.get();
}

// Dequeue the front element from the queue
void dequeue(queue<Rational>& rationals) {
    displayQueueMenu(rationals);
    if (rationals.empty()) {
        cout << "\nThe queue is empty. Nothing to dequeue.\n";
    }
    else {
        auto rational = rationals.front();
        rationals.pop();
        cout << "\n\t " + string(1, char(218)) + string(6, char(196)) + string(1, char(191)) << "\n";
        cout << "\n\t " + string(1, char(179)) << " " << setw(3) << rational.getNumerator() << "/" << setw(2) << rational.getDenominator() << " " + string(1, char(179)) << " will be dequeued (popped) from the queue.\n";
        cout << "\n\t " + string(1, char(192)) + string(6, char(196)) + string(1, char(217)) << "\n";
    }
    cout << "\nPress any key to continue . . .";
    cin.ignore();
    cin.get();
}

// Queue menu handling
void queueMenu(queue<Rational>& rationals) {
    char option;
    do {
        displayQueueMenu(rationals);
        option = inputChar("\n\tChoose an option (1-4, 0): ");

        switch (option) {
        case '1': {
            enqueue(rationals);
            break;
        }
        case '2': {
            displayRear(rationals);
            break;
        }
        case '3': {
            displayFront(rationals);
            break;
        }
        case '4': {
            dequeue(rationals);
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
