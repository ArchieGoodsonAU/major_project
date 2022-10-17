#ifndef BLOCKCLASS_H
#define BLOCKCLASS_H

#include "player.h"

class blockClass {
 public:
  float xpos, ypos, initxpos, initypos;
  float xvel, yvel;
  int scale;
  Texture image;
  Sprite mySprite;
  player* Player;
  blockClass() {
    image.loadFromFile("data/images/grass.png");
    mySprite = *(new Sprite(image));
    // std::cout << "Sprite created \n";
  }
  void update() {
    xpos = -1 * Player->xpos + initxpos;
    collide(0);
    mySprite.setPosition(Vector2f(xpos, ypos));

    ypos = -1 * Player->ypos + initypos;
    collide(1);
    mySprite.setPosition(Vector2f(xpos, ypos));
  }
  void collide(int axis) {
    // centre of screen is tradie
    int left_wall = 500;
    int right_wall = 564;
    int top_wall = 400;
    int bottom_wall = 464;
    int my_left_wall = xpos;
    int my_right_wall = xpos + 64;
    int my_top_wall = ypos;
    int my_bottom_wall = ypos + 64;
    // Check for vertical any overlap
    if (abs(xpos - 500) > 63 || abs(ypos - 400) > 63) {
      return;
    }
    if (axis == 1) {
      if (Player->yvel >= 0) {
        Player->ypos = -463 + initypos;
        ypos = ypos + Player->yvel;
        Player->yvel = 0;
        Player->floorcheck = true;
      } else {
        Player->ypos = -336 + initypos;
        ypos = ypos + Player->yvel;
        Player->yvel = 1;
      }
    }
    if (axis == 0 && abs(ypos - 400) < 63) {
      if (Player->right) {
        Player->xpos = -564 + initxpos;
        xpos = xpos + Player->xvel;
        Player->xvel = 0;
      }
      if (Player->left) {
        Player->xpos = -436 + initxpos;
        xpos = xpos + Player->xvel;
        Player->xvel = 0;
      }
    }
  }
};

#endif
