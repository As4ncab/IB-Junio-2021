/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado de Ingeniería Informática
 * Informática Básica 2020-2021
 *
 * @file caja.cc
 * @author S4yuM4ng0    (s4yum4ng0@random.com)
 * @date Jun 24 2021
 *
 * @brief Library with class and function definitions
 *
 * @bug There are no known bugs
 */

#include "caja.h"

///< Constructores

/**
 * @brief Construct a new Box::Box object
 *
 * @param l
 * @param b
 * @param h
 */
Box::Box(const double& l, const double& b, const double& h) {
  length_ = l;
  breadth_ = b;
  height_ = h;
}

///< Setters

/**
 * @brief Gives value l to length_
 *
 * @param l
 */
void Box::SetLength(const double& l) { length_ = l; }

/**
 * @brief Gives value b to breadth_
 *
 * @param b
 */
void Box::SetBreadth(const double& b) { breadth_ = b; }

/**
 * @brief Gives value h to height_
 *
 * @param h
 */
void Box::SetHeight(const double& h) { height_ = h; }

///< Operator overloadings

/**
 * @brief Operator "==" overloading for comparing Box objects
 *
 * @param caja
 * @return true
 * @return false
 */
bool Box::operator==(const Box& caja) {
  if ((length_ == caja.length_) && (breadth_ == caja.breadth_) &&
      (height_ == caja.height_)) {
    return 1;
  }
  return 0;
}

/**
 * @brief Operator "<<" overloading for printing Box objects
 *
 * @param os
 * @param box
 * @return std::ostream&
 */
std::ostream& operator<<(std::ostream& os, Box& box) {
  os << "  Length:  " << std::fixed << std::setprecision(2) << box.length()
     << "\n  Breadth: " << std::fixed << std::setprecision(2) << box.breadth()
     << "\n  Height:  " << std::fixed << std::setprecision(2) << box.height();
  return os;
}

/**
 * @brief Operator ">>" overloading for initialising Box object with the data
 *        typed in by the user
 *
 * @param is
 * @param box
 * @return std::istream&
 */
std::istream& operator>>(std::istream& is, Box& box) {
  is >> box.length_ >> box.breadth_ >> box.height_;
  return is;
}
