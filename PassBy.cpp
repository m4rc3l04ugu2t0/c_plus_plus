#include <iostream>
#include <ostream>

void square(int &number) {
  number = number * number;
  std::cout << "in the function " << number << std::endl;
}
int main() {
  int number = 5;

  std::cout << "before the function " << number << std::endl;
  square(number);
  std::cout << "after the function "<< number << std::endl;
  
  return 0;
}
