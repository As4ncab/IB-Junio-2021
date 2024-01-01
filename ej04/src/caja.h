/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado de Ingeniería Informática
 * Informática Básica 2020-2021
 *
 * @file caja.h
 * @author S4yuM4ng0    (s4yum4ng0@random.com)
 * @date Jun 24 2021
 *
 * @brief Library with class and function declarations
 *
 * @bug There are no known bugs
 */

#ifndef CAJA_H
#define CAJA_H

#include <iomanip>
#include <iostream>

///< Class declarations
class Box {
 public:
  ///< Constructors and Destructor
  Box() {}
  Box(const double&, const double&, const double&);
  ~Box() {}
  ///< Getters and Setters
  double length(void) const { return length_; }
  double breadth(void) const { return breadth_; }
  double height(void) const { return height_; }
  void SetLength(const double&);
  void SetBreadth(const double&);
  void SetHeight(const double&);
  ///< Operator overloadings
  bool operator==(const Box&);
  friend std::ostream& operator<<(std::ostream&, Box&);
  friend std::istream& operator>>(std::istream&, Box&);

 private:
  double length_{0.0};
  double breadth_{0.0};
  double height_{0.0};
};

#endif