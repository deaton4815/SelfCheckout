#include "PaymentMenu.h"

using namespace std;

void PaymentMenu::displayMenuHeader() const {
	cout << "\nPayment options:" << endl;
}

void PaymentMenu::displayMenuOptions() const {
	cout << "\nPayment options:" << endl;
	cout << "1 - Credit or debit" << endl;
	cout << "2 - Cash payment" << endl;

	cout << "\n0 - Return" << endl;
}