#pragma once
#include <iostream>
#include <string>
using namespace std;

class Empleado {
protected:
    string nombre;
    int    edad;
    string equipo;
    string puesto;
    string fechaContratacion;

    double sueldoMensual;
    double aguinaldo;
    double primaVacacional;
    double bono;

public:
    Empleado();
    Empleado(string nom, int ed, string eq, string pues, string fecha, double sueldo);

    string getNombre() const;
    string getEquipo() const;
    string getPuesto() const;
    double getSueldoMensual() const;
    double getAguinaldo() const;
    double getPrimaVacacional() const;
    double getBono() const;
    void   setBono(double b);

    void calcularAguinaldo();
    void calcularPrimaVacacional();

    Empleado& operator+=(double aumento);

    virtual void mostrarInfoLaboral() const;
    void mostrarInfoFinanciera() const;

    virtual ~Empleado() {}
};

