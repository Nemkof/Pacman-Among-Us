#include "food.h"

Food::Food(const Object& object): Entity(object){
}

Condition Food::getCondition(){return condition;}

void Food::setCondition(Condition _condition){condition = _condition;}

Apple::Apple(const Object& object)
    :Food(object)
{
    w /= 3;
    sprite.setTextureRect(IntRect(w * (rand() % 3),0,w,h));
    setCondition(Condition::notEaten);
}

Banana::Banana(const Object& object)
    :Food(object)
{
    setCondition(Condition::Hidden);
}

Energy::Energy(const Object& object)
    :Food(object)
{
    w /= 4;
    sprite.setTextureRect(IntRect(w * (rand() % 4),0,w,h));
    setCondition(Condition::notEaten);
}


