//
// Created by Will Sather on 10/22/24.
//
#pragma once

#include "sort.hpp"
#include <list>

class QuickSort : public Sort {
public:
    void sort(std::vector<int>& data) override;

private:
    void quickSort(std::vector<int>& data, int low, int high);
    int partition(std::vector<int>& data, int low, int high);
};

inline void QuickSort::sort(std::vector<int>& data) {
    if (data.size() <= 1) return;
    quickSort(data, 0, data.size() - 1);
}

inline void QuickSort::quickSort(std::vector<int>& data, int low, int high) {
    if (low < high) {
        int pi = partition(data, low, high);
        quickSort(data, low, pi - 1);
        quickSort(data, pi + 1, high);
    }
}

int QuickSort::partition(std::vector<int>& data, int low, int high) {
    int pivot = data[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (data[j] < pivot) {
            ++i;
            std::swap(data[i], data[j]);
        }
    }

    std::swap(data[i + 1], data[high]);
    return i + 1;
}