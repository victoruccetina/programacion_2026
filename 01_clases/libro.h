#ifndef LIBRO_H
#define LIBRO_H

#include <string>

class Libro {
private:
    std::string nombre;
    std::string codigo;
    bool prestado;

public:
    // Constructor
    Libro();
    Libro(std::string nombre, std::string codigo, bool prestado);

    // Métodos para actualizar
    void actualizarNombre(std::string nuevoNombre);
    void actualizarCodigo(std::string nuevoCodigo);
    void actualizarPrestado(bool nuevoEstado);

    // Métodos para mostrar
    void mostrarNombre();
    void mostrarCodigo();
    void mostrarPrestado();

    // Getters (opcionales, pero útiles)
    std::string obtenerNombre();
    std::string obtenerCodigo();
    bool obtenerPrestado();
};

#endif // LIBRO_H
