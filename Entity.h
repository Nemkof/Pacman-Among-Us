#ifndef ENTITY_H
#define ENTITY_H
#include "level.h"

using namespace sf;
using namespace std;
class Entity{
public:
    float w,h;
    float x,y;
    Texture texture;
    Sprite sprite;
    string name;

    Entity(const Object& object):
        x(object.rect.left), y(object.rect.top)
    {
        name = object.name;
        texture.loadFromFile("../../images/" + name + ".png");
        sprite.setTexture(texture);
        w = texture.getSize().x;
        h = texture.getSize().y;
        sprite.setPosition(x,y);
    }

    Sprite getSprite() {return sprite;}
    FloatRect getRect() {return FloatRect(x,y,w,h);}

};

#endif // ENTITY_H
