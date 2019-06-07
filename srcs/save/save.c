#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <parser.h>

void	sauvegarde(char *filename, t_mypolygon **list)
{
	int					fd;

	(void)list;
	if ((fd = open(filename, O_CREAT | O_RDWR, S_IRUSR \
					| S_IWUSR | S_IRGRP | S_IROTH)) < 3)
		print_error("Wrong path", -2);
	close(fd);
}
