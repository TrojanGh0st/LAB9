#include <iostream>
#include <string>

using namespace std;

// Clase base Personaje
class Personaje {
protected:
    string nombre;
    int salud;
public:
    Personaje(const string& nombre, int salud) : nombre(nombre), salud(salud) {}
    virtual void atacar(Personaje* objetivo) const = 0;
    virtual void defender() const = 0;
    virtual void usarHabilidadEspecial() const = 0;
    string obtenerNombre() const { return nombre; } 
    int obtenerSalud() const { return salud; } 
    virtual void mostrarInfo() const = 0; 
    virtual ~Personaje() = default;
};

// Clase Guerrero
class Guerrero : public Personaje {
public:
    Guerrero(const string& nombre, int salud) : Personaje(nombre, salud) {}
    void atacar(Personaje* objetivo) const override {
        cout << obtenerNombre() << " ataca con espada a " << objetivo->obtenerNombre() << "!\n";
    }
    void defender() const override {
        cout << obtenerNombre() << " se defiende con su escudo!\n";
    }
    void usarHabilidadEspecial() const override {
        cout << obtenerNombre() << " usa embestida!\n";
    }
    void mostrarInfo() const override {
        cout << "Guerrero: " << obtenerNombre() << ", Salud: " << obtenerSalud() << endl;
    }
};

// Clase Mago
class Mago : public Personaje {
public:
    Mago(const string& nombre, int salud) : Personaje(nombre, salud) {}
    void atacar(Personaje* objetivo) const override {
        cout << obtenerNombre() << " lanza una bola de fuego a " << objetivo->obtenerNombre() << "!\n";
    }
    void defender() const override {
        cout << obtenerNombre() << " se protege con un escudo mágico!\n";
    }
    void usarHabilidadEspecial() const override {
        cout << obtenerNombre() << " usa invocación!\n";
    }
    void mostrarInfo() const override {
        cout << "Mago: " << obtenerNombre() << ", Salud: " << obtenerSalud() << endl;
    }
};

// Clase Arquero
class Arquero : public Personaje {
public:
    Arquero(const string& nombre, int salud) : Personaje(nombre, salud) {}
    void atacar(Personaje* objetivo) const override {
        cout << obtenerNombre() << " dispara una flecha a " << objetivo->obtenerNombre() << "!\n";
    }
    void defender() const override {
        cout << obtenerNombre() << " se agacha para esquivar ataques!\n";
    }
    void usarHabilidadEspecial() const override {
        cout << obtenerNombre() << " usa tiro múltiple!\n";
    }
    void mostrarInfo() const override {
        cout << "Arquero: " << obtenerNombre() << ", Salud: " << obtenerSalud() << endl;
    }
};
// MENÚ
void mostrarMenu() {
    cout << "----------- Menu -----------\n";
    cout << "1. Crear Guerrero\n";
    cout << "2. Crear Mago\n";
    cout << "3. Crear Arquero\n";
    cout << "4. Mostrar información de todos los personajes\n";
    cout << "5. Luchar\n";
    cout << "6. Salir\n";
    cout << "----------------------------\n";
}

// MOSTRAR INFO DE LOS PERSOANJES YA CREADOS
void mostrarInfoPersonajes(Personaje* personajes[], int numPersonajes) {
    cout << "Información de los personajes:\n";
    for (int i = 0; i < numPersonajes; ++i) {
        personajes[i]->mostrarInfo();
    }
    cout << endl;
}

//LUCHA ENTRE PESONAJES CREADOS
void luchar(Personaje* personajes[], int numPersonajes) {
    cout << "Seleccione el atacante:\n";
    for (int i = 0; i < numPersonajes; ++i) {
        cout << i + 1 << ". " << personajes[i]->obtenerNombre() << endl;
    }
    int atacanteIndex;
    do {
        cout << "Seleccione el atacante (1-" << numPersonajes << "): ";
        cin >> atacanteIndex;
    } while (atacanteIndex < 1 || atacanteIndex > numPersonajes);

    cout << "Seleccione el objetivo:\n";
    for (int i = 0; i < numPersonajes; ++i) {
        if (i != atacanteIndex - 1) {
            cout << i + 1 << ". " << personajes[i]->obtenerNombre() << endl;
        }
    }
    int objetivoIndex;
    do {
        cout << "Seleccione el objetivo (1-" << numPersonajes << "): ";
        cin >> objetivoIndex;
    } while (objetivoIndex < 1 || objetivoIndex > numPersonajes || objetivoIndex == atacanteIndex);

    personajes[atacanteIndex - 1]->atacar(personajes[objetivoIndex - 1]);
}

//Función principal

int main() {
    const int MAX_PERSONAJES = 100;
    Personaje* personajes[MAX_PERSONAJES];
    int numPersonajes = 0;

    int opcion;
    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                int salud;
                cout << "Ingrese el nombre del Guerrero: ";
                cin >> nombre;
                cout << "Ingrese la salud del Guerrero: ";
                cin >> salud;
                personajes[numPersonajes++] = new Guerrero(nombre, salud);
                break;
            }
            case 2: {
                string nombre;
                int salud;
                cout << "Ingrese el nombre del Mago: ";
                cin >> nombre;
                cout << "Ingrese la salud del Mago: ";
                cin >> salud;
                personajes[numPersonajes++] = new Mago(nombre, salud);
                break;
            }
            case 3: {
                string nombre;
                int salud;
                cout << "Ingrese el nombre del Arquero: ";
                cin >> nombre;
                cout << "Ingrese la salud del Arquero: ";
                cin >> salud;
                personajes[numPersonajes++] = new Arquero(nombre, salud);
                break;
            }
            case 4:
                mostrarInfoPersonajes(personajes, numPersonajes);
                break;
            case 5:
                luchar(personajes, numPersonajes);
                break;
            case 6:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 6);

    for (int i = 0; i < numPersonajes; ++i) {
        delete personajes[i];
    }

    return 0;
}
