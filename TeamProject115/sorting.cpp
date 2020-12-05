#include "sorting.h"

Sorting::Sorting()
{
	dataSize = 100; 
	userChoice = 99;
	resetFlag = false;
	runTime = std::chrono::seconds{ 0 };
}


void Sorting::swap(int first, int second)
{
	int temp;

	temp = sortDataCopy[first];
	sortDataCopy[first] = sortDataCopy[second];
	sortDataCopy[second] = temp;
}

void Sorting::insertionSort()
{
	int firstOutOfOrder, location;
	int length = sortDataCopy.size(), temp;

	for (firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++)
	{
		if (sortDataCopy[firstOutOfOrder] < sortDataCopy[firstOutOfOrder - 1])
		{
			temp = sortDataCopy[firstOutOfOrder];
			location = firstOutOfOrder;

			do
			{
				sortDataCopy[location] = sortDataCopy[location - 1];
				location--;
			} while (location > 0 && sortDataCopy[location - 1] > temp);
			sortDataCopy[location] = temp;
		}
	}

}

void Sorting::SelectionSort()
{
	int smallest = 0, length = sortDataCopy.size();

	for (int current = 0; current < length - 1; current++)
	{
		smallest = current;
		for (int index = current + 1; index <= length - 1; index++)
		{
			if (sortDataCopy[index] < sortDataCopy[smallest])
			{
				if (sortDataCopy[index] < sortDataCopy[smallest])
					smallest = index;
			}
		}
		swap(current, smallest);
	}

}

void Sorting::bubble()
{
	bool flag = false;
	int last = sortDataCopy.size() - 1;

	while (!flag) {
		bool flag = true;
		for (int i = 0; i < last; i++) {
			if (sortDataCopy[i] > sortDataCopy[i + 1]) {
				swap(i, i+1);
				flag = false;
			}
		}
		last--;
		if (last == 0)
			return;
	}
}

void Sorting::merge(int left, int middle, int right) {

	int i, j, k;

	int arr1 = middle - left + 1;
	int arr2 = right - middle;

	int* fPtr = new int[arr1];
	int* sPtr = new int[arr2];


	for (i = 0; i < arr1; i++)
		fPtr[i] = sortDataCopy[left + i];

	for (j = 0; j < arr2; j++)
		sPtr[j] = sortDataCopy[middle + 1 + j];

	i = j = 0;
	k = left;

	while (i < arr1 && j < arr2)
	{
		if (fPtr[i] <= sPtr[j])
		{
			sortDataCopy[k] = fPtr[i];
			i++;
		}
		else
		{
			sortDataCopy[k] = sPtr[j];
			j++;
		}
		k++;
	}

	while (i < arr1)
	{
		sortDataCopy[k] = fPtr[i];
		k++;
		i++;
	}

	while (j < arr2)
	{
		sortDataCopy[k] = sPtr[j];
		k++;
		j++;
	}

	delete[] fPtr;
	delete[] sPtr;
}

void Sorting::mergeSortHP(int lo, int hi) 
{

	if (lo < hi)
	{
		int mid = (lo + hi) / 2;
		mergeSortHP(lo, mid);
		mergeSortHP(mid + 1, hi);
		merge(lo, mid, hi);
	}
}

void Sorting::mergeSort()
{
	int high = sortDataCopy.size() - 1;
	mergeSortHP(0, high);
}


void Sorting::quickSort()
{
	int right = sortDataCopy.size() - 1;
	quickSortHP(0, right);

}

void Sorting::quickSortHP(int m, int n)
{
	int i, j, k;
	int key;


	if (m < n)
	{
		k = partition(m, n);
		swap(m, k);
		key = sortDataCopy[m];
		i = m + 1;
		j = n;

		while (i <= j)
		{
			while ((i <= n) && (sortDataCopy[i] <= key))
			{
				i++;
			}
			while ((j >= m + 1) && (sortDataCopy[j] >= key))
			{
				j--;
			}
			if (i < j)
			{
				swap(i, j);
			}
		}
		swap(m, j);

		quickSortHP(m, j - 1);

		quickSortHP(j + 1, n);
	}
	return;
}

void Sorting::heapify(int n, int index)
{
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if (left < n && sortDataCopy[left] > sortDataCopy[largest])
		largest = left;
	if (right < n && sortDataCopy[right] > sortDataCopy[largest])
		largest = right;
	if (largest != index)
	{
		swap(index, largest);
		heapify(n, largest);
	}
}

void Sorting::heapSort()
{
	int size = sortDataCopy.size();

	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(size, i);

	for (int i = size - 1; i >= 0; i--)
	{
		swap(0, i);
		heapify(i, 0);
	}
}


void Sorting::CountSort()
{
	int size = sortDataCopy.size();
	int max = *max_element(sortDataCopy.begin(), sortDataCopy.end());
	int* outArr = new int[size];
	int* auxArr = new int[max + 1];

	for (int i = 0; i <= max; i++)
	{
		auxArr[i] = 0;
	}


	for (int i = 0; i < size; i++)
	{
		auxArr[sortDataCopy[i]]++;
	}

	for (int i = 1; i <= max; i++)
	{
		auxArr[i] += auxArr[i - 1];
	}

	for (int i = size - 1; i >= 0; i--)
	{
		outArr[--auxArr[sortDataCopy[i]]] = sortDataCopy[i];
	}

	for (int i = 0; i < size; i++)
	{
		sortDataCopy[i] = outArr[i];
	}

	delete[] outArr;
	delete[] auxArr;

}

void Sorting::RadixSort()
{
	const int BASE = 10;
	int size = sortDataCopy.size();
	int max = *max_element(sortDataCopy.begin(), sortDataCopy.end());

	int numDigits = 1, tmp = 10;
	while (max / tmp > 0)
	{
		numDigits++;
		tmp *= 10;
	}

	int* outArr = new int[size];
	int pos = 1;

	for (int i = 1; i <= numDigits; i++)
	{

		int auxArr[BASE] = { 0 };

		for (int j = 0; j < size; j++)
		{
			auxArr[sortDataCopy[j] / pos % 10]++;
		}

		for (int j = 1; j < BASE; j++)
		{
			auxArr[j] += auxArr[j - 1];
		}


		for (int j = size - 1; j >= 0; j--)
		{
			outArr[--auxArr[sortDataCopy[j] / pos % 10]] = sortDataCopy[j];
		}


		for (int i = 0; i < size; i++)
		{
			sortDataCopy[i] = outArr[i];
		}

		pos *= 10;
	}

	delete[] outArr;
}

void Sorting::printChoice()
{
	switch (userChoice)
	{
	case 1:	cout << "Insertion Sort" << endl;
		break;
	case 2:	cout << "Selection Sort" << endl;
		break;
	case 3:	cout << "Bubble Sort" << endl;
		break;
	case 4:	cout << "Merge Sort" << endl;
		break;
	case 5:	cout << "Quick Sort" << endl;
		break;
	case 6:	cout << "Heap Sort" << endl;
		break;
	case 7:	cout << "Counting Sort" << endl;
		break;
	case 8:	cout << "Radix Sort" << endl;
		break;
	case 9:	system("cls");
		break;
	default:	if (userChoice == 0)
		return;
	}
}

void Sorting::startChoice()
{
	sortDataCopy = sortDataOrig;
	printChoice();
	cout << "Data Size: " << dataSize << endl;
	start = chrono::high_resolution_clock::now();

}

void Sorting::endChoice()
{
	char choice;

	if (!resetFlag)
	{
		end = chrono::high_resolution_clock::now();
		runTime = end - start;
		cout << "Time elapsed: " << runTime.count() << " seconds\n\n";

		cin.ignore();
		cout << "Display Sorted Data? (Y/N)";
		choice = getchar();
		if (choice == 'Y' || choice == 'y')
			outputSorted();

		sortDataCopy.clear();

		cout << "Press any key to continoue";
		(void)_getch();
		system("cls");

	}
	
}
void Sorting::getSize()
{
	int size;

	cout << "Insert size of data to be sorted:\n";
	cin >> size;
	dataSize = size;
	system("cls");

}

// generate randomized integers of datasize 
void Sorting::genData()
{
	for (int i = 0; i < dataSize; ++i)
	{
		sortDataOrig.push_back(rand() % INT_MAX);
	}
}

int Sorting::getChoice()
{
	int choice;

	cout << "Data size: " << dataSize << endl;
	cout << "1: Insertion\n2: Selection\n3: Bubble\n4: Merge\n5: Quick\n6: Heap\n7: Counting\n8: Radix\n9: Change Data\n0: Exit\n";
	cin >> choice;

	userChoice = choice;
	resetFlag = false;

	return choice;
}

void Sorting::outputSorted()
{
	cout << "Sorted Data: " << endl;

	for (auto itr = sortDataCopy.begin(); itr != sortDataCopy.end(); itr++)
	{
		cout << *itr << "  ";
	}
	cout << endl;
}

void Sorting::reset()
{
	sortDataCopy.clear();
	sortDataOrig.clear();
	getSize();
	genData();
	resetFlag = true;
}