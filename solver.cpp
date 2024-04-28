#include "solver.h"

Optimizer::Optimizer(int itemCount, int capacity, const std::vector<std::pair<int, int>>& items)
    : itemCount(itemCount), capacity(capacity), items(items), maxValue(0) {}

void Optimizer::setData(int itemCount, int capacity, const std::vector<std::pair<int, int>>& items) {
    this->itemCount = itemCount;
    this->capacity = capacity;
    this->items = items;
}

void Optimizer::reset() {
    itemCount = 0;
    capacity = 0;
    maxValue = 0;
    currentItems.clear();
    bestItems.clear();
    originalIndices.clear();
}

std::pair<int, std::vector<int>> Optimizer::findSolution() {
    currentItems.resize(itemCount, 0);
    originalIndices.resize(itemCount);
    for (int i = 0; i < itemCount; ++i) {
        originalIndices[i] = i;
    }
    branchAndBound(0, 0, 0, calculateBound(0, 0, 0));
    std::vector<int> realIndices;
    for (int i = 0; i < itemCount; ++i) {
        if (bestItems[i] == 1) {
            realIndices.push_back(originalIndices[i]);
        }
    }
    return { maxValue, realIndices };
}

void Optimizer::branchAndBound(int level, int currentWeight, int currentValue, int bestValue) {
    if (level == itemCount || currentWeight > capacity)
        return;

    if (currentValue + bestValue <= maxValue)
        return;

    if (currentWeight + items[level].second <= capacity) {
        currentItems[level] = 1;
        if (currentValue + items[level].first > maxValue) {
            maxValue = currentValue + items[level].first;
            bestItems = currentItems;
        }
        branchAndBound(level + 1, currentWeight + items[level].second, currentValue + items[level].first, calculateBound(level + 1, currentWeight + items[level].second, currentValue + items[level].first));
        currentItems[level] = 0;
    }

    branchAndBound(level + 1, currentWeight, currentValue, calculateBound(level + 1, currentWeight, currentValue));
}

int Optimizer::calculateBound(int level, int currentWeight, int currentValue) const {
    int weight = currentWeight;
    int value = currentValue;

    for (int i = level; i < itemCount && weight <= capacity; ++i) {
        if (weight + items[i].second <= capacity) {
            weight += items[i].second;
            value += items[i].first;
        } else {
            value += (capacity - weight) * (items[i].first / double(items[i].second));
            break;
        }
    }

    return value - currentValue;
}
