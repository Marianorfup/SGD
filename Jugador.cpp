#include "Jugador.h"
#include <iostream>
using namespace std;

Jugador::Jugador()
    : Empleado(), posicion(""), numero(0), numJuegosTemporada(0), numPartidosRegistrados(0), totalStat1(0), totalStat2(0) {
    for (int i = 0; i < MAX_PARTIDOS; i++) { stat1[i] = 0; stat2[i] = 0; }
}

Jugador::Jugador(string nom, int ed, string eq, string fecha, double sueldo, string pos, int num, int juegosTemporada) : Empleado(nom, ed, eq, "Jugador", fecha, sueldo),
    posicion(pos), numero(num), numJuegosTemporada(juegosTemporada), numPartidosRegistrados(0), totalStat1(0), totalStat2(0) {
    for (int i = 0; i < MAX_PARTIDOS; i++) { 
        stat1[i] = 0; 
        stat2[i] = 0; 
    }
}

string Jugador::getPosicion() const
{
    return posicion;
}

int Jugador::getNumero() const
{
    return numero;
}

int Jugador::getNumJuegosTemporada() const
{
    return numJuegosTemporada;
}

int Jugador::getNumPartidosRegistrados() const
{
    return numPartidosRegistrados;
}

int Jugador::getTotalStat1() const
{
    return totalStat1;
}

int Jugador::getTotalStat2() const
{
    return totalStat2;
}

string Jugador::getNombreStat1() const {
    if (equipo == "Americano") {
        if (posicion == "Defensa") return "Tackles";
        return "Touchdowns";
    }
    else if (equipo == "Futbol") {
        if (posicion == "Mediocampista") return "Asistencias";
        if (posicion == "Defensa" || posicion == "Portero") return "Juegos sin gol";
        return "Goles";
    }
    else {
        if (posicion == "Center") return "Rebotes";
        return "Puntos";
    }
}

string Jugador::getNombreStat2() const {
    if (equipo == "Americano") {
        if (posicion == "Defensa") return "Intercepciones";
        return "Yardas";
    }
    else if (equipo == "Futbol") {
        if (posicion == "Mediocampista") return "Goles";
        if (posicion == "Defensa" || posicion == "Portero") return "Atajadas";
        return "Asistencias";
    }
    else {
        if (posicion == "Center") return "Puntos";
        return "Asistencias";
    }
}

bool Jugador::registrarPartido(int s1, int s2) {
    if (numPartidosRegistrados >= numJuegosTemporada) return false;
    stat1[numPartidosRegistrados] = s1;
    stat2[numPartidosRegistrados] = s2;
    totalStat1 += s1;
    totalStat2 += s2;
    numPartidosRegistrados++;
    return true;
}

void Jugador::calcularBono() {
    double bonoGanado = 0;

    if (equipo == "Americano") {
        if (posicion == "QB" && totalStat1 >= 20) bonoGanado = 8000;
        else if ((posicion == "WR" || posicion == "RB") && totalStat1 >= 10) bonoGanado = 6000;
        else if (posicion == "Defensa" && totalStat1 >= 15) bonoGanado = 5000;
    }
    else if (equipo == "Futbol") {
        if (posicion == "Delantero" && totalStat1 >= 15) bonoGanado = 7000;
        else if (posicion == "Mediocampista" && totalStat1 >= 10) bonoGanado = 5000;
        else if ((posicion == "Defensa" || posicion == "Portero") && totalStat1 >= 10) bonoGanado = 5000;
    }
    else {
        if ((posicion == "Point Guard" || posicion == "Shooting Guard") && totalStat1 >= 20) bonoGanado = 7000;
        else if ((posicion == "Small Forward" || posicion == "Power Forward") && totalStat1 >= 10) bonoGanado = 6000;
        else if (posicion == "Center" && totalStat1 >= 12) bonoGanado = 6000;
    }

    setBono(bonoGanado);
}

void Jugador::mostrarHistorial() const {
    cout << "\n  Total " << getNombreStat1() << ": " << totalStat1;
    cout << "\n  Total " << getNombreStat2() << ": " << totalStat2;
}

void Jugador::mostrarInfoLaboral() const {
    Empleado::mostrarInfoLaboral();
    cout << "\n  Posicion          : " << posicion;
    cout << "\n  Numero de dorsal  : " << numero;
    cout << "\n  Partidos jugados  : " << numPartidosRegistrados << " de " << numJuegosTemporada;
}