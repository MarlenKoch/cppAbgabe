#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include "Cookie.hpp"
#include "Enemy.hpp"

float randomFloat(float min, float max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(min, max);
    return dist(gen);
}

float randomGaussianFloat()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::normal_distribution<float> distribution(0, 10);
    return distribution(gen);
}

// displaying the kill screen at the end of the game
void displayKillScreen(sf::RenderWindow &window, int score, sf::Sprite background, sf::Text killScreenText, sf::Text playAgainText, sf::Text killScreenScoreText, int &health, std::vector<Cookie> &cookies, std::vector<Enemy> &enemies)
{
    window.clear();
    window.draw(background);
    window.draw(killScreenText);
    window.draw(playAgainText);
    killScreenScoreText.setString("Your score was:  " + std::to_string(score));
    window.draw(killScreenScoreText);
    window.display();

    bool waitingForClick = true;
    while (waitingForClick)
    {
        if (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            if (event->is<sf::Event::MouseButtonPressed>())
            {
                waitingForClick = false;
                health = 5;
                score = 0;
                cookies.clear();
                enemies.clear();
            }
        }
    }
}

// spawning Enemies
void spawnEnemies(sf::RenderWindow &window, std::vector<Enemy> &enemies, sf::Clock &enemyTimer)
{
    float newRadius = 50.0f;

    float x = randomFloat(newRadius, window.getSize().x - newRadius);

    float randomType = randomFloat(0, 100);
    if (randomType <= 3)
    {
        enemies.emplace_back(newRadius, sf::Vector2f(x, -30), true, 0);
    }
    else
    {
        int texture = floor(randomFloat(1, 6));

        enemies.emplace_back(newRadius, sf::Vector2f(x, -30), false, texture);
    }
    enemyTimer.restart();
}

// spawning Cookies
void spawnCookies(sf::RenderWindow &window, std::vector<Cookie> &cookies, sf::Clock &cookieTimer)
{
    float newRadius = 30.0f;
    float x = randomFloat(newRadius, window.getSize().x - newRadius);

    float randomType = randomFloat(0, 100);
    if (randomType <= 3)
    {
        cookies.emplace_back(newRadius, sf::Vector2f(x, -30), true, 0);
    }
    else
    {
        int texture = floor(randomFloat(1, 5));
        cookies.emplace_back(newRadius, sf::Vector2f(x, -30), false, texture);
    }
    cookieTimer.restart();
}

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    sf::CircleShape playerCircle(40.f);
    playerCircle.setFillColor(sf::Color::Blue);
    playerCircle.setOrigin(sf::Vector2(playerCircle.getRadius(), playerCircle.getRadius()));

    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("./assets/frog.png"))
    {
        std::cout << "Could not load player texture" << std::endl;
        return 0;
    }
    sf::Sprite frog(playerTexture);
    frog.setPosition(sf::Vector2f(playerCircle.getPosition().x - 150, playerCircle.getPosition().y - 600));
    frog.setScale(sf::Vector2f(0.25f, 0.25f));
    frog.setOrigin(sf::Vector2f(170.f, 170.f));

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("./assets/background2.jpg"))
    {
        std::cout << "Could not load texture" << std::endl;
        return 0;
    }
    sf::Sprite background(backgroundTexture);
    background.setScale(sf::Vector2f(2, 1.6));

    sf::Texture healtTexture;
    if (!healtTexture.loadFromFile("./assets/health.png"))
    {
        std::cout << "Could not load texture" << std::endl;
        return 0;
    }
    sf::Sprite heart2(healtTexture);
    heart2.setScale(sf::Vector2f(0.2f, 0.2f));

    sf::Font font;
    if (!font.openFromFile("Chatkids.ttf"))
    {
        std::cerr << "Error loading font!" << std::endl;
        return -1;
    }

    sf::Text scoreText(font);
    scoreText.setCharacterSize(70);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(sf::Vector2(10.f, 10.f));

    sf::Text killScreenText(font);
    killScreenText.setCharacterSize(120);
    killScreenText.setFillColor(sf::Color::White);
    killScreenText.setPosition(sf::Vector2(500.f, 200.f));
    killScreenText.setString("You died!");

    sf::Text playAgainText(font);
    playAgainText.setCharacterSize(60);
    playAgainText.setFillColor(sf::Color::White);
    playAgainText.setPosition(sf::Vector2(380.f, 400.f));
    playAgainText.setString("Tap anywhere to play again");

    sf::Text killScreenScore(font);
    killScreenScore.setFillColor(sf::Color::White);
    killScreenScore.setPosition(sf::Vector2f(575.f, 500.f));
    killScreenScore.setCharacterSize(40);

    std::vector<Cookie> cookies;
    std::vector<Enemy> enemies;
    sf::Clock cookieTimer;
    sf::Clock enemyTimer;
    int score = 0;
    int health = 5;

    // Game Loop
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        if (health <= 0)
        {
            displayKillScreen(window, score, background, killScreenText, playAgainText, killScreenScore, health, cookies, enemies);
        }

        if (cookieTimer.getElapsedTime().asSeconds() > ((10.f / (score + 20.f)) + 0.1f))
        {
            spawnCookies(window, cookies, cookieTimer);
        }

        if (enemyTimer.getElapsedTime().asSeconds() > ((20.f / (score + 20.f)) + 0.2f))
        {
            spawnEnemies(window, enemies, enemyTimer);
        }

        // Move the player
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        sf::Vector2f mousePositionPixel = window.mapPixelToCoords(mousePosition);
        playerCircle.setPosition(sf::Vector2f(mousePositionPixel.x, window.getSize().y - 30.f));
        frog.setPosition(sf::Vector2f(mousePositionPixel.x - 20, window.getSize().y - 50.f));

        // detecting collisions, removing cookies again
        for (auto cookie = cookies.begin(); cookie != cookies.end();)
        {
            if (cookie->collision(playerCircle))
            {
                if (cookie->getType() && health <= 10)
                {
                    health += 1;
                }
                else if (!cookie->getType())
                {
                    score += 1;
                }
                cookie = cookies.erase(cookie);
            }
            else
            {
                if (cookie->outOfFrame(window))
                {
                    cookie = cookies.erase(cookie);
                }
                else
                {
                    cookie->move(11.f - ((100.f * 9.f) / (score + 100.f)));

                    ++cookie;
                }
            }
        }

        // detecting collisions, removing enemies again
        for (auto enemy = enemies.begin(); enemy != enemies.end();)
        {
            if (enemy->collision(playerCircle))
            {
                if (enemy->getType() && health <= 10)
                {
                    health = 0;
                }
                else if (!enemy->getType())
                {
                    health -= 1;
                }
                enemy = enemies.erase(enemy);
            }
            else
            {
                if (enemy->outOfFrame(window))
                {
                    enemy = enemies.erase(enemy);
                }
                else
                {
                    enemy->move(11.f - ((100.f * 10.f) / (score + 100.f)));

                    ++enemy;
                }
            }
        }

        scoreText.setString(std::to_string(score));

        // render to screen
        window.clear();
        window.draw(background);

        for (Cookie cookie : cookies)
        {
            cookie.draw(window);
        }
        for (Enemy enemy : enemies)
        {
            enemy.draw(window);
        }

        window.draw(frog);
        window.draw(scoreText);

        for (int i = 0; i < health; i++)
        {
            heart2.setPosition(sf::Vector2f(window.getSize().x - i * 60 - 100.f, 10.f));
            window.draw(heart2);
        }

        window.display();
    }

    return 0;
}
