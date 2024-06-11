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

// Clase derivada para Libros
class Libro : public Material {
public:
    // Constructor de la clase Libro que llama al constructor de Material
    Libro(string t, string a, int c) : Material(t, a, c) {}

    // Implementación de la función mostrarDetalles para libros
    void mostrarDetalles() const override {
        
        
        
        
        
    }
};

// Clase derivada para Revistas
class Revista : public Material {
public:
    // Constructor de la clase Revista que llama al constructor de Material
    Revista(string t, string a, int c) : Material(t, a, c) {}

    // Implementación de la función mostrarDetalles para revistas
    void mostrarDetalles() const override {
        cout << "\tRevista - Titulo: " <<endl; 
        cout << titulo <<endl;
        
        cout <<"\tAutor: " <<endl;
        cout << autor <<endl;
        
        cout <<"\tCodigo: " <<endl;
        cout << codigo <<endl;
        cout <<"______________________________"<<endl;

        
        
    }
};

// Clase derivada para DVDs
class DVD : public Material {
public:
    // Constructor de la clase DVD que llama al constructor de Material
    DVD(string t, string a, int c) : Material(t, a, c) {}

    // Implementación de la función mostrarDetalles para DVDs
    void mostrarDetalles() const override {
        cout << "\tRevista - Titulo: " <<endl; 
        cout << titulo <<endl;
        
        cout <<"\tAutor: " <<endl;
        cout << autor <<endl;
        
        cout <<"\tCodigo: " <<endl;
        cout << codigo <<endl;
        
        cout <<"______________________________"<<endl;
    }
};




// Función principal
int main() {
    // Arreglo de punteros a objetos de la clase Material
    Material* materiales[3];

    // Llenar el arreglo con objetos de diferentes tipos
    materiales[0] = new Libro("Cien años de soledad", "Gabriel García Márquez", 1001);
    materiales[1] = new Revista("National Geographic", "Varios", 2001);
    materiales[2] = new DVD("El Señor de los Anillos", "Peter Jackson", 3001);

    // POLIMORFISMO: Recorrer el arreglo y llamar a la función mostrarDetalles de cada objeto
    for (int i = 0; i < 3; ++i) {
        materiales[i]->mostrarDetalles();
    }

    for (int i = 0; i < 3; ++i) {
        delete materiales[i];
    }

    return 0;
}
