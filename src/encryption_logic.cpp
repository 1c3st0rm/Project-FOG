#include <iostream>
#include <string>
#include <random>

std::string password;
std::string hash;
std::string messege;
unsigned long long pot = 18446744073709551427;
unsigned long long multiplier = 9223372036854775783;

//hasher
int main(){
   //PASSWORD
   std::cout << "Password: ";
   std::getline(std::cin, password); 

   //SCRAMBLE
   for (char c : password){
    pot = pot ^ c;
    pot = pot * multiplier;
   }
   std::cout << pot;
}