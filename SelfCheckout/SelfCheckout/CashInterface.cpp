#include "CashInterface.h"

using namespace std;

float CashInterface::getCash() const {

	float cash{ 0.f };
	displayCashPaymentPrompt();

	cin >> cash;
	return cash;
}

float CashInterface::getCash(float) const {
	
	float cash{ 0.f };
	displayCashPaymentPrompt(cash);

	cin >> cash;
	return cash;
}

void CashInterface::displayChange(float change) const {
	cout << "Change dispensed: $";
	displayTwoDecimalFloat(change);
	cout << endl;
}

void CashInterface::displayCashPaymentPrompt() const {
	cout << "\nPlease input cash amount entered: $";
}

void CashInterface::displayCashPaymentPrompt(float cash) const {
	cout << "\nYour short by $";
	displayTwoDecimalFloat(cash);
	cout << "! Please enter more cash: $";
}

void CashInterface::displayTwoDecimalFloat(float value) const {
	cout << fixed << setprecision(2) << value;
}