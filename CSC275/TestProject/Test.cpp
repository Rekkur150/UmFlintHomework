#include <iostream>


namespace S1{

       namespace S2{

           void HelloWorld(){  std::cout << "Hello World" << std::endl; }

       }

}

int main() {

	S1::S2::HelloWorld();
	return 0;
}
