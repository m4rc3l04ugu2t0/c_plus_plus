#include<iostream>
#include<cmath>

int main() {
    double a;
    double b;
    double c;

    std::cout << "Enter side A: " << std::endl;
    std::cin >> a;

    std::cout << "Enter side B: " << std::endl;
    std::cin >> b;

    c = pow(pow(a, 2) + pow(b, 2), 0.5);

    std::cout << "Side C: " << c << std::endl;

    return 0;
}