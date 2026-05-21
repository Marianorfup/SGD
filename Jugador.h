#pragma once

#include "Empleado.h"
#include <string>
using namespace std;

const int MAX_PARTIDOS = 50;

class Jugador : public Empleado {
private:
    string posicion;
    int numero;
    int numJuegosTemporada;   

    int stat1[MAX_PARTIDOS];   // TD / Goles / Puntos
    int stat2[MAX_PARTIDOS];   // Tackles / Asistencias / Rebotes
    int numPartidosRegistrados;

    int totalStat1;
    int totalStat2;

public:
    Jugador();
    Jugador(string nom, int ed, string eq, string fecha, double sueldo, string pos, int num, int juegosTemporada);

    string getPosicion() const;
    int getNumero() const;
    int getNumJuegosTemporada() const;
    int getNumPartidosRegistrados()const;
    int getTotalStat1() const;
    int getTotalStat2() const;

    string getNombreStat1() const;
    string getNombreStat2() const;

    bool registrarPartido(int s1, int s2);

    void calcularBono();
    void mostrarHistorial() const;
    void mostrarInfoLaboral() const override;
};