#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "Lives.h"
#include "Player.h"
#include "Sabotages.h"
#include "Ventilation.h"
using namespace std;

/// Singleton
class GameManager final
{
public:
    std::vector<Object>* enemySolids;
    std::vector<Object>* playerSolids;
    std::vector<Object>* solids;
    std::vector<Energy*>* energies;
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
    Text* textState;
    Text* textTasks;
    std::vector<Apple*>* apples;

    void play(float time);
    void draw(RenderWindow& window);

    ///////////////////////////SETTERS//////////////////////////////
    void setSolids(std::vector<Object>* _solids);
    void setFood(std::vector<Apple*>* _apples, Banana* _firstBanana, Banana* _secondBanana, std::vector<Energy*>* _energies);
    void setEnemy(std::vector<Enemy*>* _enemies);
    void setPlayer(Player* _player);
    void setSabotages(Sabotage* _firstSabotage, Sabotage* _secondSabotage);
    void setVentilation(Ventilation* _firstVentilation, Ventilation* _secondVentilation);
    void setLives(Lives *_lives);
    void setText(Text* _textScore, Text* _textTime, Text* _textState, Text* _textTasks);


};
//GameManager* GameManager::gameManager = nullptr;
#endif // GAMEMANAGER_H
