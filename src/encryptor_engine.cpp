#include <iostream>
#include <string>
#include <random>
#include <iomanip>
#include <iostream>
#include <string>
#include <random>
#include <iomanip>
#include <vector>

int main() {
    std::string password, message;
    unsigned long long start_pot = 18446744073709551427ULL;
    unsigned long long multiplier = 9223372036854775783ULL;

    std::cout << "Password: ";
    std::getline(std::cin, password);
    for (char c : password) { start_pot ^= (unsigned char)c; start_pot *= multiplier; }

    std::mt19937_64 engine(start_pot);
    std::uniform_int_distribution<int> tamer(0, 255);

    std::cout << "Insert Message: ";
    std::cin >> std::ws; 
    std::getline(std::cin, message);

    for (unsigned char x : message) {
        int a = (tamer(engine) % 256) + 1; // a cannot be 0 for modular inverse
        int b = 3;                         // 3 is a PERFECT primitive root for 257
        int h = tamer(engine);
        int k = tamer(engine);

        // Modular offset using 257
        int e = (x - h + 257) % 257;

        int p = 1;
        for (int i = 0; i < e; i++) p = (p * b) % 257;

        int result = (a * p + k) % 257;
        std::cout << std::hex << std::uppercase << std::setfill('0') << std::setw(2) << result << " ";
    }
    std::cout << std::endl;
    return 0;
}