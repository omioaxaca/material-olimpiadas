#include <iostream>
/*
Ejemplo para declarar arreglos.
*/

using namespace std;

int main()
{
    // 1. Declarando el arreglo sin asignarle valores
    string cuidador[5];

    cout << "¿Que hay en mi arreglo?" << endl;
    cout << cuidador << endl;

    // 2. Asignando valores a una posición en particular usando una variable
    int perro_1 = 0;
    cuidador[perro_1] = "Perro salchicha";
    cuidador[perro_1] = "Perro salchicha 2";
    cout << cuidador[perro_1] << endl;

    // 3. Asignamos el resto de los valores usando el indice del elemento al que queremos asignar el valor
    cuidador[1] = "Pastor inglés";
    cout << cuidador[1] << endl;

    cuidador[2] = "Labrador";
    cout << cuidador[2] << endl;

    cuidador[3] = "Pitbull";
    cout << cuidador[3] << endl;

    cuidador[4] = "Ovejero";
    cout << cuidador[4] << endl;

    // Si trato de ver nuevamente ver que hay en mi arreglo
    //  ¿Porque sigo sin poder ver los valores?
    cout << "¿Que hay en mi arreglo ahora?" << endl;
    cout << cuidador << endl;

    return 0;
}