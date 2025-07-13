#include "Visualizer.h"

void Visualizer::draw(const MazeSize size, const std::vector<BlockType> maze) {
    if (!windowCreated) {
        auto desktop = sf::VideoMode::getDesktopMode();
        window.create(sf::VideoMode(desktop.size), "Maze");
        windowCreated = true;
    }
    
    if (!window.isOpen()) return;
    
    while (auto event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
    
    window.clear();
    
    // Calculate tile size to fit window
    auto windowSize = window.getSize();
    float scaledTileX = (float)windowSize.x / size.width;
    float scaledTileY = (float)windowSize.y / size.height;
    float scaledTile = std::min(scaledTileX, scaledTileY);
    
    for (int x = 0; x < size.width; ++x) {
        for (int y = 0; y < size.height; ++y) {
            sf::RectangleShape cell(sf::Vector2f(scaledTile, scaledTile));
            cell.setPosition(sf::Vector2f(x * scaledTile, y * scaledTile));
            
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