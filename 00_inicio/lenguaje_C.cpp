/**
 * Archivo de referencia con ejemplos de las principales instrucciones del lenguaje C
 * Este archivo contiene ejemplos prácticos para que los estudiantes repasen los conceptos básicos
 *
 * Compilar:
 * gcc lenguaje_C.cpp -o lenguaje_C
 * o
 * g++ lenguaje_C.cpp -o lenguaje_C
 *
 * Ejecutar:
 * ./lenguaje_C
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ============================================
// 1. VARIABLES Y TIPOS DE DATOS
// ============================================
void ejemplo_variables() {
    printf("\n=== 1. VARIABLES Y TIPOS DE DATOS ===\n");
    
    // Tipos básicos
    int entero = 42;
    float decimal = 3.14f;
    double decimal_doble = 2.71828;
    char letra = 'A';
    
    // Modificadores
    short entero_corto = 100;
    long entero_largo = 1000000L;
    unsigned int positivo = 255;
    
    printf("Entero: %d\n", entero);
    printf("Float: %.2f\n", decimal);
    printf("Double: %.5lf\n", decimal_doble);
    printf("Char: %c\n", letra);
    printf("Short: %hd\n", entero_corto);
    printf("Long: %ld\n", entero_largo);
    printf("Unsigned: %u\n", positivo);
}

// ============================================
// 2. ENTRADA Y SALIDA (I/O)
// ============================================
void ejemplo_entrada_salida() {
    printf("\n=== 2. ENTRADA Y SALIDA ===\n");
    
    int numero;
    char nombre[50];
    
    printf("Ingresa un número: ");
    scanf("%d", &numero);
    
    printf("Ingresa tu nombre: ");
    scanf("%s", nombre);
    
    printf("Número ingresado: %d\n", numero);
    printf("Nombre ingresado: %s\n", nombre);
}

// ============================================
// 3. OPERADORES
// ============================================
void ejemplo_operadores() {
    printf("\n=== 3. OPERADORES ===\n");
    
    int a = 10, b = 3;
    
    // Aritméticos
    printf("Suma: %d + %d = %d\n", a, b, a + b);
    printf("Resta: %d - %d = %d\n", a, b, a - b);
    printf("Multiplicación: %d * %d = %d\n", a, b, a * b);
    printf("División: %d / %d = %d\n", a, b, a / b);
    printf("Módulo: %d %% %d = %d\n", a, b, a % b);
    
    // Relacionales
    printf("%d > %d = %d\n", a, b, a > b);
    printf("%d < %d = %d\n", a, b, a < b);
    printf("%d == %d = %d\n", a, b, a == b);
    printf("%d != %d = %d\n", a, b, a != b);
    
    // Lógicos
    printf("AND: %d && %d = %d\n", 1, 0, 1 && 0);
    printf("OR: %d || %d = %d\n", 1, 0, 1 || 0);
    printf("NOT: !%d = %d\n", 1, !1);
    
    // De asignación
    int x = 5;
    x += 3;  // x = x + 3
    printf("x += 3 resulta en: %d\n", x);
    
    // Incremento y decremento
    int y = 5;
    printf("y = %d, y++ = %d, y ahora = %d\n", y, y++, y);
    int z = 5;
    printf("z = %d, ++z = %d, z ahora = %d\n", z, ++z, z);
}

// ============================================
// 4. ESTRUCTURAS CONDICIONALES
// ============================================
void ejemplo_condicionales() {
    printf("\n=== 4. ESTRUCTURAS CONDICIONALES ===\n");
    
    int edad = 18;
    
    // if - else if - else
    if (edad < 13) {
        printf("Eres un niño\n");
    } else if (edad < 18) {
        printf("Eres un adolescente\n");
    } else {
        printf("Eres un adulto\n");
    }
    
    // Operador ternario
    int mayor = (edad >= 18) ? 1 : 0;
    printf("¿Es mayor de edad? %d\n", mayor);
    
    // switch - case
    int opcion = 2;
    switch (opcion) {
        case 1:
            printf("Opción 1 seleccionada\n");
            break;
        case 2:
            printf("Opción 2 seleccionada\n");
            break;
        case 3:
            printf("Opción 3 seleccionada\n");
            break;
        default:
            printf("Opción no válida\n");
            break;
    }
}

// ============================================
// 5. BUCLES (LOOPS)
// ============================================
void ejemplo_bucles() {
    printf("\n=== 5. BUCLES ===\n");
    
    // for
    printf("Bucle for (1 a 5): ");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    // while
    printf("Bucle while (cuenta regresiva): ");
    int contador = 5;
    while (contador > 0) {
        printf("%d ", contador);
        contador--;
    }
    printf("\n");
    
    // do-while
    printf("Bucle do-while (al menos una vez): ");
    int num = 3;
    do {
        printf("%d ", num);
        num--;
    } while (num > 0);
    printf("\n");
    
    // break y continue
    printf("Bucle con break (se detiene en 3): ");
    for (int i = 1; i <= 5; i++) {
        if (i == 3) break;
        printf("%d ", i);
    }
    printf("\n");
    
    printf("Bucle con continue (omite el 3): ");
    for (int i = 1; i <= 5; i++) {
        if (i == 3) continue;
        printf("%d ", i);
    }
    printf("\n");
}

// ============================================
// 6. ARRAYS (ARREGLOS)
// ============================================
void ejemplo_arrays() {
    printf("\n=== 6. ARRAYS ===\n");
    
    // Array unidimensional
    int numeros[5] = {1, 2, 3, 4, 5};
    printf("Array de números: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    
    // Array bidimensional (matriz)
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    printf("Matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    // Array de caracteres (string)
    char palabra[] = "Hola";
    printf("String: %s (longitud: %lu)\n", palabra, strlen(palabra));
}

// ============================================
// 7. FUNCIONES
// ============================================
int suma(int a, int b) {
    return a + b;
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

void ejemplo_funciones() {
    printf("\n=== 7. FUNCIONES ===\n");
    
    int resultado = suma(5, 3);
    printf("suma(5, 3) = %d\n", resultado);
    
    int fact = factorial(5);
    printf("factorial(5) = %d\n", fact);
}

// ============================================
// 8. PUNTEROS
// ============================================
void ejemplo_punteros() {
    printf("\n=== 8. PUNTEROS ===\n");
    
    int valor = 42;
    int *ptr = &valor;
    
    printf("Valor de la variable: %d\n", valor);
    printf("Dirección de memoria: %p\n", (void*)&valor);
    printf("Valor del puntero (dirección): %p\n", (void*)ptr);
    printf("Valor apuntado por el puntero: %d\n", *ptr);
    
    // Modificar valor a través del puntero
    *ptr = 100;
    printf("Después de *ptr = 100, valor = %d\n", valor);
}

// ============================================
// 9. STRINGS (CADENAS DE CARACTERES)
// ============================================
void ejemplo_strings() {
    printf("\n=== 9. STRINGS ===\n");
    
    char str1[] = "Hola";
    char str2[] = "Mundo";
    char resultado[50];
    
    // Longitud
    printf("Longitud de '%s': %lu\n", str1, strlen(str1));
    
    // Copiar
    strcpy(resultado, str1);
    printf("strcpy: %s\n", resultado);
    
    // Concatenar
    strcat(resultado, " ");
    strcat(resultado, str2);
    printf("strcat: %s\n", resultado);
    
    // Comparar
    int cmp = strcmp(str1, str2);
    if (cmp < 0) {
        printf("'%s' es menor que '%s'\n", str1, str2);
    } else if (cmp > 0) {
        printf("'%s' es mayor que '%s'\n", str1, str2);
    } else {
        printf("'%s' es igual a '%s'\n", str1, str2);
    }
}

// ============================================
// 10. ESTRUCTURAS (STRUCT)
// ============================================
struct Persona {
    char nombre[50];
    int edad;
    float altura;
};

void ejemplo_estructuras() {
    printf("\n=== 10. ESTRUCTURAS ===\n");
    
    struct Persona p1;
    strcpy(p1.nombre, "Juan");
    p1.edad = 25;
    p1.altura = 1.75f;
    
    printf("Persona: %s, %d años, %.2f m\n", p1.nombre, p1.edad, p1.altura);
    
    // Array de estructuras
    struct Persona personas[2] = {
        {"Ana", 30, 1.65f},
        {"Luis", 28, 1.80f}
    };
    
    for (int i = 0; i < 2; i++) {
        printf("Persona %d: %s, %d años\n", i+1, personas[i].nombre, personas[i].edad);
    }
}

// ============================================
// 11. MEMORIA DINÁMICA
// ============================================
void ejemplo_memoria_dinamica() {
    printf("\n=== 11. MEMORIA DINÁMICA ===\n");
    
    // malloc - asignar memoria
    int *arr = (int*)malloc(5 * sizeof(int));
    
    if (arr != NULL) {
        // Inicializar array
        for (int i = 0; i < 5; i++) {
            arr[i] = (i + 1) * 10;
        }
        
        printf("Array dinámico: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        
        // free - liberar memoria
        free(arr);
        printf("Memoria liberada\n");
    }
}

// ============================================
// 12. MACROS Y DIRECTIVAS DEL PREPROCESADOR
// ============================================
#define PI 3.14159
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define CUADRADO(x) ((x) * (x))

void ejemplo_macros() {
    printf("\n=== 12. MACROS ===\n");
    
    printf("PI = %.5f\n", PI);
    printf("MAX(10, 20) = %d\n", MAX(10, 20));
    printf("CUADRADO(5) = %d\n", CUADRADO(5));
}

// ============================================
// 13. ENUMERACIONES
// ============================================
enum DiaSemana {
    LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO
};

void ejemplo_enums() {
    printf("\n=== 13. ENUMERACIONES ===\n");
    
    enum DiaSemana hoy = MARTES;
    printf("Hoy es el día número: %d\n", hoy);
    
    const char* nombres[] = {
        "Lunes", "Martes", "Miércoles", "Jueves",
        "Viernes", "Sábado", "Domingo"
    };
    printf("Nombre del día: %s\n", nombres[hoy]);
}

// ============================================
// FUNCIÓN PRINCIPAL
// ============================================
int main() {
    printf("=========================================");
    printf("\nEJEMPLOS DEL LENGUAJE C");
    printf("\n=========================================\n");
    
    // Comentar las funciones que no quieras ejecutar
    ejemplo_variables();
    // ejemplo_entrada_salida();  // Descomenta para probar entrada
    ejemplo_operadores();
    ejemplo_condicionales();
    ejemplo_bucles();
    ejemplo_arrays();
    ejemplo_funciones();
    ejemplo_punteros();
    ejemplo_strings();
    ejemplo_estructuras();
    ejemplo_memoria_dinamica();
    ejemplo_macros();
    ejemplo_enums();
    
    printf("\n=========================================");
    printf("\nFIN DE LOS EJEMPLOS");
    printf("\n=========================================\n");
    
    return 0;
}