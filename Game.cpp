#include <SFML/Graphics.hpp>
#include "Player.h"
using std::string;
using namespace sf;

class Game {
    private:
        sf::RenderWindow* win;
        Player* player;
    public:
        Game(int size, std::string title) {
            win = new sf::RenderWindow(sf::VideoMode(size,size), title);
            player = new Player(10,50,50,100);
        }
        void run() {
            while (win -> isOpen()) {
                Event e;
                while (win -> pollEvent(e)) {
                    if (e.type == Event::Closed) {
                        win -> close();
                    }
                    if(Keyboard::isKeyPressed(Keyboard::A)) {
                        player->move_left(6);
                    }
                    if (Keyboard::isKeyPressed(Keyboard::D)) {
                        player->move_right(6);
                    }
                    if (Keyboard::isKeyPressed(Keyboard::W)) {
                        player->move_up(6);
                    }
                    if (Keyboard::isKeyPressed(Keyboard::S)) {
                        player->move_down(6);
                    }
                    if(Keyboard::isKeyPressed(Keyboard::Space)) {
                        player->fire();
                    }
                    if(Keyboard::isKeyPressed(Keyboard::R)) {
                        player->reload();
                    }
                }
                win -> clear();
                player -> draw(win);
                win -> display();
            }
        }
        ~Game() {
            delete player;
            delete win;
        }
};

int main(void) {
    Game g(500, "Hello World");
    g.run();
    return 0;
}