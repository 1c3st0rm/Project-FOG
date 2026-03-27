#include <iostream>
#include <string>

std::string message;
int key;

int main(){
    std::cout << "Message: ";
    std::getline(std::cin, message);
    std::cout << "Key: ";
    std::cin >> key;
    for (int i = 0; i < message.length(); i++) {
        message[i] = message[i] ^ key;
    }
    std::cout << message;
    return 0;
}