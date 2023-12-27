/**
 * @file caja.cc
 * @author Alexia Sánchez Cabrera (alu0101482323@ull.edu.es)
 *
 * @brief Complete la clase con los constructores que considere oportunos y la
 *        sobrecarga de operadores ==, extracción a través ostream e inserción a
 *        través de istream. (2 pts)
 *
 * @version 0.1
 * @date 2023-06-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "caja.h"

// Constructores
/**
 * @brief Construye un nuevo objeto Box
 *
 * @param l
 * @param b
 * @param h
 */
Box::Box(const double l, const double b, const double h) {
  length_ = l;
  breadth_ = b;
  height_ = h;
}

// Setters
/**
 * @brief Da el valor l a lenght_
 *
 * @param l
 */
void Box::SetLength(const double& l) { length_ = l; }

/**
 * @brief Da el valor b a breadth_
 *
 * @param b
 */
void Box::SetBreadth(const double& b) { breadth_ = b; }

/**
 * @brief Da el valor h a height_
 *
 * @param h
 */
void Box::SetHeight(const double& h) { height_ = h; }

// Sobrecarga de operadores
/**
 * @brief Compara dos objetos Box y devuelve 1 si son iguales, 0 si no lo son
 *
 * @param caja
 * @return true
 * @return false
 */
bool Box::operator==(const Box& caja) {
  if ((length_ == caja.length_) && (breadth_ == caja.breadth_) &&
      (height_ == caja.height_)) {
    return true;
  }

  return false;
}

/**
 * @brief Sobrecarga del operador de inserción (imprime por pantalla el objeto
 *        Box)
 *
 * @param os
 * @param Box
 * @return std::ostream&
 */
std::ostream& operator<<(std::ostream& os, Box& box) {
  os << "  Length:  " << std::fixed << std::setprecision(2) << box.length()
     << "\n  Breadth: " << std::fixed << std::setprecision(2) << box.breadth()
     << "\n  Height:  " << std::fixed << std::setprecision(2) << box.height();

  return os;
}

/**
 * @brief Sobrecarga del operador de extracción (obtiene los datos para los
 *        atributos length_, breadth_ y height_ respectivamente)
 *
 * @param is
 * @param Box
 * @return std::istream&
 */
std::istream& operator>>(std::istream& is, Box& box) {
  is >> box.length_ >> box.breadth_ >> box.height_;

  return is;
}

// Funciones
/**
 * @brief Función que imprime el propósito del programa
 *
 */
void PrintProgramPurpose() {
  std::cout << "This program changes the values of the dimensions of 3 boxes "
               "and prints them for the user to see.\n"
            << std::endl;
}

/**
 * @brief Indica si los dos objetos caja son iguales o no e imprime un mensaje
 *        por pantalla para notificar al usuario
 *
 * @param box_1
 * @param box_2
 */
void AreEqual(Box& box_1, Box& box_2) {
  if (box_1 == box_2) {
    std::cout << "The boxes are equal" << std::endl;

  } else {
    std::cout << "The boxes are different" << std::endl;
  }
}