#include "SelfCheckoutMachine.h"

SelfCheckoutMachine::SelfCheckoutMachine() {
	executeSCO();
}

// Self checkout driver
void SelfCheckoutMachine::executeSCO() {

	int portalSelection{ 0 };
	do {
		portalSelection = getPortalSelection();//First selection screen.
		executePortal(portalSelection);//Executes either customer or employee portal

		// Resets cart and pay service
		m_scoScanner.resetCart();
		m_scoPayService.resetPayService();

		//Loops back to main selection screen until a zero is entered to terminate the program
	} while (portalSelection != 0);
}

// Prompts user for portal selection until either customer
// or employee portal is selected or program is terminated
int SelfCheckoutMachine::getPortalSelection() {
	int selection{ 0 };
	do {
		selection = m_scoUserInterface.getPortalSelection();
	} while ((selection < 0) || (selection > 2));
	return selection;
}

//Executes either customer or employee interface
// based on portal selection
void SelfCheckoutMachine::executePortal(int selection) {
	switch (selection) {
	case 1:
		executeCustomerPortal();
		break;
	case 2:
		executeEmployeePortal();
		break;
	default:
		break;
	}
}

/***************************** Customer Portal ******************************************/

// Executes customer action items:
//		1.) scan item, 2.) remove item, 3.) pay, 0.) return
void SelfCheckoutMachine::executeCustomerPortal() {

	int itemCount{ 0 };
	int customerSelection{ 0 };
	do {
		customerSelection = m_scoUserInterface.getCustomerSelection();
		switch (customerSelection) {
		case 1: // Add item
			scanItem();
			++itemCount;
			break;
		case 2: // Remove item
			if (itemCount > 0) {
				removeItem();
				--itemCount;
			}
			break;
		case 3: // Pay
			if (itemCount > 0) {
				pay();
				customerSelection = 0;
			}
			break;
		default:
			break;
		}
	} while (customerSelection != 0);
}

// Customer scans an item into the cart
void SelfCheckoutMachine::scanItem() {

	int itemNumber{ 0 }; // itemNumber acts as barcode number
	do {
		itemNumber = m_scoUserInterface.scanItem();
	} while ((itemNumber < 1) || (itemNumber > 12));

	--itemNumber; // Convert to 0 index

	m_scoScanner.scanItem(itemNumber); //Add item to cart
	m_scoPayService.updatePrice(m_scoScanner.getSubtotal());//Update pay service
	displayCart();//Display updated cart and subtotal
}

void SelfCheckoutMachine::removeItem() {
	m_scoScanner.removeItem(); // Remove item from cart
	m_scoPayService.updatePrice(m_scoScanner.getSubtotal()); //Update pay service
	displayCart(); //Display updated cart and subtotal
}

// User selects card or cash payment
void SelfCheckoutMachine::pay() {

	int paymentType{ 0 };
	do {
		paymentType = getPaymentType();
	} while ((paymentType < 0) || (paymentType > 2));

	switch (paymentType) {
	case 1:
		payCard();
		break;
	case 2:
		payCash();
		break;
	default:
		break;
	}
}

void SelfCheckoutMachine::displayCart() {
	m_scoUserInterface.displayCart(m_scoScanner.getScannedItemNumbers(),
		m_scoScanner.getScannedItemIDs(), m_scoScanner.getScannedItemDescriptions(),
		m_scoScanner.getScannedItemPrices(), m_scoPayService.getSubtotal());
}

// Gets user selection of cash or card payment
int SelfCheckoutMachine::getPaymentType() {
	return m_scoUserInterface.getPaymentType(m_scoPayService.getSubtotal(),
		m_scoPayService.getTax(), m_scoPayService.getTotal());
}

// Verifies successful card payment
void SelfCheckoutMachine::payCard() {
	int confirmationCode = m_scoPayService.payElectronic();
	printReceipt(confirmationCode);
}

void SelfCheckoutMachine::payCash() {

	float change{ m_scoPayService.payCash(m_scoUserInterface.getCash()) };
	while (change < 0.f) {
		change = m_scoPayService.payCash(m_scoUserInterface.getCash(-change));
	}
	printReceipt(change);
}

// Card receipt
void SelfCheckoutMachine::printReceipt(int code) {
	m_scoUserInterface.printReceipt(m_scoScanner.getScannedItemNumbers(),
		m_scoScanner.getScannedItemIDs(), m_scoScanner.getScannedItemDescriptions(),
		m_scoScanner.getScannedItemPrices(),
		m_scoPayService.getSubtotal(), m_scoPayService.getTax(), m_scoPayService.getTotal(),
		m_scoPayService.getAmountDue(), m_scoPayService.getAmountPaid(), code);
}

// Cash receipt
void SelfCheckoutMachine::printReceipt(float change) {
	m_scoUserInterface.printReceipt(m_scoScanner.getScannedItemNumbers(),
		m_scoScanner.getScannedItemIDs(), m_scoScanner.getScannedItemDescriptions(),
		m_scoScanner.getScannedItemPrices(),
		m_scoPayService.getSubtotal(), m_scoPayService.getTax(), m_scoPayService.getTotal(),
		m_scoPayService.getAmountDue(), m_scoPayService.getAmountPaid(), change);
}

/***************************** Employee Portal ******************************************/

void SelfCheckoutMachine::executeEmployeePortal() {
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

void SelfCheckoutMachine::emptyCashPurchases() {
	const float cashPurchases{ m_scoPayService.emptyCashPurchases() };
	m_scoUserInterface.emptyCashPurchases(cashPurchases);

}