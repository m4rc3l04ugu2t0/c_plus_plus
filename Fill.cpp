#include<iostream>
#include<algorithm>
int main() {
    std::string foods[100];

    std::fill(foods, foods + 100, "pizza");

    for (std::string food : foods) {
        std::cout << food << std::endl;
    }

    return 0;
}