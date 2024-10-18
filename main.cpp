#include "menu.h"
#include "lives.h"
#include "player.h"
//#include "enemy.h"
using namespace sf;
using namespace std;

int main()
{

    //////////////////////////////СОЗДАЁМ ОКНО//////////////////////////////
    RenderWindow window(VideoMode(2000, 1750), "Among Us: Final");  // Создаём окно

    /// Открываем меню
    if(!menu(window))
    {
        return -1;
    }

    Music music;//создаем объект музыки
    music.openFromFile("../../sounds/music.ogg");//загружаем файл
    music.setVolume(5);
    music.play();//воспроизводим музыку

    //////////////////////////////ЗАГРУЖАЕМ КАРТУ//////////////////////////////
    Level lvl; // Создаём объект типа "Карта"
    lvl.LoadFromFile("../../map.tmx");  // Загружаем нашу карту
    std::vector<Object> obj = lvl.GetAllObjects(); // Получаем вектор объектов карты


    //////////////////////////////ПИХАЕМ ЕДУ В КАРТУ//////////////////////////////
    Texture appleTexture;
    appleTexture.loadFromFile("../../images/apple.png");  // Загружаем текстуру яблочка
    Sprite appleSprite;
    appleSprite.setTexture(appleTexture);  // Загружаем текстуру в спрайт

    std::vector<Object> appleObjects(lvl.GetObjects("food")); // Получаем вектор из всех тайлов-яблочек
    std::vector<Food> apples; // Создаём массив яблочек
    for(size_t i = 0; i < appleObjects.size(); i++) // Проходимся по всем тайлам-яблочкам
    {
        // Создаём хелпер-яблочко, которое будет стоять на i-том тайле
        Food tmp(appleSprite, appleObjects.at(i).rect.left, appleObjects.at(i).rect.top);
        apples.push_back(tmp); // Помещаем всё в наш вектор объектов
    }

/*
    //////////////////////////////РИСУЕМ ЛЮКИ//////////////////////////////
    Texture hatchTexture;
    hatchTexture.loadFromFile("../../images/hatch.png");

    Sprite hatchLeftSprite;
    hatchLeftSprite.setTexture(hatchTexture);
    hatchLeftSprite.setTextureRect(IntRect(0,0,60,90));
    Sprite hatchRightSprite;
    hatchRightSprite.setTexture(hatchTexture);
    hatchRightSprite.setTextureRect(IntRect(0,0,60,90));

    Object hatchLeft = lvl.GetObjects("ventilation").at(0);
    Object hatchRight = lvl.GetObjects("ventilation").at(1);

    hatchLeftSprite.setPosition(hatchLeft.rect.left, hatchLeft.rect.top + 10);
    hatchRightSprite.setPosition(hatchRight.rect.left, hatchRight.rect.top + 10);
*/
    //////////////////////////////ДЕЛАЕМ ТЕКСТУРУ ИГРОКОВ//////////////////////////////
    String pathToEntityImage = "../../images/entity.png"; // 72x90
    int widthEntity = 72, heightEntity = 90;
    Image entityImage;
    entityImage.loadFromFile(pathToEntityImage);

    //////////////////////////////ДЕЛАЕМ ТЕКСТУРУ LIVES//////////////////////////////
    String pathToLivesImage = "../../images/lives.png"; // 72x90
    int widthLives = 280, heightLives = 70;
    Image livesImage;
    livesImage.loadFromFile(pathToLivesImage);
    livesImage.createMaskFromColor(Color(255,255,255));
    Lives lives(livesImage, widthLives, heightLives, 1300, 550);


    //////////////////////////////СОЗДАЁМ ВРАГОВ//////////////////////////////
    vector<Object> rotates = lvl.GetObjects("rotate");

    vector<Enemy*> entities;//создаю список, сюда буду кидать объекты
    vector<Object> enemies = lvl.GetObjects("enemy");
    //for (size_t i = 0; i < enemies.size(); i++)// проходимся по элементам этого вектора(а именно по врагам)
    entities.push_back(new Blinky(rotates, entityImage, obj, enemies[0].rect.left, enemies[0].rect.top, widthEntity, heightEntity));//и закидываем в список всех наших врагов с карты
    entities.push_back(new Pinky(rotates, entityImage, obj, enemies[1].rect.left, enemies[1].rect.top, widthEntity, heightEntity));//и закидываем в список всех наших врагов с карты
    entities.push_back(new Inky(rotates, entityImage, obj, enemies[2].rect.left, enemies[2].rect.top, widthEntity, heightEntity));//и закидываем в список всех наших врагов с карты
    entities.push_back(new Clyde(rotates, entityImage, obj, enemies[3].rect.left, enemies[3].rect.top, widthEntity, heightEntity));//и закидываем в список всех наших врагов с карты

    //////////////////////////////СОЗДАЁМ ИГРОКА//////////////////////////////
    Object player = lvl.GetObject("player");
    Player Main_Player(entityImage, obj, player.rect.left, player.rect.top, widthEntity, heightEntity, &apples);

    //////////////////////////////РАБОТАЕМ С ТЕКСТОМ//////////////////////////////
    Font font;  // Создаём объект типа шрифт
    font.loadFromFile("../../images/forText.ttf"); // Загружаем шрифт в объект

    // Создаём текст с количеством очков
    Text textScore("", font, 55);
    textScore.setStyle(sf::Text::Bold);
    textScore.setFillColor(Color::White);

    // Создаём имя главного героя
    Text playerName("", font, 20);
    playerName.setStyle(sf::Text::Bold);
    playerName.setFillColor(Color::Red);


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
        //////////////////////////////ДАРИМ ИГРОКУ ЖИЗНЬ//////////////////////////////
        Main_Player.update(time, entities);
        window.draw(Main_Player.sprite); // Рисуем игрока

        lives.update(Main_Player.isLive());
        window.draw(lives.getSprite());

        //////////////////////////////ДАРИМ ВРАГАМ ЖИЗНЬ//////////////////////////////


            entities[0]->update(time, Main_Player.x - 200, Main_Player.y);
            entities[1]->update(time, Main_Player.x + 200, Main_Player.y);
            entities[2]->update(time, Main_Player.x, Main_Player.y - 200);
            entities[3]->update(time, Main_Player.x, Main_Player.y + 200);
            window.draw(entities[0]->sprite);
            window.draw(entities[1]->sprite);
            window.draw(entities[2]->sprite);
            window.draw(entities[3]->sprite);


        //////////////////////////////РАБОТАЕМ С ЕДОЙ//////////////////////////////
        for (auto it : apples) // Проходимся по всем яблочкам
        {
            if(!it.isDead()) // Если яблочко не съели
            window.draw(it.getSprite()); // То нужно его нарисовать
        }


        //////////////////////////////РАБОТАЕМ С ТЕКСТОМ//////////////////////////////
        textScore.setPosition(1300, 0); // Устанавливаем счёт очков в угол
        textScore.setString("score: " + std::to_string(Main_Player.getScore())); // Получаем нужную надпись
        //textScore.setString("score: " + (entities[0]->getDirection())); // Получаем нужную надпись
        window.draw(textScore); // Рисуем счёт очков

        playerName.setPosition(Main_Player.getX(), Main_Player.getY() - Main_Player.h / 5); // Устанавливаем имя игрока над ним
        playerName.setString("Impostor"); // Устанавливаем нужную надпись
        window.draw(playerName);  // Рисуем имя игрока


        // test

        //


        /// Если три раза попались врагу, то игра окончена
        if(!Main_Player.isLive()){
            window.close();
            return 1;
        }

        window.display(); // Показываем наше игровое окно
    }
    return 0;
}




