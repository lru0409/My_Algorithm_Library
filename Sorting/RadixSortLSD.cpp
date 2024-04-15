#include "SortFuncs.hpp"

static void CountingSort(int *arr, int count, int exp);

void RadixSortLSD(int *arr, int count)
{
	int max = *std::max_element(arr, arr + count);
	for(int exp = 1; max / exp > 0; exp *= 10)
		CountingSort(arr, count, exp);
}

static void CountingSort(int *arr, int count, int exp)
{
	int counting[10] = {0};

	for(int i = 0; i < count; i++)
	{
		int digit = (arr[i] / exp) % 10;
		counting[digit] += 1;
	}

	for(int i = 1; i < 10; i++)
		counting[i] += counting[i-1];
	
	int *sorted = new int[count];
	for(int i = count-1; i >= 0; i--)
	{
		int digit = (arr[i] / exp) % 10;
		int index = counting[digit] - 1;
		sorted[index] = arr[i];
		counting[digit] -= 1;
	}

	for(int i = 0; i < count; i++)
		arr[i] = sorted[i];
}
