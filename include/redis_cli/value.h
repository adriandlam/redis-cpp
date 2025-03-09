/**
 * @file value.h
 * @brief A class for storing and retrieving values with a TTL
 * 
 * This class provides a simple way to store and retrieve values with a TTL.
 * 
 */

#include <unordered_map>
#include <string>
#include <vector>

/**
 * @class Value
 * @brief Simple implementation of a value with a TTL
 * 
 * This class provides a simple way to store and retrieve values with a TTL.
 */


#include <string>

class Value {
    private:
        /** The type of the value */
        std::string type;

        /** The value of the value */
        std::string value;

        /** The TTL of the value */
        uint8_t ttl;

    public:
        /**
         * @brief Constructor for the Value class
         * @param type The type of the value
         * @param value The value of the value
         * @param ttl The TTL of the value
         */
        Value(std::string type, std::string value, uint8_t ttl);

        /**
         * @brief Get the type of the value
         * @return The type of the value
         */
        std::string get_type();

        /**
         * @brief Get the value of the value
         * @return The value of the value
         */
        std::string get_value();

        /**
         * @brief Get the TTL of the value
         * @return The TTL of the value
         */
        uint8_t get_ttl();

        /**
         * @brief Set the TTL of the value
         * @param ttl The TTL of the value
         */
        void set_ttl(uint8_t ttl);
};