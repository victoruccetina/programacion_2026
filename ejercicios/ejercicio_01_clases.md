# Ejercicio: Diseño e Implementación de Clases en C++

## Objetivo
El objetivo de este ejercicio es que los estudiantes practiquen el diseño e implementación de clases en C++, aplicando conceptos como encapsulamiento, constructores, métodos getters/setters y métodos de utilidad.

---

## Problema: Sistema de Gestión de Estudiante

Deberás diseñar e implementar una clase `Estudiante` que permita gestionar información básica de un estudiante universitario. Esta clase será utilizada por un sistema de gestión académica.

---

## Especificaciones de la Clase `Estudiante`

### Atributos Privados
La clase debe tener los siguientes atributos privados:
- `nombre` (string): Nombre completo del estudiante
- `codigo` (string): Código de identificación único del estudiante
- `edad` (int): Edad del estudiante
- `promedio` (float): Promedio de calificaciones (rango 0.0 a 10.0)
- `activo` (bool): Indica si el estudiante está activo en el sistema

### Constructores
1. **Constructor por defecto**: Inicializa todos los atributos con valores por defecto:
   - `nombre`: cadena vacía ("")
   - `codigo`: cadena vacía ("")
   - `edad`: 0
   - `promedio`: 0.0
   - `activo`: false

2. **Constructor con parámetros**: Recibe los valores iniciales para todos los atributos:
   ```cpp
   Estudiante(string nombre, string codigo, int edad, float promedio, bool activo);
   ```

### Métodos Públicos

#### Setters (Métodos para actualizar)
- `void actualizarNombre(string nuevoNombre)`: Actualiza el nombre del estudiante
- `void actualizarCodigo(string nuevoCodigo)`: Actualiza el código del estudiante
- `void actualizarEdad(int nuevaEdad)`: Actualiza la edad del estudiante
- `void actualizarPromedio(float nuevoPromedio)`: Actualiza el promedio (debe validar que esté entre 0.0 y 10.0)
- `void actualizarActivo(bool nuevoEstado)`: Actualiza el estado activo del estudiante

#### Getters (Métodos para obtener valores)
- `string obtenerNombre()`: Retorna el nombre del estudiante
- `string obtenerCodigo()`: Retorna el código del estudiante
- `int obtenerEdad()`: Retorna la edad del estudiante
- `float obtenerPromedio()`: Retorna el promedio del estudiante
- `bool obtenerActivo()`: Retorna el estado activo del estudiante

#### Métodos de Visualización
- `void mostrarNombre()`: Muestra en consola: "Nombre: [nombre]"
- `void mostrarCodigo()`: Muestra en consola: "Código: [codigo]"
- `void mostrarEdad()`: Muestra en consola: "Edad: [edad] años"
- `void mostrarPromedio()`: Muestra en consola: "Promedio: [promedio]"
- `void mostrarActivo()`: Muestra en consola: "Estado: Activo" o "Estado: Inactivo"
- `void mostrarInformacionCompleta()`: Muestra toda la información del estudiante de forma organizada

#### Métodos de Utilidad
- `void incrementarEdad()`: Incrementa la edad del estudiante en 1 año
- `void calcularEstadoAcademico()`: Muestra el estado académico basado en el promedio:
  - 9.0 - 10.0: "Excelente"
  - 8.0 - 8.9: "Muy Bueno"
  - 7.0 - 7.9: "Bueno"
  - 6.0 - 6.9: "Regular"
  - 0.0 - 5.9: "Necesita Mejorar"

---

## Estructura de Archivos

Debes crear los siguientes archivos en la carpeta `ejercicio_01_clases`:

1. **estudiante.h**: Archivo de cabecera que contiene la declaración de la clase
2. **estudiante.cpp**: Archivo de implementación con las definiciones de los métodos
3. **main_estudiante.cpp**: Archivo principal con ejemplos de uso de la clase

### Directrices para los archivos:

#### estudiante.h
- Debe incluir las directivas de preprocesador para evitar inclusiones múltiples (`#ifndef`, `#define`, `#endif`)
- Debe incluir la librería `<string>` para el tipo `string`
- Debe contener solo la declaración de la clase (interface), no la implementación

#### estudiante.cpp
- Debe incluir `"estudiante.h"` y `<iostream>`
- Debe implementar todos los métodos declarados en el archivo de cabecera
- En el método `actualizarPromedio()`, debes validar que el promedio esté entre 0.0 y 10.0. Si no está en ese rango, mostrar un mensaje de error y no actualizar el valor.

#### main_estudiante.cpp
- Debe incluir `"estudiante.h"` y `<iostream>`
- Debe demostrar el uso de la clase con al menos los siguientes casos:
  1. Crear un estudiante usando el constructor por defecto
  2. Actualizar todos sus atributos
  3. Mostrar su información completa
  4. Crear otro estudiante usando el constructor con parámetros
  5. Mostrar su información completa
  6. Llamar al método `incrementarEdad()` y mostrar la nueva edad
  7. Llamar al método `calcularEstadoAcademico()` para mostrar el estado académico
  8. Intentar actualizar el promedio con un valor inválido (por ejemplo, 15.0) para probar la validación

---

## Ejemplo de Uso Esperado

```cpp
#include <iostream>
#include "estudiante.h"

int main() {
    std::cout << "=== Sistema de Gestión de Estudiante ===" << std::endl;
    std::cout << std::endl;

    // Crear estudiante con constructor por defecto
    Estudiante estudiante1;
    std::cout << "Estudiante 1 (constructor por defecto):" << std::endl;
    estudiante1.mostrarInformacionCompleta();
    std::cout << std::endl;

    // Actualizar información del estudiante1
    estudiante1.actualizarNombre("María García López");
    estudiante1.actualizarCodigo("EST-2024-001");
    estudiante1.actualizarEdad(20);
    estudiante1.actualizarPromedio(9.2);
    estudiante1.actualizarActivo(true);

    std::cout << "Estudiante 1 después de actualizar:" << std::endl;
    estudiante1.mostrarInformacionCompleta();
    estudiante1.calcularEstadoAcademico();
    std::cout << std::endl;

    // Crear estudiante con constructor con parámetros
    Estudiante estudiante2("Juan Pérez Martínez", "EST-2024-002", 22, 7.5, true);
    std::cout << "Estudiante 2 (constructor con parámetros):" << std::endl;
    estudiante2.mostrarInformacionCompleta();
    estudiante2.calcularEstadoAcademico();
    std::cout << std::endl;

    // Incrementar edad
    std::cout << "Incrementando edad del estudiante 2:" << std::endl;
    estudiante2.incrementarEdad();
    estudiante2.mostrarEdad();
    std::cout << std::endl;

    // Probar validación de promedio
    std::cout << "Intentando actualizar promedio con valor inválido:" << std::endl;
    estudiante2.actualizarPromedio(15.0);
    estudiante2.mostrarPromedio();
    std::cout << std::endl;

    return 0;
}
```

### Salida Esperada:
```
=== Sistema de Gestión de Estudiante ===

Estudiante 1 (constructor por defecto):
Nombre: 
Código: 
Edad: 0 años
Promedio: 0.0
Estado: Inactivo

Estudiante 1 después de actualizar:
Nombre: María García López
Código: EST-2024-001
Edad: 20 años
Promedio: 9.2
Estado: Activo
Estado académico: Excelente

Estudiante 2 (constructor con parámetros):
Nombre: Juan Pérez Martínez
Código: EST-2024-002
Edad: 22 años
Promedio: 7.5
Estado: Activo
Estado académico: Bueno

Incrementando edad del estudiante 2:
Edad: 23 años

Intentando actualizar promedio con valor inválido:
Error: El promedio debe estar entre 0.0 y 10.0
Promedio: 7.5
```

---

## Criterios de Evaluación

1. **Estructura de la Clase** (20 puntos)
   - Correcta declaración de atributos privados
   - Uso adecuado de constructores
   - Organización clara del código

2. **Implementación de Métodos** (40 puntos)
   - Correcta implementación de constructores
   - Correcta implementación de setters y getters
   - Implementación de métodos de visualización
   - Implementación de métodos de utilidad

3. **Validación** (15 puntos)
   - Validación correcta del rango del promedio en `actualizarPromedio()`

4. **Encapsulamiento** (15 puntos)
   - Atributos declarados como privados
   - Acceso controlado mediante métodos públicos

5. **Organización del Código** (10 puntos)
   - Separación correcta entre archivo de cabecera (.h) e implementación (.cpp)
   - Uso correcto de directivas de preprocesador
   - Código bien comentado y legible

---

## Instrucciones de Compilación

Para compilar el programa, utiliza los siguientes comandos:

```bash
g++ estudiante.cpp main_estudiante.cpp -o estudiante
```

O si prefieres usar la opción de estándar C++17:

```bash
g++ -std=c++17 estudiante.cpp main_estudiante.cpp -o estudiante
```

Para ejecutar el programa:

```bash
./estudiante
```

---

## Notas Importantes

- Asegúrate de validar el rango del promedio en el método `actualizarPromedio()`
- Recuerda usar `this->` cuando sea necesario para evitar ambigüedades entre parámetros y atributos
- Los mensajes de salida deben ser claros y descriptivos
- Mantén un estilo de código consistente a lo largo de todo el proyecto

---

¡Buena suerte con el ejercicio! 🚀