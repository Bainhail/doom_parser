#include <stdlib.h>
#include <parser.h>

/*
**	Fonction pour gerer la Creation,
**	Ajout et Destruction de VECTEUR.
**				DEBUT
*/
t_myvec			*new_vector(float x, float y, float z)
{
	t_myvec		*new_vec;

	if ((new_vec = (t_myvec*)malloc(sizeof(t_myvec))) == NULL)
		return (NULL);
	new_vec->x = x;
	new_vec->y = y;
	new_vec->z = z;
	new_vec->next = NULL;
	return (new_vec);
}

void			pushback_vec(t_myvec **start, t_myvec *vec)
{
	t_myvec	*tmp;

	if (start != NULL && *start != NULL && vec != NULL)
	{
		tmp = *start;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = vec;
	}
	else if (start != NULL && *start == NULL && vec != NULL)
		*start = vec;
}

int				vec_listlen(const t_myvec *start)
{
	int			i;

	i = 0;
	if (start != NULL)
	{
		while (start != NULL)
		{
			i++;
			start = start->next;
		}
	}
	return (i);
}

void			vec_destruct(t_myvec **start)
{
	t_myvec	*tmp;

	if (start != NULL)
	{
		while (*start != NULL)
		{
			tmp = (*start)->next;
			free(*start);
			*start = tmp;
		}
		*start = NULL;
	}
}
/*
**	Fonction pour gerer la Creation,
**	Ajout et Destruction de VECTEUR.
**				 FIN
*/

/*
**	Fonction pour gerer la Creation,
**	Ajout et Destruction de POLYGONE.
**				DEBUT
*/
t_mypolygon		*new_polygon(t_myvec *vl, t_myvec nm, int nb_vertex, int nb_indices, int *indices)
{
	t_mypolygon		*poly;

	if ((poly = (t_mypolygon*)malloc(sizeof(t_mypolygon))) == NULL)
		return (NULL);
	poly->vertex_lst = vl;
	poly->normal = nm;
	poly->number_of_vertex = nb_vertex;
	poly->number_of_indices = nb_indices;
	poly->indices = indices;
	poly->next = NULL;
	return (poly);
}

void			pushback_poly(t_mypolygon **start, t_mypolygon *poly)
{
	t_mypolygon	*tmp;

	if (start != NULL && *start != NULL && poly != NULL)
	{
		tmp = *start;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = poly;
	}
	else if (start != NULL && *start == NULL && poly != NULL)
		*start = poly;
}

int				poly_listlen(const t_mypolygon *start)
{
	int			i;

	i = 0;
	if (start != NULL)
	{
		while (start != NULL)
		{
			i++;
			start = start->next;
		}
	}
	return (i);
}

void			poly_destruct(t_mypolygon **start)
{
	t_mypolygon	*tmp;

	if (start != NULL)
	{
		while (*start != NULL)
		{
			tmp = (*start)->next;
			vec_destruct(&((*start)->vertex_lst));
			free(*start);
			*start = tmp;
		}
		*start = NULL;
	}
}

/*
**	Fonction pour gerer la Creation,
**	Ajout et Destruction de POLYGONE.
**				 FIN
*/
