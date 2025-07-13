
#ifndef SEARCHALGORITHM_H
#define SEARCHALGORITHM_H

#include <vector>
#include "Config.h"

class SearchAlgorithm {
public:
    virtual std::vector<BlockType> step() = 0;
};

#endif //SEARCHALGORITHM_H
