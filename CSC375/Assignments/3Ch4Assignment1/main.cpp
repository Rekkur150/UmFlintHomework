#include <iostream>

class ServerGroup {
public:
	//Constructors
	ServerGroup();
	ServerGroup(const int& elementsInArray);
	ServerGroup(const ServerGroup&);

	//Assignment Operator
	void operator = (const ServerGroup&);

	//Deconstructor
	~ServerGroup();

	//Accessor
	bool spServerFree();
	bool serverFree();

	//Mutator
	void useServer(const int& avTransTime);
 	void usespServer(const int& avTransTime);
	void decServers();

private:
	//Array
	int size;
	int* servers;

	//Other
	int spServer;
	int freeServer;

};

//Purpose: Default Constructor
//Preconditons: None
//Postconditions: None
ServerGroup::ServerGroup() {};

//Purpose: Create Server Group with a certain sized Servers array
//Precondtions: Size of array
//Postconditions: None
ServerGroup::ServerGroup(const int& elementsInArray) {
	size = elementsInArray;
	servers = new int[elementsInArray];

	for (int i = 0; i < size; i++) {
		servers[i] = 0;
	}
	spServer = 0;
}

//Purpose: Copy Constuctor
//Preconditions: ServerGroup Object
//Postconditions: None
ServerGroup::ServerGroup(const ServerGroup& a) {
	size = a.size;
	servers = new int[size];

	for (int i = 0; i < size; i++) {
		servers[i] = a.servers[i];
	}

	spServer = a.spServer;
}

//Purpose: To remove dynamic memory
//Precontions: None
//Postconditions: None
ServerGroup::~ServerGroup() {
	delete [] servers;
}

//Purpose: Assignment operator
//Preconditions: ServerGroup object
//Postconditions: None
void ServerGroup::operator = (const ServerGroup& temp) {
	size = temp.size;
	delete [] servers;
	servers = new int[size];

	for (int i = 0; i < size; i++) {
		servers[i] = temp.servers[i];
	}

	spServer = temp.spServer;
	freeServer = temp.freeServer;

}

//Purpose: To check if the spServerFree is set to 0
//Preconditions: None
//Postconditions: True if it is free, false it isn't
bool ServerGroup::spServerFree() {
	if (spServer == 0) {
		return true;
	}

	return false;
}

//Purpose: To see if there an free server in servers array
//Precontions: None
//Postconditions: True if there is a free server, false is there isn't
bool ServerGroup::serverFree() {

	bool foundZero = false;

	for (int i = 0; i < size; i++) {
		if (servers[i] == 0) {
			foundZero = true;
			freeServer = i;
			break;
		}
	}

	return foundZero;
}

//Purpose:: Uses a server that is free in the servers array
//Preconditions: avTransTime
//Postconditions: None
void ServerGroup::useServer(const int& avTransTime) {
	servers[freeServer] = avTransTime;
}

//Purpose: Set the spServer to avTransTime
//Precondtions: AvTransTime
//Postconditions: None
void ServerGroup::usespServer(const int& avTransTime) {
	spServer = avTransTime;
}

//Purpose: To dec all servers in the servers array
//Precondtions: None
//Postconditions: None
void ServerGroup::decServers() {
	if (spServer != 0) {
		spServer--;
	}

	for (int i = 0; i < size; i++) {
		if (servers[i] != 0) {
			servers[i]--;
		}
	}
}

int main() {


	return 0;
}
