#pragma once

#include <string>

using namespace std;

class Item
{

public:

	Item(string, string, float);

	string getProductID();
	string getProductDescription();
	float getUnitPrice();

private:

	string m_productID;
	string m_productDescription;
	float m_unitPrice;

};