// https://omegaup.com/course/ooi-2024-verde/assignment/p1/#problems/Suma-Manhattan

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

typedef long long int i64;

using namespace std;

const i64 mod = 1000000007;

pair<i64, i64> calculaSumasAcumulada(vector<int> puntos) {
  i64 sumaPositiva = 0;
  i64 sumaNegativa = 0;
  sort(puntos.begin(), puntos.end());
  for (int i = 0; i < puntos.size(); ++i) {
    const int puntoActual = puntos[i];
    int ocurrencias = 0;
    for (int j = 0; j < puntos.size() && puntoActual == puntos[j]; ++j) {
      ocurrencias++;
    }
    // Calcular la cantidad de puntos menores al punto actual.
    int menores = i; // No es necesario restar 1 porque esta indexado en 0.
    // Calcular la cantidad de puntos mayores.
    int mayores = puntos.size() - i - ocurrencias;

    sumaPositiva += ((i64)menores * (i64)ocurrencias * (i64)puntoActual) % mod;
    sumaNegativa += ((i64)mayores * (i64)ocurrencias * (i64)puntoActual) % mod;

    sumaPositiva = sumaPositiva % mod;
    sumaNegativa = sumaNegativa % mod;
  }
  return {sumaPositiva, sumaNegativa};
}

int main() {
  int cantidadNumeros;
  cin >> cantidadNumeros;
  vector<int> puntosP(cantidadNumeros);
  vector<int> puntosQ(cantidadNumeros);

  for (int i = 0; i < cantidadNumeros; ++i) {
    cin >> puntosP[i] >> puntosQ[i];
  }

  auto sumasP = calculaSumasAcumulada(puntosP);
  auto sumasQ = calculaSumasAcumulada(puntosQ);
  i64 sumaPositiva = (sumasP.first + sumasQ.first) % mod;
  i64 sumaNegativa = (sumasP.second + sumasQ.second) % mod;

  i64 sumaManhattan = (sumaPositiva - sumaNegativa) % mod;
  if (sumaManhattan < 0) {
    sumaManhattan += mod;
  }

  cout << sumaManhattan << "\n";

  return 0;
}
