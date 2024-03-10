#include "Cart.h"

using namespace std;

void Cart::addItem(const Item& item) { m_scannedItems.push_back(item); }

vector<string> Cart::getItemIDs() {
	size_t nScannedItems{ m_scannedItems.size() };
	//string* itemIDs{ new string[nScannedItems] };
	vector<string> itemIDs(nScannedItems);

	for (size_t i{ 0 }; i < nScannedItems; ++i) {
		itemIDs[i] = m_scannedItems[i].getProductID();
	}

	return itemIDs;

}