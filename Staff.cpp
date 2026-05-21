#include "Staff.h"
#include <iostream>
using namespace std;

Staff::Staff() : Empleado(), funcion("") {
}

Staff::Staff(string nom, int ed, string eq, string fecha, double sueldo, string func) : Empleado(nom, ed, eq, "Staff", fecha, sueldo), funcion(func) {
}

string Staff::getFuncion() const { return funcion; }

void Staff::mostrarInfoLaboral() const {
    Empleado::mostrarInfoLaboral();
    cout << "\n  Funcion           : " << funcion;
}
