/*Ajoutez les includes necessaires*/
/*Include des fichiers "system"*/
#include <unistd.h>
#include <stdlib.h>
/*Include des fichiers "non system"*/
#include <parser.h>

void			readone_from_file(int fd, unsigned char **buf)
{
	if (read(fd, *buf, 4) < 0)
		print_error("Error read one from file", -3);
}

void			read_var_from_file(int fd, int *nb, int *offset)
{
	int				pow;
	unsigned char	*buf;

	pow = 0;
	*nb = 0;
	if ((buf = (unsigned char*)malloc(sizeof(unsigned char) * 4)) == NULL)
		return ;
	lseek(fd, *offset, SEEK_SET);
	readone_from_file(fd, &buf);
	(*offset) += 4;
	while (pow < 4)
	{
		*nb += (uint32_t)buf[pow] << (8 * pow);
		pow++;
	}
	if (buf != NULL)
		free(buf);
}
