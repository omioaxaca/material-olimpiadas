#include <iostream>
using namespace std;

int main() {

    // Utilizando un bucle for para imprimir los números del 1 al 10

    for (int i = 1; i <= 10; i++) {
      cout << i << " ";
    }

    // Primer ejercicio

    int multiplicando = 5;

    for (int i = 1; i <= 20; i++) {
      cout << multiplicando << " x " << i << " = " << multiplicando * i << endl;
    }

    // Segundo ejercicio

    int i = 0;
    int segundoNumero;
    cin >> segundoNumero;

    while (i <= segundoNumero) {
      cout << i <<" ";
      i++;
    }

    // Tercer ejercicio

    int tercerNumero;
    cin >> tercerNumero;

    while (tercerNumero < 0) {
      cout << "Ingresa un numero positivo: ";
    }

    cout << "¡Gracias por ingresar un numero positivo!" << endl;

     do {
            cout << "Ingresa un numero positivo: ";
            cin >> tercerNumero;
        } while (tercerNumero <= 0);

        cout << "¡Gracias por ingresar un numero positivo!" << endl;

    return 0;
}
