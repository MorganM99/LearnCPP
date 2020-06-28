#include <iostream>
#include <string>

int main() {
  std::cout << "Enter your full name: \n";
  std::string fullName {};
  std::getline (std::cin, fullName);

  std::cout << "Enter your age: \n";
  int age {};
  std::cin >> age;

  double yearsPerLetter {(static_cast<double> (age) / fullName.length())};

  std::cout << "You've lived " << yearsPerLetter
            << " years for each letter in your name. \n";
  return 0;
}