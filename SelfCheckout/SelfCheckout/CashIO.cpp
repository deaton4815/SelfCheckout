#include "CashIO.h"

using namespace std;

// First cash prompt
float CashIO::getCash() const {

	float cash{ 0.f };
	displayCashPaymentPrompt();

	cin >> cash;
	return cash;
}

// If first deposit is not enough
float CashIO::getCash(const float existingCash) const {
	
	float cash{ 0.f };
	displayCashPaymentPrompt(existingCash);

	cin >> cash;
	return cash;
}

void CashIO::displayChange(const float change) const {
	cout << "Change dispensed: $";
	displayTwoDecimalFloat(change);
	cout << endl;
}

// First prompt
void CashIO::displayCashPaymentPrompt() const {
	cout << "\nPlease input cash amount entered: $";
}

// If first deposit is not enough
void CashIO::displayCashPaymentPrompt(const float cash) const {
	cout << "\nYour short by $";
	displayTwoDecimalFloat(cash);
	cout << "! Please enter more cash: $";
}

void CashIO::displayTwoDecimalFloat(const float value) const {
	cout << fixed << setprecision(2) << value;
}