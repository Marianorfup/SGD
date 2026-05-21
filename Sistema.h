#pragma once
#include "Jugador.h"
#include "Staff.h"

const int MAX = 50;

class Sistema {
private:
    Jugador jugadores[MAX];
    Staff   staffList[MAX];
    int     numJugadores;
    int     numStaff;

    void pausar();
    string elegirEquipo();
    string elegirPosicion(const string& equipo);
    void   mostrarMetaBono(const string& equipo, const string& posicion);

public:
    Sistema();

    void agregarEmpleado();
    void registrarEstadisticas();
    void verModuloLaboral();
    void verModuloFinanciero();
    void darAumento();
    void buscarEmpleado();
    void eliminarEmpleado();
};

