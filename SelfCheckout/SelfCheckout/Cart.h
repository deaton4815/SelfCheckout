#pragma once

#include <vector>

#include "Item.h"

using namespace std;

class Cart
{
public:

	void addItem(Item);

private:

	vector<Item> m_scannedItems;
	
};