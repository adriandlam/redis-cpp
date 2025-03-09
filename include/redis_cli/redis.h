/**
 * @file Redis.h
 * @brief A simple in-memory key-value store inspired by Redis
 * 
 * This implementation provides basic Redis-like functionality for storing
 * string values associated with string keys in memory.
 */

#include <unordered_map>
#include <string>
#include <vector>
#include "value.h"

/**
 * @class Redis
 * @brief Simple implementation of an in-memory key-value store
 * 
 * This class provides a subset of Redis functionality for storing and
 * retrieving string values in memory with string keys.
 */
class Redis {
    private:
        /** Storage container for all key-value pairs */
        std::unordered_map<std::string, std::string> data;

        /**
         * @brief Check if the data store is empty
         * @return true if empty, false otherwise
         */
        bool is_empty();

    public:
        /**
         * @brief Default constructor
         * 
         * Initializes an empty Redis instance.
         */
        Redis();
    
        /**
         * @brief Retrieve a value by key
         * @param key The key to look up
         * @return The value associated with the key, or empty string if not found
         */
        std::string get(const std::string key);
    
        /**
         * @brief Store a key-value pair
         * @param key The key to associate with the value
         * @param value The value to store
         */
        void set(const std::string key, const std::string& value);
    
        /**
         * @brief Delete a key-value pair
         * @param key The key to delete
         */
        void del(const std::string key);
    
        /**
         * @brief Get all keys in the store
         * @return A vector containing all keys
         */
        std::vector<std::string> keys();
    
        /**
         * @brief Get all values in the store
         * @return A vector containing all values
         */
        std::vector<std::string> values();
    
        /**
         * @brief Get memory usage of the store in bytes
         * @return Size in bytes
         */
        size_t storage();
    
        /**
         * @brief Get number of key-value pairs in the store
         * @return Count of key-value pairs
         */
        size_t size();
    
        /**
         * @brief Remove all key-value pairs from the store
         */
        void flushall();

        /**
         * @brief Check if a key exists in the store
         * @param key The key to check
         * @return true if the key exists, false otherwise
         */
        bool exists(const std::string& key);

        /**
         * @brief Get multiple values at once
         * @param keys Vector of keys to retrieve
         * @return Vector of values corresponding to the keys (empty string for missing keys)
         */
        std::vector<std::string> mget(const std::vector<std::string>& keys);

        /**
         * @brief Set multiple key-value pairs at once
         * @param pairs Vector of key-value pairs to store
         */
        void mset(const std::vector<std::pair<std::string, std::string>>& pairs);

        /**
         * @brief Save the current data store to a file
         * @param filename The path to the file
         * @return true if save was successful, false otherwise
         */
        bool save(const std::string& filename);

        /**
         * @brief Load data from a file into the store
         * @param filename The path to the file
         * @return true if load was successful, false otherwise
         */
        bool load(const std::string& filename);
};