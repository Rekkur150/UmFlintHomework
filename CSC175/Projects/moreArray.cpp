#include <iostream>
using namespace std;

const int SIZE = 50;
int length(const char array[]);
bool search(const char arr[], const int size, const char check);
int main() {

	char phrase[] = "The dog has blue hair. HELLO WORLD YOU ARE THE BEST THING TO DAY. I AM SO GLAD THAT YOU ARE STILL UNDER MY FEET. WITH MY FEET I CAN MEASURE THINGS, HOWEVER I CANT MEASURE METERS, I DONT HAVE METERS. THERE ARE NO METERS ON ME AND THERE ARE ALSO NO STRINGS ON ME EITHER. SAD TIMES THESE ARE, YOU KNOW IT IS SAD WHEN YOU CANT MEASURE THINGS IN METERS AND WHEN YOU DONT HAVE STRINGS ON ME. I CAN WHILE AWAY THE HOURS CONFERING WITH THE FLOWES CONSAULTING WITH THE RAIN. I AM REALLY HUNGRY FOR PIZZA PLEASE GIVE PIZZA TO THE ZACAHRY IN THE ROOM. IT IS A VERY LARGE ZACHARY IN THE ROOM AND IF YOU AGREE WITH ZACHARY HE WILL BE ANGRY WITH YOU AND YOUR FRIENDS AND YOUR MOTHER AND YOUR MOTHERS MOTHER AND YOUR MOTHERS MOTHERS MOTHER AND THE POLICE. THEY FAILED THIER JOB TO ARREST YOU. I DONT DO GOLF. I DONT KNOW HOW TO HELP PEOPLE IN ANY SHAPE OR FORM.";
	char a;
	int size = 0;

	size = length(phrase);

	cout << "Search character";
	cin >> a;

	cout << "Is it true or false? : " << search(phrase,size,a) << endl;
	cout << "the length of our array is " << size << endl;

	return 0;
}

int length(const char arr[]) {
	int i = 0;
	while (arr[i] != '\0') {
		i++;
	}

	return i;
}

bool search(const char arr[], const int size,const char check) {
	for (int i = 0; i < size;i++) {
		if (arr[i] == check) {
			return true;
		}
	}

	return false;
}
