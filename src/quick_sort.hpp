//
// Created by Will Sather on 10/22/24.
//
#pragma once

#include "sort.hpp"
#include <list>

class QuickSort final : public Sort {
public:
    void sort(std::vector<int> &data) override;

private:
    static void quickSort(std::vector<int> &data, int start, int end);

    static int partition(std::vector<int> &data, int start, int end);
};

inline void QuickSort::sort(std::vector<int> &data) {
    quickSort(data, 0, data.size() - 1);
}

inline void QuickSort::quickSort(std::vector<int> &data, const int start, const int end) {
    if (start >= end) {
        return;
    }

    const int pivot = partition(data, start, end);

    quickSort(data, start, pivot - 1);
    quickSort(data, pivot + 1, end);
}

inline int QuickSort::partition(std::vector<int> &data, const int start, const int end) {
    const int pivot = data[end];
    int i = start - 1;

    for (int j = start; j < end; ++j) {
        if (data[j] < pivot) {
            ++i;
            std::swap(data[i], data[j]);
        }
    }

    std::swap(data[i + 1], data[end]);
    return i + 1;
}
