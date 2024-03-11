#pragma once

#include "SCOControlCenter.h"

class ChangeRepository
{
public:

	float getChange(float, float);
	void checkChangeLevel();

private:

	SCOControlCenter m_scoControlCenter;

	float m_repositoryAmount{ 200.00 };
	float m_minAmount{ 50.00 };

	void updateRepositoryAmount(float);
	void addChange(float);
	bool isChangeLow();
};