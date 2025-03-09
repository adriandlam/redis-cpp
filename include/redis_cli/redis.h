#include <unordered_map>
#include <string>
#include <vector>

class Redis {
    private:
        std::unordered_map<std::string, std::string> data;
        bool is_empty();

    public:
        Redis();
        std::string get(const std::string key);
        void set(const std::string key, const std::string& value);
        void del(const std::string key);
        std::vector<std::string> keys();
        std::vector<std::string> values();
        size_t storage();
        size_t size();
        void clear();
};