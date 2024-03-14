#include "PaymentIO.h"

int PaymentIO::getPaymentSelection
	(const float subtotal, const float tax, const float total) {
	
	cout << "\nAmount due:" << endl;
	displayFullPrice(subtotal, tax, total);

	return m_paymentType.getMenuSelection();
}

void PaymentIO::displayCart(const vector<unsigned int>& numbers,
	const vector<string>& ids, const vector<string>& descriptions,
	const vector<float>& prices) const {
	m_cart.displayCart(numbers, ids, descriptions, prices);
}

void PaymentIO::printReceipt(const vector<unsigned int>& numbers,
	const vector<string>& ids, const vector<string>& descriptions,
	const vector<float>& prices,
	const float subtotal, const float tax, const float total,
	const float due, const float paid, const int code) const {

	printReceiptHeader();
	displayCart(numbers, ids, descriptions, prices);
	displayFullPrice(subtotal, tax, total);
	cout << endl;
	displayPayment(due, paid, code);
	m_cart.displayLine();
	cout << endl;
}

void PaymentIO::printReceipt(const vector<unsigned int>& numbers,
	const vector<string>& ids, const vector<string>& descriptions,
	const vector<float>& prices,
	const float subtotal, const float tax, const float total,
	const float due, const float paid, const float change) const {

	printReceiptHeader();
	displayCart(numbers, ids, descriptions, prices);
	displayFullPrice(subtotal, tax, total);
	cout << endl;
	displayPayment(due, paid, change);
	m_cart.displayLine();
	cout << endl;
}

void PaymentIO::displayFullPrice
	(const float subtotal, const float tax, const float total) const {
	displaySubtotal(subtotal);
	displayTax(tax);
	displayTotal(total);
}

void PaymentIO::displaySubtotal(const float subtotal) const {
	displayValue("Subtotal: $", subtotal);
}

float PaymentIO::getCash() const { return m_cash.getCash(); }
float PaymentIO::getCash(float existingCash) const {
	return m_cash.getCash(existingCash);
}

void PaymentIO::displayPayment
	(const float due, const float paid, const int code) const {
	displayPaid(paid);
	displayDue(due);
	displayCode(code);
}

void PaymentIO::displayPayment
	(const float due, const float paid, const float change) const {
	displayPaid(paid);
	displayDue(due);
	displayChange(change);
}

void PaymentIO::printReceiptHeader() const {
	cout << endl;
	cout << "Please take your receipt:" << endl;
	m_cart.displayLine();
}

void PaymentIO::displayTax(const float tax) const { displayValue("Tax:      $", tax); }
void PaymentIO::displayTotal(const float total) const { displayValue("Total:    $", total); }
void PaymentIO::displayDue(const float due) const { displayValue("Due:      $", due); }
void PaymentIO::displayPaid(const float paid) const { displayValue("Paid:     $", paid); }

void PaymentIO::displayCode(const int code) const { m_card.displayAuthorizationCode(code); }
void PaymentIO::displayChange(const float change) const { m_cash.displayChange(change); }

void PaymentIO::displayValue(const string& caption, const float value) const {
	cout << caption;
	displayTwoDecimalFloat(value);
	cout << endl;
}
void PaymentIO::displayValue(const string& caption, const int value) const {
	cout << caption << value << endl;
}

void PaymentIO::displayTwoDecimalFloat(const float value) const {
	cout << fixed << setprecision(2) << value;
}