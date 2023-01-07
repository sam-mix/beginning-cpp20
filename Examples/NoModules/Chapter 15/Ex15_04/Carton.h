#ifndef CARTON_H
#define CARTON_H
#include <algorithm>    // For std::max()
#include <string>
#include <string_view>
#include "Box.h"

class Carton : public Box
{
public:
  // Constructor explicitly calling the base constructor
  Carton(double l, double w, double h, std::string_view mat = "cardboard")
    : Box{l, w, h}, m_material{mat}
  {}

  // Function to calculate the volume of a Carton object
  double volume(int i = 50) const override
  {
    std::cout << "(Carton argument = " << i << ") ";
    return std::max((m_length - 0.5) * (m_width - 0.5) * (m_height - 0.5), 0.0);
  }

private:
  std::string m_material;
};

#endif
