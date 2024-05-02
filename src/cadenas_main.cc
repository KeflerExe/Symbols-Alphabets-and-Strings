// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Joel Oscar Martín Gutiérrez
// Correo: alu0101473840@ull.es
// Fecha: 04/10/2022
// Archivo: cadenas_main.cc
// Contiene la función main del proyecto que usa las clases Cadenas, Alfabeto y Simbolos 
// para realizar las diferentes operaciones requeridas por el usuario

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cassert>

#include "cadenas.h"
#include "alfabetos.h"

// Función main: encargada de crear los objetos de las clases y de llamar al resto de funciones y métodos necesarios para el funcionamiento del programa.
int main(int argc, char *argv[]) {
  Usage(argc, argv);
  std::string nombre_archivo_origen = argv[1];
  std::string nombre_archivo_destino = argv[2];
  int opcode = atoi(argv[3]);
  Alfabetos<std::string> alfabeto;
  Simbolos<std::string> simbolo;
  Cadenas<std::string> cadena;
  switch (opcode) {
    case 1: {
      std::ifstream archivo_origen;
      std::string linea_extraida;
      archivo_origen.open(nombre_archivo_origen);
      while (true) {
        getline(archivo_origen, linea_extraida); 
        LectorDeDatos(linea_extraida, nombre_archivo_origen, alfabeto, simbolo, cadena);
        int longitud_cadena = 0;
        longitud_cadena = cadena.LongitudDeCadena();
        std::ofstream archivo_destino;
        archivo_destino.open(nombre_archivo_destino, std::ios_base::app);
        archivo_destino << longitud_cadena << "\n";
        archivo_destino.close();
        alfabeto.Borrar();
        cadena.Borrar();
        if (archivo_origen.eof()) {
          break;
        }
      }
      archivo_origen.close();
      break;
    }
    case 2: {
      std::ifstream archivo_origen;
      std::string linea_extraida;
      archivo_origen.open(nombre_archivo_origen);
      while (true) {
        getline(archivo_origen, linea_extraida); 
        LectorDeDatos(linea_extraida, nombre_archivo_origen, alfabeto, simbolo, cadena);
        cadena.InvierteLaCadena();
        std::ofstream archivo_destino;
        archivo_destino.open(nombre_archivo_destino, std::ios_base::app);
        archivo_destino << cadena << "\n";
        archivo_destino.close();
        alfabeto.Borrar();
        cadena.Borrar();
        if (archivo_origen.eof()) {
          break;
        }
      }
      archivo_origen.close();      
      break;
    }
    case 3: {
      std::ifstream archivo_origen;
      std::string linea_extraida;
      archivo_origen.open(nombre_archivo_origen);
      while (true) {
        getline(archivo_origen, linea_extraida); 
        LectorDeDatos(linea_extraida, nombre_archivo_origen, alfabeto, simbolo, cadena);
        Cadenas<std::string> cadena_auxiliar;
        std::ofstream archivo_destino;
        archivo_destino.open(nombre_archivo_destino, std::ios_base::app);
        archivo_destino << "& ";
        for (int iterador = 0; iterador < cadena.LongitudDeCadena(); ++iterador) {
          cadena.ObtienePrefijosDeCadena(cadena_auxiliar, iterador);
          archivo_destino << cadena_auxiliar << " ";
        }
        archivo_destino << "\n";
        archivo_destino.close();
        alfabeto.Borrar();
        cadena.Borrar();
        cadena_auxiliar.Borrar();
        if (archivo_origen.eof()) {
          break;
        }
      }
      archivo_origen.close();
      break;
    }
    case 4: {
      std::ifstream archivo_origen;
      std::string linea_extraida;
      archivo_origen.open(nombre_archivo_origen);
      while (true) {
        getline(archivo_origen, linea_extraida); 
        LectorDeDatos(linea_extraida, nombre_archivo_origen, alfabeto, simbolo, cadena);
        Cadenas<std::string> cadena_auxiliar;
        std::ofstream archivo_destino;
        archivo_destino.open(nombre_archivo_destino, std::ios_base::app);
        archivo_destino << "& ";
        for (int iterador = cadena.LongitudDeCadena() - 1; iterador >= 0; --iterador) {
          cadena.ObtieneSufijosDeCadena(cadena_auxiliar, iterador);
          archivo_destino << cadena_auxiliar << " ";
        }
        archivo_destino << "\n";
        archivo_destino.close();
        alfabeto.Borrar();
        cadena.Borrar();
        cadena_auxiliar.Borrar();
        if (archivo_origen.eof()) {
          break;
        }
      }
      archivo_origen.close();
      break;
    }
    case 5: {
      std::ifstream archivo_origen;
      std::string linea_extraida;
      archivo_origen.open(nombre_archivo_origen);
      while (true) {
        getline(archivo_origen, linea_extraida); 
        LectorDeDatos(linea_extraida, nombre_archivo_origen, alfabeto, simbolo, cadena);
        Cadenas<std::string> cadena_auxiliar;
        std::ofstream archivo_destino;
        archivo_destino.open(nombre_archivo_destino, std::ios_base::app);
        archivo_destino << "& ";
        cadena.ObtieneSubcadenas(cadena_auxiliar);
        cadena_auxiliar.Ordenar();
        cadena_auxiliar.BorraCadenasDuplicadas();
        for (int iterador = 0; iterador < cadena_auxiliar.LongitudDeCadena(); ++iterador) {
          archivo_destino << cadena_auxiliar[iterador] << " ";
        }  
        archivo_destino << "\n";
        archivo_destino.close();
        alfabeto.Borrar();
        cadena.Borrar();
        cadena_auxiliar.Borrar();
        if (archivo_origen.eof()) {
          break;
        }
      }
      archivo_origen.close();
      break;
    }
    case 6: {
      std::ifstream archivo_origen;
      std::string linea_extraida;
      archivo_origen.open(nombre_archivo_origen);
      while (true) {
        getline(archivo_origen, linea_extraida); 
        LectorDeDatos(linea_extraida, nombre_archivo_origen, alfabeto, simbolo, cadena);
        Cadenas<std::string> cadena_auxiliar;
        std::ofstream archivo_destino;
        int numero_de_simbolos{0};
        numero_de_simbolos = CompruebaElNumeroDeSimbolosEnCadena(cadena, alfabeto);
        archivo_destino.open(nombre_archivo_destino, std::ios_base::app);
        archivo_destino << numero_de_simbolos << "/" << alfabeto.TamanioVector() << "\n";
        archivo_destino.close();
        alfabeto.Borrar();
        cadena.Borrar();
        cadena_auxiliar.Borrar();
        if (archivo_origen.eof()) {
          break;
        }
      }
      archivo_origen.close();
      break;
    }
    default: {
      std::cout << "Número de operación no válido, introduzca ./cadenas_main --help para más información." << std::endl;
      exit(EXIT_FAILURE);
    }
  }
}