#include <iostream>

using namespace std;

class Empleado {
public:
    string nombre;
public:
    Empleado(const string& nombre) : nombre(nombre) {}
    virtual double calcularSalario() const = 0;
    virtual ~Empleado() = default;
};

class EmpleadoAsalariado : public Empleado {
protected:
    double salarioMensual;
public:
    EmpleadoAsalariado(const string& nombre, double salarioMensual) : Empleado(nombre), salarioMensual(salarioMensual) {}
    double calcularSalario() const override {
        return salarioMensual;
    }
};

class EmpleadoPorHora : public Empleado {
protected:
    double salarioPorHora;
    int horasTrabajadas;
public:
    EmpleadoPorHora(const string& nombre, double salarioPorHora, int horasTrabajadas) : Empleado(nombre), salarioPorHora(salarioPorHora), horasTrabajadas(horasTrabajadas) {}
    double calcularSalario() const override {
        return salarioPorHora * horasTrabajadas;
    }
};

class EmpleadoComisionista : public Empleado {
protected:
    double salarioBase;
    double ventasRealizadas;
    double comisionPorVenta;
public:
    EmpleadoComisionista(const string& nombre, double salarioBase, double ventasRealizadas, double comisionPorVenta) : Empleado(nombre), salarioBase(salarioBase), ventasRealizadas(ventasRealizadas), comisionPorVenta(comisionPorVenta) {}
    double calcularSalario() const override {
        return salarioBase + (ventasRealizadas * comisionPorVenta);
    }
};

void mostrarMenu() {
    cout << "----------- Menu -----------\n";
    cout << "1. Crear Empleado Asalariado\n";
    cout << "2. Crear Empleado Por Hora\n";
    cout << "3. Crear Empleado Comisionista\n";
    cout << "4. Calcular Salarios\n";
    cout << "5. Salir\n";
    cout << "----------------------------\n";
}

int main() {
    const int MAX_EMPLEADOS = 100;
    Empleado* empleados[MAX_EMPLEADOS];
    int numEmpleados = 0;
    int opcion;

    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                double salarioMensual;
                cout << "Ingrese el nombre del empleado asalariado: ";
                cin >> nombre;
                cout << "Ingrese el salario mensual del empleado: ";
                cin >> salarioMensual;
                empleados[numEmpleados++] = new EmpleadoAsalariado(nombre, salarioMensual);
                break;
            }
            case 2: {
                string nombre;
                double salarioPorHora;
                int horasTrabajadas;
                cout << "Ingrese el nombre del empleado por hora: ";
                cin >> nombre;
                cout << "Ingrese el salario por hora del empleado: ";
                cin >> salarioPorHora;
                cout << "Ingrese las horas trabajadas por el empleado: ";
                cin >> horasTrabajadas;
                empleados[numEmpleados++] = new EmpleadoPorHora(nombre, salarioPorHora, horasTrabajadas);
                break;
            }
            case 3: {
                string nombre;
                double salarioBase;
                double ventasRealizadas;
                double comisionPorVenta;
                cout << "Ingrese el nombre del empleado comisionista: ";
                cin >> nombre;
                cout << "Ingrese el salario base del empleado: ";
                cin >> salarioBase;
                cout << "Ingrese las ventas realizadas por el empleado: ";
                cin >> ventasRealizadas;
                cout << "Ingrese la comisión por venta del empleado: ";
                cin >> comisionPorVenta;
                empleados[numEmpleados++] = new EmpleadoComisionista(nombre, salarioBase, ventasRealizadas, comisionPorVenta);
                break;
            }
            case 4: {
                cout << "Calculando salarios...\n";
                for (int i = 0; i < numEmpleados; ++i) {
                    cout << "El salario de " << empleados[i]->nombre << " es: $" << empleados[i]->calcularSalario() << endl;
                }
                break;
            }
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 5);

    for (int i = 0; i < numEmpleados; ++i) {
        delete empleados[i];
    }

    return 0;
}
