#include "Declarations.h"

void displayLinkedListMenu(list<Rational>& rlist) {
	Rational r;
	do
	{
		system("cls");

		cout << "\n\tLinked lists are sequence containers that allow non - contiguous memory allocation.As compared to";
		cout << "\n\tvector, the linked list has slow traversal, but once a position has been found, insertion and";
		cout << "\n\tdeletion are quicker.\n";
		if (rlist.size() == 0)
		{
			cout << "\n\tThe current list is empty";
		}
		else
		{
			cout << "\n\tThe current linked list contains " << rlist.size() << " elements\n\n";
			showList(rlist);
			auto headIterator = rlist.begin();
			Rational* headAddress = &(*headIterator);
			cout << "\n\tHeader: " << headAddress;
		}
		yellow;
		cout << "\n\n\n\tLinked List Menu Option: ";
		cout << "\n\t" << string(80, char(205));
		res;
		cout << "\n\t1. Add (push) an element";
		cout << "\n\t2. Insert an element";
		cout << "\n\t3. Remove element(s)";
		cout << "\n\t4. Sort the elements in ascending order";
		cout << "\n\t5. Clear all elements";
		yellow;
		cout << "\n\t" << string(80, char(196));
		res;
		cout << "\n\t0. Return";
		yellow;
		cout << "\n\t" << string(80, char(205));
		res;
		switch (inputInteger("\n\tOption: ", 0, 5))
		{
		case 0: return; break;
		case 1: addElement(r, rlist); break;
		case 2: insertElement(r, rlist); break;
		case 3: removeElement(r, rlist); break;
		case 4: sortElement(rlist); break;
		case 5: clearElement(rlist); break;

		}
		system("pause");
	} while (true);
}

void showListHelper(list<Rational>::iterator it, list<Rational>::iterator end)
{
	if (it == end)
	{
		cout << "\n";
		return;
	}
	cout << "\t" << *it;
	showListHelper(++it, end);
}

void showList(list<Rational>& rlist)
{
	showListHelper(rlist.begin(), rlist.end());
}

void addElement(Rational& r, list<Rational>& addList)
{
	try {
		cin >> r;
	}
	catch(const exception& e){
		cout << e.what();
		return;
	}

	if (addList.size() == 0)
	{
		addList.push_back(r);
		cout << "\n\t" << r << "\twill be added to the empty list\n";
	}
	else
	{
		switch (toupper(inputChar("\n\tEnter F to add to the front or B to add from the back: ", static_cast<string>("FB"))))
		{
		case 'F':
		{
			addList.push_front(r);
			cout << "\n\t" << r << "\twill be pushed to the front of the list\n";
			break;
		}
		case 'B':
		{
			addList.push_back(r);
			cout << "\n\t" << r << "\twill be pushed from the back of the list\n";
			break;
		}
		}
	}

}

void insertElement(Rational& r, list<Rational>& insertList)
{
	try {
		cin >> r;
	}
	catch (const exception& e) {
		cout << e.what();
		return;
	}

	if (insertList.size() == 0)
	{
		auto it = insertList.begin();
		advance(it, 0);
		insertList.insert(it, r);
		cout << "\n\t" << r << "\tis inserted into the list.\n";

	}
	else
	{
		Rational r2 = r;
		cin >> r;

		int position = 0;
		for (auto it = insertList.begin(); it != insertList.end(); it++)
		{
			if (*it == r)
			{
				break;
			}
			position++;
		}
		if (position < insertList.size())
		{
			switch (toupper(inputChar("\n\tInsert Before(B) or After(A): ", static_cast<string>("AB"))))
			{
			case'B':
			{
				auto it = insertList.begin();
				advance(it, position);
				insertList.insert(it, r2);
				cout << "\n\t" << r2 << "\t is inserted before the existing element in the current list.\n ";
				break;
			}
			case 'A':
			{
				auto it = insertList.begin();
				advance(it, position + 1);
				insertList.insert(it, r2);
				cout << "\n\t" << r2 << "\t is inserted after the existing element in the current list.\n ";

				break;
			}
			}
		}
		else
		{
			cout << "\n\t" << r << "\tCannot be found in the current list.\n";

		}
	}
}

void removeElement(Rational& r, list<Rational>& removeList)
{
	if (removeList.size() == 0)
	{
		cout << "\n\tERROR: There is no elements to be removed because the list is empty.\n";
		return;
	}
	else
	{
		try {
			cin >> r;
		}
		catch (const exception& e) {
			cout << e.what();
			return;
		}
		int position = 0;
		auto once = find(removeList.begin(), removeList.end(), r);
		for (auto it = removeList.begin(); it != removeList.end(); it++)
		{
			if (*it == r)
			{
				break;
			}
			position++;
		}
		if (position < removeList.size())
		{
			switch (toupper(inputChar("\n\tDelete All(A) or only once(O): ", static_cast<string>("AO"))))
			{
			case 'A':
			{
				removeList.remove(r);
				cout << "\n\tAll occurences of " << r << " \thas been removed from the current list.\n";
				break;
			}
			case 'O':
			{

				removeList.erase(once);
				cout << "\n\tOne occurence of " << r << "\t has been removed from the current list.\n";

				break;
			}
			}

		}
		else
		{
			cout << "\n\t" << r << "\tCannot be found in the current list.\n";

		}

	}
}

void sortElement(list<Rational>& sortList)
{
	if (sortList.size() == 0)
	{
		cout << "\n\tERROR. Sort operation cannot be perform due to an empty list.\n";
		return;
	}
	else
	{
		sortList.sort();
		cout << "\n\tThe list of Rational numbers has been sorted.\n";
	}
}

void clearElement(list<Rational>& clearList)
{
	if (clearList.size() == 0)
	{
		cout << "\n\tERROR. The list is empty.";
		return;
	}
	else
	{
		clearList.clear();
		cout << "\n\tThe list of Rational numbers has been cleared.\n";
	}

}