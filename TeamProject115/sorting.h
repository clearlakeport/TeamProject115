#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <chrono>
#include <conio.h>
#include "sorting.h"

using namespace std;

void genData(int n, vector<int>& toRet);
void swap(vector<int>& userVector, int i, int j);
void swap(int& lhs, int& rhs);
void insertionSort(vector<int>& userVector);
vector<int> SelectionSort(vector<int> userVector);
vector<int> bubble(vector<int> arr, int n);
void merge(vector<int>& original, int left, int middle, int right);
void mergeSort(vector<int>& userVector, int lo, int hi);
int partition(vector<int>& userVector, int low, int high);
void quickSort(vector<int>& userVector, int left, int right);
void heapify(vector<int>& userVec, int n, int index);
void heapSort(vector<int>& userVector);
int FindMax(vector<int>userVector);
vector<int> CountSort(vector<int>userVector);
vector<int> RadixSort(vector<int>userVector);

#endif

