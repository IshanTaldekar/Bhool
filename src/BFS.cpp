#include "BFS.h"

BFS::BFS(const MazeSize &size, std::vector<BlockType> &maze) {
    this->maze = maze;
    this->size = size;
    this->parent = std::vector<Point>(size.height * size.width, {-1, -1});

    for (int i = 0; i < size.height; ++i) {
        for (int j = 0; j < size.width; ++j) {
            if (maze.at(i * size.width + j) == BlockType::START) {
                this->startPoint = Point{i, j};
            }
            if (maze.at(i * size.width + j) == BlockType::END) {
                this->endPoint = Point{i, j};
            }
        }
    }

    exploring.push(startPoint);
}

std::vector<BlockType> BFS::step() {
    if (!exploring.empty()) {
        Point currentPoint = exploring.front();

        for (const std::vector<int> &currentMove: legalMoves) {
            if (currentPoint.x + currentMove.at(0) >= 0 && currentPoint.x + currentMove.at(0) < size.height
                && currentPoint.y + currentMove.at(1) >= 0 && currentPoint.y + currentMove.at(1) < size.width) {
                Point newPoint = Point{currentPoint.x + currentMove.at(0), currentPoint.y + currentMove.at(1)};
                if (maze.at(newPoint.x * size.width + newPoint.y) == BlockType::FREE) {
                    exploring.push(newPoint);
                    parent.at(newPoint.x * size.width + newPoint.y) = currentPoint;
                    maze.at(newPoint.x * size.width + newPoint.y) = BlockType::EXPLORING;
                } else if (maze.at(newPoint.x * size.width + newPoint.y) == BlockType::END
                    && parent.at(newPoint.x * size.width + newPoint.y).x < 0) {
                    Point point = currentPoint;
                    while (maze.at(point.x * size.width + point.y) != BlockType::START) {
                        path.push(point);
                        point = parent.at(point.x * size.width + point.y);
                    }
                    parent.at(newPoint.x * size.width + newPoint.y) = currentPoint;
                }
            }
        }

        exploring.pop();
        if (maze.at(currentPoint.x * size.width + currentPoint.y) != BlockType::START) {
            maze.at(currentPoint.x * size.width + currentPoint.y) = BlockType::VISITED;
        }
    } else if (!path.empty()) {
        Point currentPoint = path.top();
        path.pop();
        maze.at(currentPoint.x * size.width + currentPoint.y) = BlockType::PATH;
    }
    return maze;
}