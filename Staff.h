#pragma once
#include "Empleado.h"
#include <string>
using namespace std;

class Staff : public Empleado {
private:
    string funcion;

public:
    Staff();
    Staff(string nom, int ed, string eq, string fecha, double sueldo, string func);

    string getFuncion() const;

    void mostrarInfoLaboral() const override;
};

