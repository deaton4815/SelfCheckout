#include "Cart.h"

using namespace std;

//Adds item to scanned items cart
void Cart::operator+=(Item newItem) {
	this->m_scannedItems.push_back(newItem);
	++this->m_countScannedItems;

	this->calculateSubtotal();
}

//Removes the most recent item from scanned items cart
void Cart::operator-=(int n) {
	n = 1;
	for (int i{ 0 }; i < n; i++) {
		this->m_scannedItems.pop_back();
	}
	--this->m_countScannedItems;
	this->calculateSubtotal();
}

//Empties the cart
void Cart::resetCart() {

	m_scannedItems.clear();
	m_countScannedItems = 0;
	m_subtotal = 0.f;

}

//Returns a vector containing the order that each item was scanned
vector<unsigned int> Cart::getItemNumbers() const {
	
	vector<unsigned int> itemNumbers(m_countScannedItems);

	for (size_t i{ 0 }; i < m_countScannedItems; ++i) {
		itemNumbers[i] = static_cast<unsigned int>(i) + 1;
	}
	return itemNumbers;
}

//Returns a vector containing the item IDs of all scanned items
//	in the order that the items were scanned
vector<string> Cart::getItemIDs() const {

	vector<string> itemIDs(m_countScannedItems);

	for (size_t i{ 0 }; i < m_countScannedItems; ++i) {
		itemIDs[i] = m_scannedItems[i].getProductID();
	}
	return itemIDs;
}

//Returns a vector containing the item descriptions of all scanned items
//	in the order that the items were scanned
vector<string> Cart::getItemDescriptions() const {

	vector<string> itemDescriptions(m_countScannedItems);

	for (size_t i{ 0 }; i < m_countScannedItems; ++i) {
		itemDescriptions[i] = m_scannedItems[i].getProductDescription();
	}
	return itemDescriptions;
}

//Returns a vector containing the item prices of all scanned items
//	in the order that the items were scanned
vector<float> Cart::getItemPrices() const {

	vector<float> itemPrices(m_countScannedItems);

	for (size_t i{ 0 }; i < m_countScannedItems; ++i) {
		itemPrices[i] = m_scannedItems[i].getUnitPrice();
	}
	return itemPrices;
}

float Cart::getSubtotal() const { return m_subtotal; }

//Calculates added price of all scanned items
void Cart::calculateSubtotal() {

	vector<float> itemPrices = getItemPrices();
	m_subtotal = accumulate(itemPrices.begin(), itemPrices.end(), 0.f);
}