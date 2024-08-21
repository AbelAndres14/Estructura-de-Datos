#include <iostream>
#include <string>

using namespace std;

class Materia {
public:
    int Clave;
    string Nombre;
    string Profesor;
    string Libro;

    Materia(int c, string n, string p, string l)
        : Clave(c), Nombre(n), Profesor(p), Libro(l) {}

    void Imprime() {
        cout << "Clave: " << Clave << endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Profesor: " << Profesor << endl;
        cout << "Libro: " << Libro << endl;
    }

    void CambiarClave(int nuevaClave) {
        Clave = nuevaClave;
    }

    void CambiarProfesor(string nuevoProfesor) {
        Profesor = nuevoProfesor;
    }
};

int main() {
    int opc;
    int nuevaClave;
    string nuevoProfesor;

    Materia Programacion(1, "Programacion", "Felipe Perez", "C++");
    Materia BaseDatos(2, "Base de Datos", "Carmen Solis", "Principios de Base de Datos");

    do {
        cout << "\nMenu" << endl;
        cout << "1.- Cambiar Clave de Programacion" << endl;
        cout << "2.- Cambiar Nombre del Profesor de Base de Datos" << endl;
        cout << "3.- Imprimir Datos de la Base de Datos" << endl;
        cout << "4.- Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opc;

        switch (opc) {
        case 1:
            cout << "Clave actual de Programacion: " << Programacion.Clave << endl;
            cout << "Ingresa la nueva Clave: ";
            cin >> nuevaClave;
            Programacion.CambiarClave(nuevaClave);
            cout << "Clave actualizada: " << Programacion.Clave << endl;
            break;

        case 2:
            cout << "Nombre actual del Profesor de Base de Datos: " << BaseDatos.Profesor << endl;
            cout << "Ingresa el nuevo Nombre del Profesor: ";
            getline(cin, nuevoProfesor);
            BaseDatos.CambiarProfesor(nuevoProfesor);
            cout << "Profesor actualizado: " << BaseDatos.Profesor << endl;
            break;

        case 3:
            cout << "Datos de la Materia Base de Datos:" << endl;
            BaseDatos.Imprime();
            break;

        case 4:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opcion no válida, intenta de nuevo.\n";
            break;
        }
    } while (opc != 4);

    return 0;
}
