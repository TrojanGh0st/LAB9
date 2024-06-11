#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

// Paso 1: Clase Forma
class Forma {
public:
    virtual double CalcularArea() const = 0;
    virtual double CalcularPerimetro() const = 0;
    virtual void MostrarInfo() const = 0;
    virtual ~Forma() = default;
};

// Paso 2: Clases Derivadas

// Clase Círculo
class Circulo : public Forma {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}

    double CalcularArea() const override {
        return 3.14159265358979323846 * radio * radio;
    }

    double CalcularPerimetro() const override {
        return 2 * 3.14159265358979323846 * radio;
    }

    void MostrarInfo() const override {
        cout << "Circulo: Radio = " << radio << "\n";
        cout << "Area: " << CalcularArea() << endl;
        cout << "Perimetro: " << CalcularPerimetro() << endl;
        cout << "-------------------------\n";
    }
};

// Clase Rectángulo
class Rectangulo : public Forma {
private:
    double ancho, alto;
public:
    Rectangulo(double a, double h) : ancho(a), alto(h) {}

    double CalcularArea() const override {
        return ancho * alto;
    }

    double CalcularPerimetro() const override {
        return 2 * (ancho + alto);
    }

    void MostrarInfo() const override {
        cout << "Rectangulo: Ancho = " << ancho << ", Alto = " << alto << "\n";
        cout << "Area: " << CalcularArea() << endl;
        cout << "Perimetro: " << CalcularPerimetro() << endl;
        cout << "-------------------------\n";
    }
};

// Clase Triángulo
class Triangulo : public Forma {
private:
    double base, altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}

    double CalcularArea() const override {
        return (base * altura) / 2;
    }

    double CalcularPerimetro() const override {
        double hipotenusa = sqrt(base * base + altura * altura);
        return base + altura + hipotenusa;
    }

    void MostrarInfo() const override {
        cout << "Triangulo: Base = " << base << ", Altura = " << altura << "\n";
        cout << "Area: " << CalcularArea() << endl;
        cout << "Perimetro: " << CalcularPerimetro() << endl;
        cout << "-------------------------\n";
    }
};

// Clase Cuadrado
class Cuadrado : public Forma {
private:
    double lado;
public:
    Cuadrado(double l) : lado(l) {}

    double CalcularArea() const override {
        return lado * lado;
    }

    double CalcularPerimetro() const override {
        return 4 * lado;
    }

    void MostrarInfo() const override {
        cout << "Cuadrado: Lado = " << lado << "\n";
        cout << "Area: " << CalcularArea() << endl;
        cout << "Perimetro: " << CalcularPerimetro() << endl;
        cout << "-------------------------\n";
    }
};

void limpiarPantalla();

//MENÚ
void mostrarMenu() {
    cout << "----------- Menu -----------\n";
    cout << "1. Crear Círculo\n";
    cout << "2. Crear Rectangulo\n";
    cout << "3. Crear Triangulo\n";
    cout << "4. Crear Cuadrado\n";
    cout << "5. Limpiar Pantalla\n";
    cout << "6. Salir\n";
    cout << "----------------------------\n";
}

//LIMPIAR PANTALLA
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls"); 
    #else
        system("clear"); 
    #endif
}

//FUNCIÓN PRINCIPAL
int main() {
    vector<Forma*> formas;

    int opcion;
    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                double radio;
                cout << "Ingrese el radio del circulo: ";
                cin >> radio;
                formas.push_back(new Circulo(radio));
                formas.back()->MostrarInfo();
                break;
            }
            case 2: {
                double ancho, alto;
                cout << "Ingrese el ancho del rectangulo: ";
                cin >> ancho;
                cout << "Ingrese el alto del rectangulo: ";
                cin >> alto;
                formas.push_back(new Rectangulo(ancho, alto));
                formas.back()->MostrarInfo();
                break;
            }
            case 3: {
                double base, altura;
                cout << "Ingrese la base del triangulo: ";
                cin >> base;
                cout << "Ingrese la altura del triangulo: ";
                cin >> altura;
                formas.push_back(new Triangulo(base, altura));
                formas.back()->MostrarInfo();
                break;
            }
            case 4: {
                double lado;
                cout << "Ingrese el lado del cuadrado: ";
                cin >> lado;
                formas.push_back(new Cuadrado(lado));
                formas.back()->MostrarInfo();
                break;
            }
            case 5:
                limpiarPantalla();
                break;
            case 6:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 6);

    for (const auto& forma : formas) {
        delete forma;
    }

    return 0;
}
