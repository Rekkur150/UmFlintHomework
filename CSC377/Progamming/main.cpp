#include <iostream>
#include <math.h>
using namespace std;

int main() {

	int foundRam = 0;

	int firstAdded = 0;

	int storage[460];
	int *loadedFrames;
	int ramSize = 400;
	int numbersToGet[12] = {10,11,104,170,74,309,185,245,246,434,458,364};
	int numbersToGetSize = 12;
	int frameSize = 0;
	int frames;
	for (int i = 0; i < 460; i++) {
		storage[i] = i;
	}

	cout << "What is the size of Ram: ";
	cin >> ramSize;

	cout << "What is the Page Frame Size: ";
	cin >> frameSize;
	frames = ramSize/frameSize;
	loadedFrames = new int[frames];

	for (int i = 0; i < frames; i++) {
		loadedFrames[i] = -1;
	}


	for (int i = 0; i < numbersToGetSize; i++) {
		cout << "Looking for " << numbersToGet[i] << endl;
		float page = floor(numbersToGet[i]/frameSize);
		cout << "Found in Page " << page << endl;
		bool loaded = false;
		for (int l = 0; l < frames; l++) {
			if (loadedFrames[l] == page) {
				cout << "Was Loaded!" << endl;
				foundRam++;
				loaded = true;
				break;
			}
		}

		if (!loaded) {
			bool emptyFrame = false;
			for (int l = 0; l < frames; l++) {
				if (loadedFrames[l] == -1) {
					cout << "Loading Page " << page << " to memory" << endl;
					loadedFrames[l] = page;
					emptyFrame = true;
					break;
				}
			}
			if (!emptyFrame) {
				cout << "Loading Page " << page << " to memory, overwriting Page " << loadedFrames[firstAdded] << endl;
				loadedFrames[firstAdded] = page;
				firstAdded++;
				if (firstAdded >= frames) {
					firstAdded = 0;
				}
			}

		}

		cout << "Frames Currently Loaded:[";
		for (int j = 0; j < frames; j++) {
			cout << loadedFrames[j] << ",";
		}
		cout << "]" << endl;
		cout << "------------------" << endl;
	}

	delete[] loadedFrames;
	return 1;
}
