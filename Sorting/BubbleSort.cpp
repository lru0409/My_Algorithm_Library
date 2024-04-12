#include "SortFuncs.hpp"

void BubbleSort(int *arr, int n) // 숫자 배열, 원소 개수
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j+1])
				std::swap(arr[j], arr[j+1]);
		}
	}
}
