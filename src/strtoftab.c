/*
** EPITECH PROJECT, 2018
** n4s
** File description:
** Splits a string into an array of doubles.
*/

#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

char **split_by(char const *, char);

double *strtoftab(char *str)
{
	double *dtab = malloc(sizeof(double) * 32);
	char *buf;

	if (!dtab)
		exit(84);
	strtok(str, ":");
	for (int i = 0; i < 2; i++)
		strtok(NULL, ":");
	for (int i = 0; i < 32; i++) {
		buf = strtok(NULL, ":");
		if (!buf)
			exit(84);
		dtab[i] = atof(buf);
	}
	return (dtab);
}
