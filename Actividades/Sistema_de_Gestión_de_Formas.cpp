#include <iostream>

using namespace std;

// Paso 1: Definición de la clase base Forma como una clase abstracta
class Forma {
public:
    // Funciones virtuales puras que deben ser implementadas por las clases derivadas
    virtual double CalcularArea() const = 0; // Función para calcular el área
    virtual double CalcularPerimetro() const = 0; // Función para calcular el perímetro
    virtual void MostrarInfo() const = 0; // Función para mostrar información de la forma
    virtual ~Forma() = default; // Destructor virtual para permitir la destrucción polimórfica
};

// Clase Círculo que hereda de Forma
class Circulo : public Forma {
private:
    double radio; // Radio del círculo
public:
    Circulo(double r) : radio(r) {} // Constructor

    // Implementación de las funciones virtuales de Forma
    double CalcularArea() const override { // Cálculo del área del círculo
        return 3.14159265358979323846 * radio * radio;
    }

    double CalcularPerimetro() const override { // Cálculo del perímetro del círculo
        return 2 * 3.14159265358979323846 * radio;
    }

    void MostrarInfo() const override { // Mostrar información del círculo
        cout << "Circulo: Radio = " << radio << "\n";
        cout << "Area: " << CalcularArea() << endl;
        cout << "Perimetro: " << CalcularPerimetro() << endl;
        cout << "-------------------------\n";
    }
};

// Clase Rectángulo que hereda de Forma
class Rectangulo : public Forma {
private:
    double ancho, alto; // Ancho y alto del rectángulo
public:
    Rectangulo(double a, double h) : ancho(a), alto(h) {} // Constructor

    // Implementación de las funciones virtuales de Forma
    double CalcularArea() const override { // Cálculo del área del rectángulo
        return ancho * alto;
    }

    double CalcularPerimetro() const override { // Cálculo del perímetro del rectángulo
        return 2 * (ancho + alto);
    }

    void MostrarInfo() const override { // Mostrar información del rectángulo
        cout << "Rectangulo: Ancho = " << ancho << ", Alto = " << alto << "\n";
        cout << "Area: " << CalcularArea() << endl;
        cout << "Perimetro: " << CalcularPerimetro() << endl;
        cout << "-------------------------\n";
    }
};

// Clase Triángulo que hereda de Forma
class Triangulo : public Forma {
private:
    double base, altura; // Base y altura del triángulo

    // Función para calcular la raíz cuadrada de un número
    double raizCuadrada(double x) const {
        double epsilon = 1e-15; // Valor de precisión
        double raiz = x;
        while (abs(raiz * raiz - x) > epsilon * x) {
            raiz = (raiz + x / raiz) / 2.0;
        }
        return raiz;
    }

    // Función para calcular el cuadrado de un número
    double cuadrado(double x) const {
        return x * x;
    }

public:
    Triangulo(double b, double h) : base(b), altura(h) {} // Constructor

    // Implementación de las funciones virtuales de Forma
    double CalcularArea() const override { // Cálculo del área del triángulo
        return (base * altura) / 2;
    }

    double CalcularPerimetro() const override { // Cálculo del perímetro del triángulo
        double hipotenusa = raizCuadrada(cuadrado(base) + cuadrado(altura));
        return base + altura + hipotenusa;
    }

    void MostrarInfo() const override { // Mostrar información del triángulo
        cout << "Triangulo: Base = " << base << ", Altura = " << altura << "\n";
        cout << "Area: " << CalcularArea() << endl;
        cout << "Perimetro: " << CalcularPerimetro() << endl;
        cout << "-------------------------\n";
    }
};

// Clase Cuadrado que hereda de Forma
class Cuadrado : public Forma {
private:
    double lado; // Lado del cuadrado
public:
    Cuadrado(double l) : lado(l) {} // Constructor

    // Implementación de las funciones virtuales de Forma
    double CalcularArea() const override { // Cálculo del área del cuadrado
        return lado * lado;
    }

    double CalcularPerimetro() const override { // Cálculo del perímetro del cuadrado
        return 4 * lado;
    }

    void MostrarInfo() const override { // Mostrar información del cuadrado
        cout << "Cuadrado: Lado = " << lado << "\n";
        cout << "Area: " << CalcularArea() << endl;
        cout << "Perimetro: " << CalcularPerimetro() << endl;
        cout << "-------------------------\n";
    }
};

void limpiarPantalla(); // Prototipo de la función para limpiar la pantalla

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
        system("cls"); // Comando para limpiar pantalla en Windows
    #else
        system("clear"); // Comando para limpiar pantalla en sistemas Unix/Linux
    #endif
}
//FUNCIÓN PRINCIPAL
int main() {
    int opcion;
    Forma* formas[100]; // Arreglo para almacenar punteros a formas
    int numFormas = 0; // Contador de formas creadas

    do {
        mostrarMenu(); // Mostrar menú de opciones
        cout << "Seleccione una opcion: ";
        cin >> opcion; // Leer opción seleccionada por el usuario

        switch (opcion) {
            case 1: { // Opción para crear un círculo
                double radio;
                cout << "Ingrese el radio del circulo: ";
                cin >> radio;
                formas[numFormas++] = new Circulo(radio); // Crear un objeto Circulo y almacenarlo en el arreglo
                formas[numFormas - 1]->MostrarInfo(); // Mostrar la información del círculo recién creado
                break;
            }
            case 2: { // Opción para crear un rectángulo
                double ancho, alto;
                cout << "Ingrese el ancho del rectangulo: ";
                cin >> ancho;
                cout << "Ingrese el alto del rectangulo: ";
                cin >> alto;
                formas[numFormas++] = new Rectangulo(ancho, alto); // Crear un objeto Rectangulo y almacenarlo en el arreglo
                formas[numFormas - 1]->MostrarInfo(); // Mostrar la información del rectángulo recién creado
                break;
            }
            case 3: { // Opción para crear un triángulo
                double base, altura;
                cout << "Ingrese la base del triangulo: ";
                cin >> base;
                cout << "Ingrese la altura del triangulo: ";
                cin >> altura;
                formas[numFormas++] = new Triangulo(base, altura); // Crear un objeto Triangulo y almacenarlo en el arreglo
                formas[numFormas - 1]->MostrarInfo(); // Mostrar la información del triángulo recién creado
                break;
            }
            case 4: { // Opción para crear un cuadrado
                double lado;
                cout << "Ingrese el lado del cuadrado: ";
                cin >> lado;
                formas[numFormas++] = new Cuadrado(lado); // Crear un objeto Cuadrado y almacenarlo en el arreglo
                formas[numFormas - 1]->MostrarInfo(); // Mostrar la información del cuadrado recién creado
                break;
            }
            case 5: // Opción para limpiar la pantalla
                limpiarPantalla();
                break;
            case 6: // Opción para salir del programa
                cout << "Saliendo...\n";
                break;
            default: // Opción para manejar una entrada inválida
                cout << "Opcion invalida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 6); // Repetir el bucle hasta que el usuario seleccione la opción de salir

    // Liberar la memoria asignada dinámicamente para los objetos de forma creados
    for (int i = 0; i < numFormas; ++i) {
        delete formas[i];
    }

    return 0;
}
