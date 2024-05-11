#include <iostream>
#include <string>

using namespace std;

int main() {

    // Tipos de variables
    int entero = 10;
    float flotante = 3.14;
    string mi_cadena = "Hola, Grupo C!";
    char caracter = 'C';


    // Tipos de datos

    cout << "Tipo de dato entero: " << entero << endl;
    cout << "Tipo de dato flotante: " << flotante << endl;
    cout << "Tipo de dato cadena: " << mi_cadena << endl;
    cout << "Tipo de dato caracter: " << caracter << endl;


    // Ejemplo de double

    double numero_double = 5.678;
    cout << "Tipo de dato double: " << numero_double << endl;


    // Ejemplo de valor flotante
    float numero_flotante = 3.1465432;
    int numero_entero = numero_flotante;
    cout << "Numero entero: " << numero_entero << endl;


    // Ejemplo de void
    void *puntero_void;
    cout << "Tipo de dato void: " << puntero_void << endl;


    // Ejemplo de operadores aritméticos y tipos de variables

    int num1, num2;
    cout << "Ingresa un número entero: ";
    cin >> num1;

    cout << "Ingresa otro número entero: ";
    cin >> num2;

    int suma = num1 + num2;
    int resta = num1 - num2;
    int multiplicacion = num1 * num2;
    int division = num1 / num2;

    cout << "Suma: " << suma << endl;
    cout << "Resta: " << resta << endl;
    cout << "Multiplicación: " << multiplicacion << endl;
    cout << "División: " << division << endl;

    return 0;
}