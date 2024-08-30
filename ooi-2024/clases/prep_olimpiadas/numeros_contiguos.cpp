#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSumOfKContiguousNumbers(const vector<int> &numeros, int K)
{
    int N = numeros.size();

    // Asegurarse de que hay al menos K números
    if (N < K)
    {
        cerr << "La cadena debe tener al menos " << K << " números." << endl;
        return -1;
    }

    // Inicializar la suma con la suma de los primeros K elementos
    int maxSum = 0;

    // Quiero recorrer mi lista de 3 en 3 utilizando dos apuntadores (izquierda y derecha)
    int izquierda = 0;
    int derecha = K - 1;

    // Aqui pon tu solución para la parte que falta!!
    // recuerda queremos recorrer la lista de 3 en 3 numeros para sumar estos 3 números
    // Después vamos a quedanos con la suma más grande (hay que comparar cual resultado es mayor y tomer este valor)
    // cuando llegue al final de la lista regresa la suma más grande

    // Regresamos la suma mas grande
    return maxSum;
}

int main()
{
    // Inicializar del vector
    vector<int> numeros;
    numeros.push_back(4);
    numeros.push_back(1);
    numeros.push_back(3);
    numeros.push_back(5);
    numeros.push_back(2);

    int K = 3; // Asignar valor de K para encontrar la suma máxima de K números contiguos

    int resultado = maxSumOfKContiguousNumbers(numeros, K);

    if (resultado != -1)
    {
        cout << "La suma máxima de " << K << " números contiguos es: " << resultado << endl;
    }

    return 0;
}