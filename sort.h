#pragma once
#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <vector>

namespace Order {
	enum order {
		ascending,
		descending,
	};
}

void printArr(const int* const arr, int len);    // printArr( array, length)
bool isSorted(const int* const arr, int, bool);  // isSorted( array, length)
void bubbleSort(int[], int, const bool);         // bubbleSort(array, length)
void selectionSort(int[], int);					 // selectionSort(array, length)	
void insertionSort(int[], int);					 // insertionSort(array, length)
void mergeSort(int arr[], int l, int r);		 // mergeSort(array, start_index, end_index)
int map(int, int, int);
//int searchMulti(int[][], int, int, int); // find a way to pass multidimensional array

#endif // !SORT_H
