#ifndef MENU_H
#define MENU_H
#include "entity.h"
bool menu(RenderWindow & window) {

    Texture BackgroundTexture;
    Texture BannerTexture;
    Texture SettingsTexture;
    Texture StartTexture;
    Texture HowToPlayTexture;
    Texture ExitTexture;

    BackgroundTexture.loadFromFile("../../images/menu/Background.png");
    BannerTexture.loadFromFile("../../images/menu/Banner.png");
    StartTexture.loadFromFile("../../images/menu/Start.png");
    SettingsTexture.loadFromFile("../../images/menu/Settings.png");
    HowToPlayTexture.loadFromFile("../../images/menu/Howtoplay.png");
    ExitTexture.loadFromFile("../../images/menu/Exit.png");

    Sprite BackgroundSprite(BackgroundTexture);
    Sprite BannerSprite(BannerTexture);
    Sprite SettingsSprite(SettingsTexture);
    Sprite StartSprite(StartTexture);
    Sprite HowToPlaySprite(HowToPlayTexture);
    Sprite ExitSprite(ExitTexture);

    BannerSprite.setPosition(450, 150);
    SettingsSprite.setPosition(500, 500); // 145x50
    StartSprite.setPosition(625, 350); // 184x107
    BackgroundSprite.setPosition(0, 0);  // 1430x940
    HowToPlaySprite.setPosition(750,500);  // 207x50
    ExitSprite.setPosition(525,575); // 67x50

    bool isMenu = 1;
    int menuNum = 0;

    Texture aboutTexture;
    aboutTexture.loadFromFile("../../images/menu/about.png");
    Sprite aboutSprite;
    aboutSprite.setTexture(aboutTexture);
    aboutSprite.setPosition(200,200);


    SoundBuffer bufferButton1;
    bufferButton1.loadFromFile("../../sounds/button1.wav");// тут загружаем в буфер что то
    Sound Button1;
    Button1.setBuffer(bufferButton1);
    Button1.setVolume(100);




    //////////////////////////////МЕНЮ///////////////////
    while (isMenu)
    {
        window.clear(Color::Black);

        SettingsSprite.setColor(Color::White);
        HowToPlaySprite.setColor(Color::White);
        ExitSprite.setColor(Color::White);
        StartSprite.setColor(Color::White);

        menuNum = 0;

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (IntRect(500, 500, 145, 50).contains(Mouse::getPosition(window))) { SettingsSprite.setColor(Color(75,75,75)); menuNum = 1; }
        if (IntRect(750, 500, 207, 50).contains(Mouse::getPosition(window))) { HowToPlaySprite.setColor(Color(75,75,75)); menuNum = 2; }
        if (IntRect(525, 575, 67, 50).contains(Mouse::getPosition(window))) { ExitSprite.setColor(Color(75,75,75)); menuNum = 3; }
        if (IntRect(625, 350, 184, 107).contains(Mouse::getPosition(window))) { StartSprite.setColor(Color(75,75,75)); menuNum = 4; }
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            /// Настройки
            if (menuNum == 1) break;
            /// Меню
            else if (menuNum == 2)
            {
                window.draw(aboutSprite);
                window.display();
                while (!Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    Event about;
                    while (window.pollEvent(about))
                    {
                        if (about.type == sf::Event::Closed)
                            window.close();
                    }
                }
            }
            /// Выход
            else if (menuNum == 3) ;
            /// Начать игру
            else if (menuNum == 4) return true;; //если нажали первую кнопку, то выходим из меню
        }

        window.draw(BackgroundSprite);
        window.draw(StartSprite);
        window.draw(BannerSprite);
        window.draw(SettingsSprite);
        window.draw(HowToPlaySprite);
        window.draw(ExitSprite);

        window.display();
    }
    return true;
}

#endif // MENU_H
