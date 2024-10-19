#ifndef FOOD_H
#define FOOD_H
#include "level.h"
using namespace sf;
class Food
{
private:
    Sprite sprite;
    int x, y;
    bool status; // False = Объект не съеден

public:
    Food(Sprite _sprite, int _x, int _y);
    void Dead();
    bool isDead();
    Sprite getSprite();
};

void initApples(Level& lvl, std::vector<Food>& apples);
#endif // FOOD_H
