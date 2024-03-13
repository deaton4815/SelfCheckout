#include "CustomerMenu.h"

using namespace std;

void CustomerMenu::displayMenuOptions() const {
	cout << "\n1 - Scan new item" << endl;
	cout << "2 - Remove previous item selection" << endl;
	cout << "3 - Pay" << endl;

	cout << "\n0 - Return" << endl;
}