#ifndef FOOD_H
#define FOOD_H
#include "level.h"
using namespace sf;

// class Food{
// private:
//     Sprite sprite;
//     int x, y;
//     enum class{
//         Eaten,     // Съеден
//         notEaten,  // Не съеден
//         Hidden     // Скрыт от игрока (для бананов)
//     }state;

//     float score = 5;
// public:
//     Food(Sprite _sprite, int _x, int _y);
//     bool isDead();
//     Sprite getSprite();

//     void Dead();
// };


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
    }status;

    float score = 50;
public:
    Banana(const Sprite& _sprite, const float& _x, const float& _y, const Vector2u& size);

    String getStatus();
    Sprite getSprite();

    void Dead();

    void setStatus(String _status);
};

void initApples(Level& lvl, std::vector<Apple>& apples);

#endif // FOOD_H
