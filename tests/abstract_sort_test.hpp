#pragma once

#include "gtest/gtest.h"
#include "sort.hpp"

class AbstractSortTest : public ::testing::Test {
protected:
    virtual Sort *getSorter() = 0;

    void testEmptyVector() {
        Sort *sorter = getSorter();
        std::vector<int> data;

        sorter->sort(data);

        EXPECT_TRUE(data.empty());
    }

    void testSingleElement() {
        Sort *sorter = getSorter();
        std::vector data = {1};

        sorter->sort(data);

        EXPECT_EQ(data, std::vector({1}));
    }

    void testSortsCorrectly() {
        Sort *sorter = getSorter();
        std::vector data = {3, 6, 8, 10, 1, 2, 1};

        sorter->sort(data);

        EXPECT_EQ(data, std::vector({1, 1, 2, 3, 6, 8, 10}));
    }

    void testAlreadySorted() {
        Sort *sorter = getSorter();
        std::vector data = {1, 2, 3, 4, 5};

        sorter->sort(data);

        EXPECT_EQ(data, std::vector({1, 2, 3, 4, 5}));
    }

    void testReverseSorted() {
        Sort *sorter = getSorter();
        std::vector data = {5, 4, 3, 2, 1};

        sorter->sort(data);

        EXPECT_EQ(data, std::vector({1, 2, 3, 4, 5}));
    }
};
