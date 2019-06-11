#ifndef		PARSER_H
# define	PARSER_H

#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

/*
** Les enums et structure suivante
** sont a commenter si vous utiliser
** les fichiers de Cosmin.
*/

typedef enum	e_myclass
{
	FRONT,
	BACK,
	SPANNING,
	ON_PLANE,
}				t_myclass;

typedef struct	s_myvec
{
	float				x;
	float				y;
	float				z;
	struct s_myvec		*next;
}				t_myvec;

//indice allow you to build multiple triangles using share vectices
typedef struct	s_mypolygon
{
	t_myvec				*vertex_lst;             //liste des vertex
	t_myvec				normal;                  //la normal au polygon
	int					number_of_vertex;        //nombre de vertex
	int					number_of_indices;       //nombre d'indices
	int					*indices;                //la listes des indices apres triangulation
	struct s_mypolygon	*next;                   //le prochain noeud dans la liste
}				t_mypolygon;

//structure principale
typedef struct	s_mywin
{
	t_mypolygon			*polygon_lst;
}				t_mywin;

//structure pour le bsp
/* typedef struct	s_mynode */
/* { */
/* 	t_mypolygon			*splitter; */
/* 	struct s_mynode		*front; */
/* 	struct s_mynode		*back; */
/* 	char				is_leaf; */
/* 	char				is_solid; */
/* }				t_mynode; */

void			print_error(char *error, int code);

/*
**	GESTION DE SAUVEGARDE
*/
void			putone_to_file(int fd, unsigned char buf);
void			put_var_to_file(int fd, uint32_t nb);
void			sauvegarde(char *filename, t_mypolygon **list);

/*
**	GESTION DE CHARGEMENT
*/
void			readone_from_file(int fd, unsigned char *buf);
void			read_var_from_file(int fd, int *nb, int *offset);
void			charge(char *filename, t_mypolygon **list);

/*
**	Fonction de TEST
**	GESTION DES LISTS
*/
t_myvec			*new_vector(float x, float y, float z);
void			pushback_vec(t_myvec **start, t_myvec *vec);
int				vec_listlen(const t_myvec *start);
void			vec_destruct(t_myvec **start);

t_mypolygon		*new_polygon(t_myvec *vl, t_myvec nm, int nb_vertex, int nb_indices, int *indices);
t_mypolygon		*new_empty_polygon(void);
void			pushback_poly(t_mypolygon **start, t_mypolygon *poly);
int				poly_listlen(const t_mypolygon *start);
void			poly_destruct(t_mypolygon **start);

/*
**	Fonction de
**		TEST
*/
t_myvec			*vec_list_creation();
t_mypolygon		*poly_list_creation();
t_mywin			test_creation();

#endif
