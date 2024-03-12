#include "SelfCheckoutEngine.h"

SelfCheckoutEngine::SelfCheckoutEngine() {
	executeSCO();
}

void SelfCheckoutEngine::executeSCO() {

	int portalSelection{ 0 };
	do {
		portalSelection = getPortalSelection();
		executePortalSelection(portalSelection);

		m_scoScanner.resetCart();

	} while (portalSelection != 0);
}

int SelfCheckoutEngine::getPortalSelection() {
	int portalSelection{ 0 };
	do {
		portalSelection = m_scoUserInterface.getPortalSelection();
	} while ((portalSelection < 0) || (portalSelection > 2));
	return portalSelection;
}

void SelfCheckoutEngine::executePortalSelection(int selection) {
	switch (selection) {
	case 1:
		executeCustomerSelection();
		break;
	case 2:
		executeEmployeeSelection();
		break;
	default:
		break;
	}
}

void SelfCheckoutEngine::executeCustomerSelection() {
	int customerSelection{ 0 };
	do {
		customerSelection = m_scoUserInterface.getCustomerSelection();
		switch (customerSelection) {
		case 1:
			executeItemSelection();
			break;
		case 2:
			//Remove item
		case 3:
			executePayment();
			customerSelection = 0;
			break;
		default:
			break;
		}
	} while (customerSelection != 0);
}

void SelfCheckoutEngine::executeEmployeeSelection() {
	int employeeSelection{ 0 };
	do {
		employeeSelection = m_scoUserInterface.getEmployeeSelection();
		switch (employeeSelection) {
		case 1:
			emptyCashPurchases();
			break;
		default:
			break;
		}
	} while (employeeSelection != 0);
}

void SelfCheckoutEngine::executeItemSelection() {

	int itemNumber{ 0 };
	do {
		itemNumber = m_scoUserInterface.getItemSelection();
	} while ((itemNumber < 1) || (itemNumber > 12));
	
	--itemNumber;
	scanItem(itemNumber);
	updatePrice();
	displayCart();
}

void SelfCheckoutEngine::executePayment() {
	displayFullPrice();
	int paymentType{ 0 };
	do {
		paymentType = m_scoUserInterface.getPaymentOption();
	} while ((paymentType < 0) || (paymentType > 2));

	switch (paymentType) {
	case 1:
		executeCardPayment();
		break;
	case 2:
		executeCashPayment();
		break;
	default:
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

void SelfCheckoutEngine::displayFullPrice() {
	m_scoUserInterface.displayFullPrice(m_scoPayService.getSubtotal(),
		m_scoPayService.getTax(), m_scoPayService.getTotal());
}

void SelfCheckoutEngine::executeCardPayment() {
	int confirmationCode = m_scoPayService.payElectronic();

	printCardReceipt(confirmationCode);

}

void SelfCheckoutEngine::executeCashPayment() {

	bool isEnough{ false };
	bool isFirst{ true };
	do {
		isEnough = m_scoPayService.payCash(m_scoUserInterface.getCash(isFirst));
		isFirst = false;
	} while (!isEnough);

	printCashReceipt();
}

void SelfCheckoutEngine::printCardReceipt(int confirmationCode) {
	m_scoUserInterface.displayReceiptHeader();
	displayCart();
	m_scoUserInterface.displayReceiptFooter();

	m_scoUserInterface.displayCardPayment(confirmationCode,
		m_scoPayService.getAmountPaid(), m_scoPayService.getAmountDue());
	m_scoUserInterface.displayReceiptFooter();
}

void SelfCheckoutEngine::printCashReceipt() {
	m_scoUserInterface.displayReceiptHeader();
	displayCart();
	m_scoUserInterface.displayReceiptFooter();

	m_scoUserInterface.displayCashPayment(m_scoPayService.getAmountPaid(),
		m_scoPayService.getAmountDue(), m_scoPayService.getChange());
	m_scoUserInterface.displayReceiptFooter();

}

void SelfCheckoutEngine::emptyCashPurchases() {
	float cashPurchases{ m_scoPayService.emptyCashPurchases() };
	m_scoUserInterface.emptyCashPurchasesDisplay(cashPurchases);
}