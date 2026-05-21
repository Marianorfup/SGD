#include <iostream>
#include "Sistema.h"
using namespace std;

void mostrarMenu() {
    cout << "\n";
    cout << "  +======================================+\n";
    cout << "  |   SISTEMA DE PERSONAL DEPORTIVO      |\n";
    cout << "  |   Americano | Futbol | Basquetbol    |\n";
    cout << "  +======================================+\n";
    cout << "  |  1) Agregar empleado                 |\n";
    cout << "  |  2) Ver modulo laboral               |\n";
    cout << "  |  3) Ver modulo financiero            |\n";
    cout << "  |  4) Registrar estadisticas / bono    |\n";
    cout << "  |  5) Dar aumento de sueldo            |\n";
    cout << "  |  6) Buscar empleado                  |\n";
    cout << "  |  0) Salir                            |\n";
    cout << "  +======================================+\n";
    cout << "  Opcion: ";
}

int main() {
    Sistema sistema;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1: sistema.agregarEmpleado();       
            break;
        case 2: sistema.verModuloLaboral();      
            break;
        case 3: sistema.verModuloFinanciero();   
            break;
        case 4: sistema.registrarEstadisticas(); 
            break;
        case 5: sistema.darAumento();            
            break;
        case 6: sistema.buscarEmpleado();        
            break;
        case 0: cout << "\n  Saliendo";   
            break;
        default: cout << "\n  Opcion invalida";
        }
    } while (opcion != 0);

    return 0;
}