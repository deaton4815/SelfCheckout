#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "PortalMenu.h"
#include "CustomerMenu.h"
#include "EmployeeMenu.h"
#include "ItemMenu.h"

#include "CartInterface.h"
#include "PaymentInterface.h"
#include "CashRepositoryInterface.h"

using namespace std;

class UserInterface
{
public:

	int getPortalSelection();

	int getCustomerSelection();
	int getEmployeeSelection();

	int scanItem();

	void displayCart(const vector<unsigned int>&, const vector<string>&,
		const vector<string>&, const vector<float>&, const float) const;

	int getPaymentType(const float, const float, const float);
	void printReceipt(const vector<unsigned int>&, const vector<string>&,
		const vector<string>&, const vector<float>&,
		const float, const float, const float,
		const float, const float, const int) const;
	void printReceipt(const vector<unsigned int>&, const vector<string>&,
		const vector<string>&, const vector<float>&,
		const float, const float, const float,
		const float, const float, const float) const;

	float getCash() const;
	float getCash(float) const;
	void emptyCashPurchases(const float) const;

private:

	PortalMenu m_portal;
	CustomerMenu m_customerPortal;
	EmployeeMenu m_employeePortal;
	ItemMenu m_availableItems;

	CartInterface m_cart;
	PaymentInterface m_payment;
	CashRepositoryInterface m_cashPurchases;
};