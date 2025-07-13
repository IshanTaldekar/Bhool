#ifndef BFS_H
#define BFS_H

#include "SearchAlgorithm.h"
#include "Config.h"
#include <queue>
#include <stack>

class BFS: public SearchAlgorithm {
    std::vector<BlockType> maze;
    std::vector<Point> parent;

    Point startPoint;
    Point endPoint;
    std::queue<Point> exploring;
    std::stack<Point> path;
    MazeSize size;
    std::vector<std::vector<int>> legalMoves {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    BFS(const MazeSize &size, std::vector<BlockType> &maze);
    virtual std::vector<BlockType> step() override;
};


#endif //BFS_H
