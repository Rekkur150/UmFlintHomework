#include <iostream>

const int a[10] = {1,2,3,4,5,6,7,8,9,10};
int  lah = 0;

float horner(int n, int b, float x) {
	std::cout << lah++ << std::endl;

	if (n-1 == b) {
		return a[b];
	}

	return a[b] + x * horner(n,b+1,x);
}

int main() {
	std::cout << horner(5,0,3) << std::endl;
}
