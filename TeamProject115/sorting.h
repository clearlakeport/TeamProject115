#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <chrono>
#include <conio.h>
#include <algorithm>

using namespace std;

//smallest to get reasonable timing
const int SIZE = 1000;

class Sorting
{
public:
   Sorting();
   //allows user defined data to be passed
   //not used in our program this time
   Sorting(vector<int> &iVec);
   void genData();
   void insertionSort();
   void SelectionSort();
   void bubble();
   void mergeSort();
   void quickSort();
   void heapSort();
   void CountSort();
   void RadixSort();
   //UI functions
   void startChoice();
   void endChoice();
   int getChoice();
   void getSize();
   void outputSorted();
   void reset();
   //used for generating different types of data sets for our report
   void modifyVec(int c);

private:
   int dataSize;
   int userChoice;
   bool resetFlag;
   vector<int> sortDataOrig, sortDataCopy;
   chrono::high_resolution_clock::time_point startT, endT;
   chrono::duration<double> runTime;
   //helper functions
   void mergeSortHP(int low, int high);
   void heapify(int size, int i);
   void merge(int left, int middle, int right);
   int pivot(int i, int j);
   void quickSortHP(int m, int n);
   void swap(int first, int second);
   void printChoice();
};

#endif


