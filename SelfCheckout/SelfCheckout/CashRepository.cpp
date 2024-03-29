#include "CashRepository.h"

void CashRepository::depositCash(float cash) {
	m_repositoryAmount += cash;
}

//Returns amount of money emptied from repository
float CashRepository::emptyRepository() {
	float dispensedCash{ m_repositoryAmount };
	resetPurchaseRepository();
	return dispensedCash;
}

void CashRepository::resetPurchaseRepository() {
	m_repositoryAmount = 0;
}