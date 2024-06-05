#include <iostream>
#include <string>
#include <algorithm>

bool isValidCreditCard(const std::string& cardNumber) {
    int sum = 0;
    bool alternate = false;

    // Iterar sobre o número do cartão de trás para frente
    for (int i = cardNumber.length() - 1; i >= 0; i--) {
        int n = cardNumber[i] - '0';

        if (alternate) {
            n *= 2;
            if (n > 9) {
                n = (n % 10) + 1;
            }
        }

        sum += n;
        alternate = !alternate;
    }

    return (sum % 10 == 0);
}

int main() {
    std::string cardNumber;

    std::cout << "Enter credit card number: ";
    std::cin >> cardNumber;

    // Remover espaços em branco da entrada
    cardNumber.erase(std::remove(cardNumber.begin(), cardNumber.end(), ' '), cardNumber.end());

    if (isValidCreditCard(cardNumber)) {
        std::cout << "The credit card number is valid." << std::endl;
    } else {
        std::cout << "The credit card number is invalid." << std::endl;
    }

    return 0;
}

