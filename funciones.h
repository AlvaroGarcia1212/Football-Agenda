//
// Created by Álvaro on 10/05/2023.
//

#ifndef AGENDAJUGADORES_FUNCIONES_H
#define AGENDAJUGADORES_FUNCIONES_H

#define MAX_CHAR 255

typedef enum posiciones{
    DELANTERO, MEDIOCENTRO, DEFENSA, PORTERO
}tPosicion;

typedef struct agendaJugadores{
    char nombre[MAX_CHAR];
    char apellidos[MAX_CHAR];
    char equipo[MAX_CHAR];
    int dorsal;
    int anyoNacimiento;
    tPosicion posicion;
} tJugador;

int menu();
tJugador *iniciaLista();
void aumentarLista(tJugador *agenda, int numJugadores);
void nuevoJugador(tJugador *agenda, int numJugadore);
void verAgenda(tJugador *agenda, int numJugadores);
void borrarJugador(tJugador *agenda, int numJugadores);
void exportarFichero(tJugador *agenda, int numJugadore);
void importarContactos(tJugador *agenda, int *numJugadores);
void importarArchivos_2(tJugador *agenda, int *numJugadores);


#endif //AGENDAJUGADORES_FUNCIONES_H
