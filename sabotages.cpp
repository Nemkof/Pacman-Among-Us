#include "sabotages.h"
#include <QMainWindow>
#include "sabotagewidget.h"
Sabotage::Sabotage(const Image& image, const float& _x, const float& _y)
{
    x = _x; y = _y;
    texture.loadFromImage(image);
    w = texture.getSize().x / 2;
    h = texture.getSize().y;
    sprite.setTexture(texture);
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

Sprite Sabotage::getSprite(){return sprite;}
FloatRect Sabotage::getRect(){  // функция получения прямоугольника. координаты объекта, размер (ширина, высота).
    return FloatRect(x, y, w, h);
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
