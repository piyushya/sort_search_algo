#include "sort.h"
#include <iostream>


// swap depreceted
void swap_d(int& a, int& b) {  // don't use this if a and b are same it will result in 0 value
    a = a + b;
    b = a - b;
    a = a - b;
}

void swap(int& a, int& b) {
    int temp{ a };
    a = b;
    b = temp;
}

void printArr(const int* const arr, int len) {
    for (int i{ 0 }; i < len; ++i) {
        std::cout << arr[i];
        if (len - i - 1)
            std::cout << ", ";
    }
    std::cout << "\n";
}

bool isSorted(const int* const arr, int len, bool order=Order::ascending) {
    int index{};
    for (index = 1; index < len; ++index) {
        if ((arr[index - 1] > arr[index] && order==Order::ascending) ||
            (arr[index - 1] < arr[index] && order == Order::descending))
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void bubbleSort(int arr[], int n, const bool order=Order::ascending) {
    bool swapped{ false };
    for (int i{ 0 }; i < n - 1; ++i) {
        swapped = false;
        if (order == Order::ascending) {
            for (int j{ 1 }; j < n - i; ++j) {
                if (arr[j - 1] > arr[j]) {
                    swap(arr[j - 1], arr[j]);
                    swapped = true;
                }
            }
        }
        else if (order == Order::descending) {
            for (int j{ 1 }; j < n - i; ++j) {
                if (arr[j - 1] < arr[j]) {
                    swap(arr[j - 1], arr[j]);
                    swapped = true;
                }
            }
        }
        if (!swapped)
            break;
    }
}

void selectionSort(int arr[], int n) {
    int l_index;
    for (int i{ 0 }; i < n-1; ++i) {
        l_index = i;
        for (int j{ i+1 }; j < n; ++j) {
            if (arr[j] > arr[l_index])
                l_index = j;
        }
        swap(arr[i], arr[l_index]);
    }
}

void insertionSort(int arr[], int n) {
    for (int i{ 1 }; i < n; ++i) {
        int j = i;
        int current{ arr[i] };
        while (j>0 && arr[j - 1] < current) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = current;
    }
}

void merge(int arr[], int l, int mid, int r)
{
    int i = l;        // starting index of left half of arr
    int j = mid + 1;   // starting index of right half of arr
    int f = l;        // index used to transfer elements in temporary array
    int temp[100000]; // temporary array

    //storing elements in the temporary array in a sorted manner//

    while (i <= mid && j <= r) {
        if (arr[i] < arr[j]) {
            temp[f] = arr[i];
            i++;
        }
        else {
            temp[f] = arr[j];
            j++;
        }
        f++;
    }

    // if elements on the left half are still left //

    if (i > mid) {
        while (j <= r) {
            temp[f] = arr[j];
            f++; j++;
        }
    }
    else {
        //  if elements on the right half are still left //
        while (i <= mid) {
            temp[f] = arr[i];
            f++; i++;
        }
    }

    // transfering all elements from temporary to arr //
    for (int f = l; f <= r; f++) {
        arr[f] = temp[f];
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);  // left half
        mergeSort(arr, mid + 1, r); // right half
        merge(arr, l, mid, r);  // merging sorted halves
    }
}

int map(int pos, int mode, int y) {
    if (mode == 0) {
        return pos / y;
    }
    else {
        return pos - ((pos / y) * y);
    }
}

int searchMulti(int arr[][], int x, int y, int search) {
    int low{ 0 }, high{ (x * y) - 1 };
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[map(mid, 0, y)][map(mid, 1, y)] == search) {
            return mid;
            break;
        }
        if (arr[map(mid, 0, y)][map(mid, 1, y)] < search)
            low = mid + 1;
        else
            high = mid - 1;
    }
}
