#ifndef COOKIE_H
#define COOKIE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Cookie
{
private:
    sf::CircleShape circle;
    bool isFly;
    int texture;
    std::vector<sf::Texture> cookieTextures;

public:
    Cookie(float radius, const sf::Vector2f &position, bool isFly, int texture);

    bool collision(sf::CircleShape playerCircle);
    void move(float speed);
    bool outOfFrame(sf::RenderWindow &window) const;
    bool getType() const;
    void draw(sf::RenderWindow &window);
};

#endif // COOKIE_H