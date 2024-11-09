#ifndef TAULA_H
#define TAULA_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "forquilla.h"
#include "filosof.h"
#include "colors.h"
#include "utilitats.h"

typedef struct s_filosof t_filosof;

typedef struct s_taula
{
    
    int quantes_forquilles;
    t_forquilla* forquilles;

    int quants_filosofs;
    t_filosof* filosofs;
    t_timestamp temps_menjar;
    t_timestamp temps_dormir;
    t_timestamp temps_morir;
    bool    executa_simulacio;


} t_taula;


t_taula* taula_init(int init_filosofs);

bool taula_destroy(t_taula* taula_destroy);

void taula_debug(t_taula* taula_debug);

void taula_demanaForquilla(t_filosof* filosof);

void taula_iniciarSimulacio(t_taula* taula);
void taula_pararSimulacio(t_taula* taula);

void taula_filosofMort(t_taula* taula,t_filosof* filosof,t_timestamp horaDefuncio);

#endif