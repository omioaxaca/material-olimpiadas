#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matriz;

struct Coordenada {
  int x, y;

  bool operator==(Coordenada rhs) {
    return x == rhs.x && y == rhs.y;
  }
};

struct Nodo {
  Coordenada p;
  int tiempo;

  // Sobrecargar el operador para que pueda usarse en la prioridad.
  bool operator<(const Nodo& rhs) const {
    return tiempo > rhs.tiempo;
  }
};

int encontrarSalida(Coordenada inicio, Coordenada fin, Matriz& mapa) {
  int numFilas = mapa.size();
  int numColumnas = mapa[0].size();

  // Matriz auxiliar para los visitados.
  Matriz visitados(numFilas, vector<int>(numColumnas, 0));

  priority_queue<Nodo> nodos;
  // Agregar el nodo inicial a la cola.
  nodos.push({inicio, 0});
  visitados[inicio.x][inicio.y] = 1;

  // Mientras aun haya estados por revisar
  while (!nodos.empty()) {
    Nodo actual = nodos.top();
    nodos.pop();

    // Verificar si ya llegue al fin.
    if (actual.p == fin) {
      return actual.tiempo;
    }

    // Revisar los estados posibles.
    vector<int> movX = {-1, 0, 1, 0};
    vector<int> movY = {0, -1, 0, 1};
    for (int i = 0; i < 4; ++i) {
      Coordenada punto = actual.p;
      punto.x += movX[i];
      punto.y += movY[i];

      // Revisar si es un estado valido.
      if (punto.x <= 0 || punto.x > numFilas ||
          punto.y <= 0 || punto.y > numColumnas) {
        // Esta fuera de la matriz.
        continue;
      }
      if (mapa[punto.x][punto.y] == -1) {
        // Es un bloque por el que no se puede pasar.
        continue;
      }
      if (visitados[punto.x][punto.y] == 1) {
        // Ya lo visitamos.
        continue;
      }
      // Sabemos que es un estado valido.
      Nodo siguiente = {punto, actual.tiempo};
      siguiente.tiempo++; // Dar un paso.
      siguiente.tiempo += mapa[punto.x][punto.y]; // tiempo que nos toma destruir el bloque.

      // Agregar a la cola
      nodos.push(siguiente);
      visitados[punto.x][punto.y] = 1;
    }
  }
  return -1;
}

int main() {
  int filas, columnas;
  cin >> filas >> columnas;
  Coordenada inicio;
  Coordenada fin;
  cin >> inicio.x >> inicio.y;
  cin >> fin.x >> fin.y;

  Matriz mapa(filas + 1, vector<int>(columnas + 1, 0)); // +1 porque indexado en 1.

  for (int i = 1; i <= filas; ++i) {
    for (int j = 1; j <= columnas; ++j) {
      char c;
      cin >> c;
      if (c == '#') {
        mapa[i][j] = -1;
      }
      if (c >= '0' && c <= '9') {
        mapa[i][j] = c - '0';
      }
    }
  }

  int tiempo = encontrarSalida(inicio, fin, mapa);
  cout << tiempo << "\n";


  return 0;
}