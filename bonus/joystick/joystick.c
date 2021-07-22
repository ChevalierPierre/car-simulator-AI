/*
** EPITECH PROJECT, 2018
** CPE_n4s_2017
** File description:
** No description
*/

#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <linux/joystick.h>
#include <stdlib.h>
#include <errno.h>
#include <values.h>
#include <unistd.h>
#include "joystick.h"

void show_joystick_info(int fd)
{
	char name[128];

	if (ioctl(fd, JSIOCGNAME(sizeof(name)), name) < 0)
		strncpy(name, "Unknown", sizeof(name));
	fprintf(stderr, "Joystick name: %s\n", name);
}

joystick_t *fill_joystick(int fd)
{
	joystick_t *joystick = malloc(sizeof(joystick_t));

	memset(joystick->axes, 0, sizeof(joystick->axes));
	memset(joystick->buttons, 0, sizeof(joystick->buttons));
	joystick->fd = fd;
	return joystick;
}

joystick_t *init_joystick(char *name)
{
	char path[PATH_MAX];
	int fd;

	memset(path, 0, sizeof(path));
	strncat(path, "/dev/input/", 11);
	strncat(path, name, PATH_MAX - 12);
	fd = open(path, O_RDONLY | O_NONBLOCK);
	if (fd == -1) {
		fprintf(stderr, "Could not find a joystick\n");
		return NULL;
	}
	show_joystick_info(fd);
	return fill_joystick(fd);
}

void process_event(joystick_t *joystick, struct js_event e)
{
	e.type &= ~JS_EVENT_INIT;
	if (e.type == JS_EVENT_BUTTON && e.number < BUTTONS) {
		joystick->buttons[e.number].state = e.value;
		joystick->buttons[e.number].checked = 0;
	} else if (e.type == JS_EVENT_AXIS && e.number < AXES) {
		joystick->axes[e.number] = e.value;
	} else {
		fprintf(stderr, "Weird event detected : type :%d, "
		  "number : %d\n", e.type, e.number);
	}
}

void update_joystick(joystick_t *joystick)
{
	struct js_event e;

	while (read(joystick->fd, &e, sizeof(e)) > 0) {
		process_event(joystick, e);
	}
	if (errno != EAGAIN) {
		free(joystick);
		exit(84);
	}
}