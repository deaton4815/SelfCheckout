/*
Class stores all item objects that have been scanned
*/
#pragma once

#include <vector>
#include <string>
#include <numeric>

#include "Item.h"

using namespace std;

class Cart
{
public:

	void addItem(const Item&);
	void removeItem();
	void resetCart();

	vector<unsigned int> getItemNumbers() const;
	vector<string> getItemIDs() const;
	vector<string> getItemDescriptions() const;
	vector<float> getItemPrices() const;
	float getSubtotal() const;

private:

	vector<Item> m_scannedItems;

	size_t m_countScannedItems{ 0 };
	float m_subtotal{ 0.f };

	void calculateSubtotal();

};