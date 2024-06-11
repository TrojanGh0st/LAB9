#include <iostream> 

#include <string> 

  

using namespace std; 

  

// Paso 1: Clase Producto 

class Producto { 

protected: 

    string nombre; 

    double precio; 

public: 

    Producto(const string& nombre, double precio) : nombre(nombre), precio(precio) {} 

    virtual double calcularPrecio() const { return precio; } // Precio base del producto 

    virtual ~Producto() = default; 

}; 

  

// Paso 2: Clases Derivadas 

  

// Clase Electronico 

class Electronico : public Producto { 

private: 

    string marca; 

public: 

    Electronico(const string& nombre, double precio, const string& marca) : Producto(nombre, precio), marca(marca) {} 

  

    // Precio de un producto electrónico con descuento del 10% 

    double calcularPrecio() const override { 

        return precio * 0.9; 

    } 

}; 

  

// Clase Ropa 

class Ropa : public Producto { 

private: 

    string talla; 

public: 

    Ropa(const string& nombre, double precio, const string& talla) : Producto(nombre, precio), talla(talla) {} 

  

    // Precio de una prenda de ropa con descuento del 20% 

    double calcularPrecio() const override { 

        return precio * 0.8; 

    } 

}; 

  

// Clase Alimento 

class Alimento : public Producto { 

private: 

    string fechaCaducidad; 

public: 

    Alimento(const string& nombre, double precio, const string& fechaCaducidad) : Producto(nombre, precio), fechaCaducidad(fechaCaducidad) {} 

  

    // Precio de un producto alimenticio sin descuento 

    double calcularPrecio() const override { 

        return precio; 

    } 

}; 

  

// Función para calcular el valor total del inventario 

double calcularValorTotal(Producto* inventario[], int numProductos) { 

    double valorTotal = 0.0; 

    for (int i = 0; i < numProductos; ++i) { 

        valorTotal += inventario[i]->calcularPrecio(); 

    } 

    return valorTotal; 

} 

  

// Función para aplicar descuentos a todos los productos del inventario 

void aplicarDescuentos(Producto* inventario[], int numProductos) { 

    for (int i = 0; i < numProductos; ++i) { 

        inventario[i]->calcularPrecio(); 

    } 

} 

  

// Función para mostrar el inventario 

void mostrarInventario(Producto* inventario[], int numProductos) { 

    cout << "Inventario:\n"; 

    for (int i = 0; i < numProductos; ++i) { 

        cout << inventario[i]->calcularPrecio() << " - " << inventario[i]->calcularPrecio() << endl; 

    } 

} 

  

// Función para liberar la memoria del inventario 

void liberarInventario(Producto* inventario[], int numProductos) { 

    for (int i = 0; i < numProductos; ++i) { 

        delete inventario[i]; 

    } 

} 

  

// MENÚ 

void mostrarMenu() { 

    cout << "----------- Menu -----------\n"; 

    cout << "1. Agregar Producto Electrónico\n"; 

    cout << "2. Agregar Producto de Ropa\n"; 

    cout << "3. Agregar Producto de Alimento\n"; 

    cout << "4. Calcular Valor Total del Inventario\n"; 

    cout << "5. Aplicar Descuentos\n"; 

    cout << "6. Mostrar Inventario\n"; 

    cout << "7. Salir\n"; 

    cout << "----------------------------\n"; 

} 

  

int main() { 

    const int MAX_PRODUCTOS = 100; // Tamaño máximo del arreglo de productos 

    Producto* inventario[MAX_PRODUCTOS]; 

    int numProductos = 0; // Contador de productos agregados al inventario 

  

    int opcion; 

    do { 

        mostrarMenu(); 

        cout << "Seleccione una opcion: "; 

        cin >> opcion; 

  

        switch (opcion) { 

            case 1: { 

                string nombre, marca; 

                double precio; 

                cout << "Ingrese el nombre del producto electrónico: "; 

                cin >> nombre; 

                cout << "Ingrese la marca del producto electrónico: "; 

                cin >> marca; 

                cout << "Ingrese el precio del producto electrónico: "; 

                cin >> precio; 

                inventario[numProductos++] = new Electronico(nombre, precio, marca); 

                break; 

            } 

            case 2: { 

                string nombre, talla; 

                double precio; 

                cout << "Ingrese el nombre del producto de ropa: "; 

                cin >> nombre; 

                cout << "Ingrese la talla del producto de ropa: "; 

                cin >> talla; 

                cout << "Ingrese el precio del producto de ropa: "; 

                cin >> precio; 

                inventario[numProductos++] = new Ropa(nombre, precio, talla); 

                break; 

            } 

            case 3: { 

                string nombre, fechaCaducidad; 

                double precio; 

                cout << "Ingrese el nombre del producto de alimento: "; 

                cin >> nombre; 

                cout << "Ingrese la fecha de caducidad del producto de alimento: "; 

                cin >> fechaCaducidad; 

                cout << "Ingrese el precio del producto de alimento: "; 

                cin >> precio; 

                inventario[numProductos++] = new Alimento(nombre, precio, fechaCaducidad); 

                break; 

            } 

            case 4: 

                cout << "Valor Total del Inventario: " << calcularValorTotal(inventario, numProductos) << endl; 

                break; 

            case 5: 

                aplicarDescuentos(inventario, numProductos); 

                cout << "Descuentos aplicados correctamente.\n"; 

                break; 

            case 6: 

                mostrarInventario(inventario, numProductos); 

                break; 

            case 7: 

                cout << "Saliendo...\n"; 

                break; 

            default: 

                cout << "Opcion invalida. Intente de nuevo.\n"; 

                break; 

        } 

    } while (opcion != 7); 

  

    liberarInventario(inventario, numProductos); 

  

    return 0; 

} 
