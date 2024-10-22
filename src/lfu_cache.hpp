#pragma once

#include "cache.hpp"
#include <unordered_map>
#include <list>

template <typename Key, typename Value>
class LFUCache : public Cache<Key, Value>
{
public:
    LFUCache(int capacity);

    void put(const Key &key, const Value &value) override;
    std::optional<Value> get(const Key &key) override;

private:
    void updateFrequency(const Key &key);

    struct CacheEntry
    {
        Value value;
        int frequency;
    };

    int capacity;
    int minFrequency;

    std::unordered_map<Key, CacheEntry> keyValueMap;                       // stores key and {value, frequency}
    std::unordered_map<int, std::list<Key>> frequencyListMap;              // stores frequency and list of keys
    std::unordered_map<Key, typename std::list<Key>::iterator> keyIterMap; // stores key and its position in the frequency list
};

template <typename Key, typename Value>
LFUCache<Key, Value>::LFUCache(int capacity) : capacity(capacity), minFrequency(0) {}

template <typename Key, typename Value>
std::optional<Value> LFUCache<Key, Value>::get(const Key &key)
{
    if (!keyValueMap.contains(key))
    {
        return std::nullopt;
    }

    // update the frequency of the key
    updateFrequency(key);

    // Return the value associated with the key
    return keyValueMap[key].value;
}

template <typename Key, typename Value>
void LFUCache<Key, Value>::put(const Key &key, const Value &value)
{
    if (capacity == 0)
        return;

    // If the key is already in the cache, update its value and frequency
    if (keyValueMap.contains(key))
    {
        keyValueMap[key].value = value;
        updateFrequency(key);
        return;
    }

    // If the cache is full, evict the least frequently used key
    if (keyValueMap.size() >= capacity)
    {
        // Evict the least frequently used key
        Key evictKey = frequencyListMap[minFrequency].back();
        frequencyListMap[minFrequency].pop_back();
        if (frequencyListMap[minFrequency].empty())
        {
            frequencyListMap.erase(minFrequency); // Remove empty list
        }
        keyValueMap.erase(evictKey);
        keyIterMap.erase(evictKey);
    }

    // Insert the new key with value and frequency 1
    keyValueMap[key] = {value, 1};
    frequencyListMap[1].push_front(key);
    keyIterMap[key] = frequencyListMap[1].begin();
    minFrequency = 1; // Reset minFrequency to 1 for new key
}

template <typename Key, typename Value>
void LFUCache<Key, Value>::updateFrequency(const Key &key)
{
    int freq = keyValueMap[key].frequency;

    // remove the key from its current frequency list
    frequencyListMap[freq].erase(keyIterMap[key]);
    if (frequencyListMap[freq].empty())
    {
        // remove empty frequency list
        frequencyListMap.erase(freq);

        // increment minFrequency if necessary
        if (minFrequency == freq)
        {
            minFrequency++;
        }
    }

    // increment the key's frequency and move it to the new list
    ++keyValueMap[key].frequency;
    int newFreq = keyValueMap[key].frequency;
    frequencyListMap[newFreq].push_front(key);
    keyIterMap[key] = frequencyListMap[newFreq].begin();
}
