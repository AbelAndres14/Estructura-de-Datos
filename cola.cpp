#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Alumno {
private:
    string nombre;
    string carrera;
    int materiasAprobadas;
    float promedio;

public:

    Alumno(string nombre, string carrera, int materiasAprobadas, float promedio)
        : nombre(nombre), carrera(carrera), materiasAprobadas(materiasAprobadas), promedio(promedio) {}

    friend ostream& operator<<(ostream& os, const Alumno& alumno) {
        os << "Nombre: " << alumno.nombre << endl;
        os << "Carrera: " << alumno.carrera << endl;
        os << "Materias aprobadas: " << alumno.materiasAprobadas << endl;
        os << "Promedio: " << alumno.promedio << endl;
        return os;
    }
};

// Definición de la clase Cola de alumnos
class Cola {
private:
    queue<Alumno> colaAlumnos;

public:
    // Encolar una solicitud de alumno
    void encolar(const Alumno& alumno) {
        colaAlumnos.push(alumno);
        cout << "Solicitud de " << alumno << " ha sido encolada." << endl;
    }

    // Atender una solicitud (elaborar constancia)
    void elaborarConstancia() {
        if (colaAlumnos.empty()) {
            cout << "No hay solicitudes en la cola." << endl;
        } else {
            Alumno alumno = colaAlumnos.front();
            colaAlumnos.pop();
            cout << "Elaborando constancia para:" << endl;
            cout << alumno << endl;
        }
    }

    // Sobrecarga del operador << para mostrar el estado de la cola
    friend ostream& operator<<(ostream& os, const Cola& cola) {
        if (cola.colaAlumnos.empty()) {
            os << "La cola esta vacia." << endl;
        } else {
            os << "Hay " << cola.colaAlumnos.size() << " solicitudes en la cola." << endl;
        }
        return os;
    }
};

int main() {
    Cola colaSolicitudes;
    int opcion;

    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Dar de alta una solicitud" << endl;
        cout << "2. Elaborar una constancia" << endl;
        cout << "3. Mostrar estado de la cola" << endl;
        cout << "4. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            string nombre, carrera;
            int materiasAprobadas;
            float promedio;
            cout << "Ingrese el nombre del alumno: ";
            cin.ignore(); // Ignorar el salto de línea pendiente
            getline(cin, nombre);
            cout << "Ingrese el nombre de la carrera: ";
            getline(cin, carrera);
            cout << "Ingrese el total de materias aprobadas: ";
            cin >> materiasAprobadas;
            cout << "Ingrese el promedio general: ";
            cin >> promedio;
            Alumno alumno(nombre, carrera, materiasAprobadas, promedio);
            colaSolicitudes.encolar(alumno);
            break;
        }
        case 2:
            colaSolicitudes.elaborarConstancia();
            break;
        case 3:
            cout << colaSolicitudes;
            break;
        case 4:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion no válida." << endl;
            break;
        }
    } while (opcion != 4);

    return 0;
}
