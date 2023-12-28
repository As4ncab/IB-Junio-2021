/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @file switch_case.cc
 * @author S4yuM4ng0    (s4yum4ng0@random.com)
 * @date Jun 24 2021
 *
 * @brief Given a string, the program switches the case of its letters; non
 *        alphabetical characters remain unchanged.
 *
 * @bug No se ha detectado bugs
 *
 */

#include <cctype>
#include <iostream>
#include <string>

///< Constant variables
const std::string kHelpText{
    "Given a string, the program switches the case of its letters; non "
    "alphabetical characters remain unchanged.\n"};

///< Function declarations
///< Info/Error functions

/**
 * @brief Function that prints the purpose of the program
 *
 */
void PrintProgramPurpose(void) { std::cout << kHelpText << std::endl; }

/**
 * @brief Function that prints they correct way of using the program
 *
 * @param argc
 * @param argv
 */
void Usage(char** argv) {
  std::cout << argv[0] << " -- String computing program\nUsage: " << argv[0]
            << " [STRING]\n  STRING: String to switch the case of its letters"
            << std::endl;
}

/**
 * @brief Function that checks if the program receives a correct amount of
 *        parameters
 *
 * @param argc
 * @param argv
 * @param kCorrectParameters
 * @return true
 * @return false
 */
bool CheckCorrectParameters(const int argc, char** argv,
                            const int kCorrectParameters) {
  if (argc > 1 && std::string(argv[1]) == "--help") {
    Usage(argv);
    return 0;
  }
  if (argc != kCorrectParameters) {
    std::cout << argv[0] << " -- String computing program\nUsage: " << argv[0]
              << " [STRING]\nTry " << argv[0] << " --help for more information"
              << std::endl;
    return 0;
  }
  return 1;
}

///< Program functions

/**
 * @brief Function that switches the case of the letters on a string
 *
 * @param text
 * @return std::string
 */
std::string SwitchCase(const std::string& text) {
  std::string changed_text{""};
  for (auto& character : text) {
    if (isalpha(character)) {
      if (isupper(character))
        changed_text += tolower(character);
      else
        changed_text += toupper(character);
    } else {
      changed_text += character;
    }
  }
  return changed_text;
}

///< Client program
int main(int argc, char* argv[]) {
  ///< Verification of suficient amount of parameters in program call
  if (!CheckCorrectParameters(argc, argv, 2)) exit(EXIT_SUCCESS);
  PrintProgramPurpose();
  ///< Print the string with its case switched
  std::cout << SwitchCase(argv[1]) << std::endl;
  return 0;
}
