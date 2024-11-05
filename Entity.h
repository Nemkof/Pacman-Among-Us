#ifndef ENTITY_H
#define ENTITY_H
#include "level.h"

using namespace sf;
using namespace std;
class Entity{
public:
    float w = 0.0, h = 0.0;
    float x = 0.0, y = 0.0;
    Texture texture;
    Sprite sprite;
    string name;

    Entity(const Object& object, string _name = ""):
        x(object.rect.left), y(object.rect.top)
    {
        // Если мы не передали имя, то ставим имя default
        if(_name == "") name = object.name;
        else name = _name;
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
