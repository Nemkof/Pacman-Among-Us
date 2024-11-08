#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "Enemy.h"
#include "Food.h"
#include "Sabotages.h"
#include "Ventilation.h"
#include "Player.h"
using namespace std;
class GameManager
{
private:
    std::vector<Object>* solids;

    std::vector<Apple*>* apples;
    std::vector<Energy>* energies;
    Banana* firstBanana;
    Banana* secondBanana;

    std::vector<Enemy*>* enemies;

    Player* player;

    Sabotage* firstSabotage;
    Sabotage* secondSabotage;

    Ventilation* firstVentilation;
    Ventilation* secondVentilation;
public:
    GameManager();

    void setSolids(std::vector<Object>* _solids);

    void setApples(std::vector<Apple*>* _apples);
    void setEnergy(std::vector<Energy>* _energies);
    void setFirstBanana(Banana* _firstBanana);
    void setSecondBanana(Banana* _secondBanana);

    void setEnemy(std::vector<Enemy*>* _enemies);
    void setPlayer(Player* _player);

    void setFirstSabotage(Sabotage* _firstSabotage);
    void setSecondSabotage(Sabotage* _secondSabotage);

    void setFirstVentilation(Ventilation* _firstVentilation);
    void setSecondVentilation(Ventilation* _secondVentilation);
};

#endif // GAMEMANAGER_H
