#ifndef TAULA_H
#define TAULA_H

#include "forquilla.h"
#include "filosof.h"

typedef struct s_taula
{
    
    int quantes_forquilles;
    t_forquilla* forquilles;

    int quants_filosofs;
    t_filosof* filosofs;


} t_taula;


#endif