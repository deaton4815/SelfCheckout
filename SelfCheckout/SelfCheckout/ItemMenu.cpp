#include "ItemMenu.h"

using namespace std;

void ItemMenu::displayMenuHeader() const {
	cout << "\nAvailable Items" << endl;
}

void ItemMenu::displayMenuOptions() const {
	cout << "\n1 - Meat01" << endl;
	cout << "2 - Meat02" << endl;
	cout << "3 - Icecream01" << endl;
	cout << "4 - Icecream02" << endl;
	cout << "5 - Corn01" << endl;
	cout << "6 - Casewater01" << endl;
	cout << "7 - Potatochips01" << endl;
	cout << "8 - Potatochips02" << endl;
	cout << "9 - Donuts01" << endl;
	cout << "10 - Sausage01" << endl;
	cout << "11 - Eggs01" << endl;
	cout << "12 - Milk01" << endl;
}

void ItemMenu::displayInputPrompt() const {
	cout << "\nEnter item number: ";
}