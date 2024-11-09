#include "taula.h"

bool taula_destroy(t_taula* taula_destroy){
        
    if (taula_destroy==NULL) return true;
    taula_pararSimulacio(taula_destroy);

    if (taula_destroy->filosofs!=NULL){
        free (taula_destroy->filosofs);
    }

    if (taula_destroy->forquilles!=NULL){
        free (taula_destroy->forquilles);
    }
    free (taula_destroy);

    return true;
}

t_taula* taula_init(int init_filosofs){
    t_taula* taula = NULL;
    int iterador = 0;
    if (init_filosofs<=1){
        dprintf(STDERR_FILENO,COLOR_RED "Error: no es pot fer amb aquests número de filosofs\n" COLOR_RST);
        return NULL;
    }
    
    taula = malloc(sizeof(t_taula));
    if (taula==NULL) {
        dprintf(STDERR_FILENO,COLOR_RED "Error: al reservar la memoria de la taula\n" COLOR_RST);
        //perror("Error al reservar la memoria de la taula: ");
        return NULL;
    }
        
    taula->quantes_forquilles = init_filosofs;
    taula->forquilles = malloc(sizeof(t_forquilla)*taula->quantes_forquilles);
    if (taula->forquilles==NULL) {
        taula_destroy(taula);
        dprintf(STDERR_FILENO,COLOR_RED "Error: al reservar la memoria de les forquilles de la taula\n" COLOR_RST);
        //perror("Error al reservar la memoria de la taula: ");
        return NULL;
    }
    
    iterador = 0;
    while(iterador < taula->quantes_forquilles){
        taula->forquilles[iterador] = forquilla_init(iterador);
        iterador++;
    }
    

    taula->filosofs = malloc(sizeof(t_filosof)*init_filosofs);
    if (taula->filosofs==NULL) {
        taula_destroy(taula);
        dprintf(STDERR_FILENO,COLOR_RED "Error: al reservar la memoria dels filosofs de la taula\n" COLOR_RST);
        //perror("Error al reservar la memoria de la taula: ");
        return NULL;
    }
    taula->quants_filosofs = init_filosofs;

    iterador = 0;
    while(iterador < taula->quants_filosofs){
        taula->filosofs[iterador] = filosof_init(iterador,taula);
        iterador++;
    }

    taula->temps_menjar = 20;
    taula->temps_dormir = 20;
    taula->temps_morir = 20;
    taula->executa_simulacio = false;
    return taula;

}

void taula_debug(t_taula* taula_debug)
{
    int iterador;

    printf("Debug Taula**********************\n");
    if (taula_debug == NULL)
    {
        printf("\tTaula és NULL\n");
        return ;
    }
    iterador = 0;
    //filosofs.
    printf("\tFilosofs\n");
    while (iterador < taula_debug->quants_filosofs)
    {
        printf("\t\tid: %d\n", taula_debug->filosofs[iterador].id);
        printf("\t\testat: %d\n", taula_debug->filosofs[iterador].estat);
        printf("\t\ttxt_estat: %s\n", taula_debug->filosofs[iterador].txt_estat);
        iterador++;
    }
    printf("\tForquilles\n");
    iterador = 0;
    while (iterador < taula_debug->quantes_forquilles)
    {
        printf("\t\tid: %d\n", taula_debug->forquilles[iterador].id);
        iterador++;
    }
    printf("FI Debug Taula*******************\n");

}

void taula_iniciarSimulacio(t_taula* taula){
    int iterador = 0;
    taula->executa_simulacio = true;
    while (iterador<taula->quants_filosofs)
    {
        filosof_iniciarSimulacio(&taula->filosofs[iterador]);
        iterador++;
    }
}

void taula_pararSimulacio(t_taula* taula){
    int iterador = 0;
    taula->executa_simulacio = false;
    while (iterador<taula->quants_filosofs)
    {
        filosof_pararSimulacio(&taula->filosofs[iterador]);
        iterador++;
    }
}

void taula_filosofMort(t_taula* taula,t_filosof* filosof,t_timestamp horaDefuncio){
    
    printf("Filosof %d mort a les %lld\n",filosof->id,horaDefuncio);
    taula_pararSimulacio(taula);
}