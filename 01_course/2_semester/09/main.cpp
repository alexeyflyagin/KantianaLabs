#include <SFML/Graphics.hpp>
#include <iostream>


class GameObject {
public:
    virtual void start() {};
    virtual void update() {};
    virtual void draw(sf::RenderWindow& window) const {};
    virtual ~GameObject() {};
};


class Player : public GameObject {
    const sf::Vector2f size = sf::Vector2f(20.f, 20.f);
    const float breathingRate = 0.1f;
    const float speed = 6.f;
    const float maxHeight = size.y * 1.1f;

    sf::RectangleShape shape;
    float isInhale;

public:
    Player(const sf::Vector2f pos = sf::Vector2f(0, 0), const sf::Color color = sf::Color::White) {
        shape = sf::RectangleShape(size);
        isInhale = true;
        shape.setPosition(pos);
        shape.setFillColor(color);
    }

    void update() override {
        breathing();
    }

    void move(sf::Vector2f direction) {
        shape.move(direction * speed);
    }

    void draw(sf::RenderWindow& window) const override {
        window.draw(shape);
    }
    
private:
    void breathing() {
        float rate = isInhale ? breathingRate : -breathingRate;
        sf::Vector2f oldSize = shape.getSize();
        shape.setSize(sf::Vector2f(shape.getSize().x, shape.getSize().y + rate));

        if (shape.getSize().y < size.y) shape.setSize(sf::Vector2f(shape.getSize().x, size.y));
        else if (shape.getSize().y > maxHeight) shape.setSize(sf::Vector2f(shape.getSize().x, maxHeight));

        if (shape.getSize().y <= size.y || shape.getSize().y >= maxHeight) isInhale = !isInhale;

        shape.setPosition(sf::Vector2f(shape.getPosition().x, shape.getPosition().y + oldSize.y - shape.getSize().y));
    }
};

sf::VideoMode videomode(500, 400);
Player player = Player(sf::Vector2f(videomode.width / 2.f, videomode.height / 2.f));

void start() {
    player.start();
}

void update() {
    player.update();
}

void drow(sf::RenderWindow& window) {
    player.draw(window);
}

int main()
{
    sf::RenderWindow window(videomode, "Master of Avoidance", sf::Style::None | sf::Style::Titlebar);
    window.setFramerateLimit(60);
    start();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left)
                    player.move(sf::Vector2f(-1, 0));
                else if (event.key.code == sf::Keyboard::Right)
                    player.move(sf::Vector2f(1, 0));
                else if (event.key.code == sf::Keyboard::Up)
                    player.move(sf::Vector2f(0, -1));
                else if (event.key.code == sf::Keyboard::Down)
                    player.move(sf::Vector2f(0, 1));
            }
        }
        update();
        window.clear();
        drow(window);
        window.display();
    }

    return 0;
}
