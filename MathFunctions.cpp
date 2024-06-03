#include<iostream>
#include<cmath>

int main() {
    double x = 3;
    double y = 4;
    double z;

    // z = std::max(x, y);
    // z = std::min(x, y);
    // z = pow(x, y);
    // z = sqrt(9);
    // z = abs(-3);
    // z = round(3.14);
    // z = ceil(3.14);
    z = floor(3.99);

    std::cout << z << std::endl;

    return 0;
}