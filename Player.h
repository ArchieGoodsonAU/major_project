#include <SFML/Graphics.hpp>
#include "Bullet.h"

class Player {
    private:
        sf::CircleShape* body;
        int mag_size;
        Bullet* mag;
    public:
        Player(int r, int x, int y, int a_mag_size) {
            body = new sf::CircleShape();
            body->setRadius(10);
            body->setPosition(x,y);
            body->setFillColor(sf::Color::Green);
            body->setOrigin(r/2,r/2);
            mag_size = a_mag_size;
            mag = new Bullet[10];
        }
        void draw(sf::RenderWindow* win) {
            win -> draw(*body);
            for (int i = 0; i < mag_size; i++) {
                if (mag[i].isFired()) {
                    mag[i].move();
                    mag[i].draw(win);
                }
            }
        }
        void move_right(int speed) {
            body -> move(speed, 0);
        }
        void move_left(int speed) {
            body -> move(-speed, 0);
        }
        void move_up(int speed) {
            body -> move(0, -speed);
        }
        void move_down(int speed) {
            body -> move(0, speed);
        }
        void fire() {
            for (int i = 0; i < mag_size; i++) {
                if (!mag[i].isFired()) {
                    mag[i].use(body->getPosition());
                    break;
                }
            }
        }
        void reload() {
            for (int i = 0; i < mag_size; i++) {
                if (mag[i].isFired()) {
                    mag[i].reload();
                }
            }
        }
        ~Player() {
            delete this->body;
            delete [] this->mag;
        };
};