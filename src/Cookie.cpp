#include "Cookie.hpp"
#include <cmath>

Cookie::Cookie(float radius, const sf::Vector2f &position, bool isFly, int texture)
    : isFly(isFly), texture(texture)
{
    // Load all cookie textures
    sf::Texture food1, food2, food3, food4, fly;
    if (!food1.loadFromFile("./assets/food1.png") || !food2.loadFromFile("./assets/food2.png") || !food3.loadFromFile("./assets/food3.png") || !food4.loadFromFile("./assets/food4.png") || !fly.loadFromFile("./assets/fly.png"))
    {
        std::cerr << "Error loading cookie textures!" << std::endl;
        return;
    }

    cookieTextures.push_back(fly);
    cookieTextures.push_back(food1);
    cookieTextures.push_back(food2);
    cookieTextures.push_back(food3);
    cookieTextures.push_back(food4);

    circle.setRadius(radius);
    circle.setPosition(position);
    circle.setOrigin(sf::Vector2f(radius, radius));
}

// detecting collisions
bool Cookie::collision(sf::CircleShape playerCircle)
{
    float dx = playerCircle.getPosition().x - circle.getPosition().x;
    float dy = playerCircle.getPosition().y - circle.getPosition().y;
    float distance = std::sqrt(dx * dx + dy * dy);
    return distance <= (playerCircle.getRadius() + circle.getRadius());
}

// moving Cookies
void Cookie::move(float speed)
{
    sf::Vector2f newPosition;
    newPosition = circle.getPosition() + sf::Vector2f(0, speed);
    circle.setPosition(newPosition);
}

// detecting if Cookie is out of frame
bool Cookie::outOfFrame(sf::RenderWindow &window) const
{
    return (circle.getPosition().y > window.getSize().y + 100);
}

// checking if Cookie is of type fly
bool Cookie::getType() const
{
    return isFly;
}

// drawing the Cookies
void Cookie::draw(sf::RenderWindow &window)
{
    circle.setFillColor(sf::Color::Magenta);
    sf::Sprite cookie(cookieTextures[texture]);
    cookie.setPosition(sf::Vector2f(circle.getPosition().x - 50, circle.getPosition().y - 50));
    cookie.setScale(sf::Vector2f(0.2, 0.2));
    window.draw(cookie);
}