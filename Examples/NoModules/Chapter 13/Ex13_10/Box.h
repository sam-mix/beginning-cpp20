#ifndef BOX_H
#define BOX_H

#include <ostream>

class Box {
 public:
  Box() = default;
  Box(double length, double width, double height)
      : m_length{length}, m_width{width}, m_height{height} {};

  double volume() const { return m_length * m_width * m_height; }

  int compare(const Box& box) const {
    if (volume() < box.volume()) return -1;
    if (volume() == box.volume()) return 0;
    return +1;
  }

  friend std::ostream& operator<<(std::ostream& out, const Box& box) {
    return out << "Box(" << box.m_length << ", " << box.m_width << ", "
               << box.m_height << ")";
  }

 private:
  double m_length{1.0};
  double m_width{1.0};
  double m_height{1.0};
};

#endif
