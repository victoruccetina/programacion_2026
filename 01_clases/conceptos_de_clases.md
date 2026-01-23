# Conceptos de Clases en C++

Este documento contiene las explicaciones necesarias para comprender y realizar el ejercicio de diseño e implementación de clases en C++.

---

## 1. ¿Qué es una Clase?

Una **clase** es un tipo de dato definido por el usuario que agrupa datos (atributos) y funciones (métodos) que operan sobre esos datos. Es el concepto fundamental de la Programación Orientada a Objetos (POO).

**Analogía**: Piensa en una clase como un molde o plantilla. Por ejemplo, la clase `Estudiante` es el molde, y cada estudiante específico (María, Juan, etc.) es un objeto creado a partir de ese molde.

```cpp
// La clase es el molde
class Estudiante {
    // Aquí van los atributos y métodos
};

// Los objetos son instancias de la clase
Estudiante estudiante1;  // Un objeto de tipo Estudiante
Estudiante estudiante2;  // Otro objeto de tipo Estudiante
```

---

## 2. Estructura Básica de una Clase

Una clase en C++ tiene la siguiente estructura general:

```cpp
class NombreClase {
private:
    // Atributos privados (solo accesibles desde dentro de la clase)
    
public:
    // Métodos públicos (accesibles desde fuera de la clase)
    // Constructores
    // Métodos de acceso (getters/setters)
    // Métodos de utilidad
};
```

### Componentes principales:

- **Atributos**: Variables que almacenan los datos del objeto
- **Métodos**: Funciones que definen el comportamiento del objeto
- **Modificadores de acceso**: `private` y `public` (también existe `protected`, pero no lo usaremos aquí)

---

## 3. Encapsulamiento: Private vs Public

El **encapsulamiento** es uno de los pilares de la POO. Consiste en ocultar los detalles internos de una clase y proporcionar una interfaz controlada para acceder a ellos.

### `private` (Privado)
- Los atributos y métodos privados **solo pueden ser accedidos desde dentro de la misma clase**
- Los atributos de una clase generalmente deben ser privados para proteger la integridad de los datos
- Ejemplo: Si `promedio` es privado, no puedes hacer `estudiante1.promedio = 15.0` desde fuera de la clase

### `public` (Público)
- Los atributos y métodos públicos **pueden ser accedidos desde cualquier parte del programa**
- Los métodos que queremos que otros usen deben ser públicos
- Ejemplo: `estudiante1.actualizarPromedio(9.5)` puede ser llamado desde `main()`

**Ejemplo práctico:**

```cpp
class Estudiante {
private:
    float promedio;  // Privado: no se puede acceder directamente
    
public:
    void actualizarPromedio(float nuevoPromedio) {  // Público: se puede llamar
        // Aquí podemos validar antes de actualizar
        if (nuevoPromedio >= 0.0 && nuevoPromedio <= 10.0) {
            promedio = nuevoPromedio;
        }
    }
    
    float obtenerPromedio() {  // Público: permite leer el valor
        return promedio;
    }
};
```

**¿Por qué usar encapsulamiento?**
- **Protección de datos**: Evita que se asignen valores inválidos directamente
- **Validación**: Permite verificar datos antes de almacenarlos
- **Mantenibilidad**: Facilita cambios internos sin afectar el código que usa la clase

---

## 4. Atributos de una Clase

Los **atributos** son variables que pertenecen a cada objeto de la clase. Cada objeto tiene su propia copia de los atributos.

### Tipos de datos comunes:

- `string`: Para texto (nombre, código)
- `int`: Para números enteros (edad)
- `float`: Para números decimales (promedio)
- `bool`: Para valores verdadero/falso (activo)

**Ejemplo:**

```cpp
class Estudiante {
private:
    std::string nombre;    // Nombre del estudiante
    std::string codigo;    // Código de identificación
    int edad;              // Edad en años
    float promedio;        // Promedio de calificaciones
    bool activo;          // ¿Está activo?
};
```

**Nota importante**: Usa `std::string` en lugar de `string` a menos que uses `using namespace std;` al inicio del archivo.

---

## 5. Constructores

Un **constructor** es un método especial que se ejecuta automáticamente cuando se crea un objeto. Su nombre es igual al de la clase y no tiene tipo de retorno.

### Constructor por defecto

Se llama cuando creas un objeto sin parámetros:

```cpp
Estudiante estudiante1;  // Llama al constructor por defecto
```

**Implementación:**

```cpp
// En el archivo .h (declaración)
Estudiante();

// En el archivo .cpp (implementación)
Estudiante::Estudiante() {
    nombre = "";
    codigo = "";
    edad = 0;
    promedio = 0.0;
    activo = false;
}
```

### Constructor con parámetros

Se llama cuando creas un objeto pasando valores iniciales:

```cpp
Estudiante estudiante2("Juan Pérez", "EST-001", 20, 8.5, true);
```

**Implementación:**

```cpp
// En el archivo .h (declaración)
Estudiante(string nombre, string codigo, int edad, float promedio, bool activo);

// En el archivo .cpp (implementación)
Estudiante::Estudiante(string nombre, string codigo, int edad, float promedio, bool activo) {
    this->nombre = nombre;
    this->codigo = codigo;
    this->edad = edad;
    this->promedio = promedio;
    this->activo = activo;
}
```

**¿Qué es `this->`?**

Cuando el nombre del parámetro es igual al nombre del atributo, usamos `this->` para distinguirlos:

```cpp
void Estudiante::actualizarEdad(int edad) {
    this->edad = edad;  // this->edad es el atributo, edad es el parámetro
}
```

`this` es un puntero al objeto actual. `this->atributo` accede al atributo del objeto.

---

## 6. Getters (Métodos para Obtener Valores)

Los **getters** son métodos públicos que permiten leer el valor de atributos privados. Suelen comenzar con "obtener" o "get".

**Patrón general:**

```cpp
TipoDato obtenerNombreAtributo() {
    return nombreAtributo;
}
```

**Ejemplos:**

```cpp
// En el archivo .h
string obtenerNombre();
int obtenerEdad();
float obtenerPromedio();

// En el archivo .cpp
string Estudiante::obtenerNombre() {
    return nombre;
}

int Estudiante::obtenerEdad() {
    return edad;
}

float Estudiante::obtenerPromedio() {
    return promedio;
}
```

**Uso:**

```cpp
Estudiante estudiante("María", "EST-001", 20, 9.0, true);
string nombre = estudiante.obtenerNombre();  // Obtiene "María"
int edad = estudiante.obtenerEdad();         // Obtiene 20
```

---

## 7. Setters (Métodos para Actualizar Valores)

Los **setters** son métodos públicos que permiten modificar el valor de atributos privados. Suelen comenzar con "actualizar" o "set".

**Patrón general:**

```cpp
void actualizarNombreAtributo(TipoDato nuevoValor) {
    nombreAtributo = nuevoValor;
}
```

**Ejemplos:**

```cpp
// En el archivo .h
void actualizarNombre(string nuevoNombre);
void actualizarEdad(int nuevaEdad);
void actualizarPromedio(float nuevoPromedio);

// En el archivo .cpp
void Estudiante::actualizarNombre(string nuevoNombre) {
    nombre = nuevoNombre;
}

void Estudiante::actualizarEdad(int nuevaEdad) {
    edad = nuevaEdad;
}

void Estudiante::actualizarPromedio(float nuevoPromedio) {
    promedio = nuevoPromedio;
}
```

**Uso:**

```cpp
Estudiante estudiante;
estudiante.actualizarNombre("Juan");
estudiante.actualizarEdad(22);
estudiante.actualizarPromedio(8.5);
```

---

## 8. Validación de Datos

Los setters son el lugar perfecto para **validar** que los datos sean correctos antes de almacenarlos.

**Ejemplo con validación:**

```cpp
void Estudiante::actualizarPromedio(float nuevoPromedio) {
    // Validar que el promedio esté en el rango válido
    if (nuevoPromedio >= 0.0 && nuevoPromedio <= 10.0) {
        promedio = nuevoPromedio;
    } else {
        std::cout << "Error: El promedio debe estar entre 0.0 y 10.0" << std::endl;
        // No actualizamos el valor si es inválido
    }
}
```

**Estructura de validación:**

```cpp
void Estudiante::actualizarPromedio(float nuevoPromedio) {
    if (/* condición válida */) {
        // Asignar el valor
        promedio = nuevoPromedio;
    } else {
        // Mostrar mensaje de error
        std::cout << "Error: [mensaje descriptivo]" << std::endl;
    }
}
```

---

## 9. Métodos de Visualización

Los métodos de visualización muestran información en la consola usando `std::cout`.

**Ejemplos básicos:**

```cpp
void Estudiante::mostrarNombre() {
    std::cout << "Nombre: " << nombre << std::endl;
}

void Estudiante::mostrarEdad() {
    std::cout << "Edad: " << edad << " años" << std::endl;
}

void Estudiante::mostrarPromedio() {
    std::cout << "Promedio: " << promedio << std::endl;
}

void Estudiante::mostrarActivo() {
    if (activo) {
        std::cout << "Estado: Activo" << std::endl;
    } else {
        std::cout << "Estado: Inactivo" << std::endl;
    }
}
```

**Método para mostrar toda la información:**

```cpp
void Estudiante::mostrarInformacionCompleta() {
    mostrarNombre();
    mostrarCodigo();
    mostrarEdad();
    mostrarPromedio();
    mostrarActivo();
}
```

**Nota**: `std::endl` inserta un salto de línea y limpia el buffer de salida.

---

## 10. Métodos de Utilidad

Los métodos de utilidad realizan operaciones específicas sobre los datos del objeto.

### Ejemplo 1: Incrementar edad

```cpp
void Estudiante::incrementarEdad() {
    edad = edad + 1;
    // O también: edad++;
}
```

### Ejemplo 2: Calcular estado académico

Este método usa estructuras condicionales (`if-else`) para determinar el estado basado en el promedio:

```cpp
void Estudiante::calcularEstadoAcademico() {
    if (promedio >= 9.0 && promedio <= 10.0) {
        std::cout << "Estado académico: Excelente" << std::endl;
    } else if (promedio >= 8.0 && promedio < 9.0) {
        std::cout << "Estado académico: Muy Bueno" << std::endl;
    } else if (promedio >= 7.0 && promedio < 8.0) {
        std::cout << "Estado académico: Bueno" << std::endl;
    } else if (promedio >= 6.0 && promedio < 7.0) {
        std::cout << "Estado académico: Regular" << std::endl;
    } else {
        std::cout << "Estado académico: Necesita Mejorar" << std::endl;
    }
}
```

**Estructura if-else if-else:**

```cpp
if (condición1) {
    // Código si condición1 es verdadera
} else if (condición2) {
    // Código si condición2 es verdadera
} else {
    // Código si ninguna condición es verdadera
}
```

---

## 11. Separación de Archivos: .h y .cpp

En C++, es una buena práctica separar la **declaración** (interfaz) de la **implementación** (código).

### Archivo de Cabecera (.h)

Contiene:
- La declaración de la clase
- Los atributos
- Las declaraciones de métodos (sin implementación)

```cpp
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

class Estudiante {
private:
    std::string nombre;
    int edad;
    // ... otros atributos

public:
    // Constructores
    Estudiante();
    Estudiante(string nombre, int edad, ...);
    
    // Métodos
    void actualizarNombre(string nuevoNombre);
    string obtenerNombre();
    // ... otros métodos
};

#endif // ESTUDIANTE_H
```

### Archivo de Implementación (.cpp)

Contiene:
- La implementación de todos los métodos declarados en el .h

```cpp
#include "estudiante.h"
#include <iostream>

// Implementación del constructor por defecto
Estudiante::Estudiante() {
    nombre = "";
    edad = 0;
    // ...
}

// Implementación de métodos
void Estudiante::actualizarNombre(string nuevoNombre) {
    nombre = nuevoNombre;
}

string Estudiante::obtenerNombre() {
    return nombre;
}

// ... implementación de otros métodos
```

**Nota importante**: En los métodos del archivo .cpp, debes usar el operador de resolución de ámbito `::`:

```cpp
void Estudiante::actualizarNombre(...) {  // Estudiante:: indica que es un método de la clase Estudiante
    // implementación
}
```

---

## 12. Directivas de Preprocesador

Las directivas de preprocesador son instrucciones que se procesan antes de compilar el código.

### Include Guards (#ifndef, #define, #endif)

Evitan que el contenido de un archivo de cabecera se incluya múltiples veces:

```cpp
#ifndef ESTUDIANTE_H    // Si ESTUDIANTE_H no está definido
#define ESTUDIANTE_H    // Define ESTUDIANTE_H

// Contenido de la clase

#endif // ESTUDIANTE_H  // Fin del bloque
```

**¿Por qué son necesarias?**

Sin include guards, si incluyes el mismo archivo .h dos veces, el compilador verá la clase declarada dos veces y dará error.

### #include

Incluye archivos de cabecera:

```cpp
#include <iostream>      // Librerías estándar: usan <>
#include <string>        // Librerías estándar: usan <>

#include "estudiante.h"  // Tus archivos: usan ""
```

**Diferencia:**
- `<archivo>`: Busca en las librerías estándar del sistema
- `"archivo"`: Busca primero en el directorio actual, luego en las librerías estándar

---

## 13. Estructura Completa de un Ejemplo

Aquí tienes un ejemplo completo y simplificado para entender la estructura:

### estudiante.h

```cpp
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

class Estudiante {
private:
    std::string nombre;
    int edad;

public:
    // Constructores
    Estudiante();
    Estudiante(std::string nombre, int edad);
    
    // Setters
    void actualizarNombre(std::string nuevoNombre);
    void actualizarEdad(int nuevaEdad);
    
    // Getters
    std::string obtenerNombre();
    int obtenerEdad();
    
    // Métodos de visualización
    void mostrarInformacion();
};

#endif // ESTUDIANTE_H
```

### estudiante.cpp

```cpp
#include "estudiante.h"
#include <iostream>

// Constructor por defecto
Estudiante::Estudiante() {
    nombre = "";
    edad = 0;
}

// Constructor con parámetros
Estudiante::Estudiante(std::string nombre, int edad) {
    this->nombre = nombre;
    this->edad = edad;
}

// Setter
void Estudiante::actualizarNombre(std::string nuevoNombre) {
    nombre = nuevoNombre;
}

void Estudiante::actualizarEdad(int nuevaEdad) {
    edad = nuevaEdad;
}

// Getter
std::string Estudiante::obtenerNombre() {
    return nombre;
}

int Estudiante::obtenerEdad() {
    return edad;
}

// Método de visualización
void Estudiante::mostrarInformacion() {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Edad: " << edad << " años" << std::endl;
}
```

### main.cpp

```cpp
#include <iostream>
#include "estudiante.h"

int main() {
    // Crear estudiante con constructor por defecto
    Estudiante estudiante1;
    estudiante1.mostrarInformacion();
    
    // Actualizar valores
    estudiante1.actualizarNombre("María");
    estudiante1.actualizarEdad(20);
    estudiante1.mostrarInformacion();
    
    // Crear estudiante con constructor con parámetros
    Estudiante estudiante2("Juan", 22);
    estudiante2.mostrarInformacion();
    
    return 0;
}
```

---

## 14. Compilación y Ejecución

Para compilar un programa con múltiples archivos:

```bash
g++ estudiante.cpp main_estudiante.cpp -o estudiante
```

**Explicación:**
- `g++`: El compilador de C++
- `estudiante.cpp main_estudiante.cpp`: Los archivos fuente a compilar
- `-o estudiante`: El nombre del ejecutable resultante

Para ejecutar:

```bash
./estudiante
```

---

## 15. Resumen de Conceptos Clave

1. **Clase**: Molde que define atributos y métodos
2. **Objeto**: Instancia específica de una clase
3. **Encapsulamiento**: Ocultar datos privados y exponer métodos públicos
4. **Constructor**: Método especial que inicializa el objeto
5. **Getter**: Método para leer atributos privados
6. **Setter**: Método para modificar atributos privados (con validación)
7. **Métodos de visualización**: Muestran información en consola
8. **Métodos de utilidad**: Realizan operaciones específicas
9. **Separación de archivos**: .h para declaración, .cpp para implementación
10. **Include guards**: Previenen inclusiones múltiples

---

## 16. Consejos para el Ejercicio

1. **Empieza por el archivo .h**: Define primero la estructura de la clase
2. **Implementa los constructores primero**: Son fundamentales para crear objetos
3. **Luego los getters y setters**: Son la base para acceder a los datos
4. **Después los métodos de visualización**: Son más simples
5. **Finalmente los métodos de utilidad**: Pueden usar los métodos anteriores
6. **Prueba cada método**: Crea objetos de prueba en `main()` y verifica que funcionen
7. **Usa nombres descriptivos**: `actualizarPromedio` es mejor que `setProm`
8. **Comenta tu código**: Ayuda a entender qué hace cada parte
9. **Valida siempre**: Especialmente en `actualizarPromedio()`
10. **Revisa la salida esperada**: Asegúrate de que los mensajes coincidan exactamente

---

## 17. Errores Comunes y Cómo Evitarlos

### Error 1: Olvidar el operador `::` en la implementación

```cpp
// ❌ Incorrecto
void actualizarNombre(string nuevoNombre) {
    nombre = nuevoNombre;
}

// ✅ Correcto
void Estudiante::actualizarNombre(string nuevoNombre) {
    nombre = nuevoNombre;
}
```

### Error 2: No usar `this->` cuando hay ambigüedad

```cpp
// ❌ Puede causar confusión
Estudiante::Estudiante(string nombre, int edad) {
    nombre = nombre;  // ¿Cuál es cuál?
}

// ✅ Correcto
Estudiante::Estudiante(string nombre, int edad) {
    this->nombre = nombre;  // this->nombre es el atributo
    this->edad = edad;
}
```

### Error 3: Olvidar los include guards

```cpp
// ❌ Sin include guards
#include <string>
class Estudiante { ... };

// ✅ Correcto
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string>
class Estudiante { ... };
#endif
```

### Error 4: No incluir el archivo .h en el .cpp

```cpp
// ❌ Falta el include
#include <iostream>
void Estudiante::actualizarNombre(...) { ... }

// ✅ Correcto
#include "estudiante.h"
#include <iostream>
void Estudiante::actualizarNombre(...) { ... }
```

---

## 18. Recursos Adicionales

- **std::string**: Tipo de dato para cadenas de texto
- **std::cout**: Para mostrar información en consola
- **std::endl**: Inserta salto de línea
- **Operadores de comparación**: `>=`, `<=`, `>`, `<`, `==`, `!=`
- **Operadores lógicos**: `&&` (y), `||` (o), `!` (no)
- **Estructuras condicionales**: `if`, `else if`, `else`

---

¡Con estos conceptos estás listo para realizar el ejercicio! Recuerda leer cuidadosamente las especificaciones y seguir el ejemplo proporcionado paso a paso. 🚀
