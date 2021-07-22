/*
** EPITECH PROJECT, 2018
** CPE_n4s_2017
** File description:
** No description
*/

#include <stdlib.h>
#include <stdio.h>
#include <values.h>
#include <unistd.h>
#include "joystick.h"
#include "commands.h"

int check_startstop(joystick_t *joystick)
{
	if (CHECK_BUTTON(9)) {
		printf(START);
		joystick->buttons[9].checked = 1;
	} else if (CHECK_BUTTON(8)) {
		printf(STOP);
		joystick->buttons[8].checked = 1;
	}
	return 1;
}

void get_speed(joystick_t *joystick)
{
	double speed;
	static double backup = 0;

	if (joystick->axes[1] != 0) {
		speed = -(joystick->axes[1] * 1.0 / MAXSHORT);
		if (speed == backup)
			return;
		backup = speed;
		if (speed > 0)
			printf(FWD, speed);
		else
			printf(BCK, -speed);
	}
}

void get_direction(joystick_t *joystick)
{
	double direction;
	static double backup = 0;

	if (joystick->axes[2] != 0) {
		direction = -(joystick->axes[2] * 1.0 / MAXSHORT) / 5;
		if (direction == backup)
			return;
		backup = direction;
		printf(WDIR, direction);
	}
}

int handle_game(joystick_t *joystick)
{
	int run;

	update_joystick(joystick);
	run = check_startstop(joystick);
	get_speed(joystick);
	get_direction(joystick);
	return run;
}

int main(void)
{
	joystick_t *joystick = init_joystick("js0");
	int run = 1;

	setbuf(stdout, NULL);
	if (joystick == NULL)
		return 84;
	while (run) {
		run = handle_game(joystick);
		usleep(250000);
	}
	sleep(2);
	return 0;
}