#include "food.h"

Apple::Apple(const Sprite& _sprite, const float& _x, const float& _y,
        const Vector2u& size): sprite(_sprite), x(_x), y(_y), w(size.x), h(size.y)
{
    sprite.setTextureRect(IntRect(0,0,w,h));
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
    status = state::Hidden;
}

String Banana::getStatus(){
    if( status == state::notEaten) return "notEaten";
    else if(status == state::Eaten) return "Eaten";
    return "Hidden";
}

void Banana::setStatus(String _status){
    if(_status == "notEaten") status = state::notEaten;
    else if(_status == "Eaten") status = state::Eaten;
    else if(_status == "Hidden") status = state::Hidden;
}

Sprite Banana::getSprite(){return sprite;}

void Banana::Dead() {status = state::Eaten;}

