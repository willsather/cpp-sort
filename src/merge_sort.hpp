//
// Created by Will Sather on 10/23/24.
//
#pragma once

#include "sort.hpp"

class MergeSort final : public Sort {
public:
    void sort(std::vector<int> &data) override;

private:
    static void mergeSort(std::vector<int> &data, int start, int end);

    static void merge(std::vector<int> &data, int start, int middle, int end);
};

inline void MergeSort::sort(std::vector<int> &data) {
    mergeSort(data, 0, data.size() - 1);
}

inline void MergeSort::mergeSort(std::vector<int> &data, int start, int end) {
    // base case
    if (start >= end) {
        return;
    }

    // calculate middle index
    const int middle = start + (end - start) / 2;

    // sort first half
    mergeSort(data, start, middle);

    // sort second half
    mergeSort(data, middle + 1, end);

    // merge the sorted subarrays
    merge(data, start, middle, end);
}

inline void MergeSort::merge(std::vector<int> &data, const int start, const int middle, const int end) {
    const std::vector<int> leftSubarray = {data.begin() + start, data.begin() + middle + 1};
    const std::vector<int> rightSubarray = {data.begin() + middle + 1, data.begin() + end + 1};

    int i = 0, j = 0, k = start;

    // compare elements from both smaller arrays and merge in sorted order
    while (i < leftSubarray.size() && j < rightSubarray.size()) {
        if (leftSubarray[i] <= rightSubarray[j]) {
            data[k++] = leftSubarray[i++];
        } else {
            data[k++] = rightSubarray[j++];
        }
    }

    // copy any remaining elements from left subarray
    while (i < leftSubarray.size()) {
        data[k++] = leftSubarray[i++];
    }

    // copy any remaining elements from right subarray
    while (j < rightSubarray.size()) {
        data[k++] = rightSubarray[j++];
    }
}
