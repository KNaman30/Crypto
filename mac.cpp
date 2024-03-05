#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

// Basic custom MAC function using XOR
std::vector<uint8_t> customMAC(const std::string& key, const std::string& message) {
    std::vector<uint8_t> mac;
    for (size_t i = 0; i < message.length(); i++) {
        mac.push_back(static_cast<uint8_t>(message[i]) ^ static_cast<uint8_t>(key[i % key.length()]));
    }
    return mac;
}

int main() {
    std::string key = "secret_key";
    std::string message = "Hello, World!";

    std::vector<uint8_t> mac = customMAC(key, message);

    std::cout << "Key: " << key << std::endl;
    std::cout << "Message: " << message << std::endl;
    std::cout << "Custom MAC: ";
    for (uint8_t byte : mac) {
        std::cout << std::hex << static_cast<int>(byte);
    }
    std::cout << std::endl;

    return 0;
}
