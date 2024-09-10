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

// Implementacion de la pila
template <typename T>
class Pila {
private:
    T* pila;
    int tamano;
    int tope;

public:
    Pila(int tam) : tamano(tam), tope(-1) {
        pila = new T[tamano];
    }

    ~Pila() {
        delete[] pila;
    }

    bool Vacia() const {
        return tope == -1;
    }

    bool Llena() const {
        return tope == tamano - 1;
    }

    bool Push(const T& elemento) {
        if (Llena()) {
            return false;
        }
        pila[++tope] = elemento;
        return true;
    }

    bool Pop() {
        if (Vacia()) {
            return false;
        }
        --tope;
        return true;
    }

    T Top() const {
        if (Vacia()) {
            cout << "La pila esta vacia." << endl;
            return T();
        }
        return pila[tope];
    }

    void Muestra() const {
        if (Vacia()) {
            cout << "La pila esta vacia." << endl;
            return;
        }
        for (int i = 0; i <= tope; i++) {
            cout << pila[i] << endl;
        }
    }
};

int main() {
    Pila<Empleado> pila(4);
    int opcion;

    do {
        cout << "\nMenu:\n1. Push\n2. Pop\n3. Top\n4. Muestra\n5. Salir\n";
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
                if (!pila.Push(emp)) {
                    cout << "La pila esta llena, no se puede agregar el empleado." << endl;
                }
                break;
            }
            case 2: {
                if (!pila.Pop()) {
                    cout << "La pila esta vacia, no se puede eliminar ningun empleado." << endl;
                } else {
                    cout << "Empleado eliminado correctamente." << endl;
                }
                break;
            }
            case 3: {
                cout << "Empleado en la cima: " << pila.Top() << endl;
                break;
            }
            case 4:
                pila.Muestra();
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida, intenta de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}

