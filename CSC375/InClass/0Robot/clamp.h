#ifndef CLAMP_H
#define CLAMP_H

#include <string>

class clamp {
private:
	std::string const OPEN = "Open";
	std::string const CLOSE = "Close";

	std::string state = OPEN;

public:

	void set_state();
	std::string get_state() const;

};

#endif
