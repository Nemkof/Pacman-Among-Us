#include "GameManager.h"
void GameManager::play(float time){
    gameTime += time / (float)500;

    firstSabotage->update(time);
    secondSabotage->update(time);
    player->update(time);
    for(size_t i = 0; i < enemies->size(); i++)
    {
        enemies->at(i)->update(time, player->x, player->y);
    }
    lives->update(player->getLives());
}

void GameManager::draw(RenderWindow& window){
    window.draw(secondVentilation->sprite);
    window.draw(firstVentilation->sprite);
    window.draw(firstSabotage->getSprite());
    window.draw(secondSabotage->getSprite());
    window.draw(player->sprite);
    window.draw(player->textName);
    window.draw(lives->getSprite());
    /////////////////////////////////////////////////////////
    for (auto it : *apples) // Проходимся по всем яблочкам
    {
        if(it->getCondition() == Condition::notEaten)
            window.draw(it->getSprite());
    }
    for (auto it : *energies) // Проходимся по всем яблочкам
    {
        if(it->getCondition() == Condition::notEaten)
            window.draw(it->getSprite());
    }
    if(firstBanana->getCondition() == Condition::notEaten) window.draw(firstBanana->getSprite()); // То нужно его нарисовать
    if(secondBanana->getCondition() == Condition::notEaten) window.draw(secondBanana->getSprite()); // То нужно его нарисовать
    /////////////////////////////////////////////////////////
    for(size_t i = 0; i < enemies->size(); i++)
    {
        window.draw(enemies->at(i)->sprite);
        window.draw(enemies->at(i)->textName);
    }
    /////////////////////////////////////////////////////////
    textScore->setString("score: " + std::to_string(player->getScore()));
    window.draw(*textScore);

    textTime->setString("time: " + std::to_string((int)gameTime));
    window.draw(*textTime);

    //textTasks->setString("tasks: " + std::to_string(player->solvedTasks) + "/4");
    textTasks->setString("tasks: " + std::to_string(Sabotage::getSolvedTasks()) + "/4");
    window.draw(*textTasks);
    /////////////////////////////////////////////////////////
    if(enemies->at(0)->ghostState == GhostState::Chase){
        textState->setFillColor(Color::Green);
        textState->setString("should run");
    }
    else if(enemies->at(0)->ghostState == GhostState::Frightened){
        textState->setFillColor(Color::Red);
        textState->setString("kill him");
    }
    else if(enemies->at(0)->ghostState == GhostState::Scatter){
        textState->setFillColor(Color::White);
        textState->setString("just relax");
    }
    window.draw(*textState);


}


void GameManager::setFood(std::vector<Apple*>* _apples, Banana* _firstBanana,
                          Banana* _secondBanana, std::vector<Energy*>* _energies){
    apples = _apples;
    firstBanana = _firstBanana;
    secondBanana =_secondBanana;
    energies = _energies;
}

void GameManager::setSabotages(Sabotage* _firstSabotage, Sabotage* _secondSabotage){
    firstSabotage = _firstSabotage;
    secondSabotage = _secondSabotage;
}

void GameManager::setVentilation(Ventilation* _firstVentilation, Ventilation* _secondVentilation){
    firstVentilation = _firstVentilation;
    secondVentilation = _secondVentilation;
}
void GameManager::setSolids(std::vector<Object>* _solids) { solids = _solids;}
void GameManager::setEnemy(std::vector<Enemy*>* _enemies) { enemies = _enemies;}
void GameManager::setPlayer(Player* _player) { player = _player;}
void GameManager::setLives(Lives *_lives){ lives = _lives;}
void GameManager::setText(Text* _textScore, Text* _textTime, Text* _textState,  Text* _textTasks){
    textScore = _textScore;
    textTime = _textTime;
    textState = _textState;
    textTasks = _textTasks;
}
