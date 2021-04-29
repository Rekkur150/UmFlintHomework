#include <iostream>

//------------------------
// Car
//------------------------

struct Car {

	Car(const std::string& carModel);
	Car(const std::string& carModel, const std::string& carMake);

	std::string make;
	std::string model;

	bool operator==(const Car& testCar) const;
};

Car::Car(const std::string& carModel) : model(carModel) {}

Car::Car(const std::string& carModel, const std::string& carMake) : model(carModel), make(carMake) {}

bool Car::operator==(const Car& testCar) const {
	if (model == testCar.model) {
		return true;
	} else {
		return false;
	}
}

std::ostream& operator << (std::ostream& out, const Car& car) {
	out << "Make: " << car.make << ", Model: " << car.model;

	return out;
}

//------------------------
// Node
//------------------------

template <class T>
struct Node {
public:
	Node();
	Node(const T& d);

	T data;
	Node<T> *next = nullptr;

	void operator=(const T&);
	void operator=(const Node<T>&);
};

template <class T>
Node<T>::Node() {}

template <class T>
Node<T>::Node(const T& d) : data(d) {}

template <class T>
void Node<T>::operator = (const T& newData) {
	data = newData;
}

template <class T>
void Node<T>::operator = (const Node<T>& newNode) {
	data = newNode.data;
}

template <class T>
class LinkList {
public:
	LinkList();

	void append(const T& data);
	void remove(const T& data);
	void print() const;

private:
	Node<T> *head = nullptr;

};

//------------------------
// Link List
//------------------------

template <class T>
LinkList<T>::LinkList() {}

template <class T>
void LinkList<T>::append(const T& data) {
	Node<T> *temp = new Node<T>(data);
	Node<T> *current = head;

	if (head == nullptr) {
		head = temp;
	} else {
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = temp;
	}
}

template <class T>
void LinkList<T>::remove(const T& data) {
	Node<T> *temp = nullptr;
	Node<T> *current = head;

	while (current->next != nullptr) {
		if (current->next->data == data) {
			temp = current->next;
			current->next = current->next->next;

			delete temp;
		} else {
			current = current->next;
		}
	}

	if (head->data == data) {
		temp = head;
		head = head->next;
		delete temp;
	}

}

template <class T>
void LinkList<T>::print() const {
	Node<T> *current = head;
	int i = 0;

	if (head != nullptr) {
		while (current != nullptr) {
			std::cout << "LinkList[" << i++ << "] = " << current->data << std::endl;
			current = current->next;
		}
	} else {
		std::cout << "LinkList is empty. D=" << std::endl;
	}


}

//------------------------
// Main
//------------------------

int main() {

	LinkList<Car> List;

	Car a("Mercedes", "2018");
	Car b("Pt Cruiser", "2001");

	List.append(b);
	List.append(b);
	List.append(a);
	List.append(b);
	List.append(b);
	List.append(b);
	List.append(b);
	List.append(a);
	List.append(a);
	List.append(a);
	List.append(b);
	List.append(b);
	List.append(a);
	List.append(a);
	List.append(a);
	List.append(a);
	List.append(a);

	List.print();

	List.remove(a);

	std::cout << std::endl << "Removing Mercedes from the list" << std::endl;

	List.print();

	return 0;
}
