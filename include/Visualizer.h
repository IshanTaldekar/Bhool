#ifndef VISUALIZER_H
#define VISUALIZER_H

#include "Config.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Visualizer {
    sf::RenderWindow window;
    bool windowCreated = false;
    static const int tileSize = 20;

public:
    void draw(const MazeSize size, const std::vector<BlockType> maze);
    void close();
};

#endif //VISUALIZER_H
