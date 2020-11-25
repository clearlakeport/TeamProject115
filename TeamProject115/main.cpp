#include "sorting.h"

int main() {
	clock_t functionTime;

	int dataSize;
	int userChoice = 99;

	vector <int> sortDataOrig;
	vector <int> sortDataCopy;

	cout << "Insert size of data to be sorted:\n";
	cin >> dataSize;

	genData(dataSize, sortDataOrig);

	system("cls");

	while (userChoice != 0) {
		cout << "Data size: " << dataSize << endl;
		cout << "1: Insertion\n2: Selection\n3: Bubble\n4: Merge\n5: Quick\n6: Heap\n7: Counting\n8: Radix\n9: Change Data\n0: Exit\n";
		cin >> userChoice;
		if (userChoice == 1) {
			system("cls");
			sortDataCopy = sortDataOrig;
			cout << "Insertion Sort\nData Size: " << dataSize << endl;
			auto start = chrono::high_resolution_clock::now();
			insertionSort(sortDataCopy);
			auto end = chrono::high_resolution_clock::now();
			chrono::duration<float> time = end - start;
			cout << "Time elapsed: " << time.count() << " seconds\n";
			cout << "Press any key to exit";
			_getch();
			system("cls");
		}
		else if (userChoice == 2) {
			system("cls");
			sortDataCopy = sortDataOrig;
			cout << "Selection Sort\nData Size: " << dataSize << endl;
			functionTime = clock();
			sortDataCopy = SelectionSort(sortDataCopy);
			functionTime = clock() - functionTime;
			cout << "Time elapsed: " << (float)functionTime / CLOCKS_PER_SEC << " seconds\n";
			cout << "Press any key to exit";
			_getch();
			system("cls");
		}
		else if (userChoice == 3) {//fix bubble
			system("cls");
			sortDataCopy = sortDataOrig;
			cout << "Bubble Sort\nData Size: " << dataSize << endl;
			functionTime = clock();
			sortDataCopy = bubble(sortDataCopy, dataSize);
			functionTime = clock() - functionTime;
			cout << "Time elapsed: " << (float)functionTime / CLOCKS_PER_SEC << " seconds\n";
			cout << "Press any key to exit";
			_getch();
			system("cls");
		}
		else if (userChoice == 4) {//fix
			system("cls");
			sortDataCopy = sortDataOrig;
			cout << "Merge Sort\nData Size: " << dataSize << endl;
			auto start = chrono::high_resolution_clock::now();
			mergeSort(sortDataCopy, 0, sortDataCopy.size() - 1);
			auto end = chrono::high_resolution_clock::now();
			chrono::duration<float> time = end - start;
			cout << "Time elapsed: " << time.count() << " seconds\n";
			cout << "Press any key to exit";
			_getch();
			system("cls");
		}
		else if (userChoice == 5) {
			system("cls");
			sortDataCopy = sortDataOrig;
			cout << "Quick Sort\nData Size: " << dataSize << endl;
			auto start = chrono::high_resolution_clock::now();
			quickSort(sortDataCopy, 0, sortDataCopy.size() - 1);
			auto end = chrono::high_resolution_clock::now();
			chrono::duration<float> time = end - start;
			cout << "Time elapsed: " << time.count() << " seconds\n";
			cout << "Press any key to exit";
			_getch();
			system("cls");
		}
		else if (userChoice == 6) {
			system("cls");
			sortDataCopy = sortDataOrig;
			cout << "Heap Sort\nData Size: " << dataSize << endl;
			auto start = chrono::high_resolution_clock::now();
			heapSort(sortDataCopy);
			auto end = chrono::high_resolution_clock::now();
			chrono::duration<float> time = end - start;
			cout << "Time elapsed: " << time.count() << " seconds\n";
			/*for(vector<int>::iterator itr = sortDataCopy.begin(); itr != sortDataCopy.end(); itr++)
			{
				cout << *itr << " ";
			}*/
			cout << endl;
			cout << "Press any key to exit";
			_getch();
			system("cls");
		}
		else if (userChoice == 7) {
			system("cls");
			sortDataCopy = sortDataOrig;
			cout << "Counting Sort\nData Size: " << dataSize << endl;
			functionTime = clock();
			sortDataCopy = CountSort(sortDataCopy);
			functionTime = clock() - functionTime;
			cout << "Time elapsed: " << (float)functionTime / CLOCKS_PER_SEC << " seconds\n";
			cout << "Press any key to exit";
			_getch();
			system("cls");
		}
		else if (userChoice == 8) {
			system("cls");
			sortDataCopy = sortDataOrig;
			cout << "Radix Sort\nData Size: " << dataSize << endl;
			functionTime = clock();
			sortDataCopy = RadixSort(sortDataCopy);
			functionTime = clock() - functionTime;
			cout << "Time elapsed: " << (float)functionTime / CLOCKS_PER_SEC << " seconds\n";
			cout << "Press any key to exit";
			_getch();
			system("cls");
		}
		else if (userChoice == 9) {
			system("cls");
			cout << "Insert size of data to be sorted:\n";
			cin >> dataSize;
			system("cls");
		}
		else if (userChoice == 0) {
			return 0;
		}
		else {
			system("cls");
		}
	}
}
