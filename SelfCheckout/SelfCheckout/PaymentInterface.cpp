#include "PaymentInterface.h"

int PaymentInterface::getPaymentSelection(float subtotal, float tax, float total) {
	displayFullPrice(subtotal, tax, total);
	return m_paymentType.getMenuSelection();
}

void PaymentInterface::printReceipt(vector<unsigned int> numbers,
	vector<string> ids, vector<string> descriptions, vector<float> prices,
	float subtotal, float tax, float total, float due,
	float paid, int code) const {

	printReceiptHeader();
	m_cart.displayCart(numbers, ids, descriptions, prices);
	displayFullPrice;
	cout << endl;
	displayPayment(due, paid, code);
	m_cart.displayLine();
	cout << endl;
}

void PaymentInterface::printReceipt(vector<unsigned int> numbers,
	vector<string> ids, vector<string> descriptions, vector<float> prices,
	float subtotal, float tax, float total, float due,
	float paid, float change) const {

	printReceiptHeader();
	m_cart.displayCart(numbers, ids, descriptions, prices);
	displayFullPrice;
	cout << endl;
	displayPayment(due, paid, change);
	m_cart.displayLine();
	cout << endl;
}

void PaymentInterface::displaySubtotal(float subtotal) const {
	displayValue("Subtotal: $", subtotal);
}

void PaymentInterface::displayFullPrice(float subtotal, float tax, float total) const {
	displaySubtotal(subtotal);
	displayTax(tax);
	displayTotal(total);
}

void PaymentInterface::displayPayment(float due, float paid, int code) const {
	displayDue(due);
	displayPaid(paid);
	displayCode(code);
}

void PaymentInterface::displayPayment(float due, float paid, float change) const {
	displayDue(due);
	displayPaid(paid);
	displayChange(change);
}

void PaymentInterface::printReceiptHeader() const {
	cout << endl;
	cout << "Please take your receipt:" << endl;
	m_cart.displayLine();
}

void PaymentInterface::displayTax(float tax) const { displayValue("Tax:      $", tax); }
void PaymentInterface::displayTotal(float total) const { displayValue("Total:    $", total); }
void PaymentInterface::displayDue(float due) const { displayValue("Due:      $", due); }
void PaymentInterface::displayPaid(float paid) const { displayValue("Paid:     $", paid); }
void PaymentInterface::displayCode(int code) const { displayValue("Confirmation code: ", code); }
void PaymentInterface::displayChange(float change) const { displayValue("Change:   $", change); }

void PaymentInterface::displayValue(const string& caption, float value) const {
	cout << caption;
	displayTwoDecimalFloat(value);
	cout << endl;
}
void PaymentInterface::displayValue(const string& caption, int value) const {
	cout << caption << value << endl;
}

void PaymentInterface::displayTwoDecimalFloat(float value) const {
	cout << fixed << setprecision(2) << value;
}