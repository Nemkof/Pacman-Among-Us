#include "SceneLoader.h"
SceneLoader::SceneLoader(Level& lvl){
    std::vector<Object> obj = lvl.GetAllObjects(); // Получаем вектор всех объектов карты

    std::vector<Object> rotates; // Получаем вектор из всех тайлов-поворотов
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
        else if(it.name == "solid") { playerSolids.push_back(it); enemySolids.push_back(it);}
        else if(it.name == "fakesolid1") enemySolids.push_back(it);
        else if (it.name == "fakesolid2") enemySolids.push_back(it);
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
    firstSabotage = new Sabotage(firstSabotageObject);
    secondSabotage = new Sabotage(secondSabotageObject);
    //////////////////////////////СОЗДАЕМ ЯБЛОКИ //////////////////////////////
    for(size_t i = 0; i < appleObjects.size(); i++)
    {
        Apple* tmp = new Apple(appleObjects.at(i));
        apples.push_back(tmp);
    }
    //////////////////////////////СОЗДАЕМ БАНАНЫ//////////////////////////////
    firstBanana = new Banana(firstBananaObject);
    secondBanana = new Banana(secondBananaObject);
    //////////////////////////////СОЗДАЕМ ЭНЕРДЖАЙЗЕРЫ//////////////////////////////
    for(size_t i = 0; i < energyObjects.size(); i++)
    {
        Energy* tmp = new Energy(energyObjects.at(i));
        energies.push_back(tmp);
    }
    //////////////////////////////СОЗДАЁМ ВЕНТИЛЯЦИЮ//////////////////////////////
    firstVentilation = new Ventilation(firstVentilationObject);
    secondVentilation = new Ventilation(secondVentilationObject);
    //////////////////////////////СОЗДАЁМ ВРАГОВ//////////////////////////////
    // создаём всех врагов
    // и закидываем в список всех наших врагов с карты
    enemies.push_back(new Blinky(blinkyObject, blinkyTargetObject));
    enemies.push_back(new Pinky(pinkyObject, pinkyTargetObject));
    enemies.push_back(new Inky(inkyObject, inkyTargetObject));
    enemies.push_back(new Clyde(clydeObject, clydeTargetObject));
    for(auto it: enemies){
        it->setRotates(&rotates);
        it->setSolids(&enemySolids);
    }

    //////////////////////////////СОЗДАЁМ ОБЪЕКТ СЕРДЕЧЕК//////////////////////////////
    lives = new Lives(livesObject);
    //////////////////////////////СОЗДАЁМ ИГРОКА//////////////////////////////
    player = new Player(playerObject);
    player->setSolids(&playerSolids);
    player->setApples(&apples);
    player->setEnergy(&energies);
    player->setFirstBanana(firstBanana);
    player->setSecondBanana(secondBanana);
    player->setFirstSabotage(firstSabotage);
    player->setSecondSabotage(secondSabotage);
    player->setEnemy(&enemies);
    player->setFirstVentilation(firstVentilation);
    player->setSecondVentilation(secondVentilation);


    font.loadFromFile("images/forText.ttf"); // Загружаем шрифт в объект

    textScore = new Text("", font, 40);
    textScore->setStyle(sf::Text::Bold);
    textScore->setFillColor(Color::White);
    textScore->setPosition(scoreObject.rect.left, scoreObject.rect.top);

    textTime = new Text("", font, 40);
    textTime->setStyle(sf::Text::Bold);
    textTime->setFillColor(Color::White);
    textTime->setPosition(timeObject.rect.left, timeObject.rect.top);
}

SceneLoader::~SceneLoader(){
    delete firstSabotage;
    delete secondSabotage;

    delete[] &apples;
    delete[] &energies;
    delete firstBanana;
    delete secondBanana;

    delete firstVentilation;
    delete secondVentilation;

    delete lives;

    delete player;
    delete[] &enemies;

    delete textScore;
    delete textTime;
}
