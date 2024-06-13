#include <iostream>
using namespace std;

/*
Aqui queremos crear 10 libros
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
    // puedo asignarle valores

    struct libro libro2;
    // puedo asignarle valores

    libro libros[2];
    libros[0] = libro1;
    libros[1] = libro2;

    // 1. tener un for que se ejecute 10 veces
    for (int i = 0; i < 2; i++)
    {
        libros[i]
        // cout << i << endl;
    }

    // for (size_t i = 0; i < count; i++)
    // {
    //     struct libro libro1;
    //     cout << "Proporcione el titulo: " << endl;
    //     cin.getline(libro1.titulo, 45, '\n');

    //     cout << "Proporcione el autor: " << endl;
    //     cin >> libro1.autor;

    //     cout << "Proporcione la editoria: " << endl;
    //     cin >> libro1.editorial;

    //     cout << "Proporcione el año de la edicion: " << endl;
    //     cin >> libro1.edicion;
    // }

    // cout << "Mi primer libro es: " << endl;
    // cout << "Titulo: ";
    // cout << libro1.titulo << endl;

    // cout << "Autor: ";
    // cout << libro1.autor << endl;

    // cout << "Editorial: ";
    // cout << libro1.editorial << endl;

    // cout << "Año de la edicion: ";
    // cout << libro1.edicion << endl;

    return 0;
}