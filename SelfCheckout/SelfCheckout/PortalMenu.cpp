#include "PortalMenu.h"

using namespace std;

void PortalMenu::displayMenuHeader() const {
	displayOpeningMessage();
	cout << "Please choose one of the following options:" << endl;
}

void PortalMenu::displayMenuOptions() const {
	cout << "\n1 - Customer Portal" << endl;
	cout << "2 - Employee Portal" << endl;

	cout << "\n0 - Terminate Program" << endl;
}

void PortalMenu::displayOpeningMessage() const {
	cout << "\n\nWelcome to Self-Checkout!" << endl << endl;
}