#include "robot.h"
#include <iostream>

robot::robot() {}

void robot::pick_up_at(int b_in, int s_in, int e_in, int w_in) {
	go_to_position(b_in, s_in, e_in, w_in);
	hand.set_state();
	std::cout << "hand state = " << hand.get_state() << std::endl;

}

void robot::drop_off_at(int b_in, int s_in, int e_in, int w_in) {
	go_to_position(b_in, s_in, e_in, w_in);
	hand.set_state();
	std::cout << "hand state = " << hand.get_state() << std::endl;
}

void robot::go_to_position(int b_in, int s_in, int e_in, int w_in) {
	while (base.get_positions() != b_in || shoulder.get_positions() != s_in || elbow.get_positions() != e_in || wrist.get_positions() != w_in) {
		base.go_to_position(b_in);
		shoulder.go_to_position(s_in);
		elbow.go_to_position(e_in);
		wrist.go_to_position(w_in);

		display_position();
	}
}

void robot::display_position() {
	std::cout << "base = " << base.get_positions() << " shoulder = " << shoulder.get_positions() << " elbow = " << elbow.get_positions() << " wrist = " << wrist.get_positions() << std::endl;
}
