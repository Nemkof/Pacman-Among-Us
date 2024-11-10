#ifndef PLAYER_H
#define PLAYER_H
#include "Enemy.h"
#include "Food.h"
#include "Sabotages.h"
#include "Ventilation.h"
class Player : public MovableEntity {
private:
    std::vector<Object>* solids;
    std::vector<Apple*>* apples;
    std::vector<Energy*>* energies;
    std::vector<Enemy*>* enemies;

    Banana* firstBanana;
    Banana* secondBanana;

    Sabotage* firstSabotage;
    Sabotage* secondSabotage;

    Ventilation* firstVentilation;
    Ventilation* secondVentilation;
    ;
public:
    float timeVentilation = 0.0;
    float timeAfterDeath = 0.0;
    int score = 0;
    short lives = 3;
    short solvedTasks = 0;

    Player(const Object& object);

    void control();

    void checkCollisionWithMap (float time, float Dx, float Dy);
    void updatePosition(float time);
    void update(float time);

    int getLives();

    int getScore();
    void checkScore();

    void setSolids(std::vector<Object>* _solids);
    void setApples(std::vector<Apple*>* _apples);
    void setEnergy(std::vector<Energy*>* _energies);
    void setEnemy(std::vector<Enemy*>* _enemies);
    void setBananas(Banana* _firstBanana, Banana* _secondBanana);
    void setSabotages(Sabotage* _firstSabotage, Sabotage* _secondSabotage);
    void setVentilations(Ventilation* _firstVentilation, Ventilation* _secondVentilation);
};

#endif // PLAYER_H
