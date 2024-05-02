// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Joel Oscar Martín Gutiérrez
// Correo: alu0101473840@ull.es
// Fecha: 04/10/2022
// Archivo: cadenas.cc
// Contiene las diferentes funciones que son llamadas desde el main encargadas de realizar ciertas funciones como extraer datos, comprobar que cadena y alfabeto coincidan etc...

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "cadenas.h"
#include "alfabetos.h"

/*
 * La función ComprobacionCadenaYAlfabeto es la encargada de comprobar que no hay ningún símbolo en la cadena que no se encuentre en el alfabeto y 
 * de que no se repitan 2 símbolos en el alfabeto. En caso de que alguno de los dos casos se cumpla saltará un mensaje de error indicándolo y se detendrá el programa.
 */
void ComprobacionCadenaYAlfabeto(const Alfabetos<std::string>& alfabeto, const Cadenas<std::string>& cadena) {
  for (int iterador = 0; iterador < cadena.LongitudDeCadena(); ++iterador) {
    bool mismo_simbolo_encontrado = false;
    for (int iterador2 = 0; iterador2 < alfabeto.TamanioVector(); ++iterador2) {
      if(cadena[iterador] == alfabeto[iterador2]) {
        mismo_simbolo_encontrado = true;
        break;
      }
    }
    if(mismo_simbolo_encontrado == false) {
      std::cout << "Fallo crítico: la cadena \"" << cadena << "\" contiene caracteres no incluidos en el alfabeto \"" << alfabeto << "\"" << std::endl;
      exit(EXIT_FAILURE);
    }
  }
  for (int iterador = 0; iterador < alfabeto.TamanioVector(); ++iterador) {
    bool mismo_simbolo_encontrado = false;
    for (int iterador2 = 0; iterador2 < alfabeto.TamanioVector(); ++iterador2) {
      if(iterador != iterador2 && alfabeto[iterador] == alfabeto[iterador2]) {
        mismo_simbolo_encontrado = true;
        break;
      }
    }
    if(mismo_simbolo_encontrado == true) {
      std::cout << "Fallo crítico: el alfabeto \"" << alfabeto << "\" contiene caracteres repetidos" << std::endl;
      exit(EXIT_FAILURE);
    }
  }
}

// Esta función calcula cuantos simbolos del total de simbolos del alfabeto se encuentran en la cadena.
int CompruebaElNumeroDeSimbolosEnCadena(const Cadenas<std::string> cadena, const Alfabetos<std::string> alfabeto) {
  int numero_de_simbolos_totales{0};
  for (int iterador1 = 0; iterador1 < alfabeto.TamanioVector(); ++iterador1) {
    for (int iterador2 = 0; iterador2 < cadena.LongitudDeCadena(); ++iterador2) {
      if (alfabeto[iterador1] == cadena[iterador2]) {
        numero_de_simbolos_totales += 1;
        break;
      }
    }
  }
  return numero_de_simbolos_totales;
}

// Esta función recibe la línea extraída del fichero y su objetivo es extraer de dicha línea la cadena, alfabeto y símbolos encontrados en ella.
void LectorDeDatos(const std::string linea_extraida, const std::string nombre_archivo_origen, Alfabetos<std::string>& alfabeto, Simbolos<std::string>& simbolo, Cadenas<std::string>& cadena) {
  int iterador1 = linea_extraida.size() - 1;
  char simbolo_extraido;
  while (linea_extraida[iterador1] != ' ' && iterador1 >= 0) {
    simbolo_extraido = linea_extraida[iterador1];
    std::string simbolo_extraido_string(1, simbolo_extraido);
    simbolo.set_data(simbolo_extraido_string);
    cadena.push_front(simbolo.get_data());
    simbolo.Borrar(); 
    --iterador1; 
  }
  simbolo.Borrar();
  if (iterador1 != -1) {
    while (iterador1 > 0) {
      --iterador1;
      if (linea_extraida[iterador1] != ' ') {
        simbolo_extraido = linea_extraida[iterador1];
        std::string simbolo_extraido_string(1, simbolo_extraido);
        simbolo.set_data(simbolo_extraido_string);
      } else {
        alfabeto.push_front(simbolo.get_data());
        simbolo.Borrar();
      }
    }
    alfabeto.push_front(simbolo.get_data());
  } else {
    for (int iterador2 = cadena.LongitudDeCadena() - 1; iterador2 >= 0; --iterador2) {
      alfabeto.push_front(cadena[iterador2]);
    }
  }
  simbolo.Borrar();
  ComprobacionCadenaYAlfabeto(alfabeto, cadena);
}

/*
 * Comprueba que los argumentos introducidos por línea de comandos sean los 
 * correctos, además de proporcionar ayuda en caso de que el usuario no sepa como se han de introducir los argumentos.
 */
void Usage(int argc, char *argv[]) {
  if (argc != 4) {
    std::string parametro_introducido = argv[1];
    if (parametro_introducido == "--help") {
      std::cout << "--Cadenas" << std::endl;
      std::cout << "Modo de uso: ./cadenas_main fichero_entrada fichero_salida opcode" << std::endl;
      std::cout << "fichero_entrada: Fichero de texto de origen donde se encuentran los alfabetos y cadenas" << std::endl;
      std::cout << "fichero_salida:  Fichero de texto de destino donde se va a escribir el resultado de las operaciones" << std::endl;
      std::cout << "opcode:  operación a realizar con los datos extraidos de los ficheros" << std::endl;
      std::cout << "Pudiendo el opcode tomar los siguientes valores:" << std::endl;
      std::cout << "opcode = 1: calcular longitud de las cadenas introducidas." << std::endl;
      std::cout << "opcode = 2: calcular inversa de las cadenas introducidas." << std::endl;
      std::cout << "opcode = 3: calcular prefijos de las cadenas introducidas." << std::endl;
      std::cout << "opcode = 4: calcular sufijos de las cadenas introducidas." << std::endl;
      std::cout << "opcode = 5: calcular subcadenas de las cadenas introducidas." << std::endl;
      exit(EXIT_SUCCESS);
    } else {
      std::cout << "--Cadenas " << std::endl;
      std::cout << "Modo de uso: ./cadenas_main fichero_entrada fichero_salida opcode" << std::endl << "Pruebe ./cadenas_main --help para más información" << std::endl;
      exit(EXIT_FAILURE);
    }
  }   
}