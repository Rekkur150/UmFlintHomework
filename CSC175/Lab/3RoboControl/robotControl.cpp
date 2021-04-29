#include <iostream>
using namespace std;

const int MAX = 9;
const int MIN = 0;

struct Joint { //Default public, class default private

	private:

	int position = 0;

	public:

	Joint() {};

	void set_position(int pos) {
		if (pos >= MIN && pos <= MAX) {
			if (position < pos) {
				position++;
			} else if (position > pos) {
				position--;
			}
		}
	}

	int get_position() {
		return position;
	}
};

struct Clamp { //OF GOD!
	private:
	bool state = false;

	public:

	bool is_open() {
		return state;
	}

	bool open() {
		state = true;
	}

	bool close() {
		state = false;
	}
};

struct Robot {

private:
	Joint base;
	Joint shoulder;
	Joint elbow;
	Joint wrist;
	Clamp hand;

	int get_base_position();
	int get_shoulder_position();
	int get_elbow_position();
	int get_wrist_position();
	bool get_hand_state();

	void set_base_position(int pos);
	void set_shoulder_position(int pos);
	void set_elbow_position(int pos);
	void set_wrist_position(int pos);
	void open_hand();
	void close_hand();

public:

	Robot() {}

	void go_to_position(int pos0,int pos1,int pos2,int pos3);
	void pick_up_at(int pos0, int pos1, int pos2, int pos3);
	void drop_off_at(int pos0, int pos1, int pos2, int pos3);

	void display_position();
};

void Robot::go_to_position(int pos0,int pos1,int pos2,int pos3) {
	while (get_base_position() != pos0 || get_shoulder_position() != pos1 || get_elbow_position() != pos2 || get_wrist_position() != pos3) {
		display_position();
		set_base_position(pos0);
		set_shoulder_position(pos1);
		set_elbow_position(pos2);
		set_wrist_position(pos3);
	}
}

int Robot::get_base_position() {
	return base.get_position();
}

int Robot::get_shoulder_position() {
	return shoulder.get_position();
}
int Robot::get_elbow_position() {
	return elbow.get_position();
}
int Robot::get_wrist_position() {
	return wrist.get_position();
}
bool Robot::get_hand_state() {
	return hand.is_open();
}
void Robot::set_base_position(int pos) {
	base.set_position(pos);
}
void Robot::set_shoulder_position(int pos) {
	shoulder.set_position(pos);
}
void Robot::set_elbow_position(int pos) {
	elbow.set_position(pos);
}
void Robot::set_wrist_position(int pos) {
	wrist.set_position(pos);
}

void Robot::close_hand() {
	hand.close();
}

void Robot::open_hand() {
	hand.open();
}

void Robot::display_position() {
	cout << "base_position = " << get_base_position() << endl
	     << "shoulder_position = " << get_shoulder_position() << endl
	     << "elbow_position = " << get_elbow_position() << endl
	     << "wrist_position = " << get_wrist_position() << endl
	     << "is_hand_open = " << get_hand_state() << endl;
}

void Robot::pick_up_at(int pos0, int pos1, int pos2, int pos3) {
	open_hand();
	go_to_position(pos0,pos1,pos2,pos3);
	close_hand();
}

void Robot::drop_off_at(int pos0, int pos1, int pos2, int pos3) {
	close_hand();
	go_to_position(pos0,pos1,pos2,pos3);
	open_hand();
}
int main() {

	Robot a;
	a.display_position();

	a.go_to_position(1,2,3,4);
	a.display_position();

	return 0;
}
