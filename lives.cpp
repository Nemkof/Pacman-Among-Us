#include "lives.h"
Lives::Lives(const Object& object): Entity(object)
{
    w = texture.getSize().x;
    h = texture.getSize().y / 3;
    sprite.setTextureRect(IntRect(0, 0, w, h));
    sprite.setPosition(x, y);
}

void Lives::update(int lives)
{
    sprite.setTextureRect(IntRect(0, h * (3 - lives), w, h));
}


