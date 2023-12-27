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

/**
 * @brief Declaración de la clase Box con atributos privados length (largo),
 *        breadth (ancho) y height (alto)
 *
 */
class Box {
 public:
  // Constructor por defecto
  Box() : length_{0.0}, breadth_{0.0}, height_{0.0} {}
  // Constructor de copia
  Box(const double, const double, const double);
  // Destructor
  ~Box() {}

  // Getters
  double length(void) const { return length_; }
  double breadth(void) const { return breadth_; }
  double height(void) const { return height_; }
  // Setters
  void SetLength(const double&);
  void SetBreadth(const double&);
  void SetHeight(const double&);

  // Sobrecarga de operadores de comparación
  bool operator==(const Box& box);
  friend std::ostream& operator<<(std::ostream&, Box&);
  friend std::istream& operator>>(std::istream&, Box&);

 private:
  double length_;
  double breadth_;
  double height_;
};

// Funciones
void PrintProgramPurpose(void);
void AreEqual(Box&, Box&);

#endif