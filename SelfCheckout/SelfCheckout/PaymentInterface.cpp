#include "PaymentInterface.h"

int PaymentInterface::getPaymentSelection
	(const float subtotal, const float tax, const float total) {
	
	cout << "\nAmount due:" << endl;
	displayFullPrice(subtotal, tax, total);

	return m_paymentType.getMenuSelection();
}

void PaymentInterface::printReceipt(const vector<unsigned int>& numbers,
	const vector<string>& ids, const vector<string>& descriptions,
	const vector<float>& prices,
	const float subtotal, const float tax, const float total,
	const float due, const float paid, const int code) const {

	printReceiptHeader();
	m_cart.displayCart(numbers, ids, descriptions, prices);
	displayFullPrice(subtotal, tax, total);
	cout << endl;
	displayPayment(due, paid, code);
	m_cart.displayLine();
	cout << endl;
}

void PaymentInterface::printReceipt(const vector<unsigned int>& numbers,
	const vector<string>& ids, const vector<string>& descriptions,
	const vector<float>& prices,
	const float subtotal, const float tax, const float total,
	const float due, const float paid, const float change) const {

	printReceiptHeader();
	m_cart.displayCart(numbers, ids, descriptions, prices);
	displayFullPrice(subtotal, tax, total);
	cout << endl;
	displayPayment(due, paid, change);
	m_cart.displayLine();
	cout << endl;
}

void PaymentInterface::displayFullPrice
	(const float subtotal, const float tax, const float total) const {
	displaySubtotal(subtotal);
	displayTax(tax);
	displayTotal(total);
}

void PaymentInterface::displaySubtotal(const float subtotal) const {
	displayValue("Subtotal: $", subtotal);
}

float PaymentInterface::getCash() const { return m_cash.getCash(); }
float PaymentInterface::getCash(float existingCash) const {
	return m_cash.getCash(existingCash);
}

void PaymentInterface::displayPayment
	(const float due, const float paid, const int code) const {
	displayDue(due);
	displayPaid(paid);
	displayCode(code);
}

void PaymentInterface::displayPayment
	(const float due, const float paid, const float change) const {
	displayDue(due);
	displayPaid(paid);
	displayChange(change);
}

void PaymentInterface::printReceiptHeader() const {
	cout << endl;
	cout << "Please take your receipt:" << endl;
	m_cart.displayLine();
}

void PaymentInterface::displayTax(const float tax) const { displayValue("Tax:      $", tax); }
void PaymentInterface::displayTotal(const float total) const { displayValue("Total:    $", total); }
void PaymentInterface::displayDue(const float due) const { displayValue("Due:      $", due); }
void PaymentInterface::displayPaid(const float paid) const { displayValue("Paid:     $", paid); }

void PaymentInterface::displayCode(const int code) const { m_card.displayCardConfirmation(code); }
void PaymentInterface::displayChange(const float change) const { m_cash.displayChange(change); }

void PaymentInterface::displayValue(const string& caption, const float value) const {
	cout << caption;
	displayTwoDecimalFloat(value);
	cout << endl;
}
void PaymentInterface::displayValue(const string& caption, const int value) const {
	cout << caption << value << endl;
}

void PaymentInterface::displayTwoDecimalFloat(const float value) const {
	cout << fixed << setprecision(2) << value;
}