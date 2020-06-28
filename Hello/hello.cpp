#include <iostream>
#include <limits>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> msg {
      "Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

  for (const std::string& word : msg) {
    std::cout << word << " ";
  }
  std::cout << std::endl;
  std::cin.clear(); // reset any error flags
  std::cin.ignore (std::numeric_limits<std::streamsize>::max(),
                   '\n'); // ignore any characters in the input buffer until we
                          // find a newline
  return 0;
}