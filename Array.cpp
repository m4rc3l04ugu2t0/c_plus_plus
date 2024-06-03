#include<iostream>
int main() {
    std::string cars[] = {"Corvett", "Mustang", "Camry"};
    int numbers[3];

    cars[2] = "Camaro";

    std::cout << cars[0] << std::endl;

    std::string students[] = {"student1", "student2", "student3"};

    for (int i = 0; i < sizeof(students)/sizeof(std::string); i++) {
        std::cout << students[i] << std::endl;
    }

    std::cout << sizeof(students);

    for(std::string student : students) {
        std::cout << student << std::endl;
    }

    return 0;
}