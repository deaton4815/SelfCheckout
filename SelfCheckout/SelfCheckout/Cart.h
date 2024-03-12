#pragma once

#include <vector>
#include <string>
#include <numeric>

#include "Item.h"

using namespace std;

class Cart
{
public:

	vector<unsigned int> getItemNumbers();
	vector<string> getItemIDs();
	vector<string> getItemDescriptions();
	vector<float> getItemPrices();
	float getSubtotal();

	void addItem(const Item&);
	void resetCart();

private:

	vector<Item> m_scannedItems;

	size_t m_countScannedItems{ 0 };
	float m_subtotal{ 0.f };

	void calculateSubtotal();

};