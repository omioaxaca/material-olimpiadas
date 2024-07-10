#include <iostream>

// Crear función iterativa para la búsqueda binaria
int busquedaBinaria(int arr[], int n, int x)
{

    // 1. definir nuestro limite inferior
    int izquierda = 0;
    // 2. definir nuestro limite superior
    int derecha = n - 1;

    while (izquierda <= derecha)
    {
        // 3. Identificar el indice que corresponde a la mitad (sacar la mitad)
        int mitad = izquierda + (derecha - izquierda) / 2;

        // 4. Comparar el valor que contiene el indice en la mitad
        if (arr[mitad] == x)
        {
            // 5. si es igual al elemento buscado: Ya terminamos
            return mitad;
        }

        // 6. Si no
        // 7. Si es menor que el elemento de la mitad entonces
        if (arr[mitad] > x)
        {
            // vamos a mover el limite superior
            derecha = mitad - 1;
        }
        else
        {
            // 8. De lo contrario: Si es mayor vamos a mover el limite inferior.
            izquierda = mitad + 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40, 44, 56, 63, 72, 87};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    int resultado = busquedaBinaria(arr, n, x);

    if (resultado != -1)
        std::cout << "Elemento encontrado en el índice " << resultado << std::endl;
    else
        std::cout << "Elemento no encontrado en el arreglo" << std::endl;

    return 0;
}
