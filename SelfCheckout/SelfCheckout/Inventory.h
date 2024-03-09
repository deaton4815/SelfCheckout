#pragma once

#include <string>

#include "Item.h"

using namespace std;

class Inventory
{
public:

	Inventory();

private:

	const Item m_meat01;
	const string m_meat01ID;
	const string m_meat01Description;
	const float m_meat01Price;

	const Item m_meat02;
	const string m_meat02ID;
	const string m_meat02Description;
	const float m_meat02Price;

	const Item m_iceCream01;
	const string m_iceCream01ID;
	const string m_iceCream01Description;
	const float m_iceCream01Price;

	const Item m_iceCream02;
	const string m_iceCream02ID;
	const string m_iceCream02Description;
	const float m_iceCream02Price;

	const Item m_corn01;
	const string m_corn01ID;
	const string m_corn01Description;
	const float m_corn01Price;

	const Item m_caseWater01;
	const string m_caseWaters01ID;
	const string m_caseWaters01Description;
	const float m_caseWaters01Price;

	const Item m_potatoChips01;
	const string m_potatoChips01ID;
	const string m_potatoChips01Description;
	const float m_potatoChips01Price;

	const Item m_potatoChips02;
	const string m_potatoChips02ID;
	const string m_potatoChips02Description;
	const float m_potatoChips02Price;

	const Item m_donuts01;
	const string m_donuts01ID;
	const string m_donuts01Description;
	const float m_donuts01Price;

	const Item m_sausage01;
	const string m_sausage01ID;
	const string m_sausage01Description;
	const float m_sausage01Price;

	const Item m_eggs01;
	const string m_eggs01ID;
	const string m_eggs01Description;
	const float m_eggs01Price;

	const Item m_milk01;
	const string m_milk01ID;
	const string m_milk01Description;
	const float m_milk01Price;
};

