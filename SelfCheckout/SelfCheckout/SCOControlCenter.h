#pragma once

#include <iostream>
#include <iomanip>

class SCOControlCenter
{
public:
	float executeLowChange(float);

private:

	void displayLowChangeMessage(float);
	float getMoreChange();

	void displayTwoDecimalFloat(float);

};