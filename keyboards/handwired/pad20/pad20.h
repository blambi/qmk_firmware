#ifndef GAMENUM_H
#define GAMENUM_H

#include "quantum.h"

// Just to make it less painful to remember
#define PIN_CLEAR(PORT, PIN) PORT &= ~(1<<PIN)
#define PIN_SET(PORT, PIN) PORT |= (1<<PIN)

#define KEYMAP( \
	k00, k01, k02, k03, \
	k10, k11, k12, k13, \
	k20, k21, k22, k23, \
	k30, k31, k32, k33, \
	k40, k41, k42, k43   \
) \
{ \
	{ k00, k01, k02, k03}, \
	{ k10, k11, k12, k13}, \
	{ k20, k21, k22, k23}, \
	{ k30, k31, k32, k33}, \
	{ k40, k41, k42, k43}  \
}

#endif
