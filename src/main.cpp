#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include "include/redis_cli/redis.h"

int main() {
    using namespace std;

    cout << "\033[1;36m=== Simple Redis CLI ===\033[0m\nType HELP for available commands\n" << endl;

    Redis redis;

    while (true) {
        cout << "\033[1;32m> \033[0m";
        string input;
        getline(cin, input);
        
        istringstream iss(input);
        string command;
        iss >> command;

        if (command == "HELP") {
            cout << "\n\033[1;33mAvailable Commands:\033[0m\n"
                 << "  \033[1;36mSET\033[0m <key> <value>  - Set a key-value pair\n"
                 << "  \033[1;36mGET\033[0m <key>         - Get the value of a key\n"
                 << "  \033[1;36mDEL\033[0m <key>         - Delete a key-value pair\n"
                 << "  \033[1;36mKEYS\033[0m              - List all keys\n"
                 << "  \033[1;36mVALUES\033[0m            - List all values\n"
                 << "  \033[1;36mSTORAGE\033[0m           - Get storage size of the database\n"
                 << "  \033[1;36mSIZE\033[0m              - Get number of key-value pairs\n"
                 << "  \033[1;36mCLEAR\033[0m             - Clear the database\n"
                 << "  \033[1;36mEXIT\033[0m              - Exit the program\n" << endl;
        } else if (command == "SET") {
            string key, value;
            iss >> key >> value;

            clock_t start = clock();
            redis.set(key, value);
            cout << "\033[1;32m[SUCCESS]\033[0m Set key '\033[1;36m" << key << "\033[0m' to value '\033[1;36m" << value << "\033[0m' (\033[1;35m" << clock() - start << "ms\033[0m)" << endl;
        } else if (command == "GET") {
            string key;
            iss >> key;

            if (redis.get(key) == "") {
                cout << "\033[1;31m[ERROR]\033[0m Key '\033[1;36m" << key << "\033[0m' not found" << endl;
                continue;
            }

            clock_t start = clock();
            cout << "\033[1;32m[SUCCESS]\033[0m Value: '\033[1;36m" << redis.get(key) << "\033[0m' (\033[1;35m" << clock() - start << "ms\033[0m)" << endl;
        } else if (command == "DEL") {
            string key;
            iss >> key;

            clock_t start = clock();
            redis.del(key);
            cout << "\033[1;32m[SUCCESS]\033[0m Deleted key '\033[1;36m" << key << "\033[0m' (\033[1;35m" << clock() - start << "ms\033[0m)" << endl;
        } else if (command == "KEYS") {
            clock_t start = clock();
            vector<string> keys = redis.keys();
            cout << "\033[1;32m[SUCCESS]\033[0m Found \033[1;36m" << keys.size() << "\033[0m keys (\033[1;35m" << clock() - start << "ms\033[0m)" << endl;
            if (!keys.empty()) {
                cout << "\033[1;33mKeys:\033[0m" << endl;
                for (const auto& key : keys) {
                    cout << "  - \033[1;36m" << key << "\033[0m" << endl;
                }
            }
        } else if (command == "VALUES") {
            clock_t start = clock();
            vector<string> values = redis.values();
            cout << "\033[1;32m[SUCCESS]\033[0m Found \033[1;36m" << values.size() << "\033[0m values (\033[1;35m" << clock() - start << "ms\033[0m)" << endl;
            if (!values.empty()) {
                cout << "\033[1;33mValues:\033[0m" << endl;
                for (const auto& value : values) {
                    cout << "  - \033[1;36m" << value << "\033[0m" << endl;
                }
            }
        } else if (command == "STORAGE") {
            clock_t start = clock();
            cout << "\033[1;32m[INFO]\033[0m Storage usage: \033[1;36m" << redis.storage() << "\033[0m bytes (\033[1;35m" << clock() - start << "ms\033[0m)" << endl;
        } else if (command == "SIZE") {
            clock_t start = clock();
            cout << "\033[1;32m[INFO]\033[0m Database contains \033[1;36m" << redis.size() << "\033[0m key-value pairs (\033[1;35m" << clock() - start << "ms\033[0m)" << endl;
        } else if (command == "CLEAR") {
            cout << "\033[1;33m[WARN]\033[0m Are you sure you want to clear all data? (y/N): ";
            string confirm;
            getline(cin, confirm);
            if (confirm == "y" || confirm == "Y") {
                clock_t start = clock();
                redis.clear();
                cout << "\033[1;32m[SUCCESS]\033[0m Database cleared (\033[1;35m" << clock() - start << "ms\033[0m)" << endl;
            } else {
                cout << "\033[1;33m[INFO]\033[0m Operation cancelled" << endl;
            }
        } else if (command == "EXIT") {
            break;
        } else {
            cout << "\033[1;31m[ERROR]\033[0m Unknown command '\033[1;36m" << command << "\033[0m'. Type HELP for available commands." << endl;
        }
    }



    return 0;
}