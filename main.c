#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
    int opt;
    tJugador *agenda = iniciaLista();
    int tamanyoLista = 5, numJugadores = 0;
    do
    {
        opt = menu();
        switch (opt)
        {
        case 1:
            printf("Ha selecionado la opcion de ver la agenda\n");
            verAgenda(agenda, numJugadores);
            break;
        case 2:
            printf("Ha selecionado la opcion de añyadir un nuevo jugador\n");
            nuevoJugador(agenda, numJugadores);
            numJugadores++;
            if (numJugadores==tamanyoLista){
                aumentarLista(agenda, numJugadores);
                tamanyoLista+=5;
            }
            break;
        case 3:
            printf("Ha selecionado la opcion de eliminar un jugador\n");
            borrarJugador(agenda, numJugadores);
            numJugadores--;
            break;
        case 4:
            printf("Ha selecionado la opcion de importar conatactos desde un fichero de texto\n");
            importarArchivos_2(agenda, &numJugadores);
            break;
        case 5:
            printf("Ha seleccionado la opcion de exportar una agenda a un fichero de texto\n");
            exportarFichero(agenda, numJugadores);
            break;
        case 0:
            printf("\t\t:::SALIENDO DEL PROGRAMA:::");
            break;
        default:
            printf("Su opcion es incorrecta\n\t\t:::REDIRIGIEDO AL MENU:::\n");
            break;
        }

    } while (opt != 0);
    free(agenda);
    return 0;
}
