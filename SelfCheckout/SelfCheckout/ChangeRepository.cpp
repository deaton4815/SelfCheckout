#include "ChangeRepository.h"

//Returns proper amount of change form change repository
//and updates repository appropriately
float ChangeRepository::getChange(float due, float paid) {

	float changeDue = paid - due;
	updateRepositoryAmount(changeDue);
	checkChangeLevel();
	return changeDue;

}

//Checks change level and calls to conrol center if needed
void ChangeRepository::checkChangeLevel() {
	bool isLow{ isChangeLow() };
	if (isLow) {
		do { //Calls to control center if change is low
			addChange(m_scoControlCenter.executeLowChange(m_repositoryAmount));
			isLow = isChangeLow();
		} while (isLow); //Continues promptining until enough change has been added
	}
}

void ChangeRepository::updateRepositoryAmount(float dispensed) {
	m_repositoryAmount -= dispensed;
}
void ChangeRepository::addChange(float added) {
	m_repositoryAmount += added;
}

//Returns bool if change is below minimum amount
bool ChangeRepository::isChangeLow() const{
	bool isLow = false;
	if (m_repositoryAmount < m_minAmount) {
		isLow = true;
	}
	return isLow;
}