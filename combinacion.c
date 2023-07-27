/*
Combinaciones
Autor: Andrade Perez Judith Adilene
Materia: Redes de Computadoras
Profesor: Guillermo Alejandro Chavez Sanchez
ayuda:chart  dela combinacion y video youtube
Explicación del programa: 
Genera todas las combinaciones posibles de un vector binario de tamaño especificado por el usuario. El programa muestra el número total de combinaciones y luego imprime todas las combinaciones en una sola línea horizontal. También muestra el total de combinaciones en cada columna y el total de vectores 
generados este comienza mostrando un encabezado y luego solicita al usuario ingresar el tamaño del vector binario. Luego de validar que el tamaño sea un número entero positivo, se procede a calcular el número total de combinaciones, que es igual a 2 elevado al tamaño del vector. 
Se crea un vector con el tamaño especificado por el usuario y se inicializa con ceros en el  programa muestra todas las combinaciones posibles en una sola línea horizontal utilizando un bucle. Para generar cada combinación, se utiliza un algoritmo que incrementa los valores del vector de manera binaria, de manera que todos los posibles valores de 0 y 1 se combinan.
Después de mostrar todas las combinaciones, el programa muestra el total de combinaciones en cada columna. El número total de combinaciones en la columna i-esima es 2 elevado a la i por el número total de combinaciones. Finalmente, se muestra el total de los vectores generados, que es igual al número total de combinaciones.
Espero que esta explicación te ayude a comprender cómo funciona el programa.
*/

#include <stdio.h>
#include <stdlib.h>

// Función para imprimir un vector en la pantalla
int printv(int *v, int length) {
    printf("\nV:");
    for (int i = 0; i < length; i++) {
        printf("%d ", v[i]);
    }
    return 0; 
}

// Función para elevar un número entero a una potencia entera
int eleva(int base, int expo) {
    int result = 1;
    for (int i = 0; i < expo; i++) {
        result *= base;
    }
    return result;
}

int main() {
    // Mostrar encabezado del programa
    printf("|-----------------------------------------------------------|\n");
    printf("|          Combinaciones                                    |\n");
    printf("|-----------------------------------------------------------|\n");

    // Solicitar al usuario el tamaño del vector
    int tamanio_vector;
    printf("\n Ingrese el tamano del vector: ");
    scanf("%d", &tamanio_vector);

    // Verificar que el tamaño del vector sea un número entero positivo
    if (tamanio_vector <= 0) {
        printf("Error: El tamaño del vector debe ser un número entero positivo.\n");
        return 1; // Salir del programa con código de error 1
    }

    // Calcular el número total de combinaciones posibles para el vector
    int combinaciones = eleva(2, tamanio_vector);
    int vector[tamanio_vector];

    // Mostrar el número total de combinaciones
    printf("\nTotal de combinaciones (T): %d\n\n", combinaciones);

    // Inicializar el vector con ceros
    for (int i = 0; i < tamanio_vector; i++) {
        vector[i] = 0;
    }

    // Mostrar todas las combinaciones en una sola línea horizontal
    for (int p = 0; p < combinaciones; p++) {
        printv(vector, tamanio_vector);

        // Generar la siguiente combinación binaria
        int k = tamanio_vector - 1;
        while (k >= 0 && vector[k] == 1) {
            vector[k] = 0;
            k--;
        }
        if (k >= 0) {
            vector[k] = 1;
        }
    }

    printf("\n");

    // Mostramos el total de combinaciones en cada columna utilizando la variable "T"
    for (int i = 0; i < tamanio_vector; i++) {
        int total_columna = eleva(2, i);
        printf("T %d: %d ", i + 1, total_columna * combinaciones);
    }

    // Mostramos el total de los vectores generados
    printf("\n\nTotal de los vectores generados: %d\n", combinaciones);

    return 0; // Salir del programa con código de éxito (0)
}
