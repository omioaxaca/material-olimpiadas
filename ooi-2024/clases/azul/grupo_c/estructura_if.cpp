#include <iostream>
#include <string>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  /*
    n > m
    n < m
    n >= m
    n <= m
    n == m

    &&
    ||
  */


  //Definicion de variables para el programa
  int numero;
  int numero2;
  string operacion;
  int result = 0;

  //Lectura de entrada de datos
  cin >> operacion;
  cin >> numero;
  cin >> numero2;

  if (operacion == "suma") {
    result = numero + numero2;
  } else if (operacion == "multiplicacion") {
    result = numero * numero2;
  } else if (operacion == "division") {
    result = numero / numero2;
  } else {
    if (numero > numero2) {
      result = numero - numero2;
    } else {
      result = numero2 - numero;
    }
  }

  cout << result << endl;

  return 0;
}