#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

class Optimizer {
public:
    Optimizer(): itemCount(0), capacity(0), maxValue(0) {}
    Optimizer(int itemCount, int capacity, const std::vector<std::pair<int, int>>& items);
    void setData(int itemCount, int capacity, const std::vector<std::pair<int, int>>& items);
    void reset();
    ~Optimizer() { reset(); };
    std::pair<int, std::vector<int>> findSolution();
    int getItemCount() const { return itemCount; };
    int getMaxValue() const { return maxValue; };
    void branchAndBound(int level, int currentWeight, int currentValue, int bestValue);
    int calculateBound(int level, int currentWeight, int currentValue) const;
private:
    int itemCount;
    int capacity;
    std::vector<std::pair<int, int>> items;
    int maxValue;
    std::vector<int> currentItems;
    std::vector<int> bestItems;
    std::vector<int> originalIndices;
};

#endif // SOLVER_H
