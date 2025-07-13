#include "../include/Visualizer.h"
#include "../include/BFS.h"
#include <vector>
#include <chrono>
#include <thread>

int main() {
    MazeSize size = {10, 8};
    std::vector<BlockType> maze = {
        BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL,
        BlockType::WALL, BlockType::START, BlockType::FREE, BlockType::FREE, BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL,
        BlockType::WALL, BlockType::FREE, BlockType::WALL, BlockType::FREE, BlockType::WALL, BlockType::FREE, BlockType::WALL, BlockType::WALL, BlockType::FREE, BlockType::WALL,
        BlockType::WALL, BlockType::FREE, BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::WALL,
        BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL, BlockType::WALL,
        BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::FREE, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::WALL,
        BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::END, BlockType::WALL,
        BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL
    };
    
    Visualizer viz;
    BFS bfs(size, maze);

    while (true) {
        viz.draw(size, maze);
        maze = bfs.step();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
    return 0;
}