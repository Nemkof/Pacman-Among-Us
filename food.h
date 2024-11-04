#ifndef FOOD_H
#define FOOD_H
#include <SFML/Graphics.hpp>
using namespace sf;

enum class Condition{
    Eaten,     // Съеден
    notEaten,  // Не съеден
    Hidden     // Скрыт от игрока (для бананов)
};

class Food{
private:
    Condition condition;
public:
    float x, y, w, h;
    Sprite sprite;
    Food(const Sprite& _sprite, const float& _x, const float& _y, const Vector2u& size);

    Sprite getSprite();
    FloatRect getRect();
    Condition getCondition();
    void setCondition(Condition _condition);
};



class Apple: public Food{
private:
public:
    static const int score = 5;
    Apple(const Sprite& _sprite, const float& _x, const float& _y, const Vector2u& size);

};

class Banana: public Food{
private:
public:
    static const int score = 50;
    Banana(const Sprite& _sprite, const float& _x, const float& _y, const Vector2u& size);

};

class Energy: public Food{
private:
public:
    Energy(const Sprite& _sprite, const float& _x, const float& _y, const Vector2u& size);
};


#endif // FOOD_H
