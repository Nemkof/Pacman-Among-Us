#include "lives.h"
Lives::Lives(Image& image, int w, int h, int posX, int posY): w(w), h(h)
{
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0, 0, w, h));
    sprite.setPosition(posX, posY);

}

void Lives::update(int lives)
{
    sprite.setTextureRect(IntRect(0, h * (3 - lives), w, h));
}

Sprite Lives::getSprite(){return sprite;}
