#include "A_star.h"

A_star::A_star(const MazeSize &size, std::vector<BlockType> &maze) {
    this->maze = maze;
    this->size = size;
    this->visitCost = std::vector<int>(size.width * size.height, -1);
    this->parent = std::vector<Point>(size.height * size.width, {-1, -1});
    this->isPathFound = false;

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

    exploring.push({this->startPoint, this->endPoint, 0});
}

std::vector<BlockType> A_star::step() {
    if (!exploring.empty() && !isPathFound) {
        Node currentNode = exploring.top();
        Point currentPoint = currentNode.currentPoint;
        exploring.pop();

        for (const std::vector<int> &currentMove: legalMoves) {
            Point newPoint = Point{currentPoint.x + currentMove.at(0), currentPoint.y + currentMove.at(1)};

            if (newPoint.x < 0 || newPoint.x >= size.height || newPoint.y < 0 || newPoint.y >= size.width) {
                continue;
            }

            if (maze.at(newPoint.x * size.width + newPoint.y) == BlockType::END) {
                Point point = currentPoint;
                while (maze.at(point.x * size.width + point.y) != BlockType::START) {
                    path.push(point);
                    point = parent.at(point.x * size.width + point.y);
                }
                parent.at(newPoint.x * size.width + newPoint.y) = currentPoint;
                isPathFound = true;
                break;
            }

            if ((maze.at(newPoint.x * size.width + newPoint.y) == BlockType::FREE) &&
                (visitCost.at(newPoint.x * size.width + newPoint.y) < 0 ||
                visitCost.at(newPoint.x * size.width + newPoint.y) > currentNode.currentCost + 1)) {
                exploring.push({newPoint, endPoint, currentNode.currentCost + 1});
                maze.at(newPoint.x * size.width +  newPoint.y) = BlockType::EXPLORING;
                visitCost.at(newPoint.x * size.width + newPoint.y) = currentNode.currentCost + 1;
                parent.at(newPoint.x * size.width + newPoint.y) = currentPoint;
            }
        }

        if (maze.at(currentPoint.x * size.width + currentPoint.y) != BlockType::START) {
            maze.at(currentPoint.x * size.width + currentPoint.y) = BlockType::VISITED;
        }
    } else if (isPathFound && !path.empty()) {
        Point currentPoint = path.top();
        path.pop();
        maze.at(currentPoint.x * size.width + currentPoint.y) = BlockType::PATH;
    }

    return maze;
}