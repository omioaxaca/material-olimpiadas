#include <iostream>
/*
Ejemplo para declarar arreglos.
*/

using namespace std;

int main()
{
    string cuidador[5] = {"Perro salchicha", "Pastor inglés", "Labrador", "Pitbull", "Ovejero"};

    // ¿Pero como puedo saber cuantos elementos tiene?
    int size_array = sizeof(cuidador) / sizeof(string);

    // Para ver cada elemento usaremos un ciclo while para que se encargue
    // de mostrar el valor de cada elemento
    int i = 0;
    while (i < size_array)
    {
        cout << cuidador[i] << endl;
        // Incrementamos el índice
        i++;
    }

    // Puedo hacer lo mismo pero ahora usando un for
    // Descomenta el codigo de abajo y comprueba que el resultado es el mismo

    // for (int k = 0; k < size_array; k++)
    // {
    //     cout << cuidador[k] << endl;
    // }

    return 0;
}