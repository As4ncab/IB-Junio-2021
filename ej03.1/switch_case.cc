/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @file switch_case.cc
 * @author Alexia Sánchez Cabrera  (alu0101482323@ull.edu.es)
 * @date Jun 24 2021
 *
 * @brief Escriba un programa switch_case que modifique todas las letras de una
 *        cadena de forma que transforme todas las mayúsculas en minúsculas y
 *        viceversa.
 *        Los caracteres que no sean mayúsculas ni minúsculas no debieran verse
 *        modificados.
 *
 * @bug No se ha detectado bugs
 *
 */

#include <cctype>
#include <iostream>
#include <string>

const std::string kErrorText{"Too few/many parameters in execution process.\n"};

/**
 * @brief Función que imprime el propósito del programa
 *
 */
void PrintProgramPurpose() {
  std::cout
      << "This program switches the case of all the letters of a string given "
         "by command line parameters; it ONLY changes the letters.\n"
      << std::endl;
}

/**
 * @brief Función que comprueba que se haya pasado el número necesario de
 *        parámetros por línea de comandos para la ejecución del programa
 *
 * @param argc
 * @param argv
 * @param kCorrectParameterNumber
 * @return true
 * @return false
 */
bool CheckCorrectParameters(const int argc, char* argv[],
                            const int kCorrectParameterNumber) {
  if (argc != kCorrectParameterNumber) {
    std::cout << kErrorText << std::endl;
    std::cout << "Try calling the program this way: \n    " << argv[0]
              << " [STRING]" << std::endl;

    return 0;
  }

  return 1;
}

/**
 * @brief Función que intercambia mayúsculas por minúsculas
 *
 * @param word
 * @return std::string
 */
std::string SwitchCase(const std::string& word) {
  std::string new_word{""};
  for (auto& character : word) {
    if (isalpha(character)) {
      if (isupper(character))
        new_word += tolower(character);
      else
        new_word += toupper(character);
    } else {
      new_word += character;
    }
  }
  return new_word;
}

int main(int argc, char* argv[]) {
  // Verificamos que hay la cantidad necesaria de parámetros; se imprime un
  // mensaje de error en caso contrario y termina el programa
  if (!CheckCorrectParameters(argc, argv, 2)) {
    exit(EXIT_SUCCESS);
  }
  PrintProgramPurpose();
  // Imprimimos el string con los cambios realizados
  std::cout << SwitchCase(argv[1]) << std::endl;
  return 0;
}