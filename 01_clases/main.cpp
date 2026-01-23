/*
 * Instrucciones de Compilación:
 * 
 * Para compilar este programa, utiliza el siguiente comando:
 * 
 *     g++ libro.cpp main.cpp -o libro
 * 
 * O si prefieres usar la opción de estándar C++17:
 * 
 *     g++ -std=c++17 libro.cpp main.cpp -o libro
 * 
 * Para ejecutar el programa:
 * 
 *     ./libro
 */

#include <iostream>
#include "libro.h"

int main() {
    std::cout << "=== Ejemplo de uso de la clase Libro ===" << std::endl;
    std::cout << std::endl;

    // Crear un libro usando el constructor por defecto
    Libro libro1;
    std::cout << "Libro 1 (constructor por defecto):" << std::endl;
    libro1.mostrarNombre();
    libro1.mostrarCodigo();
    libro1.mostrarPrestado();
    std::cout << std::endl;

    // Actualizar los valores del libro1
    libro1.actualizarNombre("Cien años de soledad");
    libro1.actualizarCodigo("LIB-001");
    libro1.actualizarPrestado(true);
    
    std::cout << "Libro 1 después de actualizar:" << std::endl;
    libro1.mostrarNombre();
    libro1.mostrarCodigo();
    libro1.mostrarPrestado();
    std::cout << std::endl;

    // Crear un libro usando el constructor con parámetros
    Libro libro2("El Quijote", "LIB-002", false);
    std::cout << "Libro 2 (constructor con parámetros):" << std::endl;
    libro2.mostrarNombre();
    libro2.mostrarCodigo();
    libro2.mostrarPrestado();
    std::cout << std::endl;

    // Actualizar algunos valores del libro2
    libro2.actualizarPrestado(true);
    std::cout << "Libro 2 después de prestarlo:" << std::endl;
    libro2.mostrarNombre();
    libro2.mostrarCodigo();
    libro2.mostrarPrestado();
    std::cout << std::endl;

    // Ejemplo: cambiar el nombre del libro2
    libro2.actualizarNombre("Don Quijote de la Mancha");
    std::cout << "Libro 2 con nombre actualizado:" << std::endl;
    libro2.mostrarNombre();
    libro2.mostrarCodigo();
    libro2.mostrarPrestado();
    std::cout << std::endl;

    // Crear otro libro disponible
    Libro libro3("1984", "LIB-003", false);
    std::cout << "Libro 3:" << std::endl;
    libro3.mostrarNombre();
    libro3.mostrarCodigo();
    libro3.mostrarPrestado();

    return 0;
}
