#include <SFML/Graphics.hpp>

class Bullet {
    private:
        sf::RectangleShape* body;
        bool fired;
    public:
        Bullet() {
            body = new sf::RectangleShape(sf::Vector2f(10,5));
            body->setFillColor(sf::Color::Red);
            body->setPosition(-1, -1);
            fired = false;
        }
        void draw(sf::RenderWindow* win) {
            win->draw(*body);
        }
        void set_position(sf::Vector2f position) {
            body->setPosition(position);
        }
        void move() {
            body->move(0.5, 0);
        }
        bool isFired() {return fired;}
        void reload() {fired = false;}
        void use(sf::Vector2f position) {
            body->setPosition(position);
            fired = true;
        }
        ~Bullet() {
            delete this->body;
        }
};