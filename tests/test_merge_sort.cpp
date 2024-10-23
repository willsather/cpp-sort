#include "abstract_sort_test.hpp"
#include "merge_sort.hpp"

class MergeSortTest : public AbstractSortTest {
protected:
    Sort *getSorter() override {
        return new MergeSort();
    }
};

TEST_F(MergeSortTest, EmptyVector) {
    testEmptyVector();
}

TEST_F(MergeSortTest, SingleElement) {
    testSingleElement();
}

TEST_F(MergeSortTest, SortsCorrectly) {
    testSortsCorrectly();
}

TEST_F(MergeSortTest, AlreadySorted) {
    testAlreadySorted();
}

TEST_F(MergeSortTest, ReverseSorted) {
    testReverseSorted();
}
