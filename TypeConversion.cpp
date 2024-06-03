#include<iostream>

int main() {
    int x = 10;
    std::cout << (char) 100 << std::endl;

    int correct = 8;
    int questions = 10;
    double score = correct/(double) questions * 100;

    std::cout << score << "%" << std::endl;

    return 0;
}