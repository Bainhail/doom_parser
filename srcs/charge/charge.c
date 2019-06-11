/*Ajoutez les includes necessaires*/
/*Include des fichiers "system"*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
/*Include des fichiers "non system"*/
#include <parser.h>

static void		read_float_from_file(int fd, float *var, int *offset)
{
	int		nb_before_coma;
	int		nb_after_coma;

	read_var_from_file(fd, &nb_before_coma, offset);
	read_var_from_file(fd, &nb_after_coma, offset);
	*var = (float)nb_before_coma + ((float)nb_after_coma / 1000);
}

static void		read_veclist_from_file(int fd, t_myvec **list, int nb_vertex, int *offset)
{
	float		x;
	float		y;
	float		z;
	t_myvec		*tmp;

	tmp = NULL;
	while (nb_vertex > 0)
	{
		read_float_from_file(fd, &x, offset);
		read_float_from_file(fd, &y, offset);
		read_float_from_file(fd, &z, offset);
		tmp = new_vector(x, y, z);
		pushback_vec(list, tmp);
		nb_vertex--;
	}
}

static void		read_polylist_from_file(int fd, t_mypolygon **list)
{
	int			nb_poly;
	t_mypolygon	*tmp;
	static int	offset = 0;

	read_var_from_file(fd, &nb_poly, &offset);
	while (nb_poly > 0)
	{
		tmp = new_empty_polygon();
		read_var_from_file(fd, &(tmp->number_of_vertex), &offset);
		read_var_from_file(fd, &(tmp->number_of_indices), &offset);
		read_veclist_from_file(fd, &(tmp->vertex_lst), tmp->number_of_vertex, &offset);
		pushback_poly(list, tmp);
		nb_poly--;
	}
}

void			charge(char *filename, t_mypolygon **list)
{
	int					fd;

	if ((fd = open(filename, O_RDONLY)) < 3)
		print_error("Wrong path", -2);
	read_polylist_from_file(fd, list);
	close(fd);
}
