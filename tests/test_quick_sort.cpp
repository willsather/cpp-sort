#include "abstract_sort_test.hpp"
#include "quick_sort.hpp"

class QuickSortTest : public AbstractSortTest {
protected:
    Sort *getSorter() override {
        return new QuickSort();
    }
};

TEST_F(QuickSortTest, EmptyVector) {
    testEmptyVector();
}

TEST_F(QuickSortTest, SingleElement) {
    testSingleElement();
}

TEST_F(QuickSortTest, SortsCorrectly) {
    testSortsCorrectly();
}

TEST_F(QuickSortTest, AlreadySorted) {
    testAlreadySorted();
}

TEST_F(QuickSortTest, ReverseSorted) {
    testReverseSorted();
}
