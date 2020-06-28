#include <iostream>

int main() {
  std::cout << "Enter an integer: \n";
  int smaller {};
  std::cin >> smaller;

  std::cout << "Enter a larger integer: \n";
  int larger {};
  std::cin >> larger;

  if (smaller > larger) {
    std::cout << "Swapping the values \n";
    int swap {};
    swap    = smaller;
    smaller = larger;
    larger  = swap;
  } // Swap dies here

  std::cout << "The smaller value is: " << smaller << "\n";
  std::cout << "The larger value is: " << larger << "\n";

  return 0; // Larger and smaller die here
}