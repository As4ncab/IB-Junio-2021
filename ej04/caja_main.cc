/**
 * @file caja_main.cc
 * @author Alexia Sánchez Cabrera (alu0101482323@ull.edu.es)
 *
 * @brief Finalmente, implemente una función principal donde se empleen los
 *        operadores sobrecargados. (2 pts)
 *
 * @version 0.1
 * @date 2023-06-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "caja.h"

int main() {
  // Valores iniciales de los constructores
  Box caja_1;
  Box caja_2{1.1, 2.2, 3.3};
  Box caja_3;

  PrintProgramPurpose();

  std::cout << "Box 1: \n" << caja_1 << std::endl;
  std::cout << "Box 2: \n" << caja_2 << std::endl;
  std::cout << "Box 3: \n" << caja_3 << std::endl;

  // Valores con cambios empleando setters
  caja_1.SetLength(caja_2.length());
  caja_1.SetBreadth(caja_2.breadth());
  caja_1.SetHeight(caja_2.height());

  std::cout << "\nBox 1: \n" << caja_1 << std::endl;
  std::cout << "Box 2: \n" << caja_2 << std::endl;
  std::cout << "Box 3: \n" << caja_3 << std::endl;

  // Valores con valores introducidos por el usuario
  std::cout << "\nInroduce the dimensions of the third box (length -> breadth -> "
               "height): ";
  std::cin >> caja_3;

  std::cout << "\nBox 1: \n" << caja_1 << std::endl;
  std::cout << "Box 2: \n" << caja_2 << std::endl;
  std::cout << "Box 3: \n" << caja_3 << std::endl;

  // Comparación con operador ==
  std::cout << "\nBox 1 = Box 2?" << std::endl;
  AreEqual(caja_1, caja_2);
  std::cout << "Box 1 = Box 3?" << std::endl;
  AreEqual(caja_1, caja_3);

  return 0;
}