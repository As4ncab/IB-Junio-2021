# Examen Junio 2021
**Lea detenidamente estas instrucciones:**
 * No escriba nada en las casillas de la parte superior de esta página.
 * El examen consta de 5 preguntas y el tiempo disponible es de 3 horas.
 * Realice cada ejercicio con bolígrafo en un FOLIO DISTINTO y entregue los ejercicios en orden.
 * Ponga nombre, apellidos y DNI en todos los folios que utilice.
 * Al finalizar el examen, ENTREGUE TODOS LOS FOLIOS que haya utilizado, incluyendo éste.
 * Al entregar el examen muestre algún documento que acredite su identidad.

## Preguntas Teóricas
### Ejercicio 01 - 2pts
**Describa qué es una dirección IP, cuál es su estructura y qué rol juega a la hora de comunicar dispositivos electrónicos dentro de una red.**

Una dirección IP es un identificador único de cada dispositivo conectado a una red (protocolo *TCP/IP*). Éstas pueden ser estáticas, es decir que no varía, o dinámicas, que son las que son otorgadas temporalmente. Existen dos tipos de direcciones IP:
 * ***IPv4*** (32 bits): La mayoría de dispositivos utilizan este tipo de dirección. Su espacio permite tener direcciones con cualquier combinación numérica comprendida dentro del rango 0.0.0.0 a 255.255.255.255 (ambos inclusive); sin embargo, algunas direcciones se encuentran reservadas para ciertas finalidades dentro de las redes *TCP/IP*.
 * ***IPv6*** (128 bits): Su espacio es bastante mayor que el de las direcciones IPv4, y debido a la gran demanda de direcciones IP, cada vez más dispositivos aceptan este tipo de dirección, Están divididas en dos partes:
   * ***Componente de Red***: Son los primeros 64 bits de la dirección y se emplean para enrutamiento.
   * ***Componente de Nodo***: Son los 64 bits restantes de la dirección y se emplean para identificar la dirección de la interfaz (deriva de la dirección física o MAC).
 
    A diferencia de las direcciones IPv4 que se representan en notación decimal, se representan en notación hexadecimal.

        2001:0DB8:AC10:FE01:0000:0000:0000:0000
        |__________________||__________________|
                 |                   |
           Comp. de Red        Comp. de Nodo 
             (64 bits)      (0s se pueden omitir)
                                 (64 bits)

### Ejercicio 02 - 2pts
**Describa detalladamente cuáles son y en qué consisten las distintas etapas de construcción de software (programa) en C++, desde los archivos de código fuente hasta obtener un archivo ejecutable. Ponga un ejemplo ilustrativo de cada una de estas etapas.**

La construcción de software en C++, se produce a través de un proceso en el cual se traduce el código (escrito en un lenguaje legible para el ser humano) a código-máquina (binario) de manera que se produzca un archivo ejecutable por el dispositivo. Este proceso consta de cuatro fases:
 * ***Preprocesado***: Se interpretan las llamadas directivas iniciadas por *#* (include, define, ifndef, pragma, ...); se sustituyen por el código correspondiente constenido en las librerías en el caso de *#include*. Se puede llamar al preprocesador de la siguinete manera:

      ```bash
      foo@bar:~$ cpp file.cc
      ```

 * ***Compilado***: Se convierte el código en C++ (*.cc) a código en lenguaje Assembly o ensamblador (*.s); este proceso es local para cada fichero por separado. En Linux, se pueden emplear dos compiladores, *Clang* y *GCC* (**G**NU **C**ompiler **C**ollection); g++ se encuentra dentro de éste último.

    El comando *g++* permite opciones de compilado y linkeado.

      ```bash
      foo@bar:~$ g++ [opciones] input_file
      ```
    
    Algunas opciones útiles de g++:
     * ***-o***: Proveer de un nombre al fichero de salida.
     * ***-std=c++17***: Interpretar el código según el estándar de C++17.
     * ***-g***: Mantener los símbolos de debugueado.
     * ***-O0***: No optimizar el proceso.
     * ***-O3***: Optimizar el proceso al máximo.

 * ***Ensamblado***: Se convierte el código en ensamblador (*.s) a código binario u objeto (*.o); este proceso también es local para cada fichero.

    Para producir el código en ensamblador:

      ```bash
      foo@bar:~$ g++ -m64 -masm=intel -S file.cc -o file.s
      ```

    Para producir el código objeto:

      ```bash
      foo@bar:~$ g++ -c file.cc -o file.o
      ```

 * ***Linkeado***: Se combinan todos los ficheros objeto (*.o) en un único fichero ejecutable. En este proceso se comprueba que todas las funciones estén correctamente implementadas.

    Para producir el ejecutable:

      ```bash
      foo@bar:~$ g++ -o program file.o
      foo@bar:~$ g++ -o program file.cc
      ```

![Compilation process image](compile.png "Compilation Process")

Una vez completadas estas cuatro fases, se puede ejecutar el programa directamente de la siguiente manera:

  ```bash
  foo@bar:~$ ./program [argumentos necesarios]
  ```

## Preguntas Prácticas
### Ejercicio 03 - 2pts
**Escriba un programa switch_case que modifique todas las letras de una cadena de forma que transforme todas las mayúsculas en minúsculas y viceversa. Los caracteres que no sean mayúsculas ni minúsculas no debieran verse modificados.**

  ```bash
  foo@bar:~$ ./switch_case Abecedario
  aBECEDARIO
  foo@bar:~$ ./switch_case PyThon
  pYtHON
  ```

***\*\*\*Los ficheros con el código fuente se encuentran añadidos al repositorio y el correo en los comentarios de cabecera es inventado (no intente contactarme a través de él)\*\*\****

Este programa se puede organizar de dos maneras:
1. En un único fichero:

    ***switch_case.cc***
    ```c++
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
    ```
  
2. En varios ficheros separando el programa cliente de la declaración de funciones:

    ***switch-case.h***
    ```c++
    /**
     * Universidad de La Laguna
     * Escuela Superior de Ingeniería y Tecnología
     * Grado de Ingeniería Informática
     * Informática Básica 2020-2021
     *
     * @file point-2d.h
     * @author S4yuM4ng0    (s4yum4ng0@random.com)
     * @date Jun 24 2021
     *
     * @brief Library with information functions declarations
     *
     * @bug There are no known bugs
     */

    #ifndef SWITCH_CASE_H
    #define SWITCH_CASE_H

    #include <cctype>
    #include <iostream>
    #include <string>

    ///< Function declarations
    std::string SwitchCase(const std::string&);

    #endif
    ```

    ***switch-case.cc***
    ```c++
    /**
     * Universidad de La Laguna
     * Escuela Superior de Ingeniería y Tecnología
     * Grado de Ingeniería Informática
     * Informática Básica 2020-2021
     *
     * @file switch-case.cc
     * @author S4yuM4ng0    (s4yum4ng0@random.com)
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
    ```

    ***switch-case_main.cc***
    ```c++
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
    ```

    Esta opción se puede compilar empleando un fichero CMakeLists.txt debido a que se emplean varios ficheros en el proceso de producción del ejecutable. Se deben seguir las siguientes instrucciones:
    ```bash
    foo@bar:~/project-dir$ mkdir build
    foo@bar:~/project-dir$ cd build/
    foo@bar:~/project-dir/build$ cmake ..
    -- The CXX compiler identification is GNU 9.4.0
    -- Check for working CXX compiler: /usr/bin/c++
    -- Check for working CXX compiler: /usr/bin/c++ -- works
    -- Detecting CXX compiler ABI info
    -- Detecting CXX compiler ABI info - done
    -- Detecting CXX compile features
    -- Detecting CXX compile features - done
    -- Configuring done
    -- Generating done
    -- Build files have been written to: /home/foo/project-dir/build
    foo@bar:~/project-dir/build$ make
    Scanning dependencies of target main
    [ 25%] Building CXX object CMakeFiles/main.dir/src/file1.cc.o
    [ 50%] Building CXX object CMakeFiles/main.dir/src/file2.cc.o
    [ 75%] Building CXX object CMakeFiles/main.dir/src/file_main.cc.o
    [100%] Linking CXX executable main
    [100%] Built target main
    ```

    Si se quisiera eliminar los ficheros generados por CMake, bastaría con eliminar el directorio build/ y todos sus subdirectorios:
    ```bash
    foo@bar:~/project-dir$ rm -rf build/
    ```

### Ejercicio 04 - 2pts
**A continuación encontrará la definición parcial de la clase Box en C++, que representa una caja a través de su largo, fondo y alto. Complete la clase con los constructores que considere oportunos y la sobrecarga de operadores ==, extracción a través *ostream* e inserción a través de istream. Finalmente, implemente una función principal donde se empleen los operadores sobrecargados.**

  ```c++
    class Box {
     public:
      int length() { return length_; }
      int breadth() { return breadth_; }
      int height() { return height_; }
     private:
      double length_;
      double breadth_;
      double height_;
    };
  ```

## Preguntas Tipo Test
### Ejercicio 05 - 2pts
**Responda Verdadero (V) o Falso (F) o elegir la/s respuesta/s correcta/s para cada una de las siguientes preguntas teniendo en cuenta las siguientes observaciones:**
 * **Por cada respuesta correcta se sumará 0.2 puntos.**
 * **Por cada respuesta incorrecta se restará 0.2 puntos.**
 * **Las preguntas sin responder se considerarán incorrectas.**
 * **La puntuación mínima de la pregunta es de 0 puntos.**

1. **El Gestor de Red es un componente habitual en un Sistema Operativo.**

2. **En la shell de Linux el directorio “home” del usuario se representa mediante el carácter /.**

3. **De acuerdo a la Guía de Estilo de código que se sigue en la asignatura, los identificadores de funciones ordinarias (no métodos de una clase) deben escribirse comenzando con letra minúscula y usando mayúscula para cada palabra.**

4. **En una relación de composición de objetos la parte (miembro) sólo puede pertenecer a un objeto (clase) a la vez.**

5. **El método emplace_back()de la clase std::vector se utiliza para eliminar el último elemento de unvector.**

6. **Al leer caracteres desde un flujo de entrada (cin) la lectura se detiene cuando se detecta un espacio en blanco o bien un retorno de carro (enter).**

7. **Una función declarada "friend" de una clase puede acceder para escritura los miembros de datos (atributos) de esa clase.**

8. **Los operadores unarios debieran sobrecargarse usando métodos de la clase.**

9. **El espacio de direcciones que permite IPv4 es mayor que el que utiliza IPv6.**

10. **El lenguaje SQL se utiliza para realizar operaciones CRUD en bases de datos no relacionales.**

