#ifndef GAME_SHOOT_H
#define GAME_SHOOT_H
#include "SFML/Graphics.hpp"

//missile sprite

class Shoot {
public:
    explicit Shoot(const sf::Sprite & sprite) : m_start(sprite.getPosition()) {
        buildShape(sprite.getPosition());
        const float rotation = sprite.getRotation();

        if (rotation == 0.0f) {
            m_velocity.x = 0.f;
            m_velocity.y = DEFAULT_PROJECTILE_SPEED;
        }
        if (rotation == 90.0f) {
            m_velocity.x = -DEFAULT_PROJECTILE_SPEED;
            m_velocity.y = 0.f;
        }
        if (rotation == 180.f) {
            m_velocity.x = 0.f;
            m_velocity.y = -DEFAULT_PROJECTILE_SPEED;
        }
        if (rotation == 270.0f) {
            m_velocity.x = DEFAULT_PROJECTILE_SPEED;
            m_velocity.y = 0;
        }
    }

    sf::Sprite & getShape() {
        return m_shape;
    }

    void setTexture(const sf::Texture & texture) {
        m_shape.setTexture(texture);

        m_shape.setTextureRect(sf::IntRect(0, 108, 50, 42));
        m_shape.setOrigin(25, 21);

        m_shape.setScale(0.3f, 0.3f);

    }


    void update() {
        m_shape.move(m_velocity * m_clock.getElapsedTime().asSeconds());
        m_clock.restart();
    }

    [[nodiscard]] bool isOnTheScreen() const {
        const bool widthCondition =
                getShapePosition().x < 0.0f || getShapePosition().x > WINDOW_X;
        const bool heightCondition =
                getShapePosition().y < 0.0f || getShapePosition().y > WINDOW_Y;

        if (widthCondition || heightCondition) {
            return false;
        }

        return true;
    }

    [[nodiscard]] sf::Vector2f getShapePosition() const {
        return m_shape.getPosition();
    }

    virtual ~Shoot() = default;

public:
    const uint16_t WINDOW_X = 1080;
    const uint16_t WINDOW_Y = 720;
    constexpr static float DEFAULT_PROJECTILE_SPEED = 1000.0f;

protected:
    void buildShape(const sf::Vector2f &shapePosition) {
//        m_shape.setSize(sf::Vector2f(10.0f, 10.0f));
//        m_shape.setFillColor(sf::Color::Red);
        m_shape.setPosition(shapePosition);
    }

private:
    sf::Sprite m_shape;


    sf::Clock m_clock;

    sf::Vector2f m_velocity;

    sf::Vector2f m_start;

    float m_bulletSpeed = DEFAULT_PROJECTILE_SPEED;
};

#endif //GAME_SHOOT_H
