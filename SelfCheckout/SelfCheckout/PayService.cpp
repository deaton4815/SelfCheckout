#include "PayService.h"

void PayService::updatePrice(float subtotal) {
	setSubtotal(subtotal);
	setTax(calculateTax());
	setTotal(calculateTotal());
}

float PayService::getSubtotal() { return m_subtotal; }
float PayService::getTax() { return m_tax; }
float PayService::getTotal() { return m_total; }

int PayService::payElectronic() {
	setAmountDue(m_total);
	int confirmationCode{ m_scoCreditCardTerminal.makePayment() };
	if (confirmationCode) {
		setAmountPaid(m_total);
		setAmountDue(0.f);
	}
	return confirmationCode;
}

float PayService::calculateTax() { return m_subtotal * m_taxRate; }
float PayService::calculateTotal() { return m_subtotal + m_tax; }

void PayService::setSubtotal(float subtotal) { m_subtotal = subtotal; }
void PayService::setTax(float tax) { m_tax = tax; }
void PayService::setTotal(float total) { m_total = total; }
void PayService::setAmountDue(float amount) { m_amountDue = amount; }
void PayService::setAmountPaid(float amount) { m_amountPaid = amount; }

float PayService::getAmountDue() { return m_amountDue; }
float PayService::getAmountPaid() { return m_amountPaid; }