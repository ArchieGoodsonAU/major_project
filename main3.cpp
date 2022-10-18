/*
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
        bool floorcheck;
        Texture tradieTexture;
        Sprite* tradieSprite;
        player(){
            tradieTexture.loadFromFile("data/images/grass.png");
            tradieSprite = new Sprite(tradieTexture);
            xvel, yvel = 400, 500;
            xpos = 500;
            ypos = 400;
            speed = 2;
            jumpHeight = 10;
            onGround = false;
            tradieSprite->setPosition(Vector2f(xpos, ypos));
        }
        void update(){

            onGround = floorcheck;
            collide();
            
            right = (Keyboard::isKeyPressed(Keyboard::Right));
            left = (Keyboard::isKeyPressed(Keyboard::Left));
            
            xvel = right * speed - left * speed;
            yvel += -jumpHeight * jump * onGround;
            if(jump){
                onGround = false;
            }
            //std::cout << ypos << std::endl;
            yvel += 0.2;
            yvel = yvel * (1-onGround); //set yvel to 0 if on ground
            xpos += xvel;
            ypos += yvel;
            jump = false;
            floorcheck = false;
            //tradieSprite->setPosition(Vector2f(xpos, std::min(ypos, 500)));
        }

        void collide(){
            if(ypos >= 500){
                onGround = true;
                ypos = 500;
            }
        }
};


class entity{
    public:
        float xpos, ypos, initxpos, initypos;
        float xvel, yvel;
        Texture image;
        Sprite mySprite;
        player* Player;
        int x_size, y_size;
        void update_location_x(){
            xpos = -1 * Player->xpos + initxpos; //Go to starting x position - any player/camera movement
        }
        void update_location_y(){
            ypos = -1 * Player->ypos + initypos; //Go to starting x position - any player/camera movement
        }
        bool check_player_collision(){
            //Player located at pixel coords (500, 400) and of size 64x64
            if(abs(xpos - 500) > x_size / 2 + 32 || abs(ypos - 400) > y_size / 2 + 32){
                return false;
            }
            return true;
        }
};

class blockClass : public entity{
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
            std::cout << "Sprite created \n";
        }
        void update(){
            std::cout << "We updating";
            update_location_x();
            if(check_player_collision()){
            collide_x();
            mySprite.setPosition(Vector2f(xpos, ypos));

            ypos = -1 * Player->ypos + initypos;
            collide_y();
            mySprite.setPosition(Vector2f(xpos, ypos));
            }
            else{
                mySprite.setPosition(Vector2f(xpos, ypos));
            }

            
        }
        void collide_y(){
            
                if(Player->yvel >= 0){
                    Player->ypos = -463 + initypos;
                    ypos = ypos + Player->yvel;
                    Player->yvel = 0;
                    Player->floorcheck = true;
                }else{
                    Player->ypos = -336 + initypos;
                    ypos = -368 + initypos;
                    Player->yvel = 1;
                }
            }
        void collide_x(){
            if(abs(ypos - 400) < 63){
                if(Player->right){
                    Player->xpos -= Player->xvel;
                    xpos = xpos + Player->xvel;
                    Player->xvel = 0;
                }
                if(Player->left){
                    Player->xpos -= Player->xvel;
                    xpos = xpos + Player->xvel;
                    Player->xvel = 0;
                }
            }

        }
};

class GameManager{
    public:

    int blockCoords[5][2] = {{800, 700},{863, 700},{926, 700},{1000, 600},{1064, 600}};
    GameManager(){
    RenderWindow window(VideoMode(1000, 800), "SFML works!");

    player player;

    
    int blockCount = 1;
    blockClass* grassblocks = new blockClass;
    //std::cout << "we made it this far \n";
    //for(int i = 0; i < blockCount; i++){
        grassblocks->initxpos = blockCoords[0][0];
        grassblocks->initypos = blockCoords[0][1];
        grassblocks->Player = &player;
    //}




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
            std::cout << grassblocks[0].initxpos;
            //for(int i = 0; i < blockCount; i++){
                std::cout << "Yeezus \n";
                grassblocks->update();
                std::cout << "Yeezus2 \n";
                //std::cout << grassblocks[i].ypos << ", "<< grassblocks[i].xpos << std::endl;
                window.draw(grassblocks->mySprite);
            //}
            window.draw(*player.tradieSprite); //Draw the rectangle

            window.display(); //Display it
        }
    }
};
int main(){
    GameManager gameManager;
    return 0;}
*/