#include "Random.h"
#include "sort.h"
#include <iostream>

int main() {
    constexpr int len{ 100 };
    int arr[len];
    for (int i{ 0 }; i < len; ++i) {
        arr[i] = Random::get(0, len);
    }
    //insertionSort(arr, len);
    //selectionSort(arr, len);
    std::cout << isSorted(arr, len, Order::ascending) << "\n";
    bubbleSort(arr, len, Order::descending);
    //mergeSort(arr, 0, len-1);
    std::cout << "done!!\n";
    std::cout << isSorted(arr, len, Order::ascending) << "\n";
    printArr(arr, len);
    return 0;
}