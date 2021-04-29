#include <iostream>

const int n = 3;


int longestPathCell(int x, int y, int matrix[n][n], int map[n][n]) {
	if (map[y][x] == 0) {
		int currentValue = matrix[y][x];

		if (x > 0 && matrix[y][x-1] == currentValue + 1) {
			map[y][x] = longestPathCell(x-1, y, matrix, map) + 1;
		} else if(x < (n-1) && matrix[y][x+1] == currentValue + 1) {
			map[y][x] = longestPathCell(x+1, y,matrix, map) + 1;
		} else if(y > 0 && matrix[y-1][x] == currentValue + 1) {
			map[y][x] = longestPathCell(x, y-1,matrix, map) + 1;
		} else if(y < (n-1) && matrix[y+1][x] == currentValue + 1) {
			map[y][x] = longestPathCell(x, y+1,matrix,map) + 1;
		} else {
			map[y][x] = 1;
		}
	}

	return map[y][x];
}

int longestPath(int matrix[n][n]) {
	int map[n][n];
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[j][i] == 0) {
				max = std::max(max, longestPathCell(i,j,matrix,map));
			}
		}
	}

	return max;

}

int main() {
	int matrix[n][n] = {	{1,2,9},
				{5,3,8},
				{4,6,7}};

	std::cout << longestPath(matrix) << std::endl;


	return 0;
}
