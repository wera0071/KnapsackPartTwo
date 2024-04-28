#include "parser.h"
#include "solver.h"

#include <iostream>
#include <vector>
#include <utility>

int main() {
    Parser parser;
    std::string filename;

    std::cout << "Enter the filename: ";
    std::cin >> filename;
    parser.readFile(filename);

    int itemCount = parser.countItems();
    int capacity = parser.calculateTotal();
    auto& items = parser.accessData();

    Optimizer optimizer(itemCount, capacity, items);
    auto [maxValue, itemIndices] = optimizer.findSolution();

    std::vector<int> results(itemCount, 0);
    std::cout << maxValue << " ";
    for (int index : itemIndices) {
        results[index] = 1;
        capacity -= items[index].second;
    }
    std::cout << capacity << "\n";
    for (int result : results) {
        std::cout << result << " ";
    }

    return 0;
}
