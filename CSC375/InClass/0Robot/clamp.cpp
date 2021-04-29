#include "clamp.h"

void clamp::set_state() {
	if (state == "Open") {
		state = "Close";
	} else {
		state = "Open";
	}
}

std::string clamp::get_state() const {
	return state;
}
