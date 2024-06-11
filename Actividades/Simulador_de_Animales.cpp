#include <iostream>

using namespace std;

// Paso 1: Clase Animal
class Animal {
protected:
    string nombre;
public:
    Animal(const string& nombre) : nombre(nombre) {}
    // Funciones virtuales puras para comer, dormir y moverse.
    // Esto permite que las clases derivadas implementen sus propias versiones de estas funciones.
    virtual void comer() const = 0;
    virtual void dormir() const = 0;
    virtual void moverse() const = 0;
    virtual ~Animal() = default;
};

// Paso 2: Clases Derivadas 

// Clase Mamífero 
class Mamifero : public Animal {
public:
    Mamifero(const string& nombre) : Animal(nombre) {}

    // Implementación de las funciones virtuales puras de la clase base.
    void comer() const override {
        cout << nombre << " comiendo comida xd\n";
    }

    void dormir() const override {
        cout << nombre << " durmiendo\n";
    }

    void moverse() const override {
        cout << nombre << " caminando\n";
    }

    // Función específica de Mamífero.
    void amamantar() const {
        cout << nombre << " amamantando a su cria\n";
    }
};

// Clase Ave
class Ave : public Animal {
public:
    Ave(const string& nombre) : Animal(nombre) {}

    // Implementación de las funciones virtuales puras de la clase base.
    void comer() const override {
        cout << nombre << " comiendo insectos\n";
    }

    void dormir() const override {
        cout << nombre << " durmiendo en un árbol\n";
    }

    void moverse() const override {
        cout << nombre << " volando\n";
    }

    // Función específica de Ave.
    void cantar() const {
        cout << nombre << " cantando fiu fiu\n";
    }
};

// Clase Serpiente
class Reptil : public Animal {
public:
    Reptil(const string& nombre) : Animal(nombre) {}

    // Implementación de las funciones virtuales puras de la clase base.
    void comer() const override {
        cout << nombre << " comiendo\n";
    }

    void dormir() const override {
        cout << nombre << " durmiendo\n";
    }

    void moverse() const override {
        cout << nombre << " reptando\n";
    }
    
    // Función específica de Reptil.
    void cambiarPiel() const {
        cout << nombre << " cambiando de piel...\n";
    }
};

// MENÚ
void mostrarMenu() {
    cout << "----------- Menu -----------\n";
    cout << "1. Crear Mamifero\n";
    cout << "2. Crear Ave\n";
    cout << "3. Crear Reptil\n";
    cout << "4. Salir\n";
    cout << "----------------------------\n";
}

int main() {
    const int MAX_ANIMALES = 100; // Tamaño máximo del arreglo de animales
    Animal* animales[MAX_ANIMALES]; // Arreglo de punteros a Animal
    int numAnimales = 0; // Contador de animales creados

    int opcion;
    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                cout << "Ingrese el nombre del mamifero: ";
                cin >> nombre;
                Mamifero* mamifero = new Mamifero(nombre);
                animales[numAnimales++] = mamifero;
                mamifero->comer();
                mamifero->dormir();
                mamifero->moverse();
                mamifero->amamantar();
                break;
            }
            case 2: {
                string nombre;
                cout << "Ingrese el nombre del ave: ";
                cin >> nombre;
                Ave* ave = new Ave(nombre);
                animales[numAnimales++] = ave;
                ave->comer();
                ave->dormir();
                ave->moverse();
                ave->cantar();
                break;
            }
            case 3: {
                string nombre;
                cout << "Ingrese el nombre del reptil: ";
                cin >> nombre;
                Reptil* reptil = new Reptil(nombre);
                animales[numAnimales++] = reptil;
                reptil->comer();
                reptil->dormir();
                reptil->moverse();
                reptil->cambiarPiel();
                break;
            }
            case 4:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 4); // Salir del bucle cuando el usuario selecciona la opción 4

    // Liberar la memoria asignada dinámicamente para los objetos de Animal creados
    for (int i = 0; i < numAnimales; ++i) {
        delete animales[i];
    }

    return 0;
}
