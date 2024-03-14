#include "CashRepositoryInterface.h"

using namespace std;

void CashRepositoryInterface::emptyCashPurchasesDisplay(const float cash) const {
	cout << "\nEmptying cash repository...Checkout Service Paused." << endl;
	cout << "Cash dispensed: $";
	displayTwoDecimalFloat(cash);
	cout << endl;

	int startButton{ 0 };
	do {
		cout << "\nEnter 1 to resume service:";
		cin >> startButton;
	} while (startButton != 1);
}

void CashRepositoryInterface::displayTwoDecimalFloat(const float value) const {
	cout << fixed << setprecision(2) << value;
}