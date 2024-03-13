#include "PayService.h"

//Makes electronic payment through credit card terminal
//and returns credit card confirmation code
int PayService::payElectronic() {
	setAmountDue(m_total);

	//Get confirmation code from credit card terminal
	int confirmationCode{ m_scoCreditCardTerminal.makePayment() };
	
	//Updates payment information if confirmation code received
	if (confirmationCode) {
		setAmountPaid(m_total);
		setAmountDue(0.f);
	}
	return confirmationCode;
}

//Executes cash payment
bool PayService::payCash(float cashPayment) {
	setAmountDue(m_total);

	//Cash payment is kept cumulatively in case more
	//deposits need to be made
	setAmountPaid(m_amountPaid + cashPayment);
	addCashPurchase(cashPayment);//Adds to cash repository

	//Funciton returns whether enough cash was deposited
	bool isEnough{ false };
	if (m_amountPaid > m_amountDue) {
		isEnough = true;
	}
	return isEnough;
}

//Gets change from change repository
float PayService::getChange() {
	float change{ m_scoChange.getChange(m_amountDue, m_amountPaid) };
	return change;
}

//Empties cash repository
float PayService::emptyCashPurchases() {
	return m_scoCashPurchase.emptyRepository();
}

//Calculates updated pricing
void PayService::updatePrice(float subtotal) {
	setSubtotal(subtotal);
	setTax(calculateTax());
	setTotal(calculateTotal());
}

//Public getters
float PayService::getSubtotal() const { return m_subtotal; }
float PayService::getTax() const { return m_tax; }
float PayService::getTotal() const { return m_total; }
float PayService::getAmountDue() const { return m_amountDue; }
float PayService::getAmountPaid() const { return m_amountPaid; }

//Resets all price and payment values to zero
void PayService::resetPayService() {
	setSubtotal(0);
	setTax(0);
	setTotal(0);
	setAmountDue(0);
	setAmountPaid(0);
}

//Deposits cash to cash repository
void PayService::addCashPurchase(float cashPayment) {
	m_scoCashPurchase.depositCash(cashPayment);
}

//Calculates tax and total
float PayService::calculateTax() const { return m_subtotal * m_taxRate; }
float PayService::calculateTotal() const { return m_subtotal + m_tax; }

//Private setters
void PayService::setSubtotal(float subtotal) { m_subtotal = subtotal; }
void PayService::setTax(float tax) { m_tax = tax; }
void PayService::setTotal(float total) { m_total = total; }
void PayService::setAmountDue(float amount) { m_amountDue = amount; }
void PayService::setAmountPaid(float amount) { m_amountPaid = amount; }