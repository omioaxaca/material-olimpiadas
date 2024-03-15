#include <iostream> // Librerias

using namespace std;

/*
Variables globales
int num;
*/

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cout << "Hola Mundo" << endl;
  cout << "Adios!" << endl;
  cout << "Hola Grupo C" << endl;

  int num; // Variable local

  cin >> num;

  cout << "El numero es: ";
  cout << num << endl;

  return 0;
}