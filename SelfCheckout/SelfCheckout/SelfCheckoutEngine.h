#pragma once

#include "BarcodeScanner.h"
#include "PayService.h"
#include "UserInterface.h"

class SelfCheckoutEngine
{
public:

	SelfCheckoutEngine();

private:
	//unsigned int getUserSelection();
	//void executeUserSelection();
	BarcodeScanner m_scoScanner;
	PayService m_scoPayService;
	UserInterface m_scoUserInterface;

	/*
	vector<unsigned int> m_itemNumbers;
	vector<string> m_itemIDs;
	vector<string> m_itemDescriptions;
	vector<float> m_itemPrices;

	float m_subtotal{ 0.f };
	float m_tax{ 0.f };
	float m_total{ 0.f };
	*/

	void executeCustomerCheckout();
	void executeItemSelection();
	void scanItem(const int);
	void updatePrice();
	void displayCart();

	/*
	void updateCartInfo();

	void updatePrice();
	void updateSubtotal();
	*/
};