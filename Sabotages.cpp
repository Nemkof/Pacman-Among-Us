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
    delay += 0.05 * time;
    if(tasksCondition != Condition::Solved && delay > 1000){
        spriteNumber += 0.002 * time;
        if(spriteNumber > 2) spriteNumber -= 2;
        sprite.setTextureRect(IntRect(w * (int)spriteNumber, 0, w, h));
    }
}

void Sabotage::run(){
    // Если мы недавно делали саботаж на этом месте
    // то нужно подождать
    if(delay < 1000) return;
    delay = 0;
    sabotageWidget* wi = new sabotageWidget();
    wi->show();
    if(wi->getStatus() == "Solved") {
        tasksCondition = Condition::Solved;
        delete wi;
    }
    else if(wi->getStatus() == "notSolved"){
        tasksCondition = Condition::notSolved;
        delete wi;
    }
}
