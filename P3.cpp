#include <iostream>
#include <string>

using namespace std;

class Empleado {
private:
    string clave;
    string nombre;
    string domicilio;
    double sueldo;
    string reportaA;

public:
    // Constructor
    Empleado(string clave, string nombre, string domicilio, double sueldo, string reportaA)
        : clave(clave), nombre(nombre), domicilio(domicilio), sueldo(sueldo), reportaA(reportaA) {}

    // Sobrecarga de operadores
    bool operator==(const Empleado& otro) const {
        return this->clave == otro.clave;
    }

    bool operator!=(const Empleado& otro) const {
        return !(*this == otro);
    }

    bool operator<(const Empleado& otro) const {
        return this->sueldo < otro.sueldo;
    }

    bool operator>(const Empleado& otro) const {
        return this->sueldo > otro.sueldo;
    }

    Empleado operator+(const Empleado& otro) const {
        return Empleado(this->clave + "-" + otro.clave,
                        this->nombre + " y " + otro.nombre,
                        this->domicilio + ", " + otro.domicilio,
                        this->sueldo + otro.sueldo,
                        this->reportaA + ", " + otro.reportaA);
    }

    friend ostream& operator<<(ostream& os, const Empleado& emp) {
        os << "Clave: " << emp.clave << "\nNombre: " << emp.nombre << "\nDomicilio: " << emp.domicilio
           << "\nSueldo: " << emp.sueldo << "\nReporta a: " << emp.reportaA << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Empleado& emp) {
        cout << "Ingrese la clave: ";
        is >> emp.clave;
        cout << "Ingrese el nombre: ";
        is>>emp.nombre;
        cout << "Ingrese el domicilio: ";
        is>>emp.domicilio;
        cout << "Ingrese el sueldo: ";
        is >> emp.sueldo;
        cout << "Ingrese el nombre de la persona a quien reporta: ";

        is>>emp.reportaA;
        return is;
    }


/*friend istream& operator <<(istream& i, Persona& p){
    cout<<"Ingresa Nombre: ";
    i>>p.Nombre;
    cout<<"Ingresa edad: ";
    i>>p.Edad;
    cout<<"Ingresa Sexo";
    i>>p.Sexo;
    cout<<"Ingresa El telefono: "
    i>>p.Tel;
    return i;
}

*/




    // Métodos para actualizar datos
    void cambiarDomicilio(string nuevoDomicilio) {
        domicilio = nuevoDomicilio;
    }

    void actualizarSueldo(double porcentaje) {
        sueldo += sueldo * (porcentaje / 100.0);
    }

    void cambiarReportaA(string nuevoReportaA) {
        reportaA = nuevoReportaA;
    }

    // Método para imprimir los datos
    void imprimirDatos() const {
        cout << *this;
    }

    // Obtener clave
    string getClave() const {
        return clave;
    }
};

// Función para buscar un empleado por clave
Empleado* buscarEmpleado(Empleado& emp1, Empleado& emp2, string clave) {
    if (emp1.getClave() == clave) return &emp1;
    if (emp2.getClave() == clave) return &emp2;
    return nullptr;
}

// Menú de opciones
void menu(Empleado& emp1, Empleado& emp2) {
    int opcion;
    do {
        cout << "\nMenu:\n";
        cout << "1. Cambiar domicilio\n";
        cout << "2. Actualizar sueldo\n";
        cout << "3. Imprimir datos de un empleado\n";
        cout << "4. Cambiar nombre de la persona a quien reporta\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            string clave, nuevoDomicilio;
            cout << "Ingrese la clave del empleado: ";
            cin >> clave;
            Empleado* emp = buscarEmpleado(emp1, emp2, clave);
            if (emp) {
                cout << "Ingrese el nuevo domicilio: ";
                cin.ignore();
                getline(cin, nuevoDomicilio);
                emp->cambiarDomicilio(nuevoDomicilio);
            } else {
                cout << "Empleado no encontrado.\n";
            }
            break;
        }
        case 2: {
            string clave;
            double porcentaje;
            cout << "Ingrese la clave del empleado: ";
            cin >> clave;
            Empleado* emp = buscarEmpleado(emp1, emp2, clave);
            if (emp) {
                cout << "Ingrese el porcentaje de incremento: ";
                cin >> porcentaje;
                emp->actualizarSueldo(porcentaje);
            } else {
                cout << "Empleado no encontrado.\n";
            }
            break;
        }
        case 3: {
            string clave;
            cout << "Ingrese la clave del empleado: ";
            cin >> clave;
            Empleado* emp = buscarEmpleado(emp1, emp2, clave);
            if (emp) {
                emp->imprimirDatos();
            } else {
                cout << "Empleado no encontrado.\n";
            }
            break;
        }
        case 4: {
            string clave, nuevoReportaA;
            cout << "Ingrese la clave del empleado: ";
            cin >> clave;
            Empleado* emp = buscarEmpleado(emp1, emp2, clave);
            if (emp) {
                cout << "Ingrese el nuevo nombre de la persona a quien reporta: ";
                cin.ignore();
                getline(cin, nuevoReportaA);
                emp->cambiarReportaA(nuevoReportaA);
            } else {
                cout << "Empleado no encontrado.\n";
            }
            break;
        }
        case 5:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opcion no valida.\n";
        }
    } while (opcion != 5);
}

int main() {
    // Declarar los objetos JefePlanta y JefePersonal
    Empleado JefePlanta("1", "Carlos Ruiz", "Av. Siempre Viva 123", 50000, "Director General");
    Empleado JefePersonal("2", "Laura Gómez", "Calle Falsa 456", 48000, "Director General");

    // Ejecutar el menú
    menu(JefePlanta, JefePersonal);

    return 0;
}
