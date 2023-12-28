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
 * @brief Given a string, the program switches the case of its letters; non
 *        alphabetical characters remain unchanged.
 *
 * @bug There are no known bugs
 */

#include "switch-case.h"
#include "tools.h"

///< Client program
int main(int argc, char* argv[]) {
  ///< Verification of suficient amount of parameters in program call
  if (!CheckCorrectParameters(argc, argv, 2)) exit(EXIT_SUCCESS);
  PrintProgramPurpose();
  ///< Print the string with its case switched
  std::cout << SwitchCase(argv[1]) << std::endl;
  return 0;
}
