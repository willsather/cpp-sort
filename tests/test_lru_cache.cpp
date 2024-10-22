#include "gtest/gtest.h"
#include "lru_cache.hpp"

// test that values are inserted and retrieved correctly
TEST(LRUCacheTest, BasicPutAndGet)
{
    LRUCache<int, std::string> cache(2);

    cache.put(1, "one");
    cache.put(2, "two");

    EXPECT_EQ(cache.get(1).value(), "one");
    EXPECT_EQ(cache.get(2).value(), "two");
}

// test that cache removes least recently used items
TEST(LRUCacheTest, RemoveTest)
{
    LRUCache<int, std::string> cache(2);

    cache.put(1, "one");
    cache.put(2, "two");
    cache.put(3, "three"); // this should remove key 1

    EXPECT_EQ(cache.get(1), std::nullopt); // key 1 should be removed
    EXPECT_EQ(cache.get(2).value(), "two");
    EXPECT_EQ(cache.get(3).value(), "three");
}

// test the least recently used order
TEST(LRUCacheTest, LRUOrderTest)
{
    LRUCache<int, std::string> cache(2);

    cache.put(1, "one");
    cache.put(2, "two");
    cache.get(1);          // access key 1, making it most recently used
    cache.put(3, "three"); // this should remove key 2

    EXPECT_EQ(cache.get(2), std::nullopt); // key 2 should be remove
    EXPECT_EQ(cache.get(1).value(), "one");
    EXPECT_EQ(cache.get(3).value(), "three");
}
