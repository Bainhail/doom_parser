/*Ajoutez les includes necessaires*/
/*Include des fichiers "system"*/
#include <unistd.h>
#include <stdlib.h>
/*Include des fichiers "non system"*/
#include <parser.h>

static uint32_t	ft_power_up(uint32_t nb, uint32_t pow)
{
	if (pow == 0)
		return (1);
	if (pow == 1)
		return (nb);
	return (nb *= ft_power_up(nb, pow - 1));
}

void			readone_from_file(int fd, unsigned char *buf)
{
	*buf = 0;
	if (read(fd, buf, 1) < 0)
		print_error("Error read one from file", -3);
}

void			read_var_from_file(int fd, int *nb, int *offset)
{
	int				pow;
	unsigned char	buf[3];

	pow = 0;
	*nb = 0;
	lseek(fd, *offset, SEEK_SET);
	while (pow < 5)
	{
		readone_from_file(fd, &buf[0]);
		(*offset)++;
		readone_from_file(fd, &buf[1]);
		(*offset)++;
		readone_from_file(fd, &buf[2]);
		(*offset)++;
		*nb += ft_power_up((uint32_t)buf[0], \
							(uint32_t)buf[1]) * (uint32_t)buf[2];
		pow++;
	}
	(*offset)++;
}
