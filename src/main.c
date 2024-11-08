#include <stdio.h>
#include <stdlib.h>
#include "taula.h"
#include "utilitats.h"

int main(int argc, char **argv){
    t_taula *taula;
    int num_filosofs;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO,COLOR_RED "Error: s'ha de passar el número de filòsofs/forquilles\n" COLOR_RST);
        return EXIT_FAILURE;
    }

    num_filosofs = utilitats_string2int(argv[1]);
    taula = taula_init(num_filosofs);
    if (taula == NULL)
        return (EXIT_FAILURE);
    taula_debug(taula);
    taula_destroy(taula);
    return(EXIT_SUCCESS);
}
