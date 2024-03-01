#pragma once
#include "DynArray.h"

template <typename T, int maxSize>
void Interface(InitDynArr<T, maxSize> arr) {
	int choice;

	do {
		cout << "Choose on of the functions:" << endl;
		cout << "1 - Get maxSize:" << endl;
		cout << "2 - Get Size:" << endl;
		cout << "3 - Sort:" << endl;
		cout << "4 - insert:" << endl;
		cout << "5 - Remove:" << endl;
		cout << "6 - Print:" << endl;
		cout << "7 - Plus:" << endl;
		cout << "8 - Minus:" << endl;
		cout << "9 - Comparison(<):" << endl;
		cout << "10 - Comparison(>):" << endl;
		cout << "11 - Get element by index:" << endl;
		cout << endl;
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1: {
			cout << "Maximum array size = " << arr.getMaxSize() << endl;
			break;
		}
		case 2: {
			cout << "Array size = " << arr.getSize() << endl;
			break;
		}
		case 3: {
			bool bAscending;
			cout << "Sort ascending (0) or descending (1)" << endl;
			cin >> bAscending;
			arr.sort(bAscending);
			break;
		}
		case 4: {
			T element;
			int n;
			cout << "Enter the number of the element and element to be added" << endl;
			cin >> element >> n;
			arr.insert(element, n);
			break;
		}
		case 5: {
			int n;
			cout << "Enter the number of the element to be removed" << endl;
			cin >> n;
			arr.remove(n);
			break;
		}
		case 6: {
			cout << "----------------------------------------------------------" << endl;
			cout << "Values of array:" << arr << endl;
			cout << "----------------------------------------------------------" << endl;
			break;
		}
		case 7: {
			T element;
			cout << "Input element for plus" << endl;
			cin >> element;
			arr + element;
			break;
		}
		case 8: {
			T element;
			cout << "Input element for minus" << endl;
			cin >> element;
			arr - element;
			break;
		}
		case 9: {
			T element;
			InitDynArr<T, maxSize> arrForTest;
			cout << "Input element for Test" << endl;
			cin >> element;
			arrForTest = arr;
			cout << "----------------------------------------------------------" << endl;
			cout << "Array(curr):" << arr << endl;
			cout << "Array(test):" << arrForTest << endl;
			cout << "Comparison result:" << endl;
			cout << (arr < arrForTest) << endl;
			cout << "----------------------------------------------------------" << endl;
			arrForTest + element;
			cout << "----------------------------------------------------------" << endl;
			cout << "Array(curr):" << arr << endl;
			cout << "Array(test):" << arrForTest << endl;
			cout << "Comparison result:" << endl;
			cout << (arr < arrForTest) << endl;
			cout << "----------------------------------------------------------" << endl;
			break;
		}
		case 10: {
			T element;
			InitDynArr<T, maxSize> arrForTest;
			cout << "Input element for Test" << endl;
			cin >> element;
			arrForTest = arr;
			cout << "----------------------------------------------------------" << endl;
			cout << "Array(curr):" << arr << endl;
			cout << "Array(test):" << arrForTest << endl;
			cout << "Comparison result:" << endl;
			cout << (arr > arrForTest) << endl;
			cout << "----------------------------------------------------------" << endl;
			arrForTest + element;
			cout << "----------------------------------------------------------" << endl;
			cout << "Array(curr):" << arr << endl;
			cout << "Array(test):" << arrForTest << endl;
			cout << "Comparison result:" << endl;
			cout << (arr > arrForTest) << endl;
			cout << "----------------------------------------------------------" << endl;
			break;
		}
		case 11: {
			int n;
			cout << "Enter the element index" << endl;
			cin >> n;
			cout << "----------------------------------------------------------" << endl;
			cout << "Values of array:" << arr[n] << endl;
			cout << "----------------------------------------------------------" << endl;
			break;
		}
		default:
			cout << "Choice of number from 1 to 11. No other numbers are allowed!" << endl;
			break;
		}
		cout << "Exit - 0" << endl;
		cout << "Proceed - 1" << endl;
		cin >> choice;
		cout << endl;
	} while (choice != 0);
}

template <int maxSize>
void chrInterface(InitDynArr<char*, maxSize> arr) {
	int choice;

	do {
		cout << "Choose on of the functions:" << endl;
		cout << "1 - Get maxSize:" << endl;
		cout << "2 - Get Size:" << endl;
		cout << "3 - Sort:" << endl;
		cout << "4 - insert:" << endl;
		cout << "5 - Remove:" << endl;
		cout << "6 - Print:" << endl;
		cout << "7 - Plus:" << endl;
		cout << "8 - Minus:" << endl;
		cout << "9 - Comparison(<):" << endl;
		cout << "10 - Comparison(>):" << endl;
		cout << "11 - Get element by index:" << endl;
		cout << endl;
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1: {
			cout << "Maximum array size = " << arr.getMaxSize() << endl;
			break;
		}
		case 2: {
			cout << "Array size = " << arr.getSize() << endl;
			break;
		}
		case 3: {
			bool bAscending;
			cout << "Sort ascending (0) or descending (1)" << endl;
			cin >> bAscending;
			arr.sort(bAscending);
			break;
		}
		case 4: {
			char element[256];
			int n;
			cout << "Enter the number of the element and element to be added" << endl;
			cin >> element >> n;
			arr.insert(element, n);
			break;
		}
		case 5: {
			int n;
			cout << "Enter the number of the element to be removed" << endl;
			cin >> n;
			arr.remove(n);
			break;
		}
		case 6: {
			cout << "----------------------------------------------------------" << endl;
			cout << "Values of array:" << arr << endl;
			cout << "----------------------------------------------------------" << endl;
			break;
		}
		case 7: {
			char element[256];
			cout << "Input element for plus" << endl;
			cin >> element;
			arr + element;
			break;
		}
		case 8: {
			char element[256];
			cout << "Input element for minus" << endl;
			cin >> element;
			arr - element;
			break;
		}
		case 9: {
			char element[256] = "endOfArrayForTest";
			InitDynArr<char*, maxSize> arrForTest;
			arrForTest = arr;
			cout << "----------------------------------------------------------" << endl;
			cout << "Array(curr):" << arr << endl;
			cout << "Array(test):" << arrForTest << endl;
			cout << "Comparison result:" << endl;
			cout << (arr < arrForTest) << endl;
			cout << "----------------------------------------------------------" << endl;
			arrForTest + element;
			cout << "----------------------------------------------------------" << endl;
			cout << "Array(curr):" << arr << endl;
			cout << "Array(test):" << arrForTest << endl;
			cout << "Comparison result:" << endl;
			cout << (arr < arrForTest) << endl;
			cout << "----------------------------------------------------------" << endl;
			break;
		}
		case 10: {
			char element[256] = "endOfArrayForTest";
			InitDynArr<char*, maxSize> arrForTest;
			arrForTest = arr;
			cout << "----------------------------------------------------------" << endl;
			cout << "Array(curr):" << arr << endl;
			cout << "Array(test):" << arrForTest << endl;
			cout << "Comparison result:" << endl;
			cout << (arr>arrForTest) << endl;
			cout << "----------------------------------------------------------" << endl;
			arrForTest + element;
			cout << "----------------------------------------------------------" << endl;
			cout << "Array(curr):" << arr << endl;
			cout << "Array(test):" << arrForTest << endl;
			cout << "Comparison result:" << endl;
			cout << (arr > arrForTest) << endl;
			cout << "----------------------------------------------------------" << endl;
			break;
		}
		case 11: {
			int n;
			cout << "Enter the element index" << endl;
			cin >> n;
			cout << "----------------------------------------------------------" << endl;
			cout << "Values of array:" << arr[n] << endl;
			cout << "----------------------------------------------------------" << endl;
			break;
		}
		default:
			cout << "Choice of number from 1 to 11. No other numbers are allowed!" << endl;
			break;
		}
		cout << "Exit - 0" << endl;
		cout << "Proceed - 1" << endl;
		cin >> choice;
		cout << endl;
	} while (choice != 0);
}