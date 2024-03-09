#pragma once

#include <string>

#include "Item.h"

using namespace std;

class Inventory
{
public:

	Inventory();

private:

	Item m_meat01;
	string m_meat01ID{ "Meat01" };
	string m_meat01Description{ "T-Bone Steak" };
	float m_meat01Price{ 7.99 };

	Item m_meat02;
	string m_meat02ID{ "Meat02" };
	string m_meat02Description{ "Tyson Fresh Chicken Wings" };
	float m_meat02Price{ 10.00 };

	Item m_iceCream01;
	string m_iceCream01ID{ "Icecream01" };
	string m_iceCream01Description{ "Chocolate Ice Cream" };
	float m_iceCream01Price{ 2.50 };

	Item m_iceCream02;
	string m_iceCream02ID{ "Icecream02" };
	string m_iceCream02Description{ "Vanilla Ice Cream" };
	float m_iceCream02Price{ 2.50 };

	Item m_corn01;
	string m_corn01ID{ "Corn01" };
	string m_corn01Description{ "Fresh Sweet Corn" };
	float m_corn01Price{ 2.00 };

	Item m_caseWater01;
	string m_caseWaters01ID{ "Casewater" };
	string m_caseWaters01Description{ "24 Bottles 16-Ox of Deer Park Water" };
	float m_caseWaters01Price{ 4.99 };

	Item m_potatoChips01;
	string m_potatoChips01ID{ "Potatochips01" };
	string m_potatoChips01Description{ "Plain Potato Chips" };
	float m_potatoChips01Price{ 2.00 };

	Item m_potatoChips02;
	string m_potatoChips02ID{ "Potatochips02" };
	string m_potatoChips02Description{ "Green Onion Potato Chips" };
	float m_potatoChips02Price{ 2.00 };

	Item m_donuts01;
	string m_donuts01ID{ "Donuts01" };
	string m_donuts01Description{ "Glazed Donutes One-Dozen" };
	float m_donuts01Price{ 4.99 };

	Item m_sausage01;
	string m_sausage01ID{ "Sausage01" };
	string m_sausage01Description{ "8-Sausage Pack" };
	float m_sausage01Price{ 4.99 };

	Item m_eggs01;
	string m_eggs01ID{ "Eggs01" };
	string m_eggs01Description{ "Dozen Eggs" };
	float m_01Price{ 3.00 };

	Item m_milk01;
	string m_milk01ID{ "Milk01" };
	string m_milk01Description{ "Gallon Milk" };
	float m_milk01Price{ 4.00 };


};

