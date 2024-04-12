#include "SortFuncs.hpp"

static int Partition(int *arr, int start, int end);

void QuickSort(int *arr, int start, int end)
{
	if (start < end)
	{
		int pivot = Partition(arr, start, end);
		QuickSort(arr, start, pivot-1);
		QuickSort(arr, pivot+1, end);
	}
}

static int Partition(int *arr, int start, int end)
{
	int pivot = arr[start];
	int left = start + 1;
	int right = end;

	while(left <= right)
	{
		while(arr[left] <= pivot && left <= end)
			left++;
		while(arr[right] >= pivot && right > start)
			right--;
		if (left < right)
			std::swap(arr[left], arr[right]);
	}

	std::swap(arr[start], arr[right]);
	return right;
}
