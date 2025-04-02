#include "Enemy.h"
#include <cmath>

Enemy::Enemy(float radius, const sf::Vector2f &position, bool isBomb, int texture)
    : isBomb(isBomb), texture(texture)
{
    // Load all enemy textures
    sf::Texture enemy1, enemy2, enemy3, enemy4, enemy5, bomb;
    if (!enemy1.loadFromFile("./assets/enemy1.png") || !enemy2.loadFromFile("./assets/enemy2.png") || !enemy3.loadFromFile("./assets/enemy3.png") || !enemy4.loadFromFile("./assets/enemy4.png") || !enemy5.loadFromFile("./assets/enemy5.png") || !bomb.loadFromFile("./assets/bomb.png"))
    {
        std::cerr << "Error loading enemy textures!" << std::endl;
        return;
    }

    enemyTextures.push_back(bomb);
    enemyTextures.push_back(enemy1);
    enemyTextures.push_back(enemy2);
    enemyTextures.push_back(enemy3);
    enemyTextures.push_back(enemy4);
    enemyTextures.push_back(enemy5);

    circle.setRadius(radius);
    circle.setPosition(position);
    circle.setOrigin(sf::Vector2f(radius, radius));
}

// detecting collisions
bool Enemy::collision(sf::CircleShape playerCircle)
{
    float dx = playerCircle.getPosition().x - circle.getPosition().x;
    float dy = playerCircle.getPosition().y - circle.getPosition().y;
    float distance = std::sqrt(dx * dx + dy * dy);
    return distance <= (playerCircle.getRadius() + circle.getRadius());
}

// moving Enemies
void Enemy::move(float speed)
{
    sf::Vector2f newPosition;
    newPosition = circle.getPosition() + sf::Vector2f(0, speed);
    circle.setPosition(newPosition);
}

// detecting if Enemy is out of frame
bool Enemy::outOfFrame(sf::RenderWindow &window) const
{
    return (circle.getPosition().y > window.getSize().y + 100);
}

// checking if Enemy is of type bomb
bool Enemy::getType() const
{
    return isBomb;
}

// drawing the Enemies
void Enemy::draw(sf::RenderWindow &window)
{
    circle.setFillColor(sf::Color::Cyan);

    sf::Sprite enemy(enemyTextures[texture]);
    enemy.setPosition(sf::Vector2f(circle.getPosition().x - 70, circle.getPosition().y - 70));
    enemy.setScale(sf::Vector2f(0.3, 0.3));
    window.draw(enemy);
}