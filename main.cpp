#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Redis {
    private:
        std::unordered_map<std::string, std::string> data;
        bool is_empty() {
            return data.empty();
        }

    public:
        std::string get(const std::string key) {
            if (data.find(key) == data.end()) {
                return "Key not found";
            }
            return data[key];
        }

        void set(const std::string key, const std::string& value) {
            data[key] = value;
        }

        size_t size() {
            return data.size();
        }

        void del(const std::string key) {
            data.erase(key);
        }
};

int main() {
    using namespace std;

    Redis redis;

    cout << "Simple Redis CLI - Type HELP for available commands" << endl;

    while (true) {
        cout << "> ";
        string command;
        getline(cin, command);

        if (command == "HELP") {
            cout << "Available commands:" << endl;
            cout << "SET <key> <value> - Set a key-value pair" << endl;
            cout << "GET <key> - Get the value of a key" << endl;
            cout << "DEL <key> - Delete a key-value pair" << endl;
            cout << "SIZE - Get the number of key-value pairs" << endl;
            cout << "EXIT - Exit the program" << endl;
        } else if (command == "SET") {

        } else if (command == "SIZE") {
            cout << redis.size() << endl;
        } else if (command == "EXIT") {
            break;
        } else {
            cout << "Unknown command, type HELP for available commands" << endl;
        }
        
    }

    return 0;
}