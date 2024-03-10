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

private:

	vector<Item> m_scannedItems;
	
};