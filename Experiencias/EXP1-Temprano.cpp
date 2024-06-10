#include <iostream>

using namespace std;

// Definición de la clase base Animal
class Animal {
public:
    // Método virtual hacerSonido
    virtual void hacerSonido() {
        cout << "Haciendo sonido de animal..." << endl;
    }
};

// Definición de la clase derivada Perro que hereda de Animal
class Perro : public Animal {
public:
    // Redefinición del método hacerSonido
    void hacerSonido() override {
        cout << "GUAU GUAU" << endl;
    }
};

int main() {
    // Enlace temprano (static binding)

    // Crear un objeto Perro
    Perro miPerro;

    // Asignarlo a una variable de tipo Animal
    Animal& animalRef = miPerro;

    // Llamar al método hacerSonido a través de la variable de tipo Animal
    animalRef.hacerSonido(); // Imprimirá "Haciendo sonido de animal..."

    cout << endl;

    // Enlace tardío (dynamic binding)

    // Repetir los pasos anteriores
    // Observe que ahora se ejecuta el método de la clase derivada (Perro)
    Animal* animalPtr = &miPerro;
    animalPtr->hacerSonido(); // Imprimirá "GUAU GUAU"

    // Análisis
    cout << endl;
    cout << "Análisis:" << endl;
    cout << "- En el enlace temprano, el método que se ejecuta se determina en tiempo de compilación basado en el tipo de la variable." << endl;
    cout << "- En el enlace tardío, el método que se ejecuta se determina en tiempo de ejecución basado en el tipo real del objeto." << endl;
    cout << "- La ventaja del enlace temprano es que es más eficiente en términos de rendimiento, ya que la resolución del método se realiza en tiempo de compilación. Sin embargo, la desventaja es que es menos flexible, ya que no permite la redefinición de métodos en tiempo de ejecución." << endl;
    cout << "- La ventaja del enlace tardío es que permite la polimorfismo y la redefinición de métodos en tiempo de ejecución, lo que aumenta la flexibilidad del código. Sin embargo, puede tener un ligero impacto en el rendimiento debido a la resolución dinámica de métodos en tiempo de ejecución." << endl;

    return 0;
}
