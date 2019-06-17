/*Ajoutez les includes necessaires*/
/*Include des fichiers "system"*/
#include <unistd.h>
/*Include des fichiers "non system"*/
#include <parser.h>

void			putone_to_file(int fd, unsigned char buf)
{
	write(fd, &buf, 1);
}

void			put_var_to_file(int fd, uint32_t nb)
{
	uint32_t	cpy;

	cpy = (nb & 0xff);
	putone_to_file(fd, (unsigned char)(cpy));
	cpy = (nb & 0xff00);
	putone_to_file(fd, (unsigned char)(cpy >> 8));
	cpy = (nb & 0xff0000);
	putone_to_file(fd, (unsigned char)(cpy >> 16));
	cpy = (nb & 0xff000000);
	putone_to_file(fd, (unsigned char)(cpy >> 24));
}
