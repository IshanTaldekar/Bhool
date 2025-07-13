#ifndef CONFIG_H
#define CONFIG_H

#include <vector>

struct MazeSize {
    int width;
    int height;
};

struct Point {
    int x;
    int y;
};

enum class BlockType {
    FREE = 0,
    WALL,
    START,
    END,
    EXPLORING,
    VISITED,
    PATH
};

#endif //CONFIG_H
