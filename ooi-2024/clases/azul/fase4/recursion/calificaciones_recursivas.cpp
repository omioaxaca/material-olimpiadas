// https://omegaup.com/arena/problem/Calificaciones-recursivas
#include <bits/stdc++.h>

using namespace std;

// Variables globales.
string cadena;
int pos = 0; // posicion dentro de la cadena.

// Funcion recursiva para calcular el promedio entre parentesis.
int promedio(int suma, int contador) {
  // Casos base
  if (pos >= cadena.length() || cadena[pos] == ')'){
    return suma / contador;
  }
  else if (cadena[pos] == '(') {
    pos++; // Incrementar la posicion al siguiente elemento antes de llamar a la funcion promedio.
    // Almacenar al resultado del subpromedio dentro de los parentesis.
    int subpromedio = promedio(0, 0);
    // La suma incrementa con base en el valor del subpromedio.
    suma += subpromedio;
    // Se incrementa el contador porque acabamos de incluir un nuevo elemento en la suma.
    contador++;
  }
  else {
    int valor = cadena[pos] - '0'; // Convertir el valor char en int
    // Incrementar la suma con el valor del numero actual y tambien el contador.
    suma += valor;
    contador++;
  }
  pos++; // Avanzar a la siguiente posicion antes de llamar a ls funcion de nuevo.
  // Volver a llamar a la funcion promedio, ahora con la nueva suma y contador.
  return promedio(suma, contador);
}

int main() {
  cin >> cadena;
  cout << promedio(0, 0);

  return 0;
}