#include <iostream>
using namespace std;

class Animal {
public:
    virtual void hacerSonido() {
        cout << "El animal hace un sonido" << endl;
    }
};

class Perro : public Animal {
public:
    void hacerSonido() override {
        cout << "El perro ladra" << endl;
    }
};

int main() {
    Animal* miAnimal = new Perro(); // Enlace temprano, variable de tipo Animal pero objeto de tipo Perro
    miAnimal->hacerSonido(); // Se llama al método hacerSonido() de la clase base Animal
    delete miAnimal;
    return 0;
}
