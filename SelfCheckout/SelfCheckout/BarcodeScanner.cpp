#include "BarcodeScanner.h"

using namespace std;

void BarcodeScanner::scanItem(const int itemNumber) {
	m_scannedItems.addItem(m_itemInventory.getItem(itemNumber));
	//updateCartItemInfo();
	//updateCartPriceInfo();
} 

vector<unsigned int> BarcodeScanner::getScannedItemNumbers() {
	return m_scannedItems.getItemNumbers();
}

vector<string> BarcodeScanner::getScannedItemIDs() {
	return m_scannedItems.getItemIDs();
}

vector<string> BarcodeScanner::getScannedItemDescriptions() {
	return m_scannedItems.getItemDescriptions();
}

vector<float> BarcodeScanner::getScannedItemPrices() {
	return m_scannedItems.getItemPrices();
}

float BarcodeScanner::getSubtotal() {
	return m_scannedItems.getSubtotal();
}

/*
void BarcodeScanner::updateCartItemInfo() {
	updateScannedNumbers();
	updateScannedIDs();
	updateScannedDescriptions();
	updateScannedPrices();
}
void BarcodeScanner::updateCartPriceInfo() { updateSubtotal(); }

void BarcodeScanner::updateScannedNumbers() {
	m_scannedItemNumbers = m_scannedItems.getItemNumbers();
}
void BarcodeScanner::updateScannedIDs() {
	m_scannedItemIDs = m_scannedItems.getItemIDs();
}
void BarcodeScanner::updateScannedDescriptions() {
	m_scannedItemDescriptions = m_scannedItems.getItemDescriptions();
}
void BarcodeScanner::updateScannedPrices() {
	m_scannedItemPrices = m_scannedItems.getItemPrices();
}
void BarcodeScanner::updateSubtotal() {
	m_cartSubtotal = m_scannedItems.getSubtotal();
}
*/
/*
vector<unsigned int> BarcodeScanner::getScannedItemNumbers() {
	updateScannedNumbers();
	return m_scannedItemNumbers;
}
vector<string> BarcodeScanner::getScannedItemIDs() {
	updateScannedIDs();
 	return m_scannedItemIDs;
}
vector<string> BarcodeScanner::getScannedItemDescriptions() { 
	updateScannedDescriptions();
	return m_scannedItemDescriptions;
}
vector<float> BarcodeScanner::getScannedItemPrices() {
	updateScannedPrices();
	return m_scannedItemPrices;
}
float BarcodeScanner::getSubtotal() {
	updateSubtotal();
	return m_cartSubtotal;
}
*/
