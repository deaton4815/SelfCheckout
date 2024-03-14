/*
* Class displays the cart contents to the user
*/
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class CartInterface
{

public:

	void displayCart (const vector<unsigned int>&, const vector<string>&,
		const vector<string>&, const vector<float>&) const;

	void displayLine() const;

private:

	const string m_numberHeader{ "Item #" };
	const string m_idHeader{ "Product ID" };
	const string m_descriptionHeader{ "Product Description" };
	const string m_costHeader{ "Unit Cost" };
	const string m_headerSpacer{ "  " };

	const size_t m_sizeNumberColumn{ 6 };
	const size_t m_sizeIDColumn{ 13 };
	const size_t m_sizeDescriptionColumn{ 35 };
	const size_t m_sizeCostColumn{ 10 };
	const size_t m_sizeColumnSpacer{ 2 };

	void displayCartHeader () const;
	void displayItem (unsigned int, string,
		string, float) const;

	void displayColumn(unsigned int, size_t) const;
	void displayColumn(string, size_t) const;
	void displayColumn(float) const;

	string getWhitespace(const size_t, const size_t) const;
	size_t getDigitCount(unsigned int) const;

	void displayTwoDecimalFloat(const float) const;
};