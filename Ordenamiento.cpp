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

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Alumno {
public:
    string nombre;
    string carrera;
    float promedio;

    Alumno(string n, string c, float p) : nombre(n), carrera(c), promedio(p) {}
};

class ListaSolicitudes {
private:
    vector<Alumno> solicitudes;

public:
    void agregarSolicitud(const Alumno& alumno) {
        solicitudes.push_back(alumno);
    }

    void ordenarSolicitudes() {
        // Ordenamiento por inserción
        for (int i = 1; i < solicitudes.size(); i++) {
            Alumno clave = solicitudes[i];
            int j = i - 1;

            // Mover elementos que son mayores que clave
            while (j >= 0 && solicitudes[j].promedio < clave.promedio) {
                solicitudes[j + 1] = solicitudes[j];
                j--;
            }
            solicitudes[j + 1] = clave;
        }
    }

    void buscarSolicitud(const string& nombre) {
        ordenarSolicitudes(); // Asegurarse de que la lista esté ordenada
        for (int i = 0; i < solicitudes.size(); i++) {
            if (solicitudes[i].nombre == nombre) {
                cout << "Solicitud encontrada en el lugar " << (i + 1) << ":" << endl;
                cout << "Nombre: " << solicitudes[i].nombre << endl;
                cout << "Carrera: " << solicitudes[i].carrera << endl;
                cout << "Promedio: " << solicitudes[i].promedio << endl;
                return;
            }
        }
        cout << "No se encontro la solicitud. Por favor, dé de alta una solicitud." << endl;
    }
};

int main() {
    ListaSolicitudes listaSolicitudes;
    int opcion;

    do {
        cout << "\n Menu " << endl;
        cout << "1. Dar de alta una solicitud" << endl;
        cout << "2. Buscar una solicitud" << endl;
        cout << "3. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            string nombre, carrera;
            float promedio;
            cout << "Ingrese el nombre del alumno: ";
            cin.ignore(); // Ignorar el salto de línea pendiente
            getline(cin, nombre);
            cout << "Ingrese el nombre de la carrera: ";
            getline(cin, carrera);
            cout << "Ingrese el promedio general: ";
            cin >> promedio;
            Alumno alumno(nombre, carrera, promedio);
            listaSolicitudes.agregarSolicitud(alumno);
            break;
        }
        case 2: {
            string nombre;
            cout << "Ingrese el nombre del alumno a buscar: ";
            cin.ignore();
            getline(cin, nombre);
            listaSolicitudes.buscarSolicitud(nombre);
            break;
        }
        case 3:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
            break;
        }
    } while (opcion != 3);

    return 0;
}