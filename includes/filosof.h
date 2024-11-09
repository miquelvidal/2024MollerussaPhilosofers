#ifndef FILOSOF_H
#define FILOSOF_H

#include <pthread.h>

#include "taula.h"
#include "utilitats.h"

#define FILOSOF_ESTAT_MENJANT 0
#define FILOSOF_ESTAT_PENSANT 1
#define FILOSOF_ESTAT_DORMINT 2

#define FILOSOF_TXT_ESTAT_MENJANT "menjant"
#define FILOSOF_TXT_ESTAT_PENSANT "pensant"
#define FILOSOF_TXT_ESTAT_DORMINT "dormint"

typedef struct s_taula t_taula;

typedef struct s_filosof
{
    //el id servirà per nom, posició i identificador.
    int id;
    int estat;
    char* txt_estat;
    t_taula* taula;
    t_forquilla* forquilla_dreta;
    t_forquilla* forquilla_esquerra;
    pthread_t id_thread;
    t_timestamp ultim_menjar;

} t_filosof;

t_filosof filosof_init(int id,t_taula* taula);

//canvis d'estat
void filosof_domir(t_filosof* filosof);
void filosof_menjar(t_filosof* filosof);
void filosof_pensar(t_filosof* filosof);

//assignar forquilla
void filosof_assignarForquilles(t_filosof* filosof,t_forquilla* forquilla_esquerra,t_forquilla* forquilla_dreta);

//iniciar simulació
void filosof_iniciarSimulacio(t_filosof* filosof);
void filosof_pararSimulacio(t_filosof* filosof);
void* filosof_menjant(void*);

#endif