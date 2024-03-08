#include <iostream>
/*
Práctica 2: Usar la entrada y salida estándar​.

1. Queremos mandar una salida a consola que pregunte al usuario:
   ¿Cuántos años tienes?
2. Después queremos mostrar la edad del usuario en consola.

*/

using namespace std;

int main()
{
    int edad;

    cout << "¿Cuántos años tienes?" << endl;
    cin >> edad;

    cout << "El usuario tiene " << edad << "años.";
    return 0;
}