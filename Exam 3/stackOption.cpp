#include "Declarations.h"

static void displayTopLines(int length)
{
    cout << "\t\t";

    cout << string(length * 10, char(205));
    cout << string(1, char(187));

    cout << '\n';
    cout << "\t\t";

    for (int i = 0; i < length; i++)
    {
        cout << char(218) << string(7, char(196)) << char(191);
        if (i == length - 1) { cout << ' ' << string(1, char(186)); }
        cout << " ";

    }
}

static void displayBottom(int length)
{
    cout << ' ' << string(1, char(186));//bottom line
    cout << "\n\t\t";

    for (int i = 0; i < length; i++)
    {
        cout << char(192) << string(7, char(196)) << char(217);//top line  └─┘
        if (i == length - 1) { cout << ' ' << string(1, char(186)); }//end line ║
        cout << " ";

    }
    cout << '\n';
    cout << "\t\t";

    cout << string(length * 10, char(205));//thick bottom line ═
    cout << string(1, char(188));//╝

}

static void displayContent(stack<Rational> rationals)
{
    if(rationals.empty())
        return;

    cout << " " << rationals.top();
    rationals.pop();

    return displayContent(rationals);
}

static void displaySingle(Rational r)
{
    cout << "\n\t";
	cout << char(218) << string(7, char(196)) << char(191)<<'\n';//top line
    cout <<'\t' << r << '\n';//rational
    cout <<'\t'<< char(192) << string(7, char(196)) << char(217) << '\n';//bottom line

}

void displayStackMenu(const stack<Rational>& rationals) {

    cls();
    cout << "\n\tStacks are type of container adaptors with LIFO (Last In First Out) type of working, where a new\n"
        << "\telement is added (pushed) at one end (top) and an element is removed (popped) from that end (top)\n"
        << "\tonly. Stack uses an encapsulated object of either vector or deque (by default) or list (sequential\n"
        << "\tcontainer class) as its underlying container, providing a specific set of member functions to\n"
        << "\taccess its elements.\n";

    int size = int(rationals.size());
    if (rationals.empty())
        cout << "\n\tThe current stack is empty.\n";
    else {
        cout << "\n\tThe current stack elements contains " + to_string(size) + " :\n\n";
        // Display stack elements
        displayTopLines(size);
        cout << "\n\ttop   " << string(1, char(175));
        displayContent(rationals);
        displayBottom(size);
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
    int option;
    do {
        displayStackMenu(rationals);
        option = inputInteger("\n\tOption: ");

        switch (toupper(option)) {
        case 1: {
            Rational temp;
            try
            {
                cin >> temp;
                rationals.push(temp);
            }
            catch (const exception& e)
            {
                cout <<"\n\t\t" << e.what();
            }
            break;
        }
        case 2: {
            if (rationals.empty()) { cout << "\n\tThe current stack is empty.\n"; return; }
            displaySingle(rationals.top());
            break;
        }
        case 3: {

            if (rationals.empty()) { cout << "\n\tThe current stack is empty.\n"; return; }
            rationals.pop();
            break;
        }
        case 0: {
            return;
        }
        default:
            cout << "\n\tInvalid option. Please try again." << endl;
        }
        cout << "\n";
        system("PAUSE");
    } while (option != '0');
}