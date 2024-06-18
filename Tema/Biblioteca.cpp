#include <iostream>
#include <string>
using namespace std;

// Clase base Material
class Material {
protected:
    string titulo;  // Título del material
    string autor;   // Autor o director del material
    int codigo;     // Código identificador del material
public:
    // Constructor de la clase base Material
    Material(string t, string a, int c) : titulo(t), autor(a), codigo(c) {}

    // Función virtual pura para mostrar detalles del material
    virtual void mostrarDetalles() const = 0;

    // Destructor virtual para la clase base Material
    virtual ~Material() {}
};

// Clase Libros
class Libro : public Material {
public:
    // Constructor de la clase Libro que llama al constructor de Material
    Libro(string t, string a, int c) : Material(t, a, c) {}

    // Función mostrarDetalles para libros
    void mostrarDetalles() const override {
        cout << "Libro - Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Codigo: " << codigo << endl;
        cout << "______________________________" << endl;
    }
};

// Clase derivada para Revistas
class Revista : public Material {
public:
    // Constructor de la clase Revista
    Revista(string t, string a, int c) : Material(t, a, c) {}

    // Función mostrarDetalles para revistas
    void mostrarDetalles() const override {
        cout << "Revista - Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Codigo: " << codigo << endl;
        cout << "______________________________" << endl;
    }
};

// Clase derivada para DVDs
class DVD : public Material {
public:
    // Constructor de la clase DVD
    DVD(string t, string a, int c) : Material(t, a, c) {}

    // Función mostrarDetalles para DVDs
    void mostrarDetalles() const override {
        cout << "DVD - Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Codigo: " << codigo << endl;
        cout << "______________________________" << endl;
    }
};

// Validación de enteros
int obtenerEntero(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail() || valor < 0) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida. Por favor, ingrese un numero entero positivo." << endl;
        } else {
            cin.ignore(10000, '\n');
            return valor;
        }
    }
}

// Poder obtenerCadena
string obtenerCadena(const string& mensaje) {
    string valor;
    cout << mensaje;
    getline(cin, valor);
    return valor;
}

// Menú
void mostrarMenu() {
    cout << "1. Crear Libro" << endl;
    cout << "2. Crear Revista" << endl;
    cout << "3. Crear DVD" << endl;
    cout << "4. Mostrar materiales creados" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opción: ";
}

int main() {
    cout << "Bienvenido a Diego's Library" << endl;
   
   
    Material* materiales[100];
    int cantidadMateriales = 0;

    int opcion;
    do {
        mostrarMenu();
        opcion = obtenerEntero("");
       
        if (opcion >= 1 && opcion <= 3 && cantidadMateriales < 100) {
            string titulo = obtenerCadena("Titulo: ");
            string autor = obtenerCadena("Autor: ");
            int codigo = obtenerEntero("Codigo: ");
           
            switch (opcion) {
                case 1:
                    materiales[cantidadMateriales++] = new Libro(titulo, autor, codigo);
                    break;
                case 2:
                    materiales[cantidadMateriales++] = new Revista(titulo, autor, codigo);
                    break;
                case 3:
                    materiales[cantidadMateriales++] = new DVD(titulo, autor, codigo);
                    break;
            }
        } else if (opcion == 4) {
            for (int i = 0; i < cantidadMateriales; ++i) {
                materiales[i]->mostrarDetalles();
            }
        } else if (opcion != 5) {
            cout << "Opción invalida o capacidad maxima alcanzada." << endl;
        }
    } while (opcion != 5);

    // Liberar la memoria asignada
    for (int i = 0; i < cantidadMateriales; ++i) {
        delete materiales[i];
    }

    cout << "Gracias por usar Diego's Library. ¡Adios!" << endl;
    return 0;
}
