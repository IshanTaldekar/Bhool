#include "Visualizer.h"

void Visualizer::draw(const MazeSize size, const std::vector<BlockType> maze) {
    if (!windowCreated) {
        window.create(sf::VideoMode(sf::Vector2u(size.width * tileSize, size.height * tileSize)), "Maze");
        windowCreated = true;
    }
    
    if (!window.isOpen()) return;
    
    while (auto event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
    
    window.clear();
    
    for (int x = 0; x < size.width; ++x) {
        for (int y = 0; y < size.height; ++y) {
            sf::RectangleShape cell(sf::Vector2f(tileSize, tileSize));
            cell.setPosition(sf::Vector2f(x * tileSize, y * tileSize));
            
            BlockType type = maze[y * size.width + x];
            if (type == BlockType::WALL) cell.setFillColor(sf::Color::Black);
            else if (type == BlockType::START) cell.setFillColor(sf::Color::Cyan);
            else if (type == BlockType::END) cell.setFillColor(sf::Color::Red);
            else if (type == BlockType::EXPLORING) cell.setFillColor(sf::Color::Yellow);
            else if (type == BlockType::VISITED) cell.setFillColor(sf::Color::Green);
            else if (type == BlockType::PATH) cell.setFillColor(sf::Color::Magenta);
            else cell.setFillColor(sf::Color::White);
            
            window.draw(cell);
        }
    }
    
    window.display();
}

void Visualizer::close() {
    if (window.isOpen()) window.close();
}