#include <iostream>
using namespace std;

/*
Ejemplo para crear una estructura par alos datos de un libro.
*/

struct libro
{
    char titulo[100];
    char autor[100];
    char editorial[100];
    int edicion;
    char anoPublicacion[20];
};

int main()
{
    struct libro libro1;

    cout << "Proporcione el titulo: " << endl;
    cin >> libro1.titulo;

    cout << "Proporcione el autor: " << endl;
    cin >> libro1.autor;

    cout << "Proporcione la editoria: " << endl;
    cin >> libro1.editorial;

    cout << "Proporcione el año de la edicion: " << endl;
    cin >> libro1.edicion;

    cout << "----- Mi primer libro es: " << endl;
    cout << "Titulo: ";
    cout << libro1.titulo << endl;

    cout << "Autor: ";
    cout << libro1.autor << endl;

    cout << "Editorial: ";
    cout << libro1.editorial << endl;

    cout << "Año de la edicion: ";
    cout << libro1.edicion << endl;

    return 0;
}