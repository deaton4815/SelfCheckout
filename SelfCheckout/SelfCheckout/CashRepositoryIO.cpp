#include "CashRepositoryIO.h"

using namespace std;

void CashRepositoryIO::emptyCashPurchasesDisplay(const float cash) const {
	cout << "\nEmptying cash repository...Checkout Service Paused." << endl;

	int startButton{ 0 };
	do {
		cout << "\nEnter 1 to resume service: ";
		cin >> startButton;
	} while (startButton != 1);

	cout << "Cash dispensed: $";
	displayTwoDecimalFloat(cash);
	cout << endl;
}

void CashRepositoryIO::displayTwoDecimalFloat(const float value) const {
	cout << fixed << setprecision(2) << value;
}