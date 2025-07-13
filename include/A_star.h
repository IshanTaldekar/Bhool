#ifndef A_STAR_H
#define A_STAR_H

#include "SearchAlgorithm.h"
#include "Config.h"
#include <queue>
#include <stack>

class A_star: public SearchAlgorithm {
    struct Node {
        Point currentPoint;
        Point endPoint;

        int currentCost;
        int heuristicCost;
        int totalCost;

        Node(Point currentPoint, Point endPoint, int currentCost): currentPoint(currentPoint), endPoint(endPoint), currentCost(currentCost) {
            heuristicCost = calculateHeuristicCost();
            totalCost = currentCost + heuristicCost;
        }

        int calculateHeuristicCost() {
            return abs(endPoint.x - currentPoint.x) + abs(endPoint.y - currentPoint.y);
        }
    };

    struct CompareNodes {
        bool operator()(const Node &lhs, const Node &rhs) {
            if (lhs.totalCost == rhs.totalCost) {
                return lhs.heuristicCost > rhs.heuristicCost;
            }
            return lhs.totalCost > rhs.totalCost;
        }
    };

    std::vector<BlockType> maze;
    std::vector<int> visitCost;
    std::priority_queue<Node, std::vector<Node>, CompareNodes> exploring;

    bool isPathFound;
    std::vector<Point> parent;
    std::stack<Point> path;

    Point startPoint;
    Point endPoint;
    MazeSize size;
    std::vector<std::vector<int>> legalMoves {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    A_star(const MazeSize &size, std::vector<BlockType> &maze);
    virtual std::vector<BlockType> step() override;
};

#endif //A_STAR_H
