#include <iostream>
/*
Práctica 3: Tres números al revés​.

Tu misión si decides aceptarla es recibir los 3 números que desactivan la bomba del destino final,
para desactivarla simplemente tienes que mostrar los 3 números recibidos en forma contraria a como
los recibiste.

Los numeros son: 3, 4, y 5 en este orden.
*/

using namespace std;

int main()
{
    // Aquí declaramos las tres variables donde vamos a colocar el varlo de los 3 números que proporcione el usuario.
    int primer_numero;
    int segundo_numero;
    int tercer_numero;

    // Indicamos al usuario que proporcione el primer número
    cout << "Escribe el primer número: ";
    cin >> primer_numero;

    // Indicamos al usuario que proporcione el segundo número
    cout << "Escribe el segundo número: ";
    cin >> segundo_numero;

    // Indicamos al usuario que proporcione el tercer número
    cout << "Escribe el tercer número: ";
    cin >> tercer_numero;

    // La salida la mostramos en orden inverso
    cout << tercer_numero << endl;
    cout << segundo_numero << endl;
    cout << primer_numero << endl;
    return 0;
}