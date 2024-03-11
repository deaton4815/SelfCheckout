#include "SelfCheckoutEngine.h"

SelfCheckoutEngine::SelfCheckoutEngine() {
	executeCustomerCheckout();
}

void SelfCheckoutEngine::executeCustomerCheckout() {

	m_scoUserInterface.displayOpeningMessage();

	int actionSelection{ 0 };
	do {
		actionSelection = m_scoUserInterface.getActionSelection();

		switch (actionSelection) {
		case 1:
			executeItemSelection();
			break;
		case 2:
			//Remove item
		case 3:
			executePayment();
		}
	} while (actionSelection != 0);
}

void SelfCheckoutEngine::executeItemSelection() {

	int itemNumber{ 0 };
	do {
		itemNumber = m_scoUserInterface.getItemSelection();
	} while ((itemNumber < 0) || (itemNumber > 12));
	
	--itemNumber;
	scanItem(itemNumber);
	updatePrice();
	displayCart();
}

void SelfCheckoutEngine::executePayment() {
	m_scoUserInterface.displayFullPrice(m_scoPayService.getSubtotal(),
		m_scoPayService.getTax(), m_scoPayService.getTotal());
	int paymentType{ 0 };
	do {
		paymentType = m_scoUserInterface.getPaymentOption();
	} while ((paymentType != 1) && (paymentType != 2));

	switch (paymentType) {
	case 1:
		executeCardPayment();
		break;
	case 2:
		executeCashPayment();
		break;
	}
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
		m_scoScanner.getScannedItemPrices(), m_scoPayService.getSubtotal());
}

void SelfCheckoutEngine::executeCardPayment() {
	int confirmationCode = m_scoPayService.payElectronic();

	m_scoUserInterface.displayCardPayment(confirmationCode,
		m_scoPayService.getAmountPaid(), m_scoPayService.getAmountDue());
}

void SelfCheckoutEngine::executeCashPayment() {

	bool isEnough{ false };
	bool isFirst{ true };
	do {
		isEnough = m_scoPayService.payCash(m_scoUserInterface.getCash(isFirst));
		isFirst = false;
	} while (!isEnough);
	m_scoUserInterface.displayCashPayment(m_scoPayService.getAmountPaid(),
		m_scoPayService.getAmountDue(), m_scoPayService.getChange());
}