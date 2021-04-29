#include <iostream>
#include "resovler.h"
#include "clamp.h"
#include "robot.h"

int main() {

	resolver tmp;
	clamp clampy;

	robot bob;

	bob.display_position();
	int i = 0;

	while (i < 10) {
		bob.pick_up_at(5,4,3,2);
		bob.drop_off_at(2,3,4,5);
		i++;
	}

	return 0;

}
