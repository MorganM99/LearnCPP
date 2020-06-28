#include <iostream>

class Fruit {
private:
  std::string m_name;
  std::string m_colour;

public:
  Fruit (const std::string& name = "", const std::string& colour = "") :
      m_name {name}, m_colour {colour} {}
  const std::string& getName() const { return m_name; }
  const std::string& getColour() const { return m_colour; }
};

class Apple : public Fruit {
private:
  double m_fiber;

public:
  Apple (const std::string& name   = "",
         const std::string& colour = "",
         double fiber              = 0.0) :
      Fruit {name, colour}, m_fiber {fiber} {}
  double getFiber() const { return m_fiber; }

  friend std::ostream& operator<< (std::ostream& out, const Apple& apple);
};

std::ostream& operator<< (std::ostream& out, const Apple& apple) {
  out << "Apple(" << apple.getName() << ", " << apple.getColour() << ", "
      << apple.getFiber() << ")"
      << "\n";
  return out;
}

class Banana : public Fruit {
private:
public:
  Banana (const std::string& name = "", const std::string& colour = "") :
      Fruit {name, colour} {}
  friend std::ostream& operator<< (std::ostream& out, const Banana& banana);
};

std::ostream& operator<< (std::ostream& out, const Banana& banana) {
  out << "Banana(" << banana.getName() << ", " << banana.getColour() << ")"
      << "\n";
  return out;
}

int main() {
  const Apple a {"Red delicious", "red", 4.2};
  std::cout << a << '\n';

  const Banana b {"Cavendish", "yellow"};
  std::cout << b << '\n';

  return 0;
}