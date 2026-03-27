#include <iostream>

char message = 'A';
char key = 24;
int main(){
    char result = message ^ key;
    std::cout << result;
    return 0;
}