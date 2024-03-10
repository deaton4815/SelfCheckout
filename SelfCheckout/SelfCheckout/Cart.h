#pragma once

#include <vector>

#include "Item.h"

using namespace std;

class Cart
{
public:

	void addItem(const Item&);

private:

	vector<Item> m_scannedItems;
	
};