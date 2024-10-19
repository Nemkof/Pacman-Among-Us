#include "entity.h"

Entity::Entity(std::string Name, float X, float Y, int W, int H)
    :x(X), y(Y), w(W), h(H), startX(X), startY(Y), name(Name)
{
    speed = 0; dx = 0; dy = 0;
    texture.loadFromFile("../../images/" + Name + ".png");
    sprite.setTexture(texture);
    sprite.setOrigin(w / 2, h / 2);
}

/// Обновляем спрайты игрока
void Entity::updateSprites(float Dx, float time)
{
    // < 0 - идем влево
    // >= 0 - иначе
    if(Dx < 0) // Идём влево
    {
        player_sprites += 0.02 * time;
        if(player_sprites > 12) player_sprites -= 12;
        sprite.setTextureRect(IntRect(w * (int)player_sprites, 0, w, h));
        sprite.setScale(-1,1);
        return;
    }
    else// Идём вправо, вверх, вниз
    {
        player_sprites += 0.02 * time;
        if(player_sprites > 11) player_sprites -= 12;
        sprite.setTextureRect(IntRect(w * (int)player_sprites, 0, w, h));
        sprite.setScale(1,1);
        return;
    }
}


FloatRect Entity::getRect(){  // функция получения прямоугольника. координаты объекта, размер (ширина, высота).
    return FloatRect(x, y, w, h); // нужна для проверки столкновений
}


float Entity::getX() {return x;}


float Entity::getY() {return y;}


Sprite Entity::getSprite() {return sprite;}

std::string Entity::getDirection(){
    if(state == left) return "left";
    if(state == right) return "right";
    if(state == up) return "up";
    if(state == down) return "down";
    return "stay";
}
