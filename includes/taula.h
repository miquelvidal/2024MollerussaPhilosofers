#ifndef TAULA_H
#define TAULA_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "forquilla.h"
#include "filosof.h"
#include "colors.h"

typedef struct s_taula
{
    
    int quantes_forquilles;
    t_forquilla* forquilles;

    int quants_filosofs;
    t_filosof* filosofs;


} t_taula;


t_taula* taula_init(int init_filosofs);

bool taula_destroy(t_taula* taula_destroy);

void taula_debug(t_taula* taula_debug);

#endif