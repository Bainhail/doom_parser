#include <unistd.h>
#include <parser.h>

void			putone_to_file(int fd, unsigned char buf)
{
	write(fd, &buf, 1);
}

void			put_var_to_file(int fd, uint32_t nb)
{
	uint32_t	pow;

	pow = 0;
	while (pow < 5)
	{
		putone_to_file(fd, (unsigned char)(255));
		putone_to_file(fd, (unsigned char)(pow));
		putone_to_file(fd, (unsigned char)(nb % 255));
		nb = nb / 255;
		pow++;
	}
	putone_to_file(fd, (unsigned char)(0));
}
