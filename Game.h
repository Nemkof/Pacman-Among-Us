#ifndef GAME_H
#define GAME_H
#include "Lives.h"
#include "Player.h"
#include "Sabotages.h"
#include "Ventilation.h"
#include "GameManager.h"
using namespace sf;
using namespace std;
int volume = 5;

int game()
{
    //////////////////////////////СОЗДАЁМ ОКНО//////////////////////////////
    RenderWindow window(VideoMode(2000, 1750), "Pacman Among Us");  // Создаём окно
    // Music music; //создаем объект музыки
    // music.openFromFile("sounds/zhelezo.ogg"); //загружаем файл
    // music.setVolume(volume);
    // music.setLoop(true);
    // music.play(); //воспроизводим музыку
    //////////////////////////////ЗАГРУЖАЕМ КАРТУ//////////////////////////////
    Level lvl;
    lvl.LoadFromFile("map.tmx");

    //////////////////////////////ПОЛУЧАЕМ ВСЕ ОБЪЕКТЫ//////////////////////////////
    std::vector<Object> obj = lvl.GetAllObjects(); // Получаем вектор всех объектов карты

    std::vector<Object> rotates; // Получаем вектор из всех тайлов-поворотов
    std::vector<Object> solidsEnemy; // Получаем вектор из всех тайлов-стен
    std::vector<Object> solidsPlayer; // Получаем вектор из всех тайлов-стен
    std::vector<Object> appleObjects; // Получаем вектор из всех тайлов-яблочек
    std::vector<Object> energyObjects; // Получаем вектор из всех тайлов-энерджайзеров
    Object firstBananaObject; // Получаем первый банан
    Object secondBananaObject; // Получаем второй банан
    Object playerObject; // Получаем тайл игрока
    Object blinkyObject; // Получаем тайл блинки
    Object pinkyObject; // Получаем тайл пинки
    Object inkyObject; // Получаем тайл инки
    Object clydeObject; // Получаем тайл клайда
    Object blinkyTargetObject; // Получаем тайл блинки
    Object pinkyTargetObject; // Получаем тайл пинки
    Object inkyTargetObject; // Получаем тайл инки
    Object clydeTargetObject; // Получаем тайл клайда
    Object firstSabotageObject; // Получаем тайл первого саботажа
    Object secondSabotageObject; // Получаем тайл второго саботажа
    Object livesObject; // Получаем тайл сердечек
    Object scoreObject; // Получаем тайл очков
    Object timeObject; // Получаем тайл очков
    Object firstVentilationObject; // Получаем тайл первой вентиляции
    Object secondVentilationObject; // Получаем тайл второй вентиляции
    for(auto it: obj){
        if (it.name == "rotate") rotates.push_back(it);
        else if(it.name == "solid") {solidsPlayer.push_back(it); solidsEnemy.push_back(it);}
        else if(it.name == "fakesolid1") solidsEnemy.push_back(it);
        else if(it.name == "fakesolid2") solidsEnemy.push_back(it);
        else if(it.name == "apple") appleObjects.push_back(it);
        else if(it.name == "energy") energyObjects.push_back(it);
        else if(it.name == "firstBanana") firstBananaObject = it;
        else if(it.name == "secondBanana") secondBananaObject = it;
        else if(it.name == "player") playerObject = it;
        else if(it.name == "Blinky") blinkyObject = it;
        else if(it.name == "Pinky") pinkyObject = it;
        else if(it.name == "Inky") inkyObject = it;
        else if(it.name == "Clyde") clydeObject = it;
        else if(it.name == "BlinkyTarget") blinkyTargetObject = it;
        else if(it.name == "PinkyTarget") pinkyTargetObject = it;
        else if(it.name == "InkyTarget") inkyTargetObject = it;
        else if(it.name == "ClydeTarget") clydeTargetObject = it;
        else if(it.name == "sabotageFirst") firstSabotageObject = it;
        else if(it.name == "sabotageSecond") secondSabotageObject = it;
        else if(it.name == "lives") livesObject = it;
        else if(it.name == "score") scoreObject = it;
        else if(it.name == "time") timeObject = it;
        else if(it.name == "firstVentilation") firstVentilationObject = it;
        else if(it.name == "secondVentilation") secondVentilationObject = it;
    }
    //////////////////////////////СОЗДАЕМ САБОТАЖИ//////////////////////////////
    Sabotage firstSabotage(firstSabotageObject);
    Sabotage secondSabotage(secondSabotageObject);
    //////////////////////////////СОЗДАЕМ ЯБЛОКИ //////////////////////////////
    std::vector<Apple*> apples;
    for(size_t i = 0; i < appleObjects.size(); i++)
    {
        Apple* tmp = new Apple(appleObjects.at(i));
        apples.push_back(tmp);
    }
    //////////////////////////////СОЗДАЕМ БАНАНЫ//////////////////////////////
    Banana firstBanana(firstBananaObject);
    Banana secondBanana(secondBananaObject);
    //////////////////////////////СОЗДАЕМ ЭНЕРДЖАЙЗЕРЫ//////////////////////////////
    std::vector<Energy*> energies;
    for(size_t i = 0; i < energyObjects.size(); i++)
    {
        Energy* tmp = new Energy(energyObjects.at(i));
        energies.push_back(tmp);
    }
    //////////////////////////////СОЗДАЁМ ВЕНТИЛЯЦИЮ//////////////////////////////
    Ventilation firstVentilation(firstVentilationObject);
    Ventilation secondVentilation(secondVentilationObject);
    //////////////////////////////СОЗДАЁМ ВРАГОВ//////////////////////////////
    vector<Enemy*> enemies;
    // создаём всех врагов
    Blinky blinky(blinkyObject, blinkyTargetObject);
    blinky.setRotates(&rotates);
    blinky.setSolids(&solidsEnemy);

    Pinky pinky(pinkyObject, pinkyTargetObject);
    pinky.setRotates(&rotates);
    pinky.setSolids(&solidsEnemy);

    Inky inky(inkyObject, inkyTargetObject);
    inky.setRotates(&rotates);
    inky.setSolids(&solidsEnemy);

    Clyde clyde(clydeObject, clydeTargetObject);
    clyde.setRotates(&rotates);
    clyde.setSolids(&solidsEnemy);
    // и закидываем в список всех наших врагов с карты
    enemies.push_back(&blinky);
    enemies.push_back(&pinky);
    enemies.push_back(&inky);
    enemies.push_back(&clyde);
    //////////////////////////////СОЗДАЁМ ОБЪЕКТ СЕРДЕЧЕК//////////////////////////////
    Lives lives(livesObject);
    //////////////////////////////СОЗДАЁМ ИГРОКА//////////////////////////////
    Player player(playerObject);
    player.setSolids(&solidsPlayer);
    player.setApples(&apples);
    player.setEnergy(&energies);
    player.setFirstBanana(&firstBanana);
    player.setSecondBanana(&secondBanana);
    player.setFirstSabotage(&firstSabotage);
    player.setSecondSabotage(&secondSabotage);
    player.setEnemy(&enemies);
    player.setFirstVentilation(&firstVentilation);
    player.setSecondVentilation(&secondVentilation);
    //////////////////////////////РАБОТАЕМ С ТЕКСТОМ//////////////////////////////
    Font font;  // Создаём объект типа шрифт
    font.loadFromFile("images/forText.ttf"); // Загружаем шрифт в объект
    // Создаём текст с количеством очков
    Text textScore("", font, 40);
    textScore.setStyle(sf::Text::Bold);
    textScore.setFillColor(Color::White);

    // Создаём текст с количеством очков
    Text textTime("", font, 40);
    textTime.setStyle(sf::Text::Bold);
    textTime.setFillColor(Color::White);

    textScore.setPosition(scoreObject.rect.left, scoreObject.rect.top);
    textTime.setPosition(timeObject.rect.left, timeObject.rect.top);
    //////////////////////////////СОЗДАЁМ ИРОВОЙ ПРОЦЕСС//////////////////////////////
    GameManager* game = new GameManager();
    game->setSolids(&solidsPlayer);
    game->setFood(&apples, &firstBanana, &secondBanana, &energies);
    game->setSabotages(&firstSabotage, &secondSabotage);
    game->setEnemy(&enemies);
    game->setPlayer(&player);
    game->setLives(&lives);
    game->setVentilation(&firstVentilation, &secondVentilation);
    game->setText(&textScore, &textTime);
    // Создаём часики для работы со временем
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
