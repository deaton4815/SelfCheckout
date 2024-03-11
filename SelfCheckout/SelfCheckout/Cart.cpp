#include "Cart.h"

using namespace std;

void Cart::addItem(const Item& item) {

	m_scannedItems.push_back(item);
	++m_countScannedItems;

	calculateSubtotal();
}

vector<unsigned int> Cart::getItemNumbers() {
	
	vector<unsigned int> itemNumbers(m_countScannedItems);

	for (size_t i{ 0 }; i < m_countScannedItems; ++i) {
		itemNumbers[i] = static_cast<unsigned int>(i) + 1;
	}
	return itemNumbers;
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

float Cart::getSubtotal() { return m_subtotal; }

void Cart::calculateSubtotal() {

	vector<float> itemPrices = getItemPrices();
	m_subtotal = accumulate(itemPrices.begin(), itemPrices.end(), 0.f);
}