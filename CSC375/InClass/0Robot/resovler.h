#ifndef RESOLVER_H
#define RESOLVER_H

class resolver {

public:

	void go_to_position(int p_in);
	int get_positions() const;

private:
	int position = 0;

};

#endif
