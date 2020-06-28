#include <iostream>

template<class T> class Pair1 {
private:
  T m_first;
  T m_second;

public:
  Pair1 (const T& first, const T& second) :
      m_first (first), m_second (second) {}
  const T& first() const { return m_first; }
  const T& second() const { return m_second; }
};

template<class T, class S> class Pair {
private:
  T m_first;
  S m_second;

public:
  Pair (const T& first, const S& second) : m_first {first}, m_second {second} {}
  const T& first() const { return m_first; }
  const S& second() const { return m_second; }
};

template<class T> class StringValuePair : public Pair<std::string, T> {
public:
  StringValuePair (const std::string& str, const T& val) :
      Pair<std::string, T> (str, val) {}
};

int main() {
  StringValuePair<int> svp ("Hello", 5);
  std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

  return 0;
}