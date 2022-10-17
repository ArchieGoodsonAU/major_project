#ifndef GAMEMANGER_H
#define GAMEMANGER_H

#include "blockClass.h"

class GameManager {
 public:
  int blockCoords[5][2] = {
      {800, 700}, {863, 700}, {926, 700}, {1000, 600}, {1064, 600}};
  GameManager() {
    RenderWindow window(VideoMode(1000, 800), "SFML works!");

    player player;

    int blockCount = 10;
    blockClass* grassblocks = new blockClass[blockCount];
    // std::cout << "we made it this far \n";
    for (int i = 0; i < blockCount; i++) {
      grassblocks[i].initxpos = blockCoords[i][0];
      grassblocks[i].initypos = blockCoords[i][1];
      grassblocks[i].Player = &player;
    }
    // std::cout << "Yeezus \n";

    sf::Clock deltaClock;
    while (window.isOpen())  // loop to update the window
    {
      sf::Event event;  // Create an event class
      while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
          window.close();
        } else if (event.type == sf::Event::KeyPressed) {
          if (event.key.code == sf::Keyboard::Up) {
            player.jump = true;
          }
        }
      }
      player.update();
      window.clear();  // Clear the screen of all elements

      for (int i = 0; i < blockCount; i++) {
        grassblocks[i].update();

        // std::cout << grassblocks[i].ypos << ", "<< grassblocks[i].xpos <<
        // std::endl;
        window.draw(grassblocks[i].mySprite);
      }
      window.draw(*player.tradieSprite);  // Draw the rectangle

      window.display();  // Display it
    }
  }
};
#endif
