#include <stdio.h>
#include <parser.h>

void	print_error(char *error_sentence, int error_code)
{
	printf("%s\nCode: %d\n", error_sentence, error_code);
	exit(-1);
}
