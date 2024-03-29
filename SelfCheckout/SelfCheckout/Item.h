/*
Class holds information of an individual item
*/

#pragma once

#include <string>

using namespace std;

class Item
{

public:

	Item(const string, const string, const float);

	Item(const Item&);

	string getProductID() const;
	string getProductDescription() const;
	float getUnitPrice() const;

private:

	const string m_productID;
	const string m_productDescription;
	const float m_unitPrice;

};