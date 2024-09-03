#include <iostream>
#include <string>

using namespace std;

class Empleado {
private:
    string nombre;
    int id;

public:
    Empleado() : nombre(""), id(0) {}

    Empleado(string nombre, int id) : nombre(nombre), id(id) {}

    bool operator==(const Empleado& otro) const {
        return (this->id == otro.id) && (this->nombre == otro.nombre);
    }

    friend ostream& operator<<(ostream& os, const Empleado& emp) {
        os << "ID: " << emp.id << ", Nombre: " << emp.nombre;
        return os;
    }

    string getNombre() const { return nombre; }
    int getId() const { return id; }
};

template <typename T>
class ListaEstatica {
private:
    T* lista;
    int tamano;
    int cantidad;

public:
    ListaEstatica(int tam) : tamano(tam), cantidad(0) {
        lista = new T[tamano];
    }

    ListaEstatica() {
        delete[] lista;
    }

    bool Vacia() const {
        return cantidad == 0;
    }

    bool Llena() const {
        return cantidad == tamano;
    }

    bool Agrega(const T& elemento) {
        if (Llena()) {
            return false;
        }
        lista[cantidad++] = elemento;
        return true;
    }

    int Buscar(const T& elemento) const {
        for (int i = 0; i < cantidad; i++) {
            if (lista[i] == elemento) {
                return i;
            }
        }
        return -1;
    }

    bool Elimina(const T& elemento) {
        int indice = Buscar(elemento);
        if (indice == -1) {
            return false;
        }
        for (int i = indice; i < cantidad - 1; i++) {
            lista[i] = lista[i + 1];
        }
        cantidad--;
        return true;
    }

    bool Inserta(const T& elemento, int posicion) {
        if (Llena() || posicion < 0 || posicion > cantidad) {
            return false;
        }
        for (int i = cantidad; i > posicion; i--) {
            lista[i] = lista[i - 1];
        }
        lista[posicion] = elemento;
        cantidad++;
        return true;
    }



    void Muestra() const {
        if (Vacia()) {
            cout << "No hay empleados en la lista." << endl;
            return;
        }
        for (int i = 0; i < cantidad; i++) {
            cout << lista[i] << endl;
        }
    }
};

int main() {
    ListaEstatica<Empleado> lista(4);
    int opcion;
    do {
        cout << "\nMenu:\n1. Agrega\n2. Buscar\n3. Elimina\n4. Inserta\n5. Muestra\n6. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                int id;
                cout << "Ingresa el nombre del empleado: ";
                cin >> nombre;
                cout << "Ingresa el ID del empleado: ";
                cin >> id;
                Empleado emp(nombre, id);
                if (!lista.Agrega(emp)) {
                    cout << "La lista esta llena, no se puede agregar el empleado." << endl;
                }
                break;
            }
            case 2: {
                string nombre;
                int id;
                cout << "Ingresa el nombre del empleado a buscar: ";
                cin >> nombre;
                cout << "Ingresa el ID del empleado a buscar: ";
                cin >> id;
                Empleado emp(nombre, id);
                int pos = lista.Buscar(emp);
                if (pos == -1) {
                    cout << "Empleado no encontrado." << endl;
                } else {
                    cout << "Empleado encontrado en la posicion: " << pos << endl;
                }
                break;
            }
            case 3: {
                string nombre;
                int id;
                cout << "Ingresa el nombre del empleado a eliminar: ";
                cin >> nombre;
                cout << "Ingresa el ID del empleado a eliminar: ";
                cin >> id;
                Empleado emp(nombre, id);
                if (!lista.Elimina(emp)) {
                    cout << "Empleado no encontrado o lista vacia." << endl;
                }
                break;
            }
            case 4: {
                string nombre;
                int id, pos;
                cout << "Ingresa el nombre del empleado a insertar: ";
                cin >> nombre;
                cout << "Ingresa el ID del empleado a insertar: ";
                cin >> id;
                cout << "Ingresa la posicion donde insertar: ";
                cin >> pos;
                Empleado emp(nombre, id);
                if (!lista.Inserta(emp, pos)) {
                    cout << "No se pudo insertar en la posicion indicada." << endl;
                }
                break;
            }
            case 5:
                lista.Muestra();
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida, intenta de nuevo." << endl;
        }
    } while (opcion != 6);

    return 0;
}
