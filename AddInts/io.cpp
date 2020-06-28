#include <iostream>

int readNumber() {
  std::cout << "Enter an integer:"
            << "\n";
  int x {};
  std::cin >> x;
  return x;
}

void writeAnswer (int x) {
  std::cout << "The answer is: " << x << "\n";
}