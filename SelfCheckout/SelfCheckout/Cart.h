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

	vector<unsigned int> getItemNumbers();
	vector<string> getItemIDs();
	vector<string> getItemDescriptions();
	vector<float> getItemPrices();
	float getSubtotal();

private:

	vector<Item> m_scannedItems;

	size_t m_countScannedItems{ 0 };
	float m_subtotal{ 0.f };

	void calculateSubtotal();

};