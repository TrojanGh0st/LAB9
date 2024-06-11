#include <iostream>
using namespace std;

// Clase base Vehiculo
class Vehiculo {
public:
    // Método virtual sonidoMotor
    virtual void sonidoMotor() const {
        cout << "Este vehículo tiene un sonido de motor genérico." << endl;
    }
};

// Clase derivada Coche
class Coche : public Vehiculo {
public:
    // Redefinición del método sonidoMotor para el coche
    void sonidoMotor() const override {
        cout << "El coche hace un sonido de motor: Vroom Vroom!" << endl;
    }
};

// Clase derivada Moto
class Moto : public Vehiculo {
public:
    // Redefinición del método sonidoMotor para la moto
    void sonidoMotor() const override {
        cout << "La moto hace un sonido de motor: Vrooom!" << endl;
    }
};

// Clase derivada Camion
class Camion : public Vehiculo {
public:
    // Redefinición del método sonidoMotor para el camión
    void sonidoMotor() const override {
        cout << "El camión hace un sonido de motor: Rrrrrrr!" << endl;
    }
};

int main() {
    // Arreglo de punteros a Vehiculo
    const int numVehiculos = 3;
    Vehiculo* vehiculos[numVehiculos];

    // Crear objetos de diferentes tipos de vehículos y almacenarlos en el arreglo
    vehiculos[0] = new Coche();
    vehiculos[1] = new Moto();
    vehiculos[2] = new Camion();

    // Recorrer el arreglo y llamar al método sonidoMotor() para cada objeto
    for (int i = 0; i < numVehiculos; ++i) {
        vehiculos[i]->sonidoMotor();
    }

    // Liberar la memoria asignada dinámicamente
    for (int i = 0; i < numVehiculos; ++i) {
        delete vehiculos[i];
    }

    return 0;
}
