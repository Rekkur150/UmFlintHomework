#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <string>

template <class T>
class Node{
public:
    Node();
    Node(const T& newData, Node<T>* newNext, Node<T>* newPrev);
    T getData() const;
    void printData(std::ostream& outstream = std::cout);
    Node<T>* getNext() const;
    Node<T>* getPrev() const;
    void setNext(Node<T> *newNext);
    void setPrev(Node<T> *newPrev);
private:
    T data;
    Node<T> *next = nullptr;
    Node<T> *prev = nullptr;
};

// Function Definitions

template <class T>
Node<T>::Node() {}

template <class T>
Node<T>::Node(const T& newData, Node<T>* newNext, Node<T>* newPrev) : data(newData), next(newNext), prev (newPrev) {}

template <class T>
T Node<T>::getData() const {return data;}

template <class T>
void Node<T>::printData(std::ostream& outstream) {outstream << data << std::endl;}

template <class T>
Node<T>* Node<T>::getNext() const {return next;}

template <class T>
Node<T>* Node<T>::getPrev() const {return prev;}

template <class T>
void Node<T>::setNext(Node<T> *newNext) {next = newNext;}

template <class T>
void Node<T>::setPrev(Node<T> *newPrev) {prev = newPrev;}

//-----------------------------------------------------------
// MyList
//-----------------------------------------------------------

template <class T>
class MyList {
public:
	MyList();
	bool isEmpty();
	Node<T>* getHead();
	void setHead(Node<T> *n);

	//Purpose:  Print a list of the students in the list from head to tail
	//Preconditions:  Calling object is a list of students
	//Postconditions:  Output each student name in the list to the console, starting with the head and moving up to the tail.
	void printContentFromHead(std::ostream& outstream= std::cout) const;
	//Purpose:  Print a list of the students in the list from head to tail
	//Preconditions:  output stream and the list of students
	//Postconditions:  Output each student name in the list to the output stream, starting with the head and moving up to the tail.

	friend std::ostream& operator << (std::ostream& outstream, const MyList<T>& myContent) {
		myContent.printContentFromHead(outstream);

		return outstream;
	}

	//Purpose:  Add a new student to the head of the list.
	//Preconditions:  Calling object is a list of students, parameters are a string last name and first name.
	//Postconditions:  Add new student to the head of the list with the given name.
	void addContentHead(const T& data);
	//Purpose:  Add a new student to the head of the list.
	//Preconditions:  input stream and the list of students
	//Postconditions:  Add new student to the head of the list with the given name.
	//  Take the first string from the input stream up to whitespace as the fname.
	//  Take the second string from the input stream up to whitespace as the lname.

	friend std::istream& operator >> (std::istream& instream, MyList<T>& myContent) {
		T data;
		instream >> data;
		myContent.addContentHead(data);

		return instream;
	}
	//Purpose:  Remove a student from the list.
	//Preconditions:  Calling object is a list of students, parameters are a string last name and first name.
	//Postconditions:  Remove a student from the list with the given name; first matching student starting from the head.
	//                  Return true if removal was successful and false otherwise (when there is no student with the given first and last name).
	bool removeContent(const T& data);
	//Purpose:  Delete all students in the list.
	//Preconditions:  Calling object is a list of students
	//Postconditions:  Safely deallocate memory for each node in the list.
	~MyList();

	//Purpose:  Print a list of the students in the list from tail to head
	//Preconditions:  Calling object is a list of students
	//Postconditions:  Output each student name in the list to the console, starting with the tail and moving back to the tail.
	void reverseList();

	//Purpose:  Print a list of the students in the list from tail to head
	//Preconditions:  Calling object is a list of students
	//Postconditions:  Output each student name in the list to the console, starting with the tail and moving back to the tail.
	void insertionSort();


private:
    Node<T> *head;
};

template <class T>
MyList<T>::MyList():head(nullptr){}

template <class T>
bool MyList<T>::isEmpty(){return head == nullptr;}

template <class T>
Node<T>* MyList<T>::getHead(){return head;}

template <class T>
void MyList<T>::setHead(Node<T> *n){head = n;}
    //Purpose:  Print a list of the students in the list from head to tail
    //Preconditions:  Calling object is a list of students
    //Postconditions:  Output each student name in the list, starting with the head and moving up to the tail.
template <class T>
void MyList<T>::printContentFromHead(std::ostream& outstream) const{
	Node<T>* curr;
	for( curr = head; curr != nullptr; curr = curr->getNext()){
	    curr->printData(outstream);
	}
}

//Purpose:  Add a new student to the head of the list.
//Preconditions:  Calling object is a list of students, parameters are a string last name and first name.
//Postconditions:  Add new student to the head of the list with the given name.
template <class T>
void MyList<T>::addContentHead(const T& data){
	Node<T>* newHotness = new Node<T>(data, head, nullptr);
	if(head != nullptr){
	    head->setPrev(newHotness);
	}
	head = newHotness;
}

//Purpose:  Remove a student from the list.
//Preconditions:  Calling object is a list of students, parameters are a string last name and first name.
//Postconditions:  Remove a student from the list with the given name; first matching student starting from the head.
//                  Return true if removal was successful and false otherwise (when there is no student with the given first and last name).
template <class T>
bool MyList<T>::removeContent(const T& data){
	Node<T>* oldAndBusted;

	for(oldAndBusted = head; oldAndBusted != nullptr; oldAndBusted = oldAndBusted->getNext()){
		if(oldAndBusted->getData()==data){
			if(oldAndBusted->getPrev() == nullptr){
			    //std::cout << "Prev student is nullptr" << std::endl;
			    //std::cout << "Next student is ";
			    //oldAndBusted->getNext()->printName();
			    if (oldAndBusted->getNext() != nullptr) {
			    	head = oldAndBusted->getNext();
			    	head->setPrev(nullptr);
			    } else {
				head = nullptr;
			    }
			}
			else if(oldAndBusted->getNext() == nullptr){
			    //std::cout << "Prev student is ";
			    //oldAndBusted->getPrev()->printName();
			    //std::cout << "Next student is nullptr" << std::endl;
			    if (oldAndBusted->getPrev() != nullptr) {
			    	oldAndBusted->getPrev()->setNext(nullptr);
			    } else {
				head = nullptr;
			    }
			}
			else{
			    //std::cout << "Prev student is ";
			    //oldAndBusted->getPrev()->printName();
			    //std::cout << "Next student is ";
			    //oldAndBusted->getNext()->printName();
			    oldAndBusted->getPrev()->setNext(oldAndBusted->getNext());
			    oldAndBusted->getNext()->setPrev(oldAndBusted->getPrev());
			}

			delete oldAndBusted;
			return true;
		}
	}

	return false;
}

//Purpose:  Delete all students in the list.
//Preconditions:  Calling object is a list of students
//Postconditions:  Safely deallocate memory for each node in the list.
template <class T>
MyList<T>::~MyList(){
	Node<T>* curr = head;
	Node<T>* temp;
	while(curr != nullptr){
		temp = curr->getNext();
		delete curr;
		curr = temp;
	}
}
//Purpose:  Reverse the order of the list
//Preconditions:  Calling object is a list of students
//Postconditions:  Objects in the list are swapped into reverse order.
//                  Example, if original list was:      A,B,C,D     where A is the head
//                  After reverseList, new list is:     D,C,B,A     where D is the new head
template <class T>
void MyList<T>::reverseList(){
	Node<T> *temp = nullptr;
	Node<T> *curr = head;      //starting at the head

	//swap next and prev values
	//for each node
	while (curr !=  nullptr)
	{
		temp = curr->getPrev();    //not, this will equal nullptr if this is the head
		curr->setPrev(curr->getNext());
		curr->setNext(temp);

		curr = curr->getPrev();
	}

	//set the new head if this is not an empty list or a list with only one node
	if(temp != nullptr)
		head = temp->getPrev();
			/*Observation for why this works:
			temp will be nullptr when the list is empty because we initialized it
			at nullptr and never iterated through the while loop

			temp will be nullptr when there was only one node because that one node was the head,
			so temp = curr->getPrev(); gave it a nullptr value on the one iteration of the while loop.*/
}

//Purpose:  Sort the list in ascending order by last name using Insertion Sort
//Preconditions:  Calling object is a list of students
//Postconditions:  Objects in the list are sorted in ascending order by last name
//                  Example, if original list was:
//                      Matt Spradling, John Grant, Tom Toybo, Sam Apples, David Pumpkins
//                          where Matt Spradling is the head
//                  After insertionSort, new list:
//                      Sam Apples, John Grant, David Pumpkins, Matt Spradling, Tom Toybo
//                          where Sam Apples is the new head
template <class T>
void MyList<T>::insertionSort(){
	Node<T> *curr = head->getNext();
	Node<T> *checking = nullptr;
	Node<T> *temp = nullptr;

	while (curr != nullptr) {

		for (checking = head; checking != curr; checking = checking->getNext()) {
			if (checking->getData() > curr->getData()) {
				break;
			}
		}

		temp = curr->getNext();

		if (checking != curr) { // Does two things, makes it that it doesn't swap when current is in order, and prevents sorting of a one node link list
			if (curr->getNext() == nullptr) { // If current is the tail, do special case
				curr->getPrev()->setNext(nullptr);
			} else {
				curr->getPrev()->setNext(curr->getNext());
				curr->getNext()->setPrev(curr->getPrev());
			}

			if (checking->getPrev() == nullptr) { // If checking is the head, do special case
				head = curr;
				curr->setPrev(nullptr);
			} else {
				checking->getPrev()->setNext(curr);
				curr->setPrev(checking->getPrev());
			}

			checking->setPrev(curr);
			curr->setNext(checking);


		}

		curr = temp;

	}
}

/*
To help you design your algorithm for insertionSort, here is a variant of insertionSort for an array of integers:
Taken from:    http://www.geeksforgeeks.org/insertion-sort/

It also shows a good example of how it works.

void insertionSort(int arr[], int n)
{
int i, key, j;
for (i = 1; i < n; i++)
{
key = arr[i];
j = i-1;

// Move elements of arr[0..i-1], that are
//   greater than key, to one position ahead
//   of their current position
while (j >= 0 && arr[j] > key)
{
   arr[j+1] = arr[j];
   j = j-1;
}
arr[j+1] = key;
}
}

*/


#endif

