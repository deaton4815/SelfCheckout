#include "PayService.h"

void PayService::updatePrice(float subtotal) {
	setSubtotal(subtotal);
	setTax(calculateTax());
	setTotal(calculateTotal());
}

float PayService::getTax() { return m_tax; }
float PayService::getTotal() { return m_total; }

float PayService::calculateTax() { return m_subtotal * m_taxRate; }
float PayService::calculateTotal() { return m_subtotal + m_tax; }

void PayService::setSubtotal(float subtotal) { m_subtotal = subtotal; }
void PayService::setTax(float tax) { m_tax = tax; }
void PayService::setTotal(float total) { m_total = total; }