#include "Inventory.h"
#include "Item.h"

#include <iostream>
#include<string>

int main() {

	Inventory testInventory;
	Item testItem{ testInventory.getMeat01() };

	cout << testItem.getProductDescription();

}