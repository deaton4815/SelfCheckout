#include "BarcodeScanner.h"
#include "Inventory.h"

#include <iostream>
#include<string>

int main() {

	BarcodeScanner scanner;
	//Inventory testInventory{ scanner.getInventory()};

	const int itemNumber{ 0 };
	//scanner.getItem();
	scanner.scanItem(itemNumber);

	/*
	scanner.scanItem(1);
	scanner.scanItem(2);
	scanner.scanItem(3);
	scanner.scanItem(4);
	scanner.scanItem(5);
	scanner.scanItem(6);
	scanner.scanItem(7);
	scanner.scanItem(8);
	scanner.scanItem(9);
	scanner.scanItem(10);
	scanner.scanItem(11);
	*/

}