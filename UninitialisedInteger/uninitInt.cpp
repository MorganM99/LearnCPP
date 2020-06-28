#include <iostream>

int main() {
  int x;          // Uninitialised-Beware
  std::cout << x; // What will we see? Fuck knows (Its 0)
  return 0;
}