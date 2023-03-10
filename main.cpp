//MOVEMENT --> WASD
//SHOOT --> SPACE

#include "Move.h"
#include "Shoot.h"
#include <list>

int main() {

    short window_width = 1080;
    short window_height = 720;

    float tank_speed = 2.5;
    //tank sprite

    sf::Image tank_image;
    sf::Texture tank_texture;
    sf::Sprite tank_sprite;

    tank_image.loadFromFile("../tanks.png");
    tank_texture.loadFromImage(tank_image);
    tank_sprite.setTexture(tank_texture);
    tank_sprite.setPosition(50, 50);

    tank_sprite.setTextureRect(sf::IntRect(0, 0, 150, 200));

    tank_sprite.setOrigin(75, 100);
    tank_sprite.setScale(0.4f, 0.4f);

    //missile sprite
    sf::Image missile_image;
    sf::Texture missile_texture;
    sf::Sprite missile_sprite;

    missile_image.loadFromFile("../explosion.png");
    missile_texture.loadFromImage(missile_image);
    missile_sprite.setTexture(missile_texture);

    missile_sprite.setTextureRect(sf::IntRect(0, 108, 50, 42));
    missile_sprite.setOrigin(25, 21);
    //missile_sprite.setRotation(90);

    missile_sprite.setScale(0.3f, 0.3f);

    //window
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "game from dreams");
    window.setFramerateLimit(120);

    //process

    std::list<Shoot *> shoots_list;
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        constexpr float reload = 0.1f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (clock.getElapsedTime().asSeconds() > reload) {
                shoots_list.push_front(new Shoot(tank_sprite));
                shoots_list.front()->setTexture(missile_texture);
                clock.restart();
            }
        }

        for (auto & shoot : shoots_list) {
            shoot->update();
        }

        while (!shoots_list.empty() && !shoots_list.front()->isOnTheScreen()) {
            shoots_list.pop_front();
        }

        Move::move(tank_speed, tank_sprite);


        window.clear(sf::Color::White);
        window.draw(tank_sprite);
        for (auto & shoot : shoots_list) {
            window.draw(shoot->getShape());
        }

        window.display();

    }

return 0;
}
