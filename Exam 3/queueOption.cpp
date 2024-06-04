#include "Declarations.h"

// Function to recursively display elements in the queue
void displayQueueElements(queue<Rational>& rationals) {
    if (rationals.empty()) {
        return;
    }
    auto rational = rationals.front();
    rationals.pop();
    cout << "│ " << setw(3) << rational.getNumerator() << "/" << setw(2) << rational.getDenominator() << "│";
    if (!rationals.empty()) {
        cout << " » ";
    }
    displayQueueElements(rationals);
}

// Display the queue menu
void displayQueueMenu(queue<Rational> rationals) {
    cls();
    cout << "\n\tQueues are type of container adaptors that operate in a first in first out (FIFO) type of\n"
         << "\tarrangement. Elements are inserted/pushed (enqueued) at the rear and are removed/popped (dequeued)\n"
         << "\tfrom the front. Queues use an encapsulated object of deque or list (sequential container class)\n"
         << "\tas its underlying container, providing a specific set of member functions to access elements.\n";

    if (rationals.empty()) {
        cout << "\n\tThe current queue is empty.\n";
    } else {
        cout << "\n\tThe current queue contains " << rationals.size() << " element(s):\n";
        cout << "            " + string(8, char(205)) << "\n";
        cout << "            " + string(1, char(218)) + string(6, char(196)) + string(1, char(191)) << "\n";
        cout << " in(rear) » ";
        displayQueueElements(rationals);
        cout << " » out(front)";
        cout << "\n            " + string(1, char(192)) + string(6, char(196)) + string(1, char(217)) << "\n";
        cout << "            " + string(8, char(205)) << "\n";
    }

    green();
    cout << "\n\n\t\t\tQueue Menu Options\n";
    cout << "\t" + string(90, char(205)) << "\n";
    res();
    cout << "\t\t\t1. Enqueue (push into the rear)\n"
         << "\t\t\t2. Rear (back)\n"
         << "\t\t\t3. Front\n"
         << "\t\t\t4. Dequeue (pop from the front)\n";
    green();
    cout << "\t" + string(90, char(196)) << "\n";
    res();
    cout << "\t\t\t0. Return\n";
    green();
    cout << "\t" + string(90, char(205)) << "\n";
    res();
    cout << "\t\t\tOption: ";
}

// Enqueue a new element into the queue
void enqueue(queue<Rational>& rationals) {
    int num, denom;
    cout << "\n\t\tInput a Rational number [numerator/denominator] to be enqueued (pushed)...\n";
    cout << "\t\t\tEnter a value (-99...99) for the numerator  : ";
    cin >> num;
    cout << "\t\t\tEnter a value (-99...99) for the denominator: ";
    cin >> denom;

    rationals.push(Rational(num, denom));
    cout << "\n\t\t " + string(1, char(218)) + string(6, char(196)) + string(1, char(191)) << "\n";
    cout << "\t\t │ " << setw(3) << num << "/" << setw(2) << denom << " │ will be enqueued (pushed) onto the queue.\n";
    cout << "\t\t " + string(1, char(192)) + string(6, char(196)) + string(1, char(217)) << "\n";

    cout << "\nPress any key to continue . . .";
    cin.ignore();
    cin.get();
}

// Display the rear element of the queue
void displayRear(const queue<Rational>& rationals) {
    displayQueueMenu(rationals);
    if (rationals.empty()) {
        cout << "\nThe queue is empty.\n";
    } else {
        auto rational = rationals.back();
        cout << "\n\t\t " + string(1, char(218)) + string(6, char(196)) + string(1, char(191)) << "\n";
        cout << "\t\t │ " << setw(3) << rational.getNumerator() << "/" << setw(2) << rational.getDenominator() << " │ is at the back of the queue.\n";
        cout << "\t\t " + string(1, char(192)) + string(6, char(196)) + string(1, char(217)) << "\n";
    }
    cout << "\nPress any key to continue . . .";
    cin.ignore();
    cin.get();
}

// Display the front element of the queue
void displayFront(const queue<Rational>& rationals) {
    displayQueueMenu(rationals);
    if (rationals.empty()) {
        cout << "\nThe queue is empty.\n";
    } else {
        auto rational = rationals.front();
        cout << "\n\t\t " + string(1, char(218)) + string(6, char(196)) + string(1, char(191)) << "\n";
        cout << "\t\t │ " << setw(3) << rational.getNumerator() << "/" << setw(2) << rational.getDenominator() << " │ is at the front of the queue.\n";
        cout << "\t\t " + string(1, char(192)) + string(6, char(196)) + string(1, char(217)) << "\n";
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
    } else {
        auto rational = rationals.front();
        rationals.pop();
        cout << "\n\t\t " + string(1, char(218)) + string(6, char(196)) + string(1, char(191)) << "\n";
        cout << "\t\t │ " << setw(3) << rational.getNumerator() << "/" << setw(2) << rational.getDenominator() << " │ will be dequeued (popped) from the queue.\n";
        cout << "\t\t " + string(1, char(192)) + string(6, char(196)) + string(1, char(217)) << "\n";
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
