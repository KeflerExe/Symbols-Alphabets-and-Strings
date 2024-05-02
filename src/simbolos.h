// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Joel Oscar Martín Gutiérrez
// Correo: alu0101473840@ull.es
// Fecha: 04/10/2022
// Archivo: simbolos.h
// Contiene la clase Simbolos encargada de crear objetos tipo simbolo y de proporcionar métodos para los mismos.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#ifndef SIMBOLOS_H
#define SIMBOLOS_H

// Clase Simbolos, encargada de crear y manejar los objetos tipo Simbolos
template<class T>
class Simbolos {  
 public:
  // Constructores
  Simbolos() : simbolo_{} {}  
  Simbolos(const T& simbolo) : simbolo_{simbolo} {}
  
  // Getter y setter
  std::string get_data(void) const { return simbolo_; }
  void set_data(const T& data) { simbolo_ = data; }

  // Métodos para modificar el atributo simbolo_
  void Borrar();
 private:
  std::string simbolo_;
};

// Método encargado de dejar la string simbolo_ vacia
template<class T>
void Simbolos<T>::Borrar() {
  simbolo_.clear();
}

#endif