#include "Empleado.h"
#include <iostream>
#include <iomanip>
using namespace std;

Empleado::Empleado() : nombre(""), edad(0), equipo(""), puesto(""), fechaContratacion(""), sueldoMensual(0), aguinaldo(0), primaVacacional(0), bono(0) {
}

Empleado::Empleado(string nom, int ed, string eq, string pues, string fecha, double sueldo) : nombre(nom), edad(ed), equipo(eq), puesto(pues), fechaContratacion(fecha), sueldoMensual(sueldo), aguinaldo(0), primaVacacional(0), bono(0) {
}

string Empleado::getNombre() const
{
    return nombre;
}

string Empleado::getEquipo() const
{
    return equipo;
}

string Empleado::getPuesto() const
{
    return puesto;
}

double Empleado::getSueldoMensual() const
{
    return sueldoMensual;
}

double Empleado::getAguinaldo() const
{
    return aguinaldo;
}

double Empleado::getPrimaVacacional() const
{
    return primaVacacional;
}

double Empleado::getBono() const
{
    return bono;
}

void Empleado::setBono(double b)
{
    bono = b;
}

void Empleado::calcularAguinaldo()
{
    aguinaldo = sueldoMensual / 30.0 * 15;
}

void Empleado::calcularPrimaVacacional()
{
    primaVacacional = sueldoMensual / 12.0 * 0.25;
}

Empleado& Empleado::operator+=(double aumento) {
    sueldoMensual += aumento;
    return *this;
}

void Empleado::mostrarInfoLaboral() const {
    cout << "\n  Nombre            : " << nombre;
    cout << "\n  Edad              : " << edad << " anios";
    cout << "\n  Equipo            : " << equipo;
    cout << "\n  Puesto            : " << puesto;
    cout << "\n  Fecha contratacion: " << fechaContratacion;
}

void Empleado::mostrarInfoFinanciera() const {
    cout << fixed << setprecision(2);
    cout << "\n  Sueldo mensual    : $" << sueldoMensual;
    cout << "\n  Aguinaldo         : $" << aguinaldo;
    cout << "\n  Prima vacacional  : $" << primaVacacional;
    cout << "\n  Bono rendimiento  : $" << bono;
    cout << "\n  Total mensual     : $" << sueldoMensual + bono;
}