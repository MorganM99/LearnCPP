#include <iostream>

int getValueFromUser() // This function returns ints
{
  std::cout << "Enter an integer: ";
  int input {};
  std::cin >> input;
  return input;
}

int doubleNumber (int x) {
  return x * 2;
}

int main() {
  int num {getValueFromUser()};
  std::cout << num << " doubled is " << doubleNumber (num) << "\n";
  return 0;
}