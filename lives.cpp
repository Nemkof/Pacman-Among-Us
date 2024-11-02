#include "lives.h"
Lives::Lives(const Image& image, const Object& object)
{
    texture.loadFromImage(image);
    w = texture.getSize().x;
    h = texture.getSize().y / 3;
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0, 0, w, h));
    sprite.setPosition(object.rect.left, object.rect.top);
}

void Lives::update(int lives)
{
    sprite.setTextureRect(IntRect(0, h * (3 - lives), w, h));
}

Sprite Lives::getSprite(){return sprite;}
