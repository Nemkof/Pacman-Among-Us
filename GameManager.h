#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "lives.h"
#include "player.h"

using namespace sf;
using namespace std;

int game()
{
    //////////////////////////////СОЗДАЁМ ОКНО//////////////////////////////
    RenderWindow window(VideoMode(2000, 1750), "Among Us: Final");  // Создаём окно

    Music music;//создаем объект музыки
    music.openFromFile("../../sounds/music.ogg");//загружаем файл
    music.setVolume(5);
    music.play();//воспроизводим музыку

    //////////////////////////////ЗАГРУЖАЕМ КАРТУ//////////////////////////////
    Level lvl; // Создаём объект типа "Карта"
    lvl.LoadFromFile("../../map.tmx");  // Загружаем нашу карту
    std::vector<Object> obj = lvl.GetAllObjects(); // Получаем вектор объектов карты

    // Получаем все необходимые объекты карты
    std::vector<Object> appleObjects(lvl.GetObjects("food")); // Получаем вектор из всех тайлов-яблочек
    std::vector<Object> rotates(lvl.GetObjects("rotate")); // Получаем вектор из всех тайлов-яблочек
    std::vector<Object> solids(lvl.GetObjects("solid")); // Получаем вектор из всех тайлов-яблочек
    Object playerObject = lvl.GetObject("player"); // Получаем вектор из всех тайлов-яблочек
    Object blinkyObject = lvl.GetObject("Blinky"); // Получаем вектор из всех тайлов-яблочек
    Object pinkyObject = lvl.GetObject("Pinky"); // Получаем вектор из всех тайлов-яблочек
    Object inkyObject = lvl.GetObject("Inky"); // Получаем вектор из всех тайлов-яблочек
    Object clydeObject = lvl.GetObject("Clyde");
    //

    //////////////////////////////ПИХАЕМ ЕДУ В КАРТУ//////////////////////////////
    Texture appleTexture;
    appleTexture.loadFromFile("../../images/apple.png");  // Загружаем текстуру яблочка
    Sprite appleSprite;
    appleSprite.setTexture(appleTexture);  // Загружаем текстуру в спрайт

    std::vector<Food> apples; // Создаём массив яблочек
    for(size_t i = 0; i < appleObjects.size(); i++) // Проходимся по всем тайлам-яблочкам
    {
        // Создаём хелпер-яблочко, которое будет стоять на i-том тайле
        Food tmp(appleSprite, appleObjects.at(i).rect.left, appleObjects.at(i).rect.top);
        apples.push_back(tmp); // Помещаем всё в наш вектор объектов
    }

    //////////////////////////////ДЕЛАЕМ ТЕКСТУРУ ИГРОКОВ//////////////////////////////
    int widthEntity = 72, heightEntity = 90;

    //////////////////////////////ДЕЛАЕМ ТЕКСТУРУ LIVES//////////////////////////////
    String pathToLivesImage = "../../images/lives.png"; // 72x90
    int widthLives = 280, heightLives = 70;
    Image livesImage;
    livesImage.loadFromFile(pathToLivesImage);
    livesImage.createMaskFromColor(Color(255,255,255));
    Lives lives(livesImage, widthLives, heightLives, 1300, 550);


    //////////////////////////////СОЗДАЁМ ВРАГОВ//////////////////////////////
    vector<Enemy*> entities;//создаю список, сюда буду кидать объекты

    //for (size_t i = 0; i < enemies.size(); i++)// проходимся по элементам этого вектора(а именно по врагам)
    Blinky blinky(rotates, solids, blinkyObject);
    Pinky pinky(rotates, solids, pinkyObject);
    Inky inky(rotates, solids, inkyObject);
    Clyde clyde(rotates, solids, clydeObject);

    entities.push_back(&blinky);//и закидываем в список всех наших врагов с карты
    entities.push_back(&pinky);//и закидываем в список всех наших врагов с карты
    entities.push_back(&inky);//и закидываем в список всех наших врагов с карты
    entities.push_back(&clyde);//и закидываем в список всех наших врагов с карты

    //////////////////////////////СОЗДАЁМ ИГРОКА//////////////////////////////
    Player player(obj, playerObject, &apples);

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

        //////////////////////////////РИСУЕМ КАРТУ//////////////////////////////
        lvl.Draw(window);

        /*
        //////////////////////////////РИСУЕМ ЛЮКИ//////////////////////////////
        window.draw(hatchRightSprite);
        window.draw(hatchLeftSprite);
        */
        //////////////////////////////РАБОТАЕМ С ЕДОЙ//////////////////////////////
        for (auto it : apples) // Проходимся по всем яблочкам
        {
            if(!it.isDead()) // Если яблочко не съели
                window.draw(it.getSprite()); // То нужно его нарисовать
        }


        //////////////////////////////ДАРИМ ИГРОКУ ЖИЗНЬ//////////////////////////////
        player.update(time, entities);
        window.draw(player.sprite); // Рисуем игрока

        lives.update(player.isLive());
        window.draw(lives.getSprite());

        //////////////////////////////ДАРИМ ВРАГАМ ЖИЗНЬ//////////////////////////////
        for(size_t i = 0; i < entities.size(); i++)
        {
            entities[i]->update(time, player.x, player.y);
            window.draw(entities[i]->sprite);
        }

        //////////////////////////////РАБОТАЕМ С ТЕКСТОМ//////////////////////////////
        textScore.setPosition(1300, 0); // Устанавливаем счёт очков в угол
        // textScore.setString("score: " + std::to_string(player.getScore())); // Получаем нужную надпись
        textScore.setString("score: " + inkyObject.name); // Получаем нужную надпись

        window.draw(textScore); // Рисуем счёт очков

        /// Если три раза попались врагу, то игра окончена
        if(!player.isLive()){
            window.close();
            return 1;
        }

        window.display(); // Показываем наше игровое окно
    }
    return 0;
}

#endif // GAMEMANAGER_H
