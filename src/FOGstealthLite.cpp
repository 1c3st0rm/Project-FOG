#include <iostream>
#include <string>
#include <random>
#include <iomanip>
#include <vector>

int main(){
    std::string startSeed = "cGxhbmV3b29kZW5saWZlaW5zdGFudHRvbW9ycm93YWNjaWRlbnR0b21vcnJvd25lYXI";
    unsigned long long start_pot = 18446744073709551427ULL;
    unsigned long long multiplier = 9223372036854775783ULL;

    std::random_device rd;
    std::vector<unsigned char> salt(4);
    for(int i =0; i < 4; i++){
        salt[i] = rd() % 256;
    }

        for(char c : startSeed){
        start_pot ^= (unsigned char)c;
        start_pot *= multiplier;
    }

    for(unsigned char s : salt){
        start_pot ^= s;
        start_pot *= multiplier;
    }

    std::vector<unsigned char> masterSeedBuffer;

    for(int i = 0 ; i < 64; i++) {
        start_pot *= multiplier;
        unsigned char lastByte = (unsigned char)(start_pot & 0xFF);
        masterSeedBuffer.push_back(lastByte);
    }
    
    for (unsigned char m : salt){
        std::cout << std::hex << std::uppercase << std::setfill('0') << std:: setw(2) << (int)m << " ";
    }

    std::string keyString(masterSeedBuffer.begin(), masterSeedBuffer.end());
    
    std::string message = "WELCOME TO THE FUTURE OF CYBERSECURITY ARCHITECTURE!";
    int j = 0;
    for (unsigned char x : keyString) {
        int a = (keyString[(j * 3) % 64] % 256) + 1; // a cannot be 0 for modular inverse
        int b = 3;                         // 3 is a perfect primitive root for 257
        int h = keyString[(j * 2) %64];
        int k = keyString[(j * 2 + 1) %64];

        // Modular offset using 257
        int e = (x - h + 257) % 257;

        int p = 1;
        for (int i = 0; i < e; i++) p = (p * b) % 257;

        int result = (a * p + k) % 257;
        
        if(result > 255){
            result = 0;
        }

        std::cout << std::hex << std::uppercase << std::setfill('0') << std::setw(2) << result << " ";
    }
    std::cout << std::endl;
    j++;
}