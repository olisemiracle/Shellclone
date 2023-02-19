#include "main.h"
/**
 * main - main finction of shell
 * @argc: total argument count
 * @argv: argument vector
 * Return:program
 */
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	var_t var[] = {NULL, 0};



	loop(var);
	return (0);
}
