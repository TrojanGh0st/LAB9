#include <iostream>
using namespace std;

// Definición de la constante PI
const double PI = 3.14159265358979323846;

// Clase base Figura
class Figura {
public:
    virtual double calcularArea() const {
        return 0.0;
    }
};

// Clase derivada Circulo
class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}

    double calcularArea() const override {
        return PI * radio * radio;
    }
};

// Clase derivada Rectangulo
class Rectangulo : public Figura {
private:
    double base, altura;
public:
    Rectangulo(double b, double h) : base(b), altura(h) {}

    double calcularArea() const override {
        return base * altura;
    }
};

// Clase derivada Triangulo
class Triangulo : public Figura {
private:
    double base, altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}

    double calcularArea() const override {
        return (base * altura) / 2.0;
    }
};

int main() {
    // Arreglo de punteros a Figura
    Figura* figuras[3];

    // Crear objetos de diferentes tipos de figuras y almacenarlos en el arreglo
    figuras[0] = new Circulo(3.0);
    figuras[1] = new Rectangulo(4.0, 5.0);
    figuras[2] = new Triangulo(3.0, 4.0);

    // Recorrer el arreglo y llamar al método calcularArea() para cada objeto
    for (int i = 0; i < 3; ++i) {
        cout << "Área de la figura " << i + 1 << ": " << figuras[i]->calcularArea() << endl;
    }

    // Liberar la memoria asignada dinámicamente
    for (int i = 0; i < 3; ++i) {
        delete figuras[i];
    }

    return 0;
}
