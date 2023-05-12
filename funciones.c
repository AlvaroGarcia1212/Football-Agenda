//
// Created by Álvaro on 10/05/2023.
//

#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vaciaPalabra(char *palabra);

int menu(){
    int opt;
    printf("Menu de agenda\n");
    printf("--------------------------------------------------\n");
    printf("[1] Ver agenda\n[2] Anyadir jugado\n[3] Borrar jugador\n[4] Importar agenda a fichero de texto\n[5] Exportar agenda de fichero de texto\n");
    printf("--------------------------------------------------\n");
    printf("Introduze tu opcion:");
    scanf("%d", &opt);
    return opt;

}

tJugador *iniciaLista(){
    tJugador *agenda;
    agenda = malloc(5*sizeof(tJugador));
    return agenda;
}

void aumentarLista(tJugador *agenda, int numJugadores){
    realloc(agenda, (numJugadores+5) * sizeof(tJugador));
}

void nuevoJugador(tJugador *agenda, int numJugadore){
    printf("Nombre:");
    fflush(stdin);
    gets((agenda + numJugadore)->nombre);
    printf("Apellidos:");
    gets((agenda + numJugadore)->apellidos);
    printf("Equipo:");
    gets((agenda + numJugadore)->equipo);
    fflush(stdin);
    printf("Dorsal:");
    scanf("%d", &((agenda + numJugadore)->dorsal));
    printf("Anyo de nacimiento:");
    scanf("%d", &((agenda + numJugadore)->anyoNacimiento));
}

void verAgenda(tJugador *agenda, int numJugadores){
    printf("\nId;Nombre;Apellidos;Equipo;Dorsal;Anyo de nacimiento\n");
    for (int i = 0; i<=numJugadores-1;i++){
        printf("%i;%s;%s;%s;%i;%i\n", i+1, (agenda+i)->nombre, (agenda+i)->apellidos, (agenda+i)->equipo, (agenda+i)->dorsal, (agenda+i)->anyoNacimiento);
    }
}

void borrarJugador(tJugador *agenda, int numJugadores){
    int id;
    char aux[MAX_CHAR];
    printf("Indique el id del jugador que desea borrar: ");
    scanf("%d", &id);
    for (int i = 0; i < numJugadores; i++){
        if (i+1 == id){
            printf("Usted desea borrar el jugador: %i;%s;%s;%s;%i;%i\n", i+1, (agenda+i)->nombre, (agenda+i)->apellidos, (agenda+i)->equipo, (agenda+i)->dorsal, (agenda+i)->anyoNacimiento);
            printf("Esta seguro (S/N):");
            fflush(stdin);
            gets(aux);
            if ((strcmp(aux, "s")== 0) || (strcmp(aux, "S") == 0)){
                strcpy((agenda+i)->nombre , (agenda+i+1)->nombre);
                strcpy((agenda+i)->apellidos , (agenda+i+1)->apellidos);
                strcpy((agenda+i)->equipo , (agenda+i+1)->equipo);
                (agenda+i)->dorsal = (agenda+i+1)->dorsal;
                (agenda+i)->anyoNacimiento = (agenda+i+1)->anyoNacimiento;
            }else{

                printf("\n\t\t:::ABORTANDO OPERACION:::\n");
                break;
            }
            for (int i = id; i<numJugadores;i++){
                strcpy((agenda+i)->nombre , (agenda+i+1)->nombre);
                strcpy((agenda+i)->apellidos , (agenda+i+1)->apellidos);
                strcpy((agenda+i)->equipo , (agenda+i+1)->equipo);
                (agenda+i)->dorsal = (agenda+i+1)->dorsal;
                (agenda+i)->anyoNacimiento = (agenda+i+1)->anyoNacimiento;
            }
        }
    }
}

void exportarFichero(tJugador *agenda, int numJugadore) {
    char file[MAX_CHAR], aux[MAX_CHAR];
    printf("Nombre del fichero en el que va a guardar su agenda:");
    fflush(stdin);
    gets(file);
    FILE *f = fopen(file, "r");

    if (f != NULL) {
        fclose(f);
        f = fopen(file, "w");
        printf("Su fichero tiene contenido, desea sobreescribirlo (s/n):");
        gets(aux);
        if ((strcmp(aux, "s") == 0) || (strcmp(aux, "S") == 0)) {
            for (int i = 0; i < numJugadore; i++) {
                fprintf(f, "%i;%s;%s;%s;%i;%i\n", i + 1, (agenda + i)->nombre, (agenda + i)->apellidos,
                        (agenda + i)->equipo, (agenda + i)->dorsal, (agenda + i)->anyoNacimiento);
            }
            fclose(f);
        } else {
            printf("\t\t:::ABORTANDO OPERACION:::");
        }

    }else{
        fclose(f);
        f = fopen(file, "w");
        for (int i = 0; i < numJugadore; i++) {
            fprintf(f, "%i;%s;%s;%s;%i;%i\n", i + 1, agenda[i].nombre, agenda[i].apellidos,
                    agenda[i].equipo, agenda[i].dorsal, agenda[i].anyoNacimiento);
        }
        fclose(f);
    }
}

void importarContactos(tJugador *agenda, int *numJugadores) {
    int num;
    char file[MAX_CHAR], aux[MAX_CHAR], aux1[MAX_CHAR] = "";
    tJugador *persona;
    strcpy(persona->nombre, "");
    strcpy(persona->apellidos, "");
    strcpy(persona->equipo, "");
    persona->dorsal = 0;
    persona->anyoNacimiento = 0;
    printf("Nombre del fichero de texto:");
    fflush(stdin);
    gets(file);
    FILE *fichero = fopen(file, "r");
    if (fichero == NULL) {
        perror("Error en apertura:");
        exit(-1);
    }
    while (feof(fichero)) {
        fscanf(fichero, "%s", aux);
    }
    char *p;
    p = aux;
    int i = 0;
    int j = 0;
    while (p[i] != '\0') {
        if (p[i] == ";") {
            j = 0;
            if (num == 0) {
                num = atoi(aux1);
            } else {
                if (strcmp(persona->nombre, "") == 0) {
                    strcpy(persona->nombre, aux1);
                } else {
                    if (strcmp(persona->apellidos, "") == 0) {
                        strcpy(persona->apellidos, aux1);
                    } else {
                        if (strcmp(persona->equipo, "") == 0) {
                            strcpy(persona->equipo, aux1);
                        } else {
                            if (persona->dorsal == 0){
                                persona->dorsal = atoi(aux1);
                            }else{
                                if (persona->anyoNacimiento == 0){
                                    persona->anyoNacimiento = atoi(aux1);
                                }
                            }
                        }
                    }
                }
            }
        }
        else{
            aux1[j] = p[i];
            i++;
            j++;
        }
    }
    fclose(fichero);
    strcpy((agenda+(*numJugadores))->nombre, persona->nombre);
    strcpy((agenda+(*numJugadores))->apellidos, persona->apellidos);
    strcpy((agenda+(*numJugadores))->equipo, persona->equipo);
    (agenda+(*numJugadores))->dorsal = persona->dorsal;
    (agenda+(*numJugadores))->anyoNacimiento = persona->anyoNacimiento;
}

void importarArchivos_2(tJugador *agenda, int *numJugadores){

    char file[MAX_CHAR] = "", aux[MAX_CHAR] = "", aux2[MAX_CHAR] = "";
    int num = 0;
    printf("Nombre del archivo:");
    fflush(stdin);
    gets(file);
    FILE *f = fopen(file, "r");
    if (f == NULL){
        perror("Error en apertura:");
        exit(-1);
    }
    while (!feof(f)){
        fgets(aux, 255, f);
        char *p;
        p = aux;
        int i = 0, j = 0;
        char nombre[MAX_CHAR] = "", apellido[MAX_CHAR] = "", equipo[MAX_CHAR] = "";
        int dorsal = 0, anyo = 0;
        num = 0;
        do{
            if (*(p+i) == ';'){
                j = 0;
                i++;
                if (num == 0){
                    num = atoi(aux2);
                }else{
                    if (strcmp(nombre, "") == 0){
                        strcpy(nombre, aux2);
                    }else{
                        if (strcmp(apellido, "") == 0){
                            strcpy(apellido, aux2);
                        }else{
                            if (strcmp(equipo, "") == 0){
                                strcpy(equipo, aux2);
                            }else{
                                if (dorsal == 0){
                                    dorsal = atoi(aux2);
                                }else{
                                    if (anyo == 0){
                                        anyo = atoi(aux2);
                                    }
                                }
                            }
                        }
                    }
                }
                vaciaPalabra(aux2);
            }else{
                aux2[j] = p[i];
                i++;
                j++;
            }
        }while (*(p+i)!='\0');
        anyo = atoi(aux2);
        vaciaPalabra(aux2);
        strcpy((agenda+(*numJugadores))->nombre, nombre);
        strcpy((agenda+(*numJugadores))->apellidos, apellido);
        strcpy((agenda+(*numJugadores))->equipo, equipo);
        (agenda+(*numJugadores))->dorsal = dorsal;
        (agenda+(*numJugadores))->anyoNacimiento = anyo;
        (*numJugadores)++;
    }
    fclose(f);

}

void vaciaPalabra(char *palabra){
    for (int i = 0; i<MAX_CHAR; i++){
        palabra[i] = 0;
    }
}