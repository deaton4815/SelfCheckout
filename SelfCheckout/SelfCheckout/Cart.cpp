#include "Cart.h"

using namespace std;

void Cart::addItem(const Item& item) {

	m_scannedItems.push_back(item);
	++m_countScannedItems;

}

vector<string> Cart::getItemIDs() {

	vector<string> itemIDs(m_countScannedItems);

	for (size_t i{ 0 }; i < m_countScannedItems; ++i) {
		itemIDs[i] = m_scannedItems[i].getProductID();
	}
	return itemIDs;
}

vector<string> Cart::getItemDescriptions() {

	vector<string> itemDescriptions(m_countScannedItems);

	for (size_t i{ 0 }; i < m_countScannedItems; ++i) {
		itemDescriptions[i] = m_scannedItems[i].getProductDescription();
	}
	return itemDescriptions;
}

vector<float> Cart::getItemPrices() {

	vector<float> itemPrices(m_countScannedItems);

	for (size_t i{ 0 }; i < m_countScannedItems; ++i) {
		itemPrices[i] = m_scannedItems[i].getUnitPrice();
	}
	return itemPrices;
}