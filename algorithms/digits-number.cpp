
#include <iostream>
using namespace std;

/*
 * DIGIT EXTRACTION
 *
 * Permite recorrer los digitos de un numero entero
 * de derecha a izquierda.
 *
 * Idea:
 *  - n % 10: obtiene el ultimo digito.
 *  - n /= 10: elimina el ultimo digito.
 *
 * Ejemplo:
 *  n = 1234
 *
 *  Iteracion 1: digit = 4, n = 123
 *  Iteracion 2: digit = 3, n = 12
 *  Iteracion 3: digit = 2, n = 1
 *  Iteracion 4: digit = 1, n = 0
 *
 * Complejidad:
 *  Tiempo:  O(log10(n)) para n > 0
 *  Espacio: O(1)
 *
 * Restriccion: n >= 0
 */

void processDigits(int n) {
    do {
        int digit = n % 10;

        // Procesar el digito.
        // Ej: sum += digit;
        // Ej: sum += digit * digit;
        // Ej: count[digit]++;

        n /= 10;

    } while (n > 0);
}


// O(log10(n)) - cantidad de dígitos
int countDigits(int n) {
    if (n == 0) return 1;

    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

// O(log10(n)) - suma de cuadrados de los dígitos
int sumSquareDigits(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}


int main() {
    int n = 12345;
    processDigits(n);

    return 0;
}