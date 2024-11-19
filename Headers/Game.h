#ifndef GAME_H
#define GAME_H
#include "Lives.h"
#include "Player.h"
#include "Sabotages.h"
#include "Ventilation.h"
#include "GameManager.h"
#include "SceneLoader.h"
#include <SFML/Audio.hpp>
#include "GameSettings.h"
using namespace sf;
using namespace std;

int game(int& gameLevel)
{
    //////////////////////////////СОЗДАЁМ ОКНО//////////////////////////////
    RenderWindow window(VideoMode(1600, 1725), "Pacman Among Us");  // Создаём окно
    Music music; //создаем объект музыки
    music.openFromFile("sounds/zhelezo.ogg"); //загружаем файл
    int volume = 5;
    if(GameSettings::Sounds == false) volume = 0;
    music.setVolume(volume);
    music.setLoop(true);
    music.play(); //воспроизводим музыку
    //////////////////////////////ЗАГРУЖАЕМ КАРТУ//////////////////////////////
    Level lvl;
    lvl.LoadFromFile("map.tmx");
    SceneLoader scene(lvl);
    //////////////////////////////СОЗДАЕМ САБОТАЖИ//////////////////////////////
    Sabotage firstSabotage(scene.firstSabotageObject);
    Sabotage secondSabotage(scene.secondSabotageObject);
    //////////////////////////////СОЗДАЕМ ЯБЛОКИ //////////////////////////////
    std::vector<Apple*> apples;
    for(size_t i = 0; i < scene.appleObjects.size(); i++)
    {
        Apple* tmp = new Apple(scene.appleObjects.at(i));
        apples.push_back(tmp);
    }
    //////////////////////////////СОЗДАЕМ БАНАНЫ//////////////////////////////
    Banana firstBanana(scene.firstBananaObject);
    Banana secondBanana(scene.secondBananaObject);
    //////////////////////////////СОЗДАЕМ ЭНЕРДЖАЙЗЕРЫ//////////////////////////////
    std::vector<Energy*> energies;
    for(size_t i = 0; i < scene.energyObjects.size(); i++)
    {
        Energy* tmp = new Energy(scene.energyObjects.at(i));
        energies.push_back(tmp);
    }
    //////////////////////////////СОЗДАЁМ ВЕНТИЛЯЦИЮ//////////////////////////////
    Ventilation firstVentilation(scene.firstVentilationObject);
    Ventilation secondVentilation(scene.secondVentilationObject);
    //////////////////////////////СОЗДАЁМ ВРАГОВ//////////////////////////////
    vector<Enemy*> enemies;
    enemies.push_back(new Blinky(scene.blinkyObject, scene.blinkyTargetObject));
    enemies.push_back(new Pinky(scene.pinkyObject, scene.pinkyTargetObject));
    enemies.push_back(new Inky(scene.inkyObject, scene.inkyTargetObject));
    enemies.push_back(new Clyde(scene.clydeObject, scene.clydeTargetObject));
    for(auto it: enemies){
        it->setRotates(&scene.rotates);
        it->setSolids(&scene.solidsEnemy);
    }
    //////////////////////////////СОЗДАЁМ ОБЪЕКТ СЕРДЕЧЕК//////////////////////////////
    Lives lives(scene.livesObject);
    //////////////////////////////СОЗДАЁМ ИГРОКА//////////////////////////////
    Player player(scene.playerObject);
    player.setSolids(&scene.solidsPlayer);
    player.setApples(&apples);
    player.setEnergy(&energies);
    player.setBananas(&firstBanana, &secondBanana);
    player.setSabotages(&firstSabotage, &secondSabotage);
    player.setEnemy(&enemies);
    player.setVentilations(&firstVentilation, &secondVentilation);
    //////////////////////////////РАБОТАЕМ С ТЕКСТОМ//////////////////////////////
    Font font;  // Создаём объект типа шрифт
    font.loadFromFile("images/forText.ttf"); // Загружаем шрифт в объект
    // Создаём текст с количеством очков
    Text textScore("", font, 40);
    textScore.setStyle(sf::Text::Bold);
    textScore.setFillColor(Color::White);
    textScore.setPosition(scene.scoreObject.rect.left, scene.scoreObject.rect.top);

    // Создаём текст с количеством очков
    Text textTime("", font, 40);
    textTime.setStyle(sf::Text::Bold);
    textTime.setFillColor(Color::White);
    textTime.setPosition(scene.timeObject.rect.left, scene.timeObject.rect.top);

    // Создаём текст с состоянием противников
    Text textState("", font, 40);
    textState.setStyle(sf::Text::Bold);
    textState.setFillColor(Color::White);
    textState.setPosition(scene.stateObject.rect.left, scene.stateObject.rect.top);

    // Создаём текст с кол-вом решенных задач
    Text textTasks("", font, 40);
    textTasks.setStyle(sf::Text::Bold);
    textTasks.setFillColor(Color::White);
    textTasks.setPosition(scene.tasksObject.rect.left, scene.tasksObject.rect.top);

    // Создаём текст с кол-вом решенных задач
    Text textLevelNum("", font, 40);
    textLevelNum.setStyle(sf::Text::Bold);
    textLevelNum.setFillColor(Color::White);
    textLevelNum.setPosition(scene.levelNumObject.rect.left, scene.levelNumObject.rect.top);
    //////////////////////////////СОЗДАЁМ ИРОВОЙ ПРОЦЕСС//////////////////////////////
    GameManager* game = new GameManager();
    game->setSolids(&scene.solidsPlayer);
    game->setFood(&apples, &firstBanana, &secondBanana, &energies);
    game->setSabotages(&firstSabotage, &secondSabotage);
    game->setEnemy(&enemies);
    game->setPlayer(&player);
    game->setLives(&lives);
    game->setVentilation(&firstVentilation, &secondVentilation);
    game->setText(&textScore, &textTime, &textState, &textTasks, &textLevelNum);
    game->levelNum = gameLevel;
    //////////////////////////////ИГРАЕМ//////////////////////////////
    Clock clock;
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMilliseconds(); // Берём у часиков время
        clock.restart(); // Запускаем часики
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(player.getLives() == 0){
            window.close();
            return 0;
        }
        if(Sabotage::getSolvedTasks() == 4){
            window.close();
            return 1;
        }
        lvl.Draw(window); // рисуем карту
        game->play(time);
        game->draw(window);
        window.display();
    }
    return 0;
}


#endif // GAME_H
