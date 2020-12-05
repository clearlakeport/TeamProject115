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

const int SIZE = 100;

class Sorting {
public:
   Sorting();
   void genData();
   void insertionSort();
   void SelectionSort();
   void bubble();
   void merge(int left, int middle, int right);
   void mergeSort();
   void quickSort();
   void heapify(int size, int i);
   void heapSort();
   void CountSort();
   void RadixSort();
   void startChoice();
   void endChoice();
   int getChoice(); 
   void getSize();
   void outputSorted();
   void reset();

private:
   int dataSize; 
   int userChoice;
   bool resetFlag;
   vector<int> sortDataOrig, sortDataCopy;
   chrono::high_resolution_clock::time_point start, end;
   chrono::duration<double> runTime;

   void mergeSortHP(int low, int high);
   int partition(int i, int j) { return ((i + j) / 2); }
   void quickSortHP(int m, int n);
   void swap(int first, int second);
   void printChoice();
};

#endif


