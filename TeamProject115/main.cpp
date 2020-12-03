#include "sorting.h"


int main()
{
	for (int i = 0; i < 4; i++)
	{
		int dataSize = SIZE * pow(10, i);
		//int dataSize = 500;

		vector<int> sortDataOrig, sortDataCopy;
		chrono::high_resolution_clock::time_point start, end;
		chrono::duration<double> runTime;


		genData(dataSize, sortDataOrig);

		if (dataSize <= 100000)
		{
			// too slow to run for more than 100,000 numbers
			sortDataCopy = sortDataOrig;
			cout << "Insertion Sort\nData Size: " << dataSize << endl;
			start = chrono::high_resolution_clock::now();
			insertionSort(sortDataCopy);
			end = chrono::high_resolution_clock::now();
			runTime = end - start;
			cout << "Time elapsed: " << runTime.count() << " seconds\n\n";

			sortDataCopy = sortDataOrig;
			cout << "Selection Sort\nData Size: " << dataSize << endl;
			start = chrono::high_resolution_clock::now();
			SelectionSort(sortDataCopy);
			end = chrono::high_resolution_clock::now();
			runTime = end - start;
			cout << "Time elapsed: " << runTime.count() << " seconds\n\n";

			sortDataCopy = sortDataOrig;
			cout << "Bubble Sort\nData Size: " << dataSize << endl;
			start = chrono::high_resolution_clock::now();
			bubble(sortDataCopy);
			end = chrono::high_resolution_clock::now();
			runTime = end - start;
			cout << "Time elapsed: " << runTime.count() << " seconds\n\n";
		}



		cout << "Merge Sort\nData Size: " << dataSize << endl;
		start = chrono::high_resolution_clock::now();
		mergeSort(sortDataCopy, 0, sortDataCopy.size() - 1);
		end = chrono::high_resolution_clock::now();
		runTime = end - start;
		cout << "Time elapsed: " << runTime.count() << " seconds\n\n";

		sortDataCopy = sortDataOrig;
		cout << "Quick Sort\nData Size: " << dataSize << endl;
		start = chrono::high_resolution_clock::now();
		quickSort(sortDataCopy, 0, sortDataCopy.size() - 1);
		end = chrono::high_resolution_clock::now();
		runTime = end - start;
		cout << "Time elapsed: " << runTime.count() << " seconds\n\n";

		sortDataCopy = sortDataOrig;
		cout << "Heap Sort\nData Size: " << dataSize << endl;
		start = chrono::high_resolution_clock::now();
		heapSort(sortDataCopy);
		end = chrono::high_resolution_clock::now();
		runTime = end - start;
		cout << "Time elapsed: " << runTime.count() << " seconds\n\n";

		sortDataCopy = sortDataOrig;
		cout << "Counting Sort\nData Size: " << dataSize << endl;
		start = chrono::high_resolution_clock::now();
		CountSort(sortDataCopy);
		end = chrono::high_resolution_clock::now();
		runTime = end - start;
		cout << "Time elapsed: " << runTime.count() << " seconds\n\n";

		sortDataCopy = sortDataOrig;
		cout << "Radix Sort\nData Size: " << dataSize << endl;
		start = chrono::high_resolution_clock::now();
		RadixSort(sortDataCopy);
		end = chrono::high_resolution_clock::now();
		runTime = end - start;
		cout << "Time elapsed: " << runTime.count() << " seconds\n\n";

	}

	return 0;
}

