#ifndef LIVES_H
#define LIVES_H
#include <SFML/Graphics.hpp>
#include "level.h"
#include "Entity.h"

using namespace sf;
class Lives: public Entity{
private:
public:
    Lives(const Object& object): Entity(object)
    {
        w = texture.getSize().x;
        h = texture.getSize().y / 3;
        sprite.setTextureRect(IntRect(0, 0, w, h));
        sprite.setPosition(x, y);
    }


    void update(int lives)
    {
        sprite.setTextureRect(IntRect(0, h * (3 - lives), w, h));
    }
};
#endif // LIVES_H
