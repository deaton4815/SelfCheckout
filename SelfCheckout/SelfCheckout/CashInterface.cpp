#include "CashInterface.h"

using namespace std;

// First cash prompt
float CashInterface::getCash() const {

	float cash{ 0.f };
	displayCashPaymentPrompt();

	cin >> cash;
	return cash;
}

// If first deposit is not enough
float CashInterface::getCash(const float existingCash) const {
	
	float cash{ 0.f };
	displayCashPaymentPrompt(existingCash);

	cin >> cash;
	return cash;
}

void CashInterface::displayChange(const float change) const {
	cout << "Change dispensed: $";
	displayTwoDecimalFloat(change);
	cout << endl;
}

// First prompt
void CashInterface::displayCashPaymentPrompt() const {
	cout << "\nPlease input cash amount entered: $";
}

// If first deposit is not enough
void CashInterface::displayCashPaymentPrompt(const float cash) const {
	cout << "\nYour short by $";
	displayTwoDecimalFloat(cash);
	cout << "! Please enter more cash: $";
}

void CashInterface::displayTwoDecimalFloat(const float value) const {
	cout << fixed << setprecision(2) << value;
}