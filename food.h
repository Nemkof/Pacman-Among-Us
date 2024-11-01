#ifndef FOOD_H
#define FOOD_H
#include "level.h"
using namespace sf;

class Apple{
private:
    Sprite sprite;
    float x, y;
    float w, h;
    bool status; // False = Объект не съеден

    float score = 5;
    bool isHalfEaten = false;
    bool isAllEaten = false;
public:
    Apple(const Sprite& _sprite, const float& _x, const float& _y, const Vector2u& size);
    bool isDead();
    Sprite getSprite();

    void checkScore();

    void createBanana();

    void Dead();
};


class Banana{
private:
    Sprite sprite;
    int x, y;
    float w, h;
    enum class state{
        Eaten,     // Съеден
        notEaten,  // Не съеден
        Hidden     // Скрыт от игрока (для бананов)
    }condition;

    float score = 50;
public:
    Banana(const Sprite& _sprite, const float& _x, const float& _y, const Vector2u& size);

    String getCondition();
    Sprite getSprite();

    void setCondition(String _condition);
};

void initApples(Level& lvl, std::vector<Apple>& apples);

#endif // FOOD_H
