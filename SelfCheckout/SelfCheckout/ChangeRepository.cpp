#include "ChangeRepository.h"

float ChangeRepository::getChange(float due, float paid) {

	float changeDue = paid - due;
	updateRepositoryAmount(changeDue);
	checkChangeLevel();
	return changeDue;

}

void ChangeRepository::checkChangeLevel() {
	bool isLow{ isChangeLow() };
	if (isLow) {
		do {
			addChange(m_scoControlCenter.executeLowChange(m_repositoryAmount));
			isLow = isChangeLow();
		} while (isLow);
	}
}

void ChangeRepository::updateRepositoryAmount(float dispensed) {
	m_repositoryAmount -= dispensed;
}

void ChangeRepository::addChange(float added) {
	m_repositoryAmount += added;
}

bool ChangeRepository::isChangeLow() {
	bool isLow = false;
	if (m_repositoryAmount < m_minAmount) {
		isLow = true;
	}
	return isLow;
}