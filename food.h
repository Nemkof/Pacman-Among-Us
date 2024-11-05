#ifndef FOOD_H
#define FOOD_H
#include "Entity.h"
using namespace sf;

enum class Condition{
    Eaten,     // Съеден
    notEaten,  // Не съеден
    Hidden     // Скрыт от игрока (для бананов)
};

class Food: public Entity{
private:
    Condition condition;
public:
    Food(const Object& object);

    Condition getCondition();
    void setCondition(Condition _condition);
};



class Apple: public Food{
private:
public:
    static const int score = 5;
    Apple(const Object& object);

};

class Banana: public Food{
private:
public:
    static const int score = 50;
    Banana(const Object& object);

};

class Energy: public Food{
private:
public:
    Energy(const Object& object);
};


#endif // FOOD_H
