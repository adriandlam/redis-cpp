#include "include/redis_cli/value.h"

Value::Value(std::string type, std::string value, uint8_t ttl) {
    this->type = type;
    this->value = value;
    this->ttl = ttl;
}

std::string Value::get_type() {
    return this->type;
}

std::string Value::get_value() {
    return this->value;
}

uint8_t Value::get_ttl() {
    return this->ttl;
}

void Value::set_ttl(uint8_t ttl) {
    this->ttl = ttl;
}