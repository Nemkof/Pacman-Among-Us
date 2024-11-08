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
    Food(const Object& object): Entity(object) {}

    Condition getCondition() {return condition;}
    void setCondition(Condition _condition) {condition = _condition;}
};



class Apple: public Food{
private:
public:
    static const int score = 5;
    Apple(const Object& object) :Food(object)
    {
        w /= 3;
        sprite.setTextureRect(IntRect(w * (rand() % 3),0,w,h));
        setCondition(Condition::notEaten);
    }

};

class Banana: public Food{
private:
public:
    static const int score = 50;
    Banana(const Object& object): Food(object) {setCondition(Condition::Hidden);}
};

class Energy: public Food{
private:
public:
    Energy(const Object& object): Food(object)
    {
        w /= 4;
        sprite.setTextureRect(IntRect(w * (rand() % 4),0,w,h));
        setCondition(Condition::notEaten);
    }
};


#endif // FOOD_H
