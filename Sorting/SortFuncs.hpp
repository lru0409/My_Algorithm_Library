#ifndef SORT_FUNCS_HPP
# define SORT_FUNCS_HPP

# include <algorithm>
# include <climits>

void BubbleSort(int *arr, int n);
void InsertionSort(int *arr, int n);
void SelectionSort(int *arr, int n);

void MergeSort(int *arr, int start, int end);
void QuickSort(int *arr, int start, int end);

void CountingSort(int *arr, int count);
void RadixSortLSD(int *arr, int count);
void RadixSortMSD(int *arr, int count);

#endif