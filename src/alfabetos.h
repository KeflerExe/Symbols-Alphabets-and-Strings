// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Joel Oscar Martín Gutiérrez
// Correo: alu0101473840@ull.es
// Fecha: 04/10/2022
// Archivo: alfabetos.h
// Contiene la clase Alfabetos encargada de crear objetos tipo alfabeto y de proporcionar métodos para los mismos.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "simbolos.h"

#ifndef ALFABETOS_H
#define ALFABETOS_H

// Clase Alfabetos, encargada de crear y manejar los objetos tipo Cadenas
template<class T>
class Alfabetos {  
 public:
  // Constructores
  Alfabetos() : alfabetos_{} {}  
  Alfabetos(const T& alfabetos) : alfabetos_{alfabetos} {}

  // Métodos de operación para modificar el atributo alfabetos_ u obtener información de el
  void push_front(const T& simbolo);
  void Borrar();
  int TamanioVector() const;

  //Sobrecarga de operadores
  std::string operator[](int posicion) const;
 private:
  std::vector<T> alfabetos_;
};

// Método encargado de introducir datos en el vector alfabetos_ en la parte frontal de este
template<class T>
void Alfabetos<T>::push_front(const T& simbolo) {
  alfabetos_.insert(alfabetos_.begin(), simbolo);
}

// Método encargado de dejar el vector alfabetos_ vacío
template<class T>
void Alfabetos<T>::Borrar() {
  alfabetos_.clear();
}

// Método encargado de obtener el tamaño del vector alfabetos
template<class T>
int Alfabetos<T>::TamanioVector() const {
  return alfabetos_.size();
}

// Sobrecarga del operador [] con el fin de poder acceder al vector alfabetos_ en una posición concreta
template<class T>
std::string Alfabetos<T>::operator[](int posicion) const{
  return alfabetos_.at(posicion);
}

// Sobrecarga del operador << para imprimir el alfabeto por pantalla 
template<class T>
std::ostream& operator<<(std::ostream& salida, const Alfabetos<T>& alfabetos) {
  for (int iterador = 0; iterador < alfabetos.TamanioVector(); ++iterador) {
    salida << alfabetos[iterador] << " ";
  }
	return salida; 
}

void LectorDeDatos(const std::string linea_extraida, const std::string nombre_archivo_origen, Alfabetos<std::string>& alfabeto, Simbolos<std::string>& simbolo, Cadenas<std::string>& cadena);
int CompruebaElNumeroDeSimbolosEnCadena(const Cadenas<std::string> cadena, const Alfabetos<std::string> alfabeto);

#endif