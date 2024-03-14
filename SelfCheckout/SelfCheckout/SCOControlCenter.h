/*
* Control center for self checkout machines.
* Has own IO since it is a separate machine
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