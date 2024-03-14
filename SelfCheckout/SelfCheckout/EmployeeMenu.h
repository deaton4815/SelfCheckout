#pragma once
#include "SelectionMenu.h"

#include <iostream>

class EmployeeMenu : public SelectionMenu
{
private:
	void displayMenuOptions() const override;
};