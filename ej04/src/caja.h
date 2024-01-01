/**
 * @file caja.h
 * @author Alexia Sánchez Cabrera (alu0101482323@ull.edu.es)
 *
 * @brief A continuación encontrará la definición parcial de la clase Box en
 *        C++, que representa una caja a través de su largo, fondo y alto.
 *        (2 pts)
 *
 * @version 0.1
 * @date 2023-06-09
 *
 * @copyright Copyright (c) 2023
 *
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

///< Function declarations
void AreEqual(Box&, Box&);

#endif