/*
** EPITECH PROJECT, 2018
** CPE_n4s_2017
** File description:
** No description
*/

#ifndef CPE_N4S_2017_JOYSTICK_H
#define CPE_N4S_2017_JOYSTICK_H

#include <asm/types.h>
#include <linux/joystick.h>

#define BUTTONS 12
#define AXES 6

#define CHECK_BUTTON(i) joystick->buttons[(i)].state && \
	!joystick->buttons[(i)].checked

struct button {
	int state;
	int checked;
};

typedef struct joystick_s {
	struct button buttons[BUTTONS];
	__s16 axes[AXES];
	int fd;
} joystick_t;

joystick_t *init_joystick(char *name);
void update_joystick(joystick_t *joystick);

#endif //CPE_N4S_2017_JOYSTICK_H
