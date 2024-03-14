#include "PaymentInterface.h"

void PaymentInterface::displaySubtotal(float subtotal) {
	cout << "\nSubtotal: $";
	displayTwoDecimalFloat(subtotal);
	cout << endl;
}

int PaymentInterface::getPaymentSelection() {
	return m_menuInterface.getMenuSelection();
}

void PaymentInterface::printReceiptHeader() {
	cout << endl;
	cout << "Please take your receipt:" << endl;
	m_cart.displayLine();
}

void PaymentInterface::displayTwoDecimalFloat(float value) {
	cout << fixed << setprecision(2) << value;
}