#include <iostream>
#include <limits>
#include <stdexcept>

class Fraction {
private:
  int m_numerator;
  int m_denominator;

public:
  Fraction (int numerator = 0, int denominator = 1) :
      m_numerator {numerator}, m_denominator {denominator} {
    if (m_denominator == 0) 
      throw std::runtime_error ("Invalid denominator");
    
    reduce();
  }

  static int gcd (int a, int b) {
    return (b == 0) ? (a > 0 ? a : -a) : gcd (b, a % b);
  }
  void reduce() {
    if (m_numerator != 0 && m_denominator != 0) {
      const int& gcd {Fraction::gcd (m_numerator, m_denominator)};
      m_numerator /= gcd;
      m_denominator /= gcd;
    }
  }

  friend Fraction operator* (const Fraction& f1, const Fraction& f2);
  friend Fraction operator* (const Fraction& f1, const int x);
  friend Fraction operator* (const int x, const Fraction& f1);
  friend std::ostream& operator<< (std::ostream& out, const Fraction& f1);
  friend std::istream& operator>> (std::istream& in, Fraction& f1);
};

Fraction operator* (const Fraction& f1, const Fraction& f2) {
  int numerator {f1.m_numerator * f2.m_numerator};
  int denominator {f1.m_denominator * f2.m_denominator};
  return Fraction {numerator, denominator};
}

Fraction operator* (const Fraction& f1, const int x) {
  int numerator {f1.m_numerator * x};
  return Fraction {numerator, f1.m_denominator};
}

Fraction operator* (const int x, Fraction& f1) {
  return Fraction {f1 * x};
}

std::ostream& operator<< (std::ostream& out, const Fraction& f1) {
  out << f1.m_numerator << "/" << f1.m_denominator;
  return out;
}

std::istream& operator>> (std::istream& in, Fraction& f1) {
  in >> f1.m_numerator;
  in.ignore (std::numeric_limits<std::streamsize>::max(), '/');
  in >> f1.m_denominator;
  f1.reduce();
  return in;
}

int main() {
  Fraction f1;
  std::cout << "Enter fraction 1: ";
  try {
    std::cin >> f1;
  } catch (std::exception& e) { std::cout << e.what() << "\n"; }

  Fraction f2;
  std::cout << "Enter fraction 2: ";
  try {
    std::cin >> f2;
  } catch (std::exception& e) { std::cout << e.what() << "\n"; }

  std::cout << f1 << " * " << f2 << " is " << f1 * f2
            << '\n'; // note: The result of f1 * f2 is an r-value

  return 0;
}