#include "resovler.h"

const int MIN_P = 0;
const int MAX_P = 9;


void resolver::go_to_position(int p_in) {
	if (p_in != position) {
		if (p_in < position && p_in >= MIN_P) {
			position--;
		}

		if (p_in > position && p_in <= MAX_P) {
			position++;
		}
	}
}

int resolver::get_positions() const {
	return position;
}
