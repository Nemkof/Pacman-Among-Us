#include "player.h"
#include "sabotagewidget.h"
Player::Player(const std::vector<Object>& _obj, const Object& object, std::vector<Apple>* _apples,
        Banana* _firstBanana, Banana* _secondBanana, Sabotage* _firstSabotage, Sabotage* _secondSabotage)
    :Entity(object)
{
    score = 0;
    speed = 0.2;
    state = stay;

    sprite.setTextureRect(IntRect(0, 0, w, h));

    obj = _obj;
    apples = _apples;
    applesNumber = apples->size();
    firstBanana = _firstBanana;
    secondBanana = _secondBanana;

    firstSabotage = _firstSabotage;
    secondSabotage = _secondSabotage;
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


void Player::checkCollisionWithMap (float time, float Dx, float Dy, const std::vector<Enemy*>& entities)
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
            else if(obj[i].name == "apple") // Если пришли к яблоку
            {
                apples->at(i).Dead(); // Мы кушаем банан, объявляем её съеденной
                obj[i].name = "deadInsideApple"; // Помечаем его в массиве как съеденныей
                score += 5;   // Получаем за неё очки
                checkScore(); // Проверяем, не пора ли рисовать банан
            }
            else if(obj[i].name == "firstBanana" && firstBanana->getCondition() == "notEaten") // Если пришли к банану
            {
                firstBanana->setCondition("Eaten"); // Мы кушаем банан, объявляем её съеденной
                obj[i].name = "deadInsideBanana";
                score += 50;   // Получаем за неё очки
            }
            else if(obj[i].name == "secondBanana" && secondBanana->getCondition() == "notEaten") // Если пришли к банану
            {
                secondBanana->setCondition("Eaten"); // Мы кушаем банан, объявляем её съеденной
                obj[i].name = "deadInsideBanana";
                score += 50;   // Получаем за неё очки
            }
            else if(obj[i].name == "sabotageFirst" || obj[i].name == "sabotageFirst"){
                if(Keyboard::isKeyPressed(Keyboard::E)){
                    sabotageWidget wi(nullptr);
                    wi.show();
                }
            }
            else if(obj[i].name == "sabotageSecond" || obj[i].name == "sabotageSecond"){
                if(Keyboard::isKeyPressed(Keyboard::E)){
                    sabotageWidget wi(nullptr);
                    wi.show();
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
                state = stay;
            }
        }
    }
}

void Player::updatePosition(float time, const std::vector<Enemy*>& entities){
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

void Player::update(float time, const std::vector<Enemy*>& entities)
{
    control();
    updatePosition(time, entities);
    updateSprites(dx, time);
}


int Player::getScore() {return score;}

void Player::checkScore(){
    if((score == applesNumber * 5 / 2) && firstBanana->getCondition() == "Hidden"){
        firstBanana->setCondition("notEaten");
    }
    else if((score >= applesNumber * 5) && secondBanana->getCondition() == "Hidden"){
        secondBanana->setCondition("notEaten");
    }
}


int Player::getLives() {return lives;} // Возвращает true, если еще есть жизни


