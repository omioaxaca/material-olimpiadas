#include <iostream>
#include <vector>
#include <algorithm>
/*
Aqui vamos a ver la capacidad que tienen los vectores de cambiar su tamaño dinámicamente.
*/

using namespace std;

int main()
{
    // Declaramos el vector
    int equipos = 2;
    int puntosIniciales = 0;
    vector<int> puntos_x_equipos(equipos, puntosIniciales);

    cout << "El tamaño inicial de mi vector es: " << endl;
    // Usamos una nueva función que ya existe para saber
    // el tamaño del vector, la funcoin: size()
    cout << puntos_x_equipos.size() << endl;

    for (int i = 0; i < 5; i++)
    {
        // Aqui estamos agregando elementos al vector
        puntos_x_equipos.push_back(i);
    }

    cout << "El tamaño final de mi vector es: " << endl;
    cout << puntos_x_equipos.size() << endl;

    // Existen mas funciones que podemos usar con los vectores como:
    //  pop_back(), insert(), erase(), sort()
}