#pragma once

#include <string>

using namespace std;

class Item
{
private:

	string m_productID{ "" };
	string m_productDescription{ "" };
	float m_unitPrice{ 0 };

protected:

	void setProductID(string);
	void setProductDescription(string);
	void setUnitPrice(float);

public:

	string getProductID();
	string getProductDescription();
	float getUnitPrice();

};