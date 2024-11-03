#include "food.h"
Food::Food(const Sprite& _sprite, const float& _x, const float& _y, const Vector2u& size){
    sprite = _sprite;
    x = _x;
    y = _y;
    w = size.x;
    h = size.y;
    sprite.setPosition(x,y);
}
FloatRect Food::getRect(){  // функция получения прямоугольника. координаты объекта, размер (ширина, высота).
    return FloatRect(x, y, w, h);
}
Sprite Food::getSprite(){return sprite;}

Condition Food::getCondition(){return condition;}

void Food::setCondition(Condition _condition){condition = _condition;}

Apple::Apple(const Sprite& _sprite, const float& _x, const float& _y, const Vector2u& size)
    :Food(_sprite, _x, _y, size)
{
    w /= 3;
    sprite.setTextureRect(IntRect(w * (rand() % 3),0,w,h));
    setCondition(Condition::notEaten);
}

Banana::Banana(const Sprite& _sprite, const float& _x, const float& _y, const Vector2u& size)
    :Food(_sprite, _x, _y, size)
{
    setCondition(Condition::Hidden);
}

Energy::Energy(const Sprite& _sprite, const float& _x, const float& _y, const Vector2u& size)
    :Food(_sprite, _x, _y, size)
{
    w /= 4;
    sprite.setTextureRect(IntRect(w * (rand() % 4),0,w,h));
    setCondition(Condition::notEaten);
}


