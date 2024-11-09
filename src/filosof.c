#include "filosof.h"

t_filosof filosof_init(int id,t_taula* taula){
    t_filosof filosof;
    filosof.id = id;
    filosof.estat = FILOSOF_ESTAT_PENSANT;
    filosof.txt_estat = FILOSOF_TXT_ESTAT_PENSANT;
    filosof.taula = taula;
    filosof.forquilla_dreta=NULL;
    filosof.forquilla_esquerra=NULL;
    filosof.id_thread=-1;
    filosof.ultim_menjar=-1;
    return filosof;
}

void filosof_domir(t_filosof* filosof)
{
    (*filosof).estat = FILOSOF_ESTAT_DORMINT;
    (*filosof).txt_estat = FILOSOF_TXT_ESTAT_DORMINT;
}
void filosof_menjar(t_filosof* filosof)
{
    (*filosof).estat = FILOSOF_ESTAT_MENJANT;
    (*filosof).txt_estat = FILOSOF_TXT_ESTAT_MENJANT;
}
void filosof_pensar(t_filosof* filosof)
{
    (*filosof).estat = FILOSOF_ESTAT_PENSANT;
    (*filosof).txt_estat = FILOSOF_TXT_ESTAT_PENSANT;
}

void filosof_iniciarSimulacio(t_filosof* filosof){
    
    t_timestamp time; 
    pthread_t id_thread;
    pthread_create(&id_thread,NULL,filosof_menjant,filosof);
    time = utilitats_obte_timestamp();
    filosof->id_thread = id_thread;
    filosof->ultim_menjar = time;
}


void filosof_pararSimulacio(t_filosof* filosof){
    
    t_timestamp time; 
    pthread_join(filosof->id_thread,NULL);

    time = utilitats_obte_timestamp();

    printf("Hola soc el filosof %d estic parant thread al ts %lld \n",filosof->id, time);

}

//el cicle de vida del filosof
void* filosof_menjant(void* void_filosof){
    t_filosof* filosof = (t_filosof*) void_filosof;
    t_timestamp time; 
    /*
    t_timestamp time; 
    time = utilitats_obte_timestamp();
    printf("Hola soc el filosof %d estic %s amb ts %lld\n",filosof->id,filosof->txt_estat, time);
    */
    //cicle de vida
    while(filosof->taula->executa_simulacio) 
    {
        time = utilitats_obte_timestamp();
      //  if ((time-filosof->ultim_menjar)>filosof->taula->temps_morir)
      //      taula_filosofMort(filosof->taula,filosof,time);
      //  else
            printf("Hola soc el filosof %d estic %s amb ts %lld\n",filosof->id,filosof->txt_estat, time);
        sleep(1);
    }
    

    return void_filosof;
}

void filosof_assignarForquilles(t_filosof* filosof,t_forquilla* forquilla_esquerra,t_forquilla* forquilla_dreta){
    filosof->forquilla_dreta = forquilla_dreta;
    filosof->forquilla_esquerra = forquilla_esquerra;
}