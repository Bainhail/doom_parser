#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <parser.h>

static void		put_float_to_file(int fd, float var)
{
	int			deci;

	deci = (var - (int)var) * 1000;
	put_var_to_file(fd, (int)var);
	put_var_to_file(fd, (int)deci);
}

static void		put_veclist_to_file(int fd, t_myvec **list, int nb)
{
	int			i;
	t_myvec		*tmp;

	i = 0;
	tmp = *list;
	while (i < nb)
	{
		put_float_to_file(fd, tmp->x);
		put_float_to_file(fd, tmp->y);
		put_float_to_file(fd, tmp->z);
		tmp = tmp->next;
		i++;
	}
}

static void		put_polylist_to_file(int fd, t_mypolygon **list)
{
	t_mypolygon	*tmp;

	if (list != NULL && *list != NULL)
	{
		tmp = *list;
		while (tmp != NULL)
		{
			put_var_to_file(fd, tmp->number_of_vertex);
			put_var_to_file(fd, tmp->number_of_indices);
			put_veclist_to_file(fd, &(tmp->vertex_lst), tmp->number_of_vertex);
			tmp = tmp->next;
		}
	}
}

void			sauvegarde(char *filename, t_mypolygon **list)
{
	int			fd;

	(void)list;
	if ((fd = open(filename, O_CREAT | O_RDWR, S_IRUSR \
					| S_IWUSR | S_IRGRP | S_IROTH)) < 3)
		print_error("Wrong path", -2);
	put_polylist_to_file(fd, list);
	close(fd);
}
