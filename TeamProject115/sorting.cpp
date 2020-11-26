#include "sorting.h"

void genData(int n, vector<int>& toRet) {

	srand(time(NULL));
	for (int i = 0; i < n; ++i) {
		toRet.push_back(rand() % INT_MAX);
	}
}

void insertionSort(vector<int>& userVec)
{
	int firstOutOfOrder, location;
	int length = userVec.size(), temp;

	for (firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++)
	{
		if (userVec[firstOutOfOrder] < userVec[firstOutOfOrder - 1])
		{
			temp = userVec[firstOutOfOrder];
			location = firstOutOfOrder;

			do
			{
				userVec[location] = userVec[location - 1];
				location--;
			} while (location > 0 && userVec[location - 1] > temp);
			userVec[location] = temp;
		}
	}

}

void SelectionSort(vector<int>& userVec)
{
	int smallest = 0, length = userVec.size(), holdData;

	for (int current = 0; current < length - 1; current++)
	{
		smallest = current;
		for (int index = current + 1; index <= length - 1; index++)
		{
			if (userVec[index] < userVec[smallest])
			{
				swap(userVec[smallest], userVec[index]);
			}
		}
	}

}

void bubble(vector<int>& arr)
{
	bool flag = false;
	int last = arr.size() - 1;

	while (!flag) {
		bool flag = true;
		for (int i = 0; i < last; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				flag = false;
			}
		}
		last--;
		if (last == 0)
			return;
	}
}

void merge(vector<int>& original, int left, int middle, int right) {

	int i, j, k;

	int arr1 = middle - left + 1;
	int arr2 = right - middle;

	int* fPtr = new int[arr1];
	int* sPtr = new int[arr2];


	for (i = 0; i < arr1; i++)
		fPtr[i] = original[left + i];

	for (j = 0; j < arr2; j++)
		sPtr[j] = original[middle + 1 + j];

	i = j = 0;
	k = left;

	while (i < arr1 && j < arr2)
	{
		if (fPtr[i] <= sPtr[j])
		{
			original[k] = fPtr[i];
			i++;
		}
		else
		{
			original[k] = sPtr[j];
			j++;
		}
		k++;
	}

	while (i < arr1)
	{
		original[k] = fPtr[i];
		k++;
		i++;
	}

	while (j < arr2)
	{
		original[k] = sPtr[j];
		k++;
		j++;
	}

	delete[] fPtr;
	delete[] sPtr;
}

void mergeSort(vector<int>& userVector, int lo, int hi) {

	if (lo < hi)
	{
		int mid = (lo + hi) / 2;
		mergeSort(userVector, lo, mid);
		mergeSort(userVector, mid + 1, hi);
		merge(userVector, lo, mid, hi);
	}
}

int partition(vector<int>& userVector, int low, int high)
{
	int pivot = userVector[low];
	bool done = false;

	int i = low + 1;
	int j = high;

	while (!done)
	{
		while (i <= j && userVector[i] <= pivot)
			i++;
		while (userVector[j] >= pivot && j >= i)
			j--;
		if (i > j)
			done = true;
		else
			swap(userVector[i], userVector[j]);
	}

	swap(userVector[low], userVector[j]);

	return j;
}

void quickSort(vector<int>& userVector, int left, int right)
{
	int p;

	if (left < right)
	{
		p = partition(userVector, left, right);
		quickSort(userVector, left, p - 1);
		quickSort(userVector, p + 1, right);
	}
}

void heapify(vector<int>& userVec, int n, int index)
{
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if (left < n && userVec[left] > userVec[largest])
		largest = left;
	if (right < n && userVec[right] > userVec[largest])
		largest = right;
	if (largest != index)
	{
		swap(userVec[index], userVec[largest]);
		heapify(userVec, n, largest);
	}
}

void heapSort(vector<int>& userVector)
{
	int n = userVector.size();

	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(userVector, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(userVector[0], userVector[i]);
		heapify(userVector, i, 0);
	}
}


void CountSort(vector<int>& userVec)
{
	int size = userVec.size();
	int max = *max_element(userVec.begin(), userVec.end());
	int* outArr = new int[size];
	int* auxArr = new int[max + 1];

	for (int i = 0; i <= max; i++)
	{
		auxArr[i] = 0;
	}


	for (int i = 0; i < size; i++)
	{
		auxArr[userVec[i]]++;
	}

	for (int i = 1; i <= max; i++)
	{
		auxArr[i] += auxArr[i - 1];
	}

	for (int i = size - 1; i >= 0; i--)
	{
		outArr[--auxArr[userVec[i]]] = userVec[i];
	}

	for (int i = 0; i < size; i++)
	{
		userVec[i] = outArr[i];
	}

	delete[] outArr;
	delete[] auxArr;

}

void RadixSort(vector<int>& userVec)
{
	const int BASE = 10;
	int size = userVec.size();
	int max = *max_element(userVec.begin(), userVec.end());

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
			auxArr[userVec[j] / pos % 10]++;
		}

		for (int j = 1; j < BASE; j++)
		{
			auxArr[j] += auxArr[j - 1];
		}


		for (int j = size - 1; j >= 0; j--)
		{
			outArr[--auxArr[userVec[j] / pos % 10]] = userVec[j];
		}


		for (int i = 0; i < size; i++)
		{
			userVec[i] = outArr[i];
		}

		pos *= 10;
	}

	delete[] outArr;
}
