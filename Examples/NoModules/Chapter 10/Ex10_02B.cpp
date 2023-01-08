// Overloading function templates
#include <format>
#include <iostream>
#include <string>

template <typename T>
T larger(T a, T b);  // Function template prototype
template <typename T>
T* larger(T*, T*);
template <typename T>
const T* larger(const std::vector<T>& data);

int main() {
  int big_int{17011983}, small_int{10};
  std::cout <<

      big_int << ", " << small_int << ", " << larger(big_int, small_int)
            << std::endl;
  std::cout << big_int << ", " << small_int << ", "
            << *larger(&big_int, &small_int) << std::endl;

  std::vector<double> data = {-1.4, 7.3, -100.0, 54.1, 16.3};
  std::cout << "The largest value in data is " << *larger(data) << std::endl;

  std::vector<std::string> words = {"The", "higher", "the", "fewer"};
  std::cout << *larger(words) << std::endl;
}

// Template for functions to return the larger of two values
template <typename T>
T larger(T a, T b) {
  return a > b ? a : b;
}

template <typename T>
T* larger(T* a, T* b) {
  return *a > *b ? a : b;
}

template <typename T>
const T* larger(const std::vector<T>& data) {
  const T* result{};  // The largest of an empty vector is nullptr
  for (auto& value : data)
    if (!result || value > *result) result = &value;
  return result;
}