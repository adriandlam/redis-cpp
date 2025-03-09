#include "include/redis_cli/redis.h"

using namespace std;

Redis::Redis() {
    data = unordered_map<string, string>();
}

bool Redis::is_empty() {
    return data.empty();
}

string Redis::get(const string key) {
    if (data.find(key) == data.end()) {
        return "";
    }
    return data[key];
}

void Redis::set(const string key, const string& value) {
    data[key] = value;
}

void Redis::del(const string key) {
    data.erase(key);
}

vector<string> Redis::keys() {
    vector<string> keys;
    for (const auto& pair: data) {
        keys.push_back(pair.first);
    }
    return keys;
}

vector<string> Redis::values() {
    vector<string> values;
    for (const auto& pair: data) {
        values.push_back(pair.second);
    }
    return values;
}

size_t Redis::storage() {
    size_t storage = 0;
    for (const auto& pair: data) {
        storage += pair.first.size() + pair.second.size();
    }
    return storage;
}

size_t Redis::size() {
    return data.size();
}

void Redis::clear() {
    data.clear();
}   