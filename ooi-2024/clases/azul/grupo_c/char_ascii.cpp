#include <iostream>

using namespace std;

int main() {

    // Tipo de variable
    char caracter = 'd';

    int asciiValueCaracter = int(caracter);

    cout << "El valor ASCII de " << caracter << " es " << asciiValueCaracter << endl;
    cout << "El valor hexadecimal de '" << caracter << "' es 0x" << hex << asciiValueCaracter << endl;


    return 0;
}