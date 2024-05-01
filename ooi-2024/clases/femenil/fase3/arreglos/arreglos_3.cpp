#include <iostream>
/*
Aqui voy a crear un arreglo del tamaño que el usuario me diga
Y después voy a asignar el valor que el usuario me diga en cada uno
de sus elementos.

En este caso mi arreglo es de enteros.
*/

using namespace std;

int main()
{
    int cantidad;

    cout << "¿Cuantos valores quieres poner?" << endl;
    cin >> cantidad;

    int calificaciones[cantidad];
    int posicion = 0;

    while (posicion < cantidad)
    {
        cout << "Pon un valor: " << endl;
        cin >> calificaciones[posicion];
        posicion = posicion + 1;
    }

    return 0;
}