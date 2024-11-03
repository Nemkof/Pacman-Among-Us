#ifndef PLAYER_H
#define PLAYER_H
#include "enemy.h"
#include "food.h"
#include "sabotages.h"
class Player : public Entity {
private:
    short lives = 3;
    std::vector<Object>* solids;
    std::vector<Apple>* apples;
    std::vector<Energy>* energies;
    std::vector<Enemy*>* enemies;
    Banana* firstBanana;
    Banana* secondBanana;
    Sabotage* firstSabotage;
    Sabotage* secondSabotage;

    int score = 0;

    Music sound;
public:
    Player(const Object& object);

    void control();

    void checkCollisionWithMap (float time, float Dx, float Dy);
    void updatePosition(float time);
    void update(float time);

    int getLives();

    int getScore();
    void checkScore();

    void setSolids(std::vector<Object>* _solids);
    void setApples(std::vector<Apple>* _apples);
    void setEnergy(std::vector<Energy>* _energies);
    void setEnemy(std::vector<Enemy*>* _enemies);
    void setFirstBanana(Banana* _firstBanana);
    void setSecondBanana(Banana* _secondBanana);
    void setFirstSabotage(Sabotage* _firstSabotage);
    void setSecondSabotage(Sabotage* _secondSabotage);
};

#endif // PLAYER_H
