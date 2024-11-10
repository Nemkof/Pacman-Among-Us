#include "Player.h"
#include "GameSettings.h"
Player::Player(const Object& object)
    :MovableEntity(object, "Player")
{
    speed = 0.8;
    sprite.setTextureRect(IntRect(0, 0, w, h));
    direction = Direction::stay;

    name = GameSettings::Nickname;
    textName.setFillColor(Color::Red);
    textName.setString(name);
}

void Player::control(){
    if(GameSettings::controller == Controller::Arrows){
        if (Keyboard::isKeyPressed(Keyboard::Left) && direction != Direction::right) {
            direction = Direction::left;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right) && direction != Direction::left) {
            direction = Direction::right;
        }
        if (Keyboard::isKeyPressed(Keyboard::Up) && direction != Direction::down) {
            direction = Direction::up;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down) && direction != Direction::up) {
            direction = Direction::down;
        }
    }
    else if(GameSettings::controller == Controller::Letters){
        if (Keyboard::isKeyPressed(Keyboard::A) && direction != Direction::right) {
            direction = Direction::left;
        }
        if (Keyboard::isKeyPressed(Keyboard::D) && direction != Direction::left) {
            direction = Direction::right;
        }
        if (Keyboard::isKeyPressed(Keyboard::W) && direction != Direction::down) {
            direction = Direction::up;
        }
        if (Keyboard::isKeyPressed(Keyboard::S) && direction != Direction::up) {
            direction = Direction::down;
        }
    }
}


void Player::checkCollisionWithMap (float time, float Dx, float Dy)
{
    /// Проверяем столкновение со стенами
    for (size_t i = 0; i < solids->size(); i++)
    {
        if (getRect().intersects(solids->at(i).rect))
        {
            if (Dy>0)	{ y = solids->at(i).rect.top - h;  dy = 0; }
            if (Dy<0)	{ y = solids->at(i).rect.top + solids->at(i).rect.height;   dy = 0; }
            if (Dx>0)	{ x = solids->at(i).rect.left - w; dx = 0;}
            if (Dx<0)	{ x = solids->at(i).rect.left + solids->at(i).rect.width; dx = 0;}
        }
    }

    /// Проверяем столкновение с яблоками
    for (size_t i = 0; i < apples->size(); i++)
    {
        if (apples->at(i)->getCondition() == Condition::notEaten
            && getRect().intersects(apples->at(i)->getRect()))
        {
            score += Apple::score;
            checkScore(); // Проверяем, не пора ли рисовать банан
            apples->at(i)->setCondition(Condition::Eaten);
        }
    }

    /// Проверяем столкновение с энерджайзерами
    for (size_t i = 0; i < energies->size(); i++)
    {
        if (energies->at(i)->getCondition() == Condition::notEaten
            && getRect().intersects(energies->at(i)->getRect()))
        {
            energies->at(i)->setCondition(Condition::Eaten);
            for(size_t i = 0; i < enemies->size(); i++){
                enemies->at(i)->runAway();
            }
        }
    }

    /// Проверяем столкновение с бананами
    if(getRect().intersects(firstBanana->getRect()) && firstBanana->getCondition() == Condition::notEaten){
        firstBanana->setCondition(Condition::Eaten);
        score += Banana::score;
    }
    if(getRect().intersects(secondBanana->getRect()) && secondBanana->getCondition() == Condition::notEaten){
        secondBanana->setCondition(Condition::Eaten);
        score += Banana::score;
    }

    /// Проверяем столкновение с саботажем
    if(getRect().intersects(firstSabotage->getRect()) && Keyboard::isKeyPressed(Keyboard::E)){
        if(firstSabotage->delay > 1000)
            firstSabotage->run();
    }
    if(getRect().intersects(secondSabotage->getRect()) && Keyboard::isKeyPressed(Keyboard::E)){
        if(secondSabotage->delay > 1000){
            secondSabotage->run();
            x = startX; y = startY;
        }
    }

    /// Проверяем столкновение с врагами
    for(size_t i = 0; i < enemies->size(); i++){
        if(getRect().intersects(enemies->at(i)->getRect())){
            if(Enemy::ghostState != GhostState::Frightened
                && lives >= 1 && timeAfterDeath > 2500){
                lives--;
                x = startX; y = startY;
                if (Dy>0)	{ y -= dy * time;  dy = 0; }
                if (Dy<0)	{ y += dy * time;  dy = 0; }
                if (Dx>0)	{ x -= dx * time;  dx = 0;}
                if (Dx<0)	{ x += dx * time;  dx = 0;}
                sprite.setPosition(x + w / 2, y + h / 2);
                direction = Direction::stay;
                timeAfterDeath = 0;
            }
            else if (Enemy::ghostState == GhostState::Frightened){
                score += 100;
                enemies->at(i)->death();
            }
        }
    }

    /// Проверяем столкновение с вентиляцией
    if(getRect().intersects(firstVentilation->getRect()) && Keyboard::isKeyPressed(Keyboard::E)){
        if(timeVentilation > 2000){
            x = secondVentilation->x;
            y = secondVentilation->y;
            timeVentilation = 0;
        }
    }
    else if(getRect().intersects(secondVentilation->getRect()) && Keyboard::isKeyPressed(Keyboard::E)){
        if(timeVentilation > 2000){
            x = firstVentilation->x;
            y = firstVentilation->y;
            timeVentilation = 0;
        }
    }
}

void Player::updatePosition(float time){
    if(direction == Direction::right) dx = speed;
    else if(direction == Direction::left) dx = -speed;
    else if(direction == Direction::down) dy = speed;
    else if(direction == Direction::up) dy = -speed;

    x += dx*time;
    checkCollisionWithMap(time, dx, 0);
    y += dy*time;
    checkCollisionWithMap(time, 0, dy);
    sprite.setPosition(x + w / 2, y + h / 2);
}

void Player::update(float time)
{
    control();
    updatePosition(time);
    updateSprites(dx, time);
    updateNamePosition();

    timeVentilation += time;
    timeAfterDeath += time;
    if(timeAfterDeath < 2500){
        sprite.setColor(Color(rand(), rand(), rand()));
    }
    else{
        sprite.setColor(Color::White);
    }
}


int Player::getScore() {return score;}

/// Проверяем, не пора ли выкидывать бананы на карту
void Player::checkScore(){
    if((score >= ((int)apples->size() * Apple::score / 2)) && firstBanana->getCondition() == Condition::Hidden){
        firstBanana->setCondition(Condition::notEaten);
    }
    else if((score >= ((int)apples->size() * Apple::score + Banana::score))
             && secondBanana->getCondition() == Condition::Hidden){
        secondBanana->setCondition(Condition::notEaten);
    }
}


int Player::getLives() {return lives;}

void Player::setApples(std::vector<Apple*>* _apples) { apples = _apples;}
void Player::setEnergy(std::vector<Energy*>* _energies) { energies = _energies;}
void Player::setBananas(Banana* _firstBanana, Banana* _secondBanana){
    firstBanana = _firstBanana;
    secondBanana = _secondBanana;
}
void Player::setSabotages(Sabotage* _firstSabotage, Sabotage* _secondSabotage){
    firstSabotage = _firstSabotage;
    secondSabotage = _secondSabotage;
}
void Player::setSolids(std::vector<Object>* _solids) { solids = _solids;}
void Player::setEnemy(std::vector<Enemy*>* _enemies) { enemies = _enemies;}
void Player::setVentilations(Ventilation* _firstVentilation, Ventilation* _secondVentilation) {
    firstVentilation = _firstVentilation;
    secondVentilation = _secondVentilation;
}
