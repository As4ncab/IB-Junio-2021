/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado de Ingeniería Informática
 * Informática Básica 2020-2021
 *
 * @file tools.h
 * @author S4yuM4ng0    (s4yum4ng0@random.com)
 * @date Jun 24 2021
 *
 * @brief Library with information functions declarations
 *
 * @bug There are no known bugs
 */

#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <string>

///< Constant variables
const std::string kHelpText{
    "Given the dimensions of a box, the program instantiates a 'Caja' object "
    "and computes it.\n"};

///< Info/Error functions
void PrintProgramPurpose(void);
void Usage(char**);
bool CheckCorrectParameters(const int, char**, const int);

#endif
