#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "lives.h"
#include "player.h"
#include "sabotages.h"
using namespace sf;
using namespace std;
int volume = 0;

int game()
{
    //////////////////////////////СОЗДАЁМ ОКНО//////////////////////////////
    RenderWindow window(VideoMode(2000, 1750), "Among Us: Final");  // Создаём окно

    Music music; //создаем объект музыки
    music.openFromFile("../../sounds/music.ogg"); //загружаем файл
    music.setVolume(volume);
    music.play(); //воспроизводим музыку

    //////////////////////////////ЗАГРУЖАЕМ КАРТУ//////////////////////////////
    Level lvl;
    lvl.LoadFromFile("../../map.tmx");

    //////////////////////////////ПОЛУЧАЕМ ВСЕ ОБЪЕКТЫ//////////////////////////////
    std::vector<Object> obj = lvl.GetAllObjects(); // Получаем вектор всех объектов карты

    std::vector<Object> rotates; // Получаем вектор из всех тайлов-поворотов
    std::vector<Object> solids; // Получаем вектор из всех тайлов-стен
    std::vector<Object> appleObjects; // Получаем вектор из всех тайлов-яблочек
    Object firstBananaObject; // Получаем первый банан
    Object secondBananaObject; // Получаем второй банан
    Object playerObject; // Получаем тайл игрока
    Object blinkyObject; // Получаем тайл блинки
    Object pinkyObject; // Получаем тайл пинки
    Object inkyObject; // Получаем тайл инки
    Object clydeObject; // Получаем тайл клайда
    Object firstSabotageObject; // Получаем тайл первого саботажа
    Object secondSabotageObject; // Получаем тайл второго саботажа
    Object livesObject;
    Object scoreObject;
    Object firstVentilation;
    Object secondVentilation;
    for(auto it: obj){
        if (it.name == "rotate") rotates.push_back(it);
        else if(it.name == "solid") solids.push_back(it);
        else if(it.name == "fakesolid1") solids.push_back(it);
        else if(it.name == "fakesolid2") solids.push_back(it);
        else if(it.name == "apple") appleObjects.push_back(it);
        else if(it.name == "firstBanana") firstBananaObject = it;
        else if(it.name == "secondBanana") secondBananaObject = it;
        else if(it.name == "player") playerObject = it;
        else if(it.name == "Blinky") blinkyObject = it;
        else if(it.name == "Pinky") pinkyObject = it;
        else if(it.name == "Inky") inkyObject = it;
        else if(it.name == "Clyde") clydeObject = it;
        else if(it.name == "sabotageFirst") firstSabotageObject = it;
        else if(it.name == "sabotageSecond") secondSabotageObject = it;
        else if(it.name == "lives") livesObject = it;
        else if(it.name == "score") scoreObject = it;
    }

    //////////////////////////////ПИХАЕМ САБОТАЖИ В КАРТУ//////////////////////////////
    Image firstSabotageImage;
    firstSabotageImage.loadFromFile("../../images/firstSabotage.png");
    Sabotage firstSabotage(firstSabotageImage, firstSabotageObject);

    Image secondSabotageImage;
    secondSabotageImage.loadFromFile("../../images/secondSabotage.png");
    Sabotage secondSabotage(secondSabotageImage, secondSabotageObject);
    //////////////////////////////ПИХАЕМ ЯБЛОКИ В КАРТУ//////////////////////////////
    Image appleImage;
    appleImage.loadFromFile("../../images/apple.png");  // Загружаем текстуру яблочка
    appleImage.createMaskFromColor(Color(255,255,255));
    Texture appleTexture;
    appleTexture.loadFromImage(appleImage);  // Загружаем текстуру яблочка
    Sprite appleSprite;
    appleSprite.setTexture(appleTexture);  // Загружаем текстуру в спрайт

    std::vector<Apple> apples; // Создаём массив яблочек
    for(size_t i = 0; i < appleObjects.size(); i++) // Проходимся по всем тайлам-яблочкам
    {
        // Создаём хелпер-яблочко, которое будет стоять на i-том тайле
        Apple tmp(appleSprite, appleObjects.at(i).rect.left, appleObjects.at(i).rect.top, appleTexture.getSize());
        apples.push_back(tmp); // Помещаем всё в наш вектор объектов
    }

    //////////////////////////////ПИХАЕМ БАНАНЫ В КАРТУ//////////////////////////////
    Image bananaImage;
    bananaImage.loadFromFile("../../images/banana.png");  // Загружаем текстуру банана
    bananaImage.createMaskFromColor(Color(255,255,255));
    Texture bananaTexture;
    bananaTexture.loadFromImage(bananaImage);  // Загружаем текстуру банана
    Sprite bananaSprite;
    bananaSprite.setTexture(bananaTexture);  // Загружаем текстуру в спрайт
    Banana firstBanana(bananaSprite, firstBananaObject.rect.left, firstBananaObject.rect.top, bananaTexture.getSize()); // Создаём первый банан
    Banana secondBanana(bananaSprite, secondBananaObject.rect.left, secondBananaObject.rect.top, bananaTexture.getSize()); // Создаём второй банан

    //////////////////////////////СОЗДАЁМ ИГРОКА//////////////////////////////
    Player player(obj, playerObject);
    player.setApples(&apples);
    player.setFirstBanana(&firstBanana);
    player.setSecondBanana(&secondBanana);
    player.setFirstSabotage(&firstSabotage);
    player.setSecondSabotage(&secondSabotage);
    //////////////////////////////СОЗДАЁМ ОБЪЕКТ СЕРДЕЧЕК//////////////////////////////
    Lives lives(livesObject);

    //////////////////////////////СОЗДАЁМ ВРАГОВ//////////////////////////////
    vector<Enemy*> entities;// создаём список, сюда будем кидать объекты
    // создаём всех врагов
    Blinky blinky(rotates, solids, blinkyObject);
    Pinky pinky(rotates, solids, pinkyObject);
    Inky inky(rotates, solids, inkyObject);
    Clyde clyde(rotates, solids, clydeObject);
    // и закидываем в список всех наших врагов с карты
    entities.push_back(&blinky);
    entities.push_back(&pinky);
    entities.push_back(&inky);
    entities.push_back(&clyde);

    //////////////////////////////РАБОТАЕМ С ТЕКСТОМ//////////////////////////////
    Font font;  // Создаём объект типа шрифт
    font.loadFromFile("../../images/forText.ttf"); // Загружаем шрифт в объект
    // Создаём текст с количеством очков
    Text textScore("", font, 55);
    textScore.setStyle(sf::Text::Bold);
    textScore.setFillColor(Color::White);

    // Создаём часики для работы со временем
    Clock clock;
    while (window.isOpen())
    {
        //////////////////////////////ВРЕМЯ//////////////////////////////
        float time = clock.getElapsedTime().asMicroseconds(); // Берём у часиков время
        clock.restart(); // Запускаем часики
        time = time / 800; // Уменьшаем время, чтобы не так быстро всё летало

        //////////////////////////////ДАРИМ ИГРЕ ЖИЗНЬ//////////////////////////////
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        /// Если три раза попались врагу, то игра окончена
        if(!player.getLives()){
            window.close();
            return 1;
        }


        lvl.Draw(window); // Рисуем карту

        //////////////////////////////РАБОТАЕМ С ЕДОЙ//////////////////////////////
        for (auto it : apples) // Проходимся по всем яблочкам
        {
            if(!it.isDead()) // Если яблочко не съели
                window.draw(it.getSprite()); // То нужно его нарисовать
        }
        if(firstBanana.getCondition() == "notEaten") window.draw(firstBanana.getSprite()); // То нужно его нарисовать
        if(secondBanana.getCondition() == "notEaten") window.draw(secondBanana.getSprite()); // То нужно его нарисовать
        //////////////////////////////ДАРИМ САБОТАЖАМ ЖИЗНЬ//////////////////////////////
        firstSabotage.update(time);
        window.draw(firstSabotage.getSprite());

        secondSabotage.update(time);
        window.draw(secondSabotage.getSprite());
        //////////////////////////////ДАРИМ ИГРОКУ ЖИЗНЬ//////////////////////////////
        player.update(time, entities);
        window.draw(player.sprite); // Рисуем игрока

        lives.update(player.getLives());
        window.draw(lives.getSprite());

        //////////////////////////////ДАРИМ ВРАГАМ ЖИЗНЬ//////////////////////////////
        for(size_t i = 0; i < entities.size(); i++)
        {
            entities[i]->update(time, player.x, player.y);
            window.draw(entities[i]->sprite);
        }



        //////////////////////////////РАБОТАЕМ С ТЕКСТОМ//////////////////////////////
        textScore.setPosition(scoreObject.rect.left, scoreObject.rect.top); // Устанавливаем счёт очков в угол
        textScore.setString("score: " + std::to_string(player.getScore())); // Получаем нужную надпись
        window.draw(textScore); // Рисуем счёт очков

        window.display(); // Показываем наше игровое окно
    }
    return 0;
}

#endif // GAMEMANAGER_H
