#include "Declarations.h"


// made by Thi Truong
// VECTOR 

// Define a function to throw an out-of-range exception
void outOfRange(const string& errorMessage)
{
    throw errorMessage;
}

void vectorMenu(vector<Rational>& rationals)
{

    do
    {
        // Display the menu and current elements of vector
        displayVectorMenu(rationals);

        switch (inputInteger("\n\tOption: ", 0, 6))
        {
        case 1: // Add an element
        {
            try
            {
                cout << "\n\t\tInput a Rational number [numerator/denominator] to be added...";
                int num = inputInteger("\n\t\t\tEnter a value (-99...99) for the numerator  : ", -99, 99);
                int den = inputInteger("\t\t\tEnter a value (-99...99) for the denominator: ", -99, 99);

                rationals.push_back(Rational(num, den));

                cout << "\n\t\t"; displaySingle(rationals.back());  cout << " will be added to the back of the vector.\n\n";
            }
            catch (const exception& e)
            {
                cout << "\n\t\t" << e.what() << "\n";
            }

            break;
        }

        case 2: // Insert an element
        {
            try
            {
                Rational temp;
                /*cout << "\n\t\tInput a Rational number [numerator/denominator] to be inserted...";
                int num = inputInteger("\n\t\t\tEnter a value (-99...99) for the numerator  : ", -99, 99);
                int den = inputInteger("\t\t\tEnter a value (-99...99) for the denominator: ", -99, 99);*/

                cin >> temp;

                string promt = "\t\tInsert the Rational number at index (0..." + to_string(rationals.size() - 1) + ") of the vector: ";
                int pos = inputInteger(promt, 0, int(rationals.size() - 1));

                rationals.insert(rationals.begin() + pos, temp);

                cout << "\n\t\t";
                displaySingle(rationals[pos]);
                cout << " will be inserted at index " << pos << " to the vector.\n\n";
            }
            catch (const exception& e)
            {
                cout << "\n\t\t" << e.what() << "\n";
            }

            break;
        }
        case 3: // Retrieve an element
        {
            try
            {
                if (rationals.empty())
                    outOfRange("\n\tERROR: Retrieve operation cannot be performed from an empty vector.\n\n");

                int pos = inputInteger("\n\t\tEnter an index of the Rational number from the vector to be retrieved: ", -1, true);

                if (pos >= rationals.size())
                    outOfRange("\n\t\tEXCEPTIONAL ERROR: invalid vector subscript.\n\n");

                cout << "\n\t\t" << rationals[pos] << " is located at index(" << pos << ") from the vector.\n\n";

                cout << "\n\t\t" << &rationals[pos] << "\n\n";

            }
            catch (const string& error)
            {
                cout << error;
            }

            break;
        }
        case 4: // Erase an element
        {
            try
            {
                if (rationals.empty())
                    outOfRange("\n\tERROR: Erase operation cannot be performed from an empty vector.\n\n");

                cout << "\n\t\tInput a Rational number [numerator/denominator] to be removed...";

                int num = inputInteger("\n\t\t\tEnter a value (-99...99) for the numerator  : ", -99, 99);
                int den = inputInteger("\t\t\tEnter a value (-99...99) for the denominator: ", -99, 99);

                Rational objToBeRemoved(num, den);

                auto it = find(rationals.begin(), rationals.end(), objToBeRemoved);

                // checks whether the Rational object was found in the vector
                if (it != rationals.end())
                {
                    // Ask if user wants to remove only one or all of elements found
                    switch (toupper(inputChar("\n\t\tDo you want to remove (O-one or A-all) element(s): ", "OA")))
                    {
                    case 'O':
                    {
                        rationals.erase(it);
                        cout << "\n\t\t" << objToBeRemoved << " will be removed from the vector.\n\n";
                        break;
                    }
                    case 'A':
                    {
                        rationals.erase(remove(rationals.begin(), rationals.end(), objToBeRemoved), rationals.end());
                        cout << "\n\t\t" << objToBeRemoved << " will be removed from the vector.\n\n";
                        break;
                    }
                    }
                }
                else
                    cout << "\n\t\t" << objToBeRemoved << " cannot be found from the vector.\n\n";
            }

            catch (const string& error)
            {
                cout << error;
            }

            catch (const exception& e)
            {
                cout << "\n\t\t" << e.what() << "\n";
            }

            break;
        }
        case 5: // Sort the vector
        {
            try
            {
                if (rationals.empty())
                    outOfRange("\n\tERROR: Sort operation cannot be performed from an empty vector.\n\n");

                sort(rationals.begin(), rationals.end());

                cout << "\n\t\tThe vector of Rational numbers will be sorted in ascending order.\n\n";
            }
            catch (const string& error)
            {
                cout << error;
            }

            break;
        }
        case 6: // Clear all elements
        {
            try
            {
                if (rationals.empty())
                    outOfRange("\n\tERROR: Clear operation cannot be performed from an empty vector.\n\n");

                rationals.clear();

                cout << "\n\t\tThe vector will be cleared of all Rational elements.\n\t";
            }
            catch (const string& error)
            {
                cout << error;
            }

            break;
        }
        case 0:
        {
            return;
        }
        default:
            cout << "\n\tInvalid option. Please try again." << endl;
        }

        system("pause");

    } while (true);

}



// Precondition: a rational object, two integers holding index and size of the object
// Postcondition: display the value of rationals[index]
void displayElements(const vector<Rational>& rationals, int index, int size)
{
    if (index < size)
    {
        cout << setw(6) << right << rationals[index];
        displayElements(rationals, index + 1, size);
    }
}


void displayVectorMenu(const vector<Rational>& rationals)
{
    system("cls");

    cout << "\n\tVectors (array) are same as dynamic arrays with the ability to resize itself automatically\n"
        << "\twhen an element is inserted or deleted, that contains their storage being handled automatically\n"
        << "\tby the container. Vector elements are placed in contiguous storage so that they can be accessed\n"
        << "\tand traversed using iterators or indexes.\n";

    if (rationals.empty())
    {
        cout << "\n\tThe current vector is empty.\n";
    }
    else
    {
        cout << "\n\tThe current vector contains " << rationals.size() << " element(s):\n\n\t\t  ";

        displayElements(rationals, 0, rationals.size());

        cout << "\n\n\tIndex: ";

        for (int i = 0; i < rationals.size(); i++)
        {
            cout << setw(9) << right << i;
        }

        cout << "\n\n\tstarting address: " << &rationals[0];
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
