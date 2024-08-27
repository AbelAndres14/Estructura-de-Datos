#include <iostream>
#include <string>

using namespace std;

class Materia {
private:
    string clave;
    string nombre;
    string maestro;

public:
    Materia(string c = "", string n = "", string m = "") : clave(c), nombre(n), maestro(m) {}

    // Sobrecarga de operadores
    bool operator==(const Materia& nuevo) const {
        return clave == nuevo.clave && nombre == nuevo.nombre && maestro == nuevo.maestro;
    }

    bool operator!=(const Materia& nuevo) const {
        return !(*this == nuevo);
    }

    bool operator<(const Materia& nuevo) const {
        return clave < nuevo.clave;
    }

    bool operator>(const Materia& nuevo) const {
        return clave > nuevo.clave;
    }

    Materia operator+(const Materia& nuevo) const {
        return Materia(clave + nuevo.clave, nombre + " & " + nuevo.nombre, maestro + " & " + nuevo.maestro);
    }

    friend istream& operator>>(istream& in, Materia& m) {
        cout << "Ingrese clave: ";
        in >> m.clave;
        cout << "Ingrese nombre: ";
        in.ignore();
        getline(in, m.nombre);
        cout << "Ingrese maestro: ";
        getline(in, m.maestro);
        return in;
    }

    friend ostream& operator<<(ostream& o, const Materia& m) {
        o << "Clave: " << m.clave;
        o<< "\nNombre: " << m.nombre;
        o << "\nMaestro: " << m.maestro << endl;
        return o;
    }

    void cambiarClave(const string& nuevaClave) {
        clave = nuevaClave;
    }

    void cambiarMaestro(const string& nuevoMaestro) {
        maestro = nuevoMaestro;
    }
};

int main() {
    Materia Programacion("1", "Programacion", "Juan Hernandez");
    Materia BasesDatos("2", "Bases de Datos", "Carmen Segoviano");

    int opcion;
    do {
        cout << "\n\tMenu:\n\n";
        cout << "1. Cambiar la clave de Programacion\n";
        cout << "2. Cambiar el nombre del maestro de  Bases de Datos\n";
        cout << "3. Imprimir todos los datos de Bases de Datos\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout<<"\n";

        switch (opcion) {
            case 1: {
                string nuevaClave;
                cout << "Ingrese la nueva clave para Programacion: ";
                cin >> nuevaClave;
                Programacion.cambiarClave(nuevaClave);
                break;
            }
            case 2: {
                string nuevoMaestro;
                cout << "Ingrese el nuevo nombre del maestro para BasesDatos: ";
                cin.ignore();
                getline(cin, nuevoMaestro);
                BasesDatos.cambiarMaestro(nuevoMaestro);
                break;
            }
            case 3:
                cout << BasesDatos;
                break;
            case 4:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}
