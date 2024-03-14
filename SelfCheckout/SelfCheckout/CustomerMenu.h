#pragma once
#include "SelectionMenu.h"

#include <iostream>
class CustomerMenu : public SelectionMenu
{
private:
	void displayMenuOptions() const override;
};

