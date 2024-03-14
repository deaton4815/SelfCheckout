#include "UserInterface.h"

using namespace std;

int UserInterface::getPortalSelection() { return m_portal.getMenuSelection(); }
int UserInterface::getCustomerSelection() { return m_customerPortal.getMenuSelection(); }
int UserInterface::getEmployeeSelection() { return m_employeePortal.getMenuSelection(); }
int UserInterface::scanItem() { return m_availableItems.getMenuSelection(); }

void UserInterface::displayCart(const vector<unsigned int>& itemNumbers,
	const vector<string>& itemIDs, const vector<string>& itemDescriptions,
	const vector<float>& itemPrices, const float subtotal) const {

	m_payment.displayCart(itemNumbers, itemIDs, itemDescriptions, itemPrices);
	m_payment.displaySubtotal(subtotal);
}

int UserInterface::getPaymentType(const float subtotal, const float tax, const float total) {
	return m_payment.getPaymentSelection(subtotal, tax, total);
}

void UserInterface::printReceipt(const vector<unsigned int>& numbers,
	const vector<string>& ids, const vector<string>& descriptions,
	const vector<float>& prices,
	const float subtotal, const float tax, const float total,
	const float due, const float paid, const int code) const {

	m_payment.printReceipt(numbers, ids, descriptions, prices,
		subtotal, tax, total, due, paid, code);
}
void UserInterface::printReceipt(const vector<unsigned int>& numbers,
	const vector<string>& ids, const vector<string>& descriptions,
	const vector<float>& prices,
	const float subtotal, const float tax, const float total,
	const float due, const float paid, const float change) const {

	m_payment.printReceipt(numbers, ids, descriptions, prices,
		subtotal, tax, total, due, paid, change);
}

float UserInterface::getCash() const { return m_payment.getCash(); }
float UserInterface::getCash(float existingCash) const {
	return m_payment.getCash(existingCash);
}

void UserInterface::emptyCashPurchases(const float cash) const{
	m_cashPurchases.emptyCashPurchasesDisplay(cash);
}
