#include <parser.h>

int		main(int ac, char **av)
{
	t_mypolygon	*list;
	t_mypolygon	*tmp;
	t_myvec		*vec_tmp;

	list = NULL;
	if (ac != 2)
		print_error("Usage: ./charge_test [filepath]\n", -2);
	charge(av[1], &list);
	if (list != NULL)
	{
		tmp = list;
		while (tmp != NULL)
		{
			vec_tmp = tmp->vertex_lst;
			printf("%d\n", tmp->number_of_vertex);
			while (vec_tmp != NULL)
			{
				printf("x = %.3f, y = %.3f, z = %.3f\n", vec_tmp->x, vec_tmp->y, vec_tmp->z);
				vec_tmp = vec_tmp->next;
			}
			tmp = tmp->next;
		}
		/*commenter la ligne suivante pour ne pas free la liste*/
		poly_destruct(&list);
	}
	return (0);
}
