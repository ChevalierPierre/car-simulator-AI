/*
** EPITECH PROJECT, 2018
** n4s
** File description:
** Main
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "n4s.h"
#include "commands.h"

void start(void)
{
	char *line = NULL;
	size_t size = 0;
	ssize_t tmp;

	setbuf(stdout, NULL);
	printf(START);
	tmp = getline(&line, &size, stdin);
	if (tmp < 0)
		exit(84);
	printf(FWD, 0.35);
	tmp += getline(&line, &size, stdin);
	if (tmp < 0) {
		free(line);
		exit(84);
	}
	free(line);
}

int handle_run(void)
{
	int run = 1;
	char *info;

	info = handle_direction();
	if (strcmp(info, "Track Cleared") == 0) {
		printf(FWD, 0.0);
		run = 0;
	}
	return (run);
}

int main(void)
{
	int run = 1;

	start();
	while (run)
		run = handle_run();
	sleep(8);
	printf(STOP);
}
