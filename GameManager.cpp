#include "GameManager.h"

GameManager::GameManager() {}

void GameManager::setApples(std::vector<Apple*>* _apples) { apples = _apples;}
void GameManager::setEnergy(std::vector<Energy>* _energies) { energies = _energies;}
void GameManager::setFirstBanana(Banana* _firstBanana) {firstBanana = _firstBanana;}
void GameManager::setSecondBanana(Banana* _secondBanana) {secondBanana = _secondBanana;}
void GameManager::setFirstSabotage(Sabotage* _firstSabotage) {firstSabotage = _firstSabotage;}
void GameManager::setSecondSabotage(Sabotage* _secondSabotage) {secondSabotage = _secondSabotage;}
void GameManager::setSolids(std::vector<Object>* _solids) { solids = _solids;}
void GameManager::setEnemy(std::vector<Enemy*>* _enemies) { enemies = _enemies;}
void GameManager::setFirstVentilation(Ventilation* _firstVentilation) {firstVentilation = _firstVentilation;}
void GameManager::setSecondVentilation(Ventilation* _secondVentilation) {secondVentilation = _secondVentilation;}
