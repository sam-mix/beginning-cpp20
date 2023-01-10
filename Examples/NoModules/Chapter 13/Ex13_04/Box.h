#ifndef BOX_H
#define BOX_H

#include <compare>  // For std::partial_ordering (see Chapter 4)
#include <ostream>  // For std::ostream

class Box {
 public:
  // Constructors
  Box() = default;
  Box(double l, double w, double h) : m_length{l}, m_width{w}, m_height{h} {}

  double volume() const { return m_length * m_width * m_height; }

  // Accessors
  double getLength() const { return m_length; }
  double getWidth() const { return m_width; }
  double getHeight() const { return m_height; }

  std::partial_ordering operator<=>(const Box& otherBox) const {
    return volume() <=> otherBox.volume();
  }
  std::partial_ordering operator<=>(double otherVolume) const {
    return volume() <=> otherVolume;
  }

  bool operator==(const Box& otherBox) const = default;

 private:
  double m_length{1.0};
  double m_width{1.0};
  double m_height{1.0};
};

inline std::ostream& operator<<(std::ostream& stream, const Box& box) {
  stream << "Box(" << box.getLength() << ", " << box.getWidth() << ", "
         << box.getHeight() << ") ";
  return stream;
}

#endif
