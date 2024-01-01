/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado de Ingeniería Informática
 * Informática Básica 2020-2021
 *
 * @file switch-case_main.cc
 * @author S4yuM4ng0    (s4yum4ng0@random.com)
 * @date Jun 24 2021
 *
 * @brief Given the dimensions of a box, the program instantiates a "Caja"
 *        object and computes it.
 *
 * @bug There are no known bugs
 */

#include "caja.h"
#include "tools.h"

///< Client program
int main(int argc, char* argv[]) {
  ///< Verification of suficient amount of parameters in program call
  if (!CheckCorrectParameters(argc, argv, 4)) exit(EXIT_SUCCESS);
  ///< Initial values
  Box caja_1{std::stod(argv[1]), std::stod(argv[2]), std::stod(argv[3])};
  Box caja_2{1.1, 2.2, 3.3};
  Box caja_3;
  PrintProgramPurpose();
  std::cout << "Box 1:\n"
            << caja_1 << "\nBox 2:\n"
            << caja_2 << "\nBox 3:\n"
            << caja_3 << std::endl;
  ///< Values introduced by the user
  std::cout
      << "\nInroduce the dimensions of the third box (length -> breadth -> "
         "height): ";
  std::cin >> caja_3;
  std::cout << "Updated values:\nBox 1:\n"
            << caja_1 << "\nBox 2:\n"
            << caja_2 << "\nBox 3:\n"
            << caja_3 << std::endl;
  ///< Compairisons
  std::cout << "Box 1 = Box 2?" << std::endl;
  if (caja_1 == caja_2) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
  std::cout << "Box 1 = Box 3?" << std::endl;
  if (caja_1 == caja_3) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
  return 0;
}