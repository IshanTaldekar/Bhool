#include "../include/Visualizer.h"
#include "../include/BFS.h"
#include "../include/A_star.h"
#include <vector>
#include <chrono>
#include <thread>

int main() {
    // MazeSize size = {10, 8};
    // std::vector<BlockType> maze = {
    //     BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL,
    //     BlockType::WALL, BlockType::START, BlockType::FREE, BlockType::FREE, BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL,
    //     BlockType::WALL, BlockType::FREE, BlockType::WALL, BlockType::FREE, BlockType::WALL, BlockType::FREE, BlockType::WALL, BlockType::WALL, BlockType::FREE, BlockType::WALL,
    //     BlockType::WALL, BlockType::FREE, BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::WALL,
    //     BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL, BlockType::WALL,
    //     BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::FREE, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::WALL,
    //     BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::END, BlockType::WALL,
    //     BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL
    // };

    MazeSize size = {10, 20};
    std::vector<BlockType> maze = {
        BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL,
        BlockType::WALL, BlockType::START, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL,
        BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL,
        BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL,
        BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL,
        BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL,
        BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL,
        BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL,
        BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL,
        BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL,
        BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL,
        BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL,
        BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL,
        BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL,
        BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL,
        BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL,
        BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL,
        BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL,
        BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::WALL,
        BlockType::WALL, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::FREE, BlockType::END, BlockType::WALL,
        BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL, BlockType::WALL
    };

    Visualizer viz;
    A_star aStar(size, maze);
    BFS bfs(size, maze);

    while (true) {
        viz.draw(size, maze);
        maze = aStar.step();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    return 0;
}