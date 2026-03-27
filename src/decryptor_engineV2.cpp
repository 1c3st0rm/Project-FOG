#include <iostream>
#include <string>
#include <random>
#include <iomanip>
#include <sstream>

int findInverse(int a) {
    int m = 257, r = a, x0 = 0, x1 = 1;
    while (r != 0) {
        int q = m / r;
        int t = r; r = m % r; m = t;
        t = x1; x1 = x0 - q * x1; x0 = t;
    }
    if (x0 < 0) x0 += 257;
    return x0;
}

int main() {
    int hex_val;
    std::string password;
    std::string pepper = "1c3st0rm_4_The_Win";
    unsigned long long start_pot = 18446744073709551427ULL;
    unsigned long long multiplier = 9223372036854775783ULL;

    std::cout << "Password: ";
    std::getline(std::cin, password);
    for (char c : password){ 
        start_pot ^= (unsigned char)c; start_pot *= multiplier; 
    }

    std::cout << "Hex: ";
    for(int i = 0; i <4; i++){
        std::cin >> std::hex >> hex_val;

        start_pot = start_pot ^ hex_val;
        start_pot = start_pot * multiplier;
    }

    for(char n : pepper){
        start_pot = start_pot ^ n;
        start_pot = start_pot * multiplier;
    }

    std::mt19937_64 engine(start_pot);
    std::uniform_int_distribution<int> tamer(0, 255);

    // Pre-calculate the Log Table for mod 257
    int logTable[257];
    for(int i = 0; i < 257; i++) logTable[i] = -1;
    int val = 1;
    for (int e = 0; e < 256; e++) {
        logTable[val] = e;
        val = (val * 3) % 257;
    }

    std::cout << "Decrypted Message: ";
    int encryptionValue;

    while (std::cin >> std::hex >> encryptionValue) {
        int encryptedValue = encryptionValue;
        int a = (tamer(engine) % 256) + 1;
        int h = tamer(engine);
        int k = tamer(engine);

        int stripped = (encryptedValue - k + 257) % 257;
        int Z = findInverse(a);
        int powerResult = (stripped * Z) % 257;

        int exponent = logTable[powerResult];
        if (exponent == -1) {
            std::cout << "?";
        } else {
            std::cout << (char)((h + exponent) % 257);
        }
    }
    std::cout << std::endl;
    return 0;
}