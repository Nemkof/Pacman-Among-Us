#include "food.h"

Apple::Apple(const Sprite& _sprite, const float& _x, const float& _y,
        const Vector2u& size): sprite(_sprite), x(_x), y(_y), w(size.x / 3), h(size.y)
{
    sprite.setTextureRect(IntRect(w * (rand() % 3),0,w,h));
    sprite.setPosition(x,y);
    status = false;
}

bool Apple::isDead(){return status;}

Sprite Apple::getSprite(){return sprite;}

void Apple::Dead(){status = true;}


Banana::Banana(const Sprite& _sprite, const float& _x, const float& _y, const Vector2u& size)
    :sprite(_sprite), x(_x), y(_y), w(size.x), h(size.y)
{
    sprite.setTextureRect(IntRect(0,0,w,h));
    sprite.setPosition(x,y);
    condition = state::Hidden;
}

String Banana::getCondition(){
    if(condition == state::notEaten) return "notEaten";
    else if(condition == state::Eaten) return "Eaten";
    return "Hidden";
}

void Banana::setCondition(String _status){
    if(_status == "notEaten") condition = state::notEaten;
    else if(_status == "Eaten") condition = state::Eaten;
    else if(_status == "Hidden") condition = state::Hidden;
}

Sprite Banana::getSprite(){return sprite;}

