#include "Sabotages.h"
#include "SabotageWidget.h"
Sabotage::Sabotage(const Object& object):
    Entity(object)
{
    w = texture.getSize().x / 2;
    sprite.setTextureRect(IntRect(0, 0, w, h));
    sprite.setPosition(x, y);
}

void Sabotage::update(float time)
{
    delay += 0.3 * time;
    if(delay > 1000){
        spriteNumber += 0.005 * time;
        if(spriteNumber > 2) spriteNumber -= 2;
        sprite.setTextureRect(IntRect(w * (int)spriteNumber, 0, w, h));
    }
}

bool Sabotage::run(){
    sabotageWidget* wi = new sabotageWidget();
    wi->show();
    if(wi->getStatus() == SabotageCondition::Finished) {
        delete wi;
        delay = 0;
    }
    return 0;
}

short Sabotage::solvedTasks = 0;
