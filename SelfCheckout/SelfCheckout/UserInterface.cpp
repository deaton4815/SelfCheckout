#include "UserInterface.h"

using namespace std;

/*
UserInterface::UserInterface() {
	displayOpeningMessage();
}
*/

void UserInterface::displayOpeningMessage() {
	cout << "Hello and welcome to self-checkout!" << endl;
}

int UserInterface::getActionSelection() {

	displayActionPrompt();
	displayAvailableActions();
	int selection{ getUserSelection() };
}

int UserInterface::getItemSelection() {
	displayAvailableItems();
	int itemSelection{ getUserSelection() };
	return itemSelection;
}

void UserInterface::displayActionPrompt() {
	cout << "Please choose one of the following options.\n";
	cout << "Enter the number that corresponds with your selection." << endl;
}

void UserInterface::displayAvailableActions() {
	cout << "1 - Scan new item." << endl;
}

void UserInterface::displayAvailableItems() {
	cout << "Available Items:" << endl;
	cout << "Enter the number that corresponds with your selection." << endl;
	cout << "1 - Meat01" << endl;
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

int UserInterface::getUserSelection() {
	int selection{ 0 };
	cin >> selection;
	return selection;
}