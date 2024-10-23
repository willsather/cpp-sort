//
// Created by Will Sather on 10/22/24.
//
#pragma once

#include <vector>

class Sort {
public:
    virtual ~Sort() = default;

    virtual void sort(std::vector<int> &data) = 0;
};
