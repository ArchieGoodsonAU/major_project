#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>
using namespace sf;

class player {
 public:
  bool jump, left, right = false;
  bool onGround;
  float xvel, yvel;
  int speed, jumpHeight;
  int xpos, ypos;
  bool floorcheck;
  Texture tradieTexture;
  Sprite* tradieSprite;
  player() {
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
  void update() {
    onGround = floorcheck;
    collide();

    right = (Keyboard::isKeyPressed(Keyboard::Right));
    left = (Keyboard::isKeyPressed(Keyboard::Left));

    xvel = right * speed - left * speed;
    yvel += -jumpHeight * jump * onGround;
    if (jump) {
      onGround = false;
    }
    // std::cout << ypos << std::endl;
    yvel += 0.2;
    yvel = yvel * (1 - onGround);  // set yvel to 0 if on ground
    xpos += xvel;
    ypos += yvel;
    jump = false;
    floorcheck = false;
    // tradieSprite->setPosition(Vector2f(xpos, std::min(ypos, 500)));
  }

  void collide() {
    if (ypos >= 500) {
      onGround = true;
      ypos = 500;
    }
  }
};

#endif
