#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <parser.h>

void	charge(char *filename, t_mypolygon *list)
{
	int					fd;

	(void)list;
	if ((fd = open(filename, O_RDONLY)) < 3)
		print_error("Wrong path", -2);
	close(fd);
}
