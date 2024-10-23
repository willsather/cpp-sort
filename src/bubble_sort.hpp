//
// Created by Will Sather on 10/22/24.
//
#pragma once

#include "sort.hpp"

class BubbleSort : public Sort {
public:
    void sort(std::vector<int> &data) override;
};

inline void BubbleSort::sort(std::vector<int> &data) {
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data.size() - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
            }
        }
    }
}
