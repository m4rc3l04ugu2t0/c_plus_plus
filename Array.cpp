#include<iostream>
int main() {
    std::string cars[] = {"Corvett", "Mustang", "Camry"};
    int numbers[3];

    cars[2] = "Camaro";

    std::cout << cars[0] << std::endl;

    return 0;
}