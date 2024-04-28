#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <cmath>
#include <vector>

class Parser {
public:
    Parser(): itemCount(0) {};
    void initialize();
    void cleanUp();
    ~Parser() { cleanUp(); };
    void readFile(const std::string& filename);
    int countItems() const { return itemCount; };
    int calculateTotal() const { return totalCapacity; };
    std::vector<std::pair<int, int>>& accessData() { return data; };
private:
    int itemCount;
    int totalCapacity;
    std::vector<std::pair<int, int>> data;
};

#endif // PARSER_H
