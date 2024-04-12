#ifndef SORT_FUNCS_HPP
# define SORT_FUNCS_HPP

# include <algorithm>

void BubbleSort(int *arr, int n);
void InsertionSort(int *arr, int n);
void SelectionSort(int *arr, int n);
void MergeSort(int *arr, int start, int end);
void QuickSort(int *arr, int start, int end);

#endif