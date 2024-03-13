#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class CartInterface
{

public:

	CartInterface();

	void displayCart (vector<unsigned int>, vector<string>,
		vector<string>, vector<float>, float) const;

private:

	string m_numberHeader;
	string m_idHeader;
	string m_descriptionHeader;
	string m_costHeader;
	string m_headerSpacer;

	size_t m_sizeNumberHeader;
	size_t m_sizeIDHeader;
	size_t m_sizeDescriptionHeader;
	size_t m_sizeCostHeader;
	size_t m_sizeHeaderSpacer;

	void displayCartHeader () const;
	void displayItem (unsigned int, string,
		string, float) const;

	void displayColumn(unsigned int, size_t) const;
	void displayColumn(string, size_t) const;
	void displayColumn(float) const;

	string getWhitespace(size_t, size_t) const;
	size_t getDigitCount(unsigned int) const;

	void displayLine() const;
	void displayTwoDecimalFloat(float) const;
};

