/*
** EPITECH PROJECT, 2018
** n4s
** File description:
** Gets LIDAR information and takes decisions
*/

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "n4s.h"
#include "commands.h"

double *get_lidar_info(void)
{
	char *line = NULL;
	size_t size = 0;
	double *infos;

	printf(INFOLI);
	getline(&line, &size, stdin);
	fprintf(stderr, "LIDAR: %s", line);
	infos = strtoftab(line);
	return (infos);
}

double calc_speed(double wall)
{
	if (wall > 1200)
		return 0.7;
	if (wall > 1000)
		return 0.4;
	if (wall > 700)
		return 0.25;
	if (wall > 600)
		return 0.2;
	if (wall > 400)
		return 0.1;
	return (0.05);
}

double wheels_dir(double *lidar)
{
	double mid = lidar[17];
	double coeff = lidar[2] < lidar[29] ? -1 : 1;

	if (mid > 1200)
		return (coeff * 0.05);
	if (mid > 1000)
		return (coeff * 0.1);
	if (mid > 700)
		return (coeff * 0.15);
	if (mid > 600)
		return (coeff * 0.2);
	if (mid > 400)
		return (coeff * 0.3);
	if (mid > 200)
		return (coeff * 0.4);
	return (coeff * 0.55);
}

char *handle_direction(void)
{
	double *infos = get_lidar_info();

	printf(FWD, calc_speed(infos[17]));
	clear_stdin();
	printf(WDIR, wheels_dir(infos));
	clear_stdin();
	return (strtok(NULL, ":"));
}
