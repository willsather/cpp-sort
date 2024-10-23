#include "abstract_sort_test.hpp"
#include "bubble_sort.hpp"

class BubbleSortTest : public AbstractSortTest {
protected:
    Sort* getSorter() override {
        return new BubbleSort();
    }
};

TEST_F(BubbleSortTest, EmptyVector) {
    testEmptyVector();
}

TEST_F(BubbleSortTest, SingleElement) {
    testSingleElement();
}

TEST_F(BubbleSortTest, SortsCorrectly) {
    testSortsCorrectly();
}

TEST_F(BubbleSortTest, AlreadySorted) {
    testAlreadySorted();
}

TEST_F(BubbleSortTest, ReverseSorted) {
    testReverseSorted();
}
