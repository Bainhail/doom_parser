#include <stdlib.h>
#include <parser.h>

t_myvec			*vec_list_creation()
{
	int		i;
	float	x;
	float	y;
	float	z;
	t_myvec	*list;
	t_myvec	*vec;

	x = 0.5f;
	y = -42.865f;
	z = 2094.8974651f;
	list = NULL;
	vec = NULL;
	i = 0;
	/*modifier le chiffre pour ajouter ou supprimer le nombre de vertex par polygone*/
	while (i < 7/*<--*/)
	{
		if ((vec = new_vector(x + i, y + i, z + i)) == NULL)
			print_error("Erreur dans creation vecteur", -4);
		pushback_vec(&list, vec);
		i++;
	}
	vec = NULL;
	return (list);
}

t_mypolygon		*poly_list_creation()
{
	int			i;
	t_myvec		normal;
	t_mypolygon	*list;
	t_mypolygon	*poly;

	i = 0;
	normal.x = 0.0f;
	normal.y = 0.0f;
	normal.z = 0.0f;
	normal.next = NULL;
	/*modifier le chiffre pour ajouter ou supprimer le nombre de polygone*/
	while (i < 18/*<--*/)
	{
		/*modifier le chiffre pour ajouter ou supprimer le nombre de vertex par polygone*/
		if ((poly = new_polygon(vec_list_creation(), normal, 7/*<--*/, 0, NULL)) == NULL)
			print_error("Erreur dans creation polygon", -5);
		pushback_poly(&list, poly);
		i++;
	}
	poly = NULL;
	return (list);
}

t_mywin			test_creation()
{
	t_mywin		w;

	if ((w.polygon_lst = poly_list_creation()) == NULL)
			print_error("Erreur dans creation", -6);
	return (w);
}
