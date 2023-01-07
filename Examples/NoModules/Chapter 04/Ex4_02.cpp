// Three-way comparison of integers
#include <compare>  // Required when using operator <=> (even for fundamental types)
#include <format>
#include <iostream>

int main()
{
  std::cout << "Please enter a number: ";

  int value;
  std::cin >> value;

  std::strong_ordering ordering{ value <=> 0 };

  std::cout << std::format("value < 0: {}\n", ordering == std::strong_ordering::less);
  std::cout << std::format("value > 0: {}\n", ordering == std::strong_ordering::greater);
  std::cout << std::format("value == 0: {}\n", ordering == std::strong_ordering::equal);
}
