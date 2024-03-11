#include "SelfCheckoutEngine.h"

//void SelfCheckoutEngine::executeUserSelection()

void SelfCheckoutEngine::executeItemSelection(const int itemNumber) {
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