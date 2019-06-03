#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

void	print_error(char *error_sentence, int error_code)
{
	printf("%s\nCode: %d\n", error_sentence, error_code);
	exit(-1);
}

void	putone_to_file(int fd, unsigned char buf)
{
	write(fd, &buf, 1);
}

uint32_t	ft_power_up(uint32_t nb, uint32_t pow)
{
	if (pow == 0)
		return (1);
	if (pow == 1)
		return (nb);
	return (nb *= ft_power_up(nb, pow - 1));
}

void	readone_from_file(int fd, unsigned char *buf)
{
	*buf = 0;
	if (read(fd, buf, 1) < 0)
		print_error("Error read one from file\n", -3);
}

void	read_var_from_file(int fd, int *nb, int *offset)
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
		*nb += ft_power_up((uint32_t)buf[0], (uint32_t)buf[1]) * (uint32_t)buf[2];
		pow++;
	}
	(*offset)++;
}

void	put_var_to_file(int fd, uint32_t nb)
{
	uint32_t	pow;
	uint32_t	mult;

	pow = 0;
	mult = 0;
	while (pow < 5)
	{
		mult = nb / 255;
		putone_to_file(fd, (unsigned char)(255));
		putone_to_file(fd, (unsigned char)(pow));
		putone_to_file(fd, (unsigned char)(nb % 255));
//		printf("mult = %d\ncpy / 255 reste = %d\npow = %d\n\n", mult, nb % 255, pow);
		nb = nb / 255;
		pow++;
	}
	putone_to_file(fd, (unsigned char)(0));
}

int		main(int ac, char **av)
{
	int					fd;
	int					nb_res;
	char				c;
	uint32_t			nb1;
	uint32_t			nb2;
	static int			offset = 0;

	nb1 = -2;
	nb2 = 521;
	c = '\n';
	printf("nb1 = %u, nb2 = %u\n", nb1, nb2);
	printf("nb1 = %d, nb2 = %d\n", nb1, nb2);
	if (ac != 2)
		print_error("Usage: ./exec [file_path]", -1);
	if ((fd = open(av[1], O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 3)
		print_error("Wrong path", -2);
	printf("Creation et ouverture du fichier \"%s\" -> le file descritor est %d\n", av[1], fd);
/*Debut du traitement de fichier*/
	printf("print nb1\n");
	put_var_to_file(fd, nb1);
	printf("print nb2\n");
	put_var_to_file(fd, nb2);
	printf("print c\n");
	put_var_to_file(fd, c);

	read_var_from_file(fd, &nb_res, &offset);
	printf("nb = %d\n", nb_res);
	read_var_from_file(fd, &nb_res, &offset);
	printf("nb = %d\n", nb_res);
	read_var_from_file(fd, &nb_res, &offset);
	printf("nb = %c\n", (char)nb_res);
/**/
	close(fd);
	return(0);
}
