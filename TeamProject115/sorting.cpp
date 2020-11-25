#include "sorting.h"

void genData(int n, vector<int> &toRet) {

	srand(time(NULL));
	for (int i = 0; i < n; ++i) {
		toRet.push_back(rand() % INT_MAX);
	}
}

void swap(vector<int>& userVector, int i, int j) {
	int temp = userVector.at(i);
	userVector.at(i) = userVector.at(j);
	userVector.at(j) = temp;
	return;
}

void insertionSort(vector<int>& userVector) {
	for (unsigned int i = 1; i < userVector.size(); i++) {
		int j, v = userVector.at(i);
		for (j = i - 1; j >= 0; j--) {
			if (userVector.at(j) < v) {
				break;
			}
			userVector.at(j + 1) = userVector.at(j);
		}
		userVector.at(j + 1) = v;
	}
	return;
}

vector<int> SelectionSort(vector<int> userVector) {
	for (int i = 0; i < userVector.size(); ++i) {
		int min = i;
		for (int j = userVector.size() - 1; j > i; --j) {
			if (userVector.at(j) < userVector.at(min)) {
				min = j;
			}
		}
		int temp = userVector.at(i);
		userVector.at(i) = userVector.at(min);
		userVector.at(min) = temp;
	}
	return userVector;
}

vector<int> bubble(vector<int> arr, int n) {
	bool flag = false;
	int last = n - 1;

	while (!flag) {
		bool flag = true;
		for (int i = 0; i < last; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				flag = false;
			}
		}
		last--;
		if (last == 0)return arr;
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

void swap(int& lhs, int& rhs)
{
	int temp;

	temp = lhs;
	lhs = rhs;
	rhs = temp;

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


int FindMax(vector<int>userVector) {
	int max = 0;
	for (int i = 0; i < userVector.size(); ++i) {//finds the maximum value from the vector
		if (userVector.at(i) > max) {
			max = i;
		}
	}
	return max;
}

vector<int> CountSort(vector<int>userVector) {
	vector<int>output(userVector.size());
	int max = FindMax(userVector);
	int temp = userVector.at(max);

	vector<int>aux(10, 0);//auxiliary array for the digit
	for (int j = 0; j < userVector.size(); ++j) {
		++aux.at(userVector.at(j));//stores the amount of times a number shows up at the certain digit
	}
	for (int j = 1; j < aux.size(); ++j) {//adds the counts together
		aux.at(j) += aux.at(j - 1);
	}
	for (int j = userVector.size() - 1; j >= 0; --j) {
		int a = aux.at(userVector.at(j));//finds the aux count for the value at digit i
		int b = (userVector.at(j));
		output.at(a - 1) = userVector.at(j);//adds the value for digit i to output
		--aux.at(b);//decrements the digit i count
	}

	return output;
}

vector<int> RadixSort(vector<int>userVector) {
	vector<int>output(userVector.size());
	int max = FindMax(userVector);
	int temp = userVector.at(max);
	int digits = 1;

	while (temp / 10 >= 1) {//finds the number of digits for the max number
		++digits;
		temp /= 10;
	}

	for (int i = 1; i <= digits; ++i) {
		vector<int>aux(10, 0);//auxiliary array for the digit
		int digitMod = pow(10, i);
		for (int j = 0; j < userVector.size(); ++j) {
			++aux.at((userVector.at(j) % digitMod) / (pow(10, (i - 1))));//stores the amount of times a number shows up at the certain digit
		}
		for (int j = 1; j < aux.size(); ++j) {//adds the counts together
			aux.at(j) += aux.at(j - 1);
		}
		for (int j = userVector.size() - 1; j >= 0; --j) {
			int a = aux.at((userVector.at(j) % digitMod) / (pow(10, (i - 1))));//finds the aux count for the value at digit i
			int b = (userVector.at(j) % digitMod) / (pow(10, (i - 1)));
			output.at(a - 1) = userVector.at(j);//adds the value for digit i to output
			--aux.at(b);//decrements the digit i count
		}
		userVector = output;
	}
	return output;
}