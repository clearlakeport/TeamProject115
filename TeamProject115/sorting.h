#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <chrono>
#include <conio.h>
#include <algorithm>
#include "sorting.h"

using namespace std;

const int SIZE = 1000;

void genData(int n, vector<int>& toRet);
void insertionSort(vector<int>& userVector);
void SelectionSort(vector<int>& userVector);
void bubble(vector<int>& arr);
void merge(vector<int>& original, int left, int middle, int right);
void mergeSort(vector<int>& userVector, int lo, int hi);
int partition(vector<int>& userVector, int low, int high);
void quickSort(vector<int>& userVector, int left, int right);
void heapify(vector<int>& userVec, int n, int index);
void heapSort(vector<int>& userVector);
void CountSort(vector<int>& userVector);
void RadixSort(vector<int>& userVector);

#endif


