#ifndef ROBOT_H
#define ROBOT_H

#include "resovler.h"
#include "clamp.h"
class robot {

private:
	resolver base;
	resolver shoulder;
	resolver elbow;
	resolver wrist;
	clamp hand;

	void go_to_position(int b_in, int s_in, int e_in, int w_in1);

public:
	robot();

	void drop_off_at(int b_in, int s_in, int e_in, int w_in);
	void pick_up_at(int b_in, int s_in, int e_in, int w_in);
	void display_position();
};

#endif
