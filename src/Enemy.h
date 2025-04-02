#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Enemy
{
private:
    sf::CircleShape circle;
    bool isBomb;
    int texture;
    std::vector<sf::Texture> enemyTextures;

public:
    Enemy(float radius, const sf::Vector2f &position, bool isBomb, int texture);

    bool collision(sf::CircleShape playerCircle);
    void move(float speed);
    bool outOfFrame(sf::RenderWindow &window) const;
    bool getType() const;
    void draw(sf::RenderWindow &window);
};

#endif // ENEMY_H