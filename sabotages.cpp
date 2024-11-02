#include "sabotages.h"
#include <QMainWindow>
Sabotage::Sabotage(const Image& image, const Object& object)
{
    texture.loadFromImage(image);
    w = texture.getSize().x / 2;
    h = texture.getSize().y;
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0, 0, w, h));
    sprite.setPosition(object.rect.left, object.rect.top);
}

void Sabotage::update(float time)
{
    if(tasksCondition != Condition::Solved){
        spriteNumber += 0.002 * time;
        if(spriteNumber > 2) spriteNumber -= 2;
        sprite.setTextureRect(IntRect(w * (int)spriteNumber, 0, w, h));
    }
}

Sprite Sabotage::getSprite(){return sprite;}

void Sabotage::run(){

}
