#include <iostream>
#include "DynArray.h"
#include "Interface.h"

const int electedMaxSize = 50;

int main(){   
	srand(time(NULL));
	int facechoice;

	do {
		cout << "Input type:" << endl;
		cout << "1 - int:" << endl;
		cout << "2 - double:" << endl;
		cout << "3 - char*:" << endl;
		cout << "4 - vec:" << endl;
		cout << endl;
		cin >> facechoice;
		cout << endl;

		switch (facechoice) {
		case 1: {
			InitDynArr<int, electedMaxSize> arr;
			Interface(arr);
			break;
		}
		case 2: {
			InitDynArr<float, electedMaxSize> arr;
			Interface(arr);
			break;
		}
		case 3: {
			InitDynArr<char*, electedMaxSize> arr;
			chrInterface(arr);
			break;
		}
		case 4: {
			InitDynArr<Vec2, electedMaxSize> arr;
			Interface(arr);
			break;
		}
		default:
			cout << "choice of number from 1 to 4. no other numbers are allowed!" << endl;
			break;
		}
	} while (facechoice < 1 or facechoice > 4);

	std::cout << "End of programm.\n";
    return 0;
}