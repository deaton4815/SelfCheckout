#include "SelectionMenu.h"

using namespace std;

int SelectionMenu::getMenuSelection() {
	displayMenuHeader();
	displayMenuOptions();
	displayInputPrompt();
	int selection{ getUserInput() };
	return selection;
}

void SelectionMenu::displayMenuHeader() const {
	cout << "\nPlease choose one of the following options:" << endl;
}

void SelectionMenu::displayInputPrompt() const {
	cout << "\nEnter selection number: ";
}

int SelectionMenu::getUserInput() {
	int selection{ 0 };
	cin >> selection;
}

void SelectionMenu::setSelection(int input) { m_selection = input; }