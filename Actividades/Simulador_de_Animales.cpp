#include <iostream>
#include <vector>

using namespace std;

// Paso 1: Clase Animal
class Animal {
protected:
    string nombre;
public:
    Animal(const string& nombre) : nombre(nombre) {}
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

    void comer() const override {
        cout << nombre << " comiendo comida xd\n";
    }

    void dormir() const override {
        cout << nombre << " durmiendo\n";
    }

    void moverse() const override {
        cout << nombre << " caminando\n";
    }

    void amamantar() const {
        cout << nombre << " amamantando a su cria\n";
    }
};

// Clase Ave
class Ave : public Animal {
public:
    Ave(const string& nombre) : Animal(nombre) {}

    void comer() const override {
        cout << nombre << " comiendo insectos\n";
    }

    void dormir() const override {
        cout << nombre << " durmiendo en un árbol\n";
    }

    void moverse() const override {
        cout << nombre << " volando\n";
    }

    void cantar() const {
        cout << nombre << " cantando fiu fiu\n";
    }
};

// Clase Serpiente
class Reptil : public Animal {
public:
    Reptil(const string& nombre) : Animal(nombre) {}

    void comer() const override {
        cout << nombre << " comiendo\n";
    }

    void dormir() const override {
        cout << nombre << " durmiendo\n";
    }

    void moverse() const override {
        cout << nombre << " reptando\n";
    }
    
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
    vector<Animal*> animales;

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
                animales.push_back(mamifero);
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
                animales.push_back(ave);
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
                animales.push_back(reptil);
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
    } while (opcion != 4);

    for (const auto& animal : animales) {
        delete animal;
    }

    return 0;
}
