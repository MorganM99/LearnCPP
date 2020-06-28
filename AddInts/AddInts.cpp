#include "io.h"

int main() {
  int x {readNumber()};
  int y {readNumber()};

  int result {x + y};

  writeAnswer (result);

  return 0;
}