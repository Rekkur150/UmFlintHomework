#include <iostream>
#include <vector>

std::vector<int> Merge(std::vector<int> a, std::vector<int> b) {
	int aPos = 0;
	int bPos = 0;
	std::vector<int> merged;

	while (aPos != a.size()) {
		if (a[aPos] >= b[bPos] && (bPos < b.size())) {
			merged.push_back(b[bPos]);
			bPos++;
		} else {
			merged.push_back(a[aPos]);
			aPos++;
		}
	}

	for (int i = bPos; i < b.size(); i++) {
		merged.push_back(b[i]);
	}

	return merged;
}

void printVector(std::vector<int> a) {
	for (int i = 0;  i < a.size(); i++) {
		std::cout << "a[" << i << "] = " << a[i] << std::endl;
	}
}

std::vector<int> Trim(std::vector<int> L, float e) {
	int m = L.size();
	std::vector<int> Lprime;
	Lprime.push_back(L[0]);
	int last = L[0];

	for (int i = 1; i < m; i++) {
		if (L[i] > last * (1 + e)) {
			Lprime.push_back(L[i]);
			last = L[i];
		}
	}

	return Lprime;
}

std::vector<int> ApproxSubsetSum(std::vector<int>& S, int t, float e) {
	int n = S.size();
	int x = 0;
	std::vector<std::vector<int>> L;
	std::vector<int> returnV;
	std::vector<int> temp;
	L.push_back(std::vector<int> (1));

	for (int i = 1; i < n+1; i++) {
		//Create L[n-1]+S[i]
		temp = L[i-1];
		for (int j = 0; j < temp.size(); j++) {
			temp[j] = temp[j] + S[i-1];
		}

		//Merge and Trim
		L.push_back(Merge(L[i-1],temp));
		L[i] = Trim(L[i], e/(2*n));

		//Delete elements greater than t and find z*
		for (int j = 0; j < L[i].size(); j++) {
			if (L[i][j] > t) {
				L[i].erase(L[i].begin() + j);
				j--;
			} else {
				x = std::max(x,L[i][j]);
			}
		}

	}

	//Get the values needed to get z*

	bool found = false;
	for (int i = n+1; i > 0; i--) {
		found = false;
		for (int j = L[i-1].size(); j > 0; j--) {
			if (L[i-1][j] == x) {
				found = true;
				break;
			}
		}
		if (!found && x != 0) {
			x = x - S[i-1];
			returnV.push_back(S[i-1]);
		}

	}



	return returnV;
}


int main() {
	std::vector<int> a;
	std::vector<int> temp;

	a.push_back(-10);
	a.push_back(1);
	a.push_back(5);
	a.push_back(7);
	a.push_back(12);
	a.push_back(20);



	temp = ApproxSubsetSum(a, 19, 1);
	printVector(temp);

	return 0;
}


