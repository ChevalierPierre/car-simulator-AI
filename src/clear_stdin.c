/*
** EPITECH PROJECT, 2018
** CPE_n4s_2017
** File description:
** A function to clear the programs standard input
*/

#include <stdio.h>
#include <stdlib.h>

void clear_stdin(void)
{
	char *line = NULL;
	size_t size = 0;

	getline(&line, &size, stdin);
	free(line);
}