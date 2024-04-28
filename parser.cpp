#include "parser.h"

void Parser::initialize() {
    if (itemCount <= 0)
        return;
    if (totalCapacity <=0)
        return;
}

void Parser::cleanUp() {
    itemCount = 0;
    totalCapacity = 0;
}

void Parser::readFile(const std::string& filename) {
    this->cleanUp();

    std::ifstream fileStream(filename);

    fileStream >> itemCount;
    fileStream >> totalCapacity;
    this->initialize();

    data.reserve(itemCount);
    for(int i = 0; i < itemCount; i++) {
        int value, weight;
        fileStream >> value >> weight;
        data.emplace_back(std::make_pair(value, weight));
    }

    fileStream.close();
}
