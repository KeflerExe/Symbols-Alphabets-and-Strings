// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Joel Oscar Martín Gutiérrez
// Correo: alu0101473840@ull.es
// Fecha: 04/10/2022
// Archivo: cadenas.h
// Contiene la clase Cadenas encargada de crear objetos tipo cadena y de proporcionar métodos para los mismos.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "simbolos.h"

#ifndef CADENAS_H
#define CADENAS_H

// Clase Cadenas, encargada de crear y manejar los objetos tipo Cadenas
template<class T>
class Cadenas {  
 public:
  // Constructores
  Cadenas() : cadena_{} {}  
  Cadenas(const T& cadena) : cadena_{cadena} {}

  // Métodos de operación correspondientes a las 5 operaciones disponibles con cadenas.
  int LongitudDeCadena() const;
  void InvierteLaCadena();
  void ObtienePrefijosDeCadena(Cadenas<T>& cadena_auxiliar, const int posicion_cadena_original) const;
  void ObtieneSufijosDeCadena(Cadenas<T>& cadena_auxiliar, const int posicion_cadena_original) const;
  void ObtieneSubcadenas(Cadenas<T>& cadena_auxiliar) const;

  // Métodos para modificar el atributo cadena_
  void push_front(const T&);
  void push_back(const T&);
  void Borrar();
  void Ordenar();
  void BorraCadenasDuplicadas();

  // Sobrecarga de operadores
  std::string operator[](int posicion) const;
  friend std::ofstream& operator<< <>(std::ofstream& salida, const Cadenas<T>& cadena);
  friend std::ostream& operator<< <>(std::ostream& salida, const Cadenas<T>& cadena);
 private:
  std::vector<T> cadena_;
};

// Método encargado de introducir datos en el vector cadena_ en la parte frontal de este
template<class T>
void Cadenas<T>::push_front(const T& estructura_a_introducir) {
  cadena_.insert(cadena_.begin(), estructura_a_introducir);
}

// Método encargado de introducir datos en el vector cadena_ en la parte trasera del mismo
template<class T>
void Cadenas<T>::push_back(const T& estructura_a_introducir) {
  cadena_.push_back(estructura_a_introducir);
}

// Método encargado de dejar el vector cadena_ vacío
template<class T>
void Cadenas<T>::Borrar() {
  cadena_.clear();
}

// Método encargado de ordenar los datos del vector cadena_
template<class T>
void Cadenas<T>::Ordenar() {
  std::sort(cadena_.begin(), cadena_.end());
}

// Método encargado de borrar las cadenas duplicadas que pudiera haber en el vector cadena_
template<class T>
void Cadenas<T>::BorraCadenasDuplicadas() {
  cadena_.erase(std::unique(cadena_.begin(), cadena_.end()), cadena_.end());
}

// Método encargado de obtener la longitud de la cadena
template<class T>
int Cadenas<T>::LongitudDeCadena() const {
  return cadena_.size();
}

// Método encargado de invertir la cadena
template<class T>
void Cadenas<T>::InvierteLaCadena() {
  std::reverse(cadena_.begin(), cadena_.end());
}

// Método encargado de obtener los prefijos de la cadena
template<class T>
void Cadenas<T>::ObtienePrefijosDeCadena(Cadenas<T>& cadena_auxiliar, const int posicion_cadena_original) const {
  cadena_auxiliar.push_back(cadena_[posicion_cadena_original]);
}

// Método encargado de obtener los sufijos de la cadena
template<class T>
void Cadenas<T>::ObtieneSufijosDeCadena(Cadenas<T>& cadena_auxiliar, const int posicion_cadena_original) const {
  cadena_auxiliar.push_front(cadena_[posicion_cadena_original]);
}

// Método encargado de obtener las subcadenas de la cadena
template<class T>
void Cadenas<T>::ObtieneSubcadenas(Cadenas<T>& cadena_auxiliar) const {
  std::string string_auxiliar;
  for (int iterador1 = 0; iterador1 < LongitudDeCadena(); ++iterador1) {
    string_auxiliar.erase();
  	for (int iterador2 = iterador1; iterador2 < LongitudDeCadena(); ++iterador2) {
      string_auxiliar = string_auxiliar + cadena_[iterador2];
   		cadena_auxiliar.push_back(string_auxiliar);
    }
  }
}

// Sobrecarga del operador [] con el fin de poder acceder al vector cadena_ en una posición concreta
template<class T>
std::string Cadenas<T>::operator[](int posicion) const {
  return cadena_.at(posicion);
}

// Sobrecarga del operador << para escribir la cadena en el archivo de destino
template<class T>
std::ofstream& operator<<(std::ofstream& salida, const Cadenas<T>& cadena) {
  for (int iterador = 0; iterador < cadena.LongitudDeCadena(); ++iterador) {
    salida << cadena[iterador];
  }
	return salida; 
}

// Sobrecarga del operador << para imprimir la cadena por pantalla 
template<class T>
std::ostream& operator<<(std::ostream& salida, const Cadenas<T>& cadena) {
  for (int iterador = 0; iterador < cadena.LongitudDeCadena(); ++iterador) {
    salida << cadena[iterador];
  }
	return salida; 
}

void Usage(int argc, char *argv[]);

#endif