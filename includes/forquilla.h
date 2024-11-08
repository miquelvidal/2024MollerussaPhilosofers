#ifndef FORQUILLA_H
# define FORQUILLA_H


typedef struct s_forquilla
{
    //el id servirà per nom, posició i identificador.
    int id;

} t_forquilla;

t_forquilla forquilla_init(int id);

#endif