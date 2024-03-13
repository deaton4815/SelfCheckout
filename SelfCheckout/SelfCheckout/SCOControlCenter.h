/*
* Control center for self checkout machines.
*/

#pragma once

#include <iostream>
#include <iomanip>

class SCOControlCenter
{
public:
	float executeLowChange(float);

private:

	void displayLowChangeMessage(float) const;
	float getMoreChange();

	void displayTwoDecimalFloat(float) const;

};