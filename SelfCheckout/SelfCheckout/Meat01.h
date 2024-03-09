#pragma once

#include "Item.h"
#include <string>

using namespace std;

class Meat01 : public Item
{
private:

	string m_productID{ "Meat01" };
	string m_productDescription{ "T-Bone Steak" };
	float m_unitPrice{ 7.99 };

public:
	Meat01();
};

