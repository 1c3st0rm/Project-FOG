#include <iostream>

char message;
int key;

int main(){
    std::cout << "Enter message: ";
    std::cin >> message;
    std::cout << "Enter key: ";
    std::cin >> key;
    char result = message ^ key;
    std::cout << result;
    return 0;
}