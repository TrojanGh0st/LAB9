#include <iostream>
#include <string>
using namespace std;

class Persona {
public:
    // Método de saludo para saludar sin nombre
    void saludar() {
        cout << "¡Hola! ¿Cómo estás?" << endl;
    }

    // Método de saludo para saludar a una persona por su nombre
    void saludar(const string& nombre) {
        cout << "¡Hola, " << nombre << "! ¿Cómo estás?" << endl;
    }

    // Método de saludo para saludar formalmente a una persona por su título y nombre
    void saludar(const string& titulo, const string& nombre) {
        cout << "Estimado(a) " << titulo << " " << nombre << ", ¿Cómo está usted?" << endl;
    }
};

int main() {
    Persona persona;

    // Saludar sin nombre
    persona.saludar();

    // Saludar a una persona por su nombre
    persona.saludar("Juan");

    // Saludar formalmente a una persona por su título y nombre
    persona.saludar("Sr.", "Pérez");

    return 0;
}
