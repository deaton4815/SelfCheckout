#include "BarcodeScanner.h"

using namespace std;

void BarcodeScanner::scanItem(const int itemNumber) {
	m_scannedItems.addItem(m_itemInventory.getItem(itemNumber));
	m_scannedItemCount += 1;
} 

vector<string> BarcodeScanner::getScannedItemIDs() {
	//string* itemIDs{ new string[m_scannedItemCount] };
	//ctor<string> = m_scannedItems.getItemIDs;
	//*itemIDs =  m_scannedItems.getItemIDs();
	//return *itemIDs;
	vector<string>itemIDs = m_scannedItems.getItemIDs();
	return itemIDs;
}