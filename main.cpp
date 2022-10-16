#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
using namespace sf;


class player{
    public:
        bool jump, left, right = false;
        bool onGround;
        float xvel, yvel;
        int speed, jumpHeight;
        int xpos, ypos;
        Texture tradieTexture;
        Sprite* tradieSprite;
        player(){
            tradieTexture.loadFromFile("data/images/tradie.png");
            tradieSprite = new Sprite(tradieTexture);
            xvel, yvel = 400, 500;
            xpos = 500;
            ypos = 400;
            speed = 2;
            jumpHeight = 6;
            onGround = false;
            tradieSprite->setPosition(Vector2f(xpos, ypos));
        }
        void update(){

            right = (Keyboard::isKeyPressed(Keyboard::Right));
            left = (Keyboard::isKeyPressed(Keyboard::Left));
            
            xvel = right * speed - left * speed;
            yvel += -jumpHeight * jump * onGround;
            if(jump){
                onGround = false;
            }
            //std::cout << ypos << std::endl;
            yvel += 0.1;
            yvel = yvel * (1-onGround); //set yvel to 0 if on ground
            xpos += xvel;
            ypos += yvel;
            jump = false;
            collide();
            //tradieSprite->setPosition(Vector2f(xpos, std::min(ypos, 500)));
        }

        void collide(){
            if(ypos > 500){
                onGround = true;
                ypos = 500;
            }
        }
};


class blockClass{
    public:
        float xpos, ypos, initxpos, initypos;
        float xvel, yvel;
        int scale;
        Texture image;
        Sprite mySprite;
        player* Player;
        blockClass(){
            image.loadFromFile("data/images/grass.png");
            mySprite = *(new Sprite(image));
            //std::cout << "Sprite created \n";
        }
        void update(){
            ypos = -1 * Player->ypos + initypos;
            collide(1);
            mySprite.setPosition(Vector2f(xpos, ypos));
            xpos = -1 * Player->xpos + initxpos;
            mySprite.setPosition(Vector2f(xpos, ypos));
        }
        void collide(int axis){
            //centre of screen is tradie
            int left_wall = 500;
            int right_wall = 564;
            int top_wall = 400;
            int bottom_wall = 464;
            int my_left_wall = xpos;
            int my_right_wall = xpos + 64;
            int my_top_wall = ypos;
            int my_bottom_wall = ypos + 64;
            //Check for vertical any overlap
            if(abs(xpos - 500) > 64 || abs(ypos - 400) > 64){
                return;
            }
            if(axis == 1){
                if(Player->yvel > 0){
                    Player->ypos = -464 + initypos;
                    ypos = ypos + Player->yvel;
                    Player->onGround = true;
                }
            }

        }
};


class GameManager{
    public:

    int blockCoords[2][2] = {{750, 750},{400, 400}};
    GameManager(){
    RenderWindow window(VideoMode(1000, 800), "SFML works!");

    player player;

    
    int blockCount = 2;
    blockClass* grassblocks = new blockClass[blockCount];
    //std::cout << "we made it this far \n";
    for(int i = 0; i < blockCount; i++){
        grassblocks[i].initxpos = blockCoords[i][0];
        grassblocks[i].initypos = blockCoords[i][0];
        grassblocks[i].Player = &player;
    }
    //std::cout << "Yeezus \n";



    sf::Clock deltaClock;
    while (window.isOpen()) //loop to update the window
        {
            sf::Event event; //Create an event class
            while(window.pollEvent(event)){
                if(event.type == Event::Closed){
                    window.close();
                }else if(event.type == sf::Event::KeyPressed){
                    if(event.key.code == sf::Keyboard::Up){
                        player.jump = true;
                    }
                }
            }
            player.update();
            window.clear(); //Clear the screen of all elements
            
            for(int i = 0; i < blockCount; i++){
                grassblocks[i].update();

                //std::cout << grassblocks[i].ypos << ", "<< grassblocks[i].xpos << std::endl;
                window.draw(grassblocks[i].mySprite);
            }
            window.draw(*player.tradieSprite); //Draw the rectangle

            window.display(); //Display it
        }
    }
};
int main(){
    GameManager gameManager;
    return 0;}