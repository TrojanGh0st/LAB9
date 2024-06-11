#include <iostream>
#include <string>
using namespace std;

// Clase abstracta FiguraGeometrica
class FiguraGeometrica {
public:
    // Métodos virtuales puros para calcular el área y el perímetro
    virtual double calcularArea() const = 0;
    virtual double calcularPerimetro() const = 0;
};

// Clase derivada Circulo
class Circulo : public FiguraGeometrica {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}

    double calcularArea() const override {
        return 3.14159265358979323846 * radio * radio;
    }

    double calcularPerimetro() const override {
        return 2 * 3.14159265358979323846 * radio;
    }
};

// Clase derivada Rectangulo
class Rectangulo : public FiguraGeometrica {
private:
    double base, altura;
public:
    Rectangulo(double b, double h) : base(b), altura(h) {}

    double calcularArea() const override {
        return base * altura;
    }

    double calcularPerimetro() const override {
        return 2 * (base + altura);
    }
};

// Clase derivada Triangulo
class Triangulo : public FiguraGeometrica {
private:
    double lado1, lado2, lado3;
public:
    Triangulo(double l1, double l2, double l3) : lado1(l1), lado2(l2), lado3(l3) {}

    double calcularArea() const override {
        double s = (lado1 + lado2 + lado3) / 2.0;
        return sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
    }

    double calcularPerimetro() const override {
        return lado1 + lado2 + lado3;
    }
};

int main() {
    // Arreglo de punteros a FiguraGeometrica
    const int numFiguras = 3;
    FiguraGeometrica* figuras[numFiguras];

    // Crear objetos de diferentes tipos de figuras geométricas y almacenarlos en el arreglo
    figuras[0] = new Circulo(3.0);
    figuras[1] = new Rectangulo(4.0, 5.0);
    figuras[2] = new Triangulo(3.0, 4.0, 5.0);

    // Recorrer el arreglo y llamar a los métodos calcularArea() y calcularPerimetro() para cada objeto
    for (int i = 0; i < numFiguras; ++i) {
        cout << "Figura " << i + 1 << ":" << endl;
        cout << "Área: " << figuras[i]->calcularArea() << endl;
        cout << "Perímetro: " << figuras[i]->calcularPerimetro() << endl << endl;
    }

    // Liberar la memoria asignada dinámicamente
    for (int i = 0; i < numFiguras; ++i) {
        delete figuras[i];
    }

    return 0;
}
