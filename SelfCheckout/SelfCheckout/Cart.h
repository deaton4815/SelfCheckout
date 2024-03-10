#pragma once

#include <vector>
#include <string>

#include "Item.h"

using namespace std;

class Cart
{
public:

	void addItem(const Item&);

	vector<string> getItemIDs();
	vector<string> getItemDescriptions();
	vector<float> getItemPrices();

private:

	vector<Item> m_scannedItems;

	size_t m_countScannedItems{ 0 };

};