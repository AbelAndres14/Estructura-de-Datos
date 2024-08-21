#include <iostream>
#include <string>

using namespace std;

class Empleado {
public:
    string clave;
    string nombre;
    string domicilio;
    float sueldo;
    string reportaA;

    Empleado(string c, string n, string d, double s, string r)
            : clave(c), nombre(n), domicilio(d), sueldo(s), reportaA(r) {}

    void imprimirDatos() {
        cout << "Clave: " << clave << "\nNombre: " << nombre << "\nDomicilio: " << domicilio
             << "\nSueldo: " << sueldo << "\nReporta a: " << reportaA << endl;
    }

    void cambiarDomicilio(string& nuevoDomicilio) {
        domicilio = nuevoDomicilio;
    }

     void cambiarReportaA( string& nuevoReportaA) {
        reportaA = nuevoReportaA;
    }

    void actualizarSueldo(double porcentajeIncremento) {
        sueldo += sueldo * (porcentajeIncremento / 100);
    }

};

int main() {
    Empleado jefePlanta("1", "Carlos Perez", "Calle 123", 50000, "Director General");
    Empleado jefePersonal("2", "Ana Gomez", "Avenida 456", 45000, "Director General");

    int opcion;
    string clave, nuevoDomicilio, nuevoReportaA;
    double porcentajeIncremento;

    do {
        cout<<endl<< "Menu:\n1. Cambiar domicilio\n2. Actualizar sueldo\n3. Imprimir datos\n4. Cambiar reporta a\n5. Salir\nSeleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese la clave del empleado: ";
                cin >> clave;
                cout << "Ingrese el nuevo domicilio: ";
                cin.ignore();
                getline(cin, nuevoDomicilio);
                if (clave == "1") {
                    jefePlanta.cambiarDomicilio(nuevoDomicilio);
                } else if (clave == "2") {
                    jefePersonal.cambiarDomicilio(nuevoDomicilio);
                } else {
                    cout << "Empleado no encontrado.\n";
                }
                break;
            case 2:
                cout << "Ingrese la clave del empleado: ";
                cin >> clave;
                cout << "Ingrese el porcentaje de incremento: ";
                cin >> porcentajeIncremento;
                if (clave == "1") {
                    jefePlanta.actualizarSueldo(porcentajeIncremento);
                } else if (clave == "2") {
                    jefePersonal.actualizarSueldo(porcentajeIncremento);
                } else {
                    cout << "Empleado no encontrado.\n";
                }
                break;
            case 3:
                cout << "Ingrese la clave del empleado: ";
                cin >> clave;
                if (clave == "1") {
                    jefePlanta.imprimirDatos();
                } else if (clave == "2") {
                    jefePersonal.imprimirDatos();
                } else {
                    cout << "Empleado no encontrado.\n";
                }
                break;
            case 4:
                cout << "Ingrese la clave del empleado: ";
                cin >> clave;
                cout << "Ingrese el nuevo nombre de la persona a quien reporta: ";
                cin.ignore();
                getline(cin, nuevoReportaA);
                if (clave == "1") {
                    jefePlanta.cambiarReportaA(nuevoReportaA);
                } else if (clave == "2") {
                    jefePersonal.cambiarReportaA(nuevoReportaA);
                } else {
                    cout << "Empleado no encontrado.\n";
                }
                break;
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
                break;
        }
    } while (opcion != 5);

    return 0;
}
