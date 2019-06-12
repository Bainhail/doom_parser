/*Ajoutez les includes necessaires*/
/*Include des fichiers "system"*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
/*Include des fichiers "non system"*/
#include <parser.h>

static void		put_float_to_file(int fd, float var)
{
	int			deci;

	deci = (var - (int)var) * 1000;
	put_var_to_file(fd, (int)var);
	put_var_to_file(fd, (int)deci);
}

static int		put_veclist_to_file(int fd, t_myvec **list, int nb)
{
	int			i;
	t_myvec		*tmp;

	i = 0;
	if (list != NULL && *list != NULL)
	{
		tmp = *list;
		while (i < nb && tmp != NULL)
		{
			put_float_to_file(fd, tmp->x);
			put_float_to_file(fd, tmp->y);
			put_float_to_file(fd, tmp->z);
			tmp = tmp->next;
			i++;
		}
		if (tmp == NULL && i < nb)
			return (-1);
	}
	return (0);
}

static void		put_polylist_to_file(int fd, t_mypolygon **list)
{
	t_mypolygon	*tmp;

	if (list != NULL && *list != NULL)
	{
		tmp = *list;
		put_var_to_file(fd, poly_listlen(tmp));
		while (tmp != NULL)
		{
			put_var_to_file(fd, tmp->number_of_vertex);
			put_var_to_file(fd, tmp->number_of_indices);
			if (put_veclist_to_file(fd, &(tmp->vertex_lst), tmp->number_of_vertex) < 0)
			{
				poly_destruct(list);
				print_error("put_veclist_to_file:\nNombre de vertex FAUX", -7);
			}
			tmp = tmp->next;
		}
	}
}

void			sauvegarde(char *filename, t_mypolygon **list)
{
	char		c;
	char		buf[4];
	int			fd;

	buf[0] = '\0';
	if ((fd = open(filename, O_CREAT | O_RDWR, S_IRUSR \
						| S_IWUSR | S_IRGRP | S_IROTH)) < 3)
		print_error("Wrong path", -2);
	if (read(fd, &c, 1) == 1)
	{
		write(1, "le fichier n'est pas vide\n", 26);
		while (strcmp(buf, "oui") != 0 && strcmp(buf, "non") != 0)
		{
			write(1, "Voulez-vous ecraser les donnees ?[oui][non]:\n", 46);
			read(0, buf, 4);
			buf[3] = '\0';
		}
		lseek(fd, 0, SEEK_SET);
		(strcmp(buf, "oui") == 0) ? put_polylist_to_file(fd, list) : close(fd);
	}
	else
		put_polylist_to_file(fd, list);
	/*commenter la ligne suivante pour ne pas free la liste*/
	poly_destruct(list);
	close(fd);
}
