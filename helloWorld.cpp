#include <iostream>

// typedef std::string text_t;
// typedef int number_t;
using text_t = std::string;
using number_t = int;
using float_t = double;

int main() {
    const text_t firstName = "Bro";
    number_t age = 18;
    float_t height = 1.80;
    age+=1;
    age++;

    std::cout << "Hello world!" << std::endl;
    std::cout << "firstName => " << firstName << "age => " << age << std::endl;

    return 0;
}