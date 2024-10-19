#include "player.h"

Player::Player(std::string Name, std::vector<Object>& _obj, float X, float Y, int W, int H, std::vector<Food> *_apples)
    :Entity(Name, X, Y, W, H)
{
    score = 0;
    speed = 0.2;
    obj = _obj;
    state = stay;
    apples = _apples;
    sprite.setTextureRect(IntRect(0, 0, w, h));
}


void Player::control(){
    if (Keyboard::isKeyPressed(Keyboard::Left) && state != right) {
        state = left;
    }
    if (Keyboard::isKeyPressed(Keyboard::Right) && state != left) {
        state = right;
    }
    if (Keyboard::isKeyPressed(Keyboard::Up) && state != down) {
        state = up;
    }
    if (Keyboard::isKeyPressed(Keyboard::Down) && state != up) {
        state = down;
    }
}


void Player::checkCollisionWithMap (float time, float Dx, float Dy, std::vector<Enemy*> entities)
{
    for (size_t i = 0; i < obj.size(); i++) // Проходимся по всем элементам карты
    {
        if (getRect().intersects(obj[i].rect)) // Если мы пересекаемся с каким-то тайликом
        {

            if (obj[i].name == "solid") // И этот тайлик помечен знаком "Стена"
            { // То мы должны остановить нашего игрока перед стеной
                if (Dy>0)	{ y = obj[i].rect.top - h;  dy = 0; }
                if (Dy<0)	{ y = obj[i].rect.top + obj[i].rect.height;   dy = 0; }
                if (Dx>0)	{ x = obj[i].rect.left - w; dx = 0;}
                if (Dx<0)	{ x = obj[i].rect.left + obj[i].rect.width; dx = 0;}
            }
            else if(obj[i].name == "food") // Если тайлик помечен знаком "Еда"
            {
                if(!apples->at(i).isDead()) // И если эта еда ещё не съедена
                {
                    apples->at(i).Dead(); // Мы кушаем еду, объявляем её съеденной
                    score += 5;   // И получаем за неё очки
                }
            }
        }
    }
    /// Проверяем столкновение с врагами
    for(auto enemy : entities){
        if(getRect().intersects(enemy->getRect()))
        {
            if(lives >= 1)
            {
                lives--;
                x = startX; y = startY;
                if (Dy>0)	{ y -= dy * time;  dy = 0; }
                if (Dy<0)	{ y += dy * time;  dy = 0; }
                if (Dx>0)	{ x -= dx * time;  dx = 0;}
                if (Dx<0)	{ x += dx * time;  dx = 0;}
                sprite.setPosition(x + w / 2, y + h / 2);
            }
        }
    }
}


void Player::updatePosition(float time, std::vector<Enemy*> entities){
    if(state == right) dx = speed;
    else if(state == left) dx = -speed;
    else if(state == down) dy = speed;
    else if(state == up) dy = -speed;

    x += dx*time;
    checkCollisionWithMap(time, dx, 0, entities);
    y += dy*time;
    checkCollisionWithMap(time, 0, dy, entities);
    sprite.setPosition(x + w / 2, y + h / 2);
}

void Player::update(float time, std::vector<Enemy*> entities)
{
    control();
    updatePosition(time, entities);
    updateSprites(dx, time);
}


int Player::getScore() {return score;}


int Player::isLive() {return lives;} // Возвращает true, если еще есть жизни

