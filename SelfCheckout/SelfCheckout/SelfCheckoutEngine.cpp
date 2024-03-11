#include "SelfCheckoutEngine.h"

SelfCheckoutEngine::SelfCheckoutEngine() {
	executeCustomerCheckout();
}

void SelfCheckoutEngine::executeCustomerCheckout() {

	m_scoUserInterface.displayOpeningMessage();

	int actionSelection{ 0 };

	//do
	actionSelection = m_scoUserInterface.getActionSelection();

	switch (actionSelection) {
	case 1:
		executeItemSelection();
		break;
	}

	//while
}

void SelfCheckoutEngine::executeItemSelection() {
	const int itemNumber{ m_scoUserInterface.getItemSelection() };
	scanItem(itemNumber);
	updatePrice();

	//updateCartInfo();
	//updatePrice();
}

void SelfCheckoutEngine::scanItem(const int itemNumber) {
	m_scoScanner.scanItem(itemNumber);
}

void SelfCheckoutEngine::updatePrice() {
	m_scoPayService.updatePrice(m_scoScanner.getSubtotal());
}

void SelfCheckoutEngine::displayCart() {
	m_scoUserInterface.displayCart(m_scoScanner.getScannedItemNumbers(),
		m_scoScanner.getScannedItemIDs(), m_scoScanner.getScannedItemDescriptions(),
		m_scoScanner.getScannedItemPrices(), m_scoPayService.getSubtotal(),
		m_scoPayService.getTax(), m_scoPayService.getTotal());
}
/*
void SelfCheckoutEngine::updatePrice() {
	updateSubtotal();
	m_scoPayService.updatePrice(m_subtotal);
	m_tax = m_scoPayService.getTax();
	m_total = m_scoPayService.getTotal();
}

void SelfCheckoutEngine::updateCartInfo() {
	m_itemNumbers = m_scoScanner.getScannedItemNumbers();
	m_itemIDs = m_scoScanner.getScannedItemIDs();
	m_itemDescriptions = m_scoScanner.getScannedItemDescriptions();
	m_itemPrices = m_scoScanner.getScannedItemPrices();
}

void SelfCheckoutEngine::updateSubtotal() {
	m_subtotal = m_scoScanner.getSubtotal();
}*/