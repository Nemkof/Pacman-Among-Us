#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "Enemy.h"
#include "Food.h"
#include "Sabotages.h"
#include "Ventilation.h"
#include "Player.h"
#include "Lives.h"
using namespace std;

/// Singleton
class GameManager final
{
private:
    std::vector<Object>* solids;

    std::vector<Apple*>* apples;
    std::vector<Energy> energies;
    Banana* firstBanana;
    Banana* secondBanana;

    std::vector<Enemy*>* enemies;

    Player* player;
    Lives* lives;

    Sabotage* firstSabotage;
    Sabotage* secondSabotage;

    Ventilation* firstVentilation;
    Ventilation* secondVentilation;

    float gameTime = 0;
    Text* textScore;
    Text* textTime;
public:    

    void play(float time);
    void draw(RenderWindow& window);

    ///////////////////////////SETTERS//////////////////////////////
    void setSolids(std::vector<Object>* _solids);
    void setFood(std::vector<Apple*>* _apples, Banana* _firstBanana, Banana* _secondBanana, std::vector<Energy>& _energies);
    void setEnemy(std::vector<Enemy*>* _enemies);
    void setPlayer(Player* _player);
    void setSabotages(Sabotage* _firstSabotage, Sabotage* _secondSabotage);
    void setVentilation(Ventilation* _firstVentilation, Ventilation* _secondVentilation);
    void setLives(Lives *_lives);
    void setText(Text* textScore, Text* textTime);
};
//GameManager* GameManager::gameManager = nullptr;
#endif // GAMEMANAGER_H
