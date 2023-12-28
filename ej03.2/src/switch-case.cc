/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado de Ingeniería Informática
 * Informática Básica 2020-2021
 *
 * @file switch-case.cc
 * @author S4yuM4ng0    (s4yum4ng0@random.art.com)
 * @date Jun 24 2021
 *
 * @brief Library with information functions definitions
 *
 * @bug There are no known bugs
 */

#include "switch-case.h"

///< Function implementations
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
