#include "Sistema.h"
#include <iostream>
#include <iomanip>
using namespace std;

Sistema::Sistema() : numJugadores(0), numStaff(0) {}

void Sistema::pausar() {
    cout << "\n  Presiona Enter para continuar...";
    cin.ignore();
    cin.get();
}

string Sistema::elegirEquipo() {
    int op;
    do {
        cout << "\n  Equipo:\n"
            << "  1) Americano\n"
            << "  2) Futbol\n"
            << "  3) Basquetbol\n"
            << "  Opcion: ";
        cin >> op;

        if (op < 1 || op > 3) {
            cout << "  Opcion invalida Intenta de nuevo\n";
        }
    } while (op < 1 || op > 3); 

    if (op == 1) return "Americano";
    if (op == 2) return "Futbol";
    return "Basquetbol";
}

string Sistema::elegirPosicion(const string& equipo) {
    int op;
    if (equipo == "Americano") {
        cout << "\n  Posicion:\n  1) QB\n  2) WR\n  3) RB\n  4) Defensa\n";
        cout<< "  Opcion: ";
        cin >> op;
        string pos[] = { "QB","WR","RB","Defensa" };
        return pos[op - 1];
    }
    else if (equipo == "Futbol") {
        cout << "\n  Posicion:\n  1) Delantero\n  2) Mediocampista\n  3) Defensa\n  4) Portero\n";
        cout << "  Opcion: ";
        cin >> op;
        string pos[] = { "Delantero","Mediocampista","Defensa","Portero" };
        return pos[op - 1];
    }
    else {
        cout << "\n  Posicion:\n  1) Point Guard\n  2) Shooting Guard\n  3) Small Forward\n  4) Power Forward\n  5) Center\n";
        cout << "  Opcion: ";
        cin >> op;
        string pos[] = { "Point Guard","Shooting Guard","Small Forward","Power Forward","Center" };
        return pos[op - 1];
    }
}

void Sistema::mostrarMetaBono(const string& equipo, const string& posicion) {
    cout << "\n  --- Meta para bono ---";
    if (equipo == "Americano") {
        if (posicion == "QB")                              
            cout << "\n  20 touchdowns  -> $8,000";
        else if (posicion == "WR" || posicion == "RB")    
            cout << "\n  10 touchdowns  -> $6,000";
        else                                               
            cout << "\n  15 tackles     -> $5,000";
    }
    else if (equipo == "Futbol") {
        if (posicion == "Delantero")                       
            cout << "\n  15 goles          -> $7,000";
        else if (posicion == "Mediocampista")              
            cout << "\n  10 asistencias    -> $5,000";
        else                                               
            cout << "\n  10 juegos sin gol -> $5,000";
    }
    else {
        if (posicion == "Point Guard" || posicion == "Shooting Guard")
            cout << "\n  20 pts promedio -> $7,000";
        else if (posicion == "Small Forward" || posicion == "Power Forward")
            cout << "\n  10 pts + 8 reb  -> $6,000";
        else                                               
            cout << "\n  12 rebotes prom -> $6,000";
    }
    cout << "\n  ----------------------";
}

void Sistema::agregarEmpleado() {
    string nombre, fecha, equipo;
    int    edad, tipo;
    double sueldo;

    cout << "\n  == NUEVO EMPLEADO ==";
    cout << "\n  Nombre     : "; 
    cin.ignore(); 
    getline(cin, nombre);
    cout << "  Edad       : "; 
    cin >> edad;
    equipo = elegirEquipo();
    cout << "  Fecha contratacion (dd/mm/aaaa): "; 
    cin >> fecha;
    cout << "  Sueldo mensual $: "; 
    cin >> sueldo;
    cout << "\n  Tipo:\n  1) Jugador\n  2) Staff\n  Opcion: "; 
    cin >> tipo;

    if (tipo == 1 && numJugadores < MAX) {
        string posicion;
        int    numero, juegosTemporada;
        posicion = elegirPosicion(equipo);
        cout << "  Numero de dorsal: "; 
        cin >> numero;

        if (equipo == "Americano")  
            juegosTemporada = 17;
        else if (equipo == "Futbol")     
            juegosTemporada = 38;
        else                             
            juegosTemporada = 82;

        jugadores[numJugadores] = Jugador(nombre, edad, equipo, fecha, sueldo, posicion, numero, juegosTemporada);
        jugadores[numJugadores].calcularAguinaldo();
        jugadores[numJugadores].calcularPrimaVacacional();
        numJugadores++;
        cout << "\n  Jugador registrado con exito.";
    }
    else if (tipo == 2 && numStaff < MAX) {
        string funcion;
        cout << "  Funcion (Entrenador/Medico/Fisio/Analista/otro): ";
        cin.ignore(); 
        getline(cin, funcion);

        staffList[numStaff] = Staff(nombre, edad, equipo, fecha, sueldo, funcion);
        staffList[numStaff].calcularAguinaldo();
        staffList[numStaff].calcularPrimaVacacional();
        numStaff++;
        cout << "\n  Staff registrado con exito.";
    }
    else {
        cout << "\n  No se pudo registrar.";
    }
    pausar();
}

void Sistema::registrarEstadisticas() {
    if (numJugadores == 0) {
        cout << "\n  No hay jugadores registrados.";
        pausar(); 
        return;
    }

    cout << "\n  == REGISTRAR ESTADISTICAS ==\n";
    string deportes[] = { "Americano", "Futbol", "Basquetbol" };
    for (int d = 0; d < 3; d++) {
        bool hay = false;
        for (int i = 0; i < numJugadores; i++)
            if (jugadores[i].getEquipo() == deportes[d]) { 
                hay = true; 
                break; 
            }
        if (!hay) continue;

        cout << "  --- " << deportes[d] << " ---\n";
        for (int i = 0; i < numJugadores; i++) {
            if (jugadores[i].getEquipo() != deportes[d]) continue;
            cout << "  " << i + 1 << ") " << jugadores[i].getNombre() << " [" << jugadores[i].getPosicion() << "]" << " | Partidos: " << jugadores[i].getNumPartidosRegistrados() << "/" << jugadores[i].getNumJuegosTemporada() << "\n";
        }
    }

    int idx;
    cout << "  Selecciona jugador: "; cin >> idx;
    idx--;
    if (idx < 0 || idx >= numJugadores) {
        cout << "\n  Opcion invalida."; pausar(); return;
    }

    Jugador& j = jugadores[idx];

    if (j.getNumPartidosRegistrados() >= j.getNumJuegosTemporada()) {
        cout << "\n  Temporada completa para este jugador.";
        cout << "\n  Mostrando historial:";
        j.mostrarHistorial();
        pausar(); return;
    }

    mostrarMetaBono(j.getEquipo(), j.getPosicion());
    cout << "\n  Partido " << j.getNumPartidosRegistrados() + 1 << " de " << j.getNumJuegosTemporada();

    int s1, s2;
    cout << "\n  " << j.getNombreStat1() << ": "; cin >> s1;
    cout << "  " << j.getNombreStat2() << ": "; cin >> s2;

    j.registrarPartido(s1, s2);
    j.calcularBono();

    cout << "\n  Partido " << j.getNumPartidosRegistrados() << " registrado.";
    cout << "\n  Acumulado temporada:";
    j.mostrarHistorial();

    if (j.getBono() > 0)
        cout << "\n\n  * Meta alcanzada! Bono acumulado: $" << j.getBono();
    else
        cout << "\n\n  Meta aun no alcanzada. Sigue adelante.";

    pausar();
}

void Sistema::verModuloLaboral() {
    cout << "\n  == MODULO LABORAL ==\n";

    if (numJugadores == 0 && numStaff == 0) {
        cout << "\n  No hay empleados registrados.";
        pausar();
        return;
    }

    string deportes[] = { "Americano", "Futbol", "Basquetbol" };
    for (int d = 0; d < 3; d++) {
        bool hayJugadores = false;
        for (int i = 0; i < numJugadores; i++) {
            if (jugadores[i].getEquipo() == deportes[d]) {
                hayJugadores = true;
                break;
            }
        }

        bool hayStaff = false;
        for (int i = 0; i < numStaff; i++) {
            if (staffList[i].getEquipo() == deportes[d]) {
                hayStaff = true;
                break;
            }
        }

        if (!hayJugadores && !hayStaff) continue;

        cout << "\n  ========================================";
        cout << "\n  === " << deportes[d] << " ===";
        cout << "\n  ========================================";

        if (hayJugadores) {
            cout << "\n  --- JUGADORES ---";
            for (int i = 0; i < numJugadores; i++) {
                if (jugadores[i].getEquipo() != deportes[d]) continue;
                jugadores[i].mostrarInfoLaboral();
                if (jugadores[i].getNumPartidosRegistrados() > 0)
                    jugadores[i].mostrarHistorial();
                cout << "\n";
            }
        }

        if (hayStaff) {
            cout << "\n  --- STAFF ---";
            for (int i = 0; i < numStaff; i++) {
                if (staffList[i].getEquipo() != deportes[d]) continue;
                staffList[i].mostrarInfoLaboral();
                cout << "\n";
            }
        }
    }
    pausar();
}

void Sistema::verModuloFinanciero() {
    cout << "\n  == MODULO FINANCIERO ==\n";

    if (numJugadores == 0 && numStaff == 0) {
        cout << "\n  No hay empleados registrados.";
        pausar(); return;
    }

    double totalNomina = 0;
    string deportes[] = { "Americano", "Futbol", "Basquetbol" };

    for (int d = 0; d < 3; d++) {
        bool hayJ = false, hayS = false;
        for (int i = 0; i < numJugadores; i++)
            if (jugadores[i].getEquipo() == deportes[d]) { hayJ = true; break; }
        for (int i = 0; i < numStaff; i++)
            if (staffList[i].getEquipo() == deportes[d]) { hayS = true; break; }

        if (!hayJ && !hayS) continue;

        cout << "\n  === " << deportes[d] << " ===";

        if (hayJ) {
            cout << "\n  --- Jugadores ---";
            for (int i = 0; i < numJugadores; i++) {
                if (jugadores[i].getEquipo() != deportes[d]) continue;
                cout << "\n  " << jugadores[i].getNombre();
                jugadores[i].mostrarInfoFinanciera();
                totalNomina += jugadores[i].getSueldoMensual() + jugadores[i].getBono();
                cout << "\n";
            }
        }
        if (hayS) {
            cout << "\n  --- Staff ---";
            for (int i = 0; i < numStaff; i++) {
                if (staffList[i].getEquipo() != deportes[d]) continue;
                cout << "\n  " << staffList[i].getNombre();
                staffList[i].mostrarInfoFinanciera();
                totalNomina += staffList[i].getSueldoMensual();
                cout << "\n";
            }
        }
    }

    cout << "\n  ========================";
    cout << "\n  NOMINA TOTAL MES: $" << fixed << setprecision(2) << totalNomina;
    cout << "\n  ========================";
    pausar();
}

void Sistema::darAumento() {
    cout << "\n  == DAR AUMENTO ==\n";
    int tipo;
    cout << "  1) A jugador\n  2) A staff\n  Opcion: "; cin >> tipo;

    if (tipo == 1) {
        if (numJugadores == 0) { 
            cout << "\n  Sin jugadores."; 
            pausar(); 
            return; 
        }
        for (int i = 0; i < numJugadores; i++)
            cout << "  " << i + 1 << ") " << jugadores[i].getNombre() << "\n";
        int idx; cout << "  Selecciona: "; cin >> idx; idx--;
        double aumento; cout << "  Monto del aumento $: "; cin >> aumento;
        jugadores[idx] += aumento;   
        cout << "\n  Nuevo sueldo: $" << jugadores[idx].getSueldoMensual();
    }
    else {
        if (numStaff == 0) { 
            cout << "\n  Sin staff."; 
            pausar(); 
            return; 
        }
        for (int i = 0; i < numStaff; i++)
            cout << "  " << i + 1 << ") " << staffList[i].getNombre() << "\n";
        int idx; cout << "  Selecciona: "; cin >> idx; idx--;
        double aumento; cout << "  Monto del aumento $: "; cin >> aumento;
        staffList[idx] += aumento;   
        cout << "\n  Nuevo sueldo: $" << staffList[idx].getSueldoMensual();
    }
    pausar();
}

void Sistema::buscarEmpleado() {
    string buscar;
    cout << "\n  Nombre a buscar: "; 
    cin.ignore(); 
    getline(cin, buscar);
    bool encontrado = false;

    for (int i = 0; i < numJugadores; i++) {
        if (jugadores[i].getNombre().find(buscar) != string::npos) {
            cout << "\n  -- Jugador encontrado --";
            jugadores[i].mostrarInfoLaboral();
            jugadores[i].mostrarInfoFinanciera();
            encontrado = true;
        }
    }
    for (int i = 0; i < numStaff; i++) {
        if (staffList[i].getNombre().find(buscar) != string::npos) {
            cout << "\n  -- Staff encontrado --";
            staffList[i].mostrarInfoLaboral();
            staffList[i].mostrarInfoFinanciera();
            encontrado = true;
        }
    }
    if (!encontrado) cout << "\n  Empleado no encontrado.";
    pausar();
}