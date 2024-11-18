#include <iostream>
#include <string>
using namespace std;

class Solicitud {
private:
    string nombreAlumno;
    string carrera;
    int materiasAprobadas;
    float promedioGeneral;

public:
    Solicitud() : nombreAlumno(""), carrera(""), materiasAprobadas(0), promedioGeneral(0.0) {}

    // Constructor con parámetros
    Solicitud(string nombre, string carrera, int materias, float promedio)
        : nombreAlumno(nombre), carrera(carrera), materiasAprobadas(materias), promedioGeneral(promedio) {}

    friend ostream& operator<<(ostream& out, const Solicitud& s) {
        out << "Nombre del alumno: " << s.nombreAlumno << "\nCarrera: " << s.carrera
            << "\nTotal de materias aprobadas: " << s.materiasAprobadas
            << "\nPromedio general: " << s.promedioGeneral << endl;
        return out;
    }
};

template<class T>
class Cola;

template<class T>
class node {
private:
    T data;
    node<T>* sig;
public:
    node() : sig(nullptr) {}
    T& getData() { return data; }
    node<T>* getSig() { return sig; }

    friend class Cola<T>;
};


template<class T>
class Cola {
private:
    node<T>* frente;
    node<T>* final;

public:
    Cola() : frente(nullptr), final(nullptr) {}

    bool vacia() const { return frente == nullptr; }
    void encolar(T elem);
    bool desencolar();
    T& verFrente() const;
    void imprimir() const;
};

template<class T>
void Cola<T>::encolar(T elem) {

    node<T>* nuevoNodo = new node<T>;
    nuevoNodo->getData() = elem;
    nuevoNodo->sig = nullptr;
    if (vacia()) {
        frente = final = nuevoNodo;
    } else {
        final->sig = nuevoNodo;
        final = nuevoNodo;
    }
}

template<class T>
bool Cola<T>::desencolar() {
    if (vacia()) {
        return false;
    }
    node<T>* temp = frente;
    frente = frente->sig;
    delete temp;
    if (frente == nullptr) {
        final = nullptr;
    }
    return true;
}

template<class T>
T& Cola<T>::verFrente() const {
    return frente->getData();
}

template<class T>
void Cola<T>::imprimir() const {
    node<T>* aux = frente;
    while (aux != nullptr) {
        cout << aux->getData() << "-> " << endl;
        aux = aux->getSig();
    }
}

void registrarSolicitud(Cola<Solicitud>& cola) {
    string nombre, carrera;
    int materias;
    float promedio;

    cout << "Ingrese nombre del alumno: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese carrera: ";
    getline(cin, carrera);
    cout << "Ingrese total de materias aprobadas: ";
    cin >> materias;
    cout << "Ingrese promedio general: ";
    cin >> promedio;

    Solicitud nuevaSolicitud(nombre, carrera, materias, promedio);
    cola.encolar(nuevaSolicitud);
}

void elaborarConstancia(Cola<Solicitud>& cola) {
    if (cola.vacia()) {
        cout << "No hay solicitudes en la cola." << endl;
    } else {
        cout << "Elaborando constancia para:\n" << cola.verFrente();
        cola.desencolar();
    }
}

int main() {
    Cola<Solicitud> colaSolicitudes;
    int opcion;

    do {
        cout << "\n1. Registrar solicitud de constancia\n2. Elaborar constancia\n3. Mostrar todas las solicitudes\n4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarSolicitud(colaSolicitudes);
                break;
            case 2:
                elaborarConstancia(colaSolicitudes);
                break;
            case 3:
                colaSolicitudes.imprimir();
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
        }
    } while (opcion != 4);
    return 0;
}