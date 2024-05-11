#include <iostream>
#include<string>

using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  // while - mientras cumpla condicion haz esto
  // for
  // Rafael

  //int contador = 1;
  //int resultado = 0;

  //Primeros ejemplos
  /*while (contador <= 10) {
    resultado = resultado + contador;
    contador++;
  }*/

  /*for (int i = 10; i > 0; i--) {
    cout << i << endl;
    resultado += i;
  }*/

  //cout << resultado << endl;

  //Segundo ejemplo string
  /*string name = "Alejandro";
  // [1, 2, 3, 4] = 10
  // [0, 1, 2, 3]

  for (int i = 0; i < name.size(); i++) {
    cout << name[i] << endl;
  }

  cout << name << endl;*/

  //Tercer ejemplo cadenas o array, n=4
  int numeros[4] = {7, 8, 9, 10};
  int resultado = 0;

  for (int i = 0; i < 4; i++) {
    resultado = resultado + numeros[i];
  }

  cout << resultado << endl;

  return 0;
}