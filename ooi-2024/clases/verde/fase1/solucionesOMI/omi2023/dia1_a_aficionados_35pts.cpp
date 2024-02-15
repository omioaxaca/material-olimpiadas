#include <bits/stdc++.h>

using namespace std;

const int MAX_VALOR = 1000;

// Regresa true si la cantidad de aficionados de un mismo equipo es mayor que la mitad del rango.
bool esInestable(int inicio, int fin, vector<int>& numeros) {
  vector<int> cubeta(MAX_VALOR + 1, 0); // +1 porque el valor maximo tambien se usa
  int mayorOcurrencia = 0;
  for (int i = inicio; i <= fin; ++i) {
    cubeta[numeros[i]]++;
    mayorOcurrencia = max(mayorOcurrencia, cubeta[numeros[i]]);
  }
  // cout << "inicio:" << inicio << " fin: " << fin << "\n";
  // cout << mayorOcurrencia << "\n";
  int cantidadElementos = fin - inicio + 1;
  if ((double)mayorOcurrencia > (double)cantidadElementos/2) {
    return true;
  }
  return false;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int cantidadNumeros = 0;
  cin >> cantidadNumeros;
  vector<int> numeros(cantidadNumeros + 1); // indexado en 1
  for(int i = 1; i <= cantidadNumeros; ++i) {
    cin >> numeros[i];
  }

  for (int i = 1; i <= cantidadNumeros; ++i) {
    for (int j = i + 1; j <= cantidadNumeros; j++) {
      if (esInestable(i, j, numeros)) {
        cout << i << " " << j << "\n";
        return 0;
      }
    }
  }
  cout << "-1\n";

  return 0;
}
