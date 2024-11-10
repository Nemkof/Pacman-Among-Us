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
    if(tasksCondition != TaskCondition::Solved && delay > 1000){
        spriteNumber += 0.005 * time;
        if(spriteNumber > 2) spriteNumber -= 2;
        sprite.setTextureRect(IntRect(w * (int)spriteNumber, 0, w, h));
    }
}

bool Sabotage::run(){
    // Если мы недавно делали саботаж на этом месте
    // то нужно подождать
    tasksCondition = TaskCondition::notSolved;
    bool status = false;
    delay = 0;
    sabotageWidget* wi = new sabotageWidget(status);
    wi->show();
    if(wi->getStatus() == "Solved") {
        tasksCondition = TaskCondition::Solved;
        delete wi;
        cout << "successing" << endl;
    }
    else if(wi->getStatus() == "notSolved"){
        tasksCondition = TaskCondition::notSolved;
        delete wi;
        cout << "332323successing" << endl;
    }
    if(status) tasksCondition = TaskCondition::Solved;
    return 0;
}
