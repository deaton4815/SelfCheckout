#include "BarcodeScanner.h"

using namespace std;

//Add item to cart form inventory
void BarcodeScanner::scanItem(const int itemNumber) {
	//m_scannedItems.addItem(m_itemInventory.getItem(itemNumber));
	m_scannedItems += m_itemInventory.getItem(itemNumber);
}

//Removes item most recently added to cart
void BarcodeScanner::removeItem() {
	m_scannedItems -= 1;
}

//Public getters of information in cart
vector<unsigned int> BarcodeScanner::getScannedItemNumbers() const {
	return m_scannedItems.getItemNumbers();
}
vector<string> BarcodeScanner::getScannedItemIDs() const {
	return m_scannedItems.getItemIDs();
}
vector<string> BarcodeScanner::getScannedItemDescriptions() const {
	return m_scannedItems.getItemDescriptions();
}
vector<float> BarcodeScanner::getScannedItemPrices() const {
	return m_scannedItems.getItemPrices();
}
float BarcodeScanner::getSubtotal() const {
	return m_scannedItems.getSubtotal();
}

//Empty the cart
void BarcodeScanner::resetCart() { m_scannedItems.resetCart(); }