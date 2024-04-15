#include "SortFuncs.hpp"

void CountingSort(int *arr, int count)
{
	int min = *std::min_element(arr, arr + count);
	int max = *std::max_element(arr, arr + count);
	int range = max - min + 1;

	int *counting = new int[range];
	std::fill(counting, counting + range, 0);

	for(int i = 0; i < count; i++)
		counting[arr[i] - min] += 1;
	
	for(int i = 1; i < range; i++)
		counting[i] += counting[i-1];

	int *sorted = new int[count];
	for(int i = count-1; i >= 0; i--)
	{
		int index = counting[arr[i] - min] - 1;
		sorted[index] = arr[i];
		counting[arr[i] - min] -= 1;
	}

	for(int i = 0; i < count; i++)
		arr[i] = sorted[i];
}
